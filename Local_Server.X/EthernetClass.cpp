/* 
 * File:   EthernetClass.cpp
 * Author: te
 * 
 * Created on 22 December 2018, 15:25
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <xc.h>
#include "Globals.h"
#include "my_uart.h"
#include "EthernetClass.h"

#if ETHERCARD_SEND_PIPELINING
#define BREAKORCONTINUE retry=0; continue;
#else
#define BREAKORCONTINUE break;
#endif

static uint8_t www_fd; // ID of current http request (only one http request at a time - one of the 8 possible concurrent TCP/IP connections) 
uint8_t dnstid_l; // a counter for transaction ID


#define DNSCLIENT_SRC_PORT_H 0xE0

#define DNS_TYPE_A 1
#define DNS_CLASS_IN 1


uint8_t Stash::map[SCRATCH_MAP_SIZE];
Stash::Block Stash::bufs[BUFCOUNT];

EthernetClass::EthernetClass() {
}

EthernetClass::EthernetClass(const EthernetClass& orig) {
}

EthernetClass::~EthernetClass() {
}

uint8_t* EthernetClass::tcpOffset() {
    return buffer + 0x36;
};

void EthernetClass::xferSPI(uint8_t data) {

    SPI2BUF = data;
    while (!SPI2STATbits.SPITBE | !SPI2STATbits.SPIRBF);
    delay_uS(1);
    uint8_t dummy = SPI2BUF;
}

void EthernetClass::writeRegByte(uint8_t address, uint8_t data) {
    SetBank(address);
    writeOp(ENC28J60_WRITE_CTRL_REG, address, data);
}

void EthernetClass::writeReg(uint8_t address, uint16_t data) {
    writeRegByte(address, data);
    writeRegByte(address + 1, data >> 8);
}

void EthernetClass::SetBank(uint8_t address) {
    if ((address & BANK_MASK) != Enc28j60Bank) {
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_BSEL1 | ECON1_BSEL0);
        Enc28j60Bank = address & BANK_MASK;
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, Enc28j60Bank >> 5);
    }
}

void EthernetClass::writeOp(uint8_t op, uint8_t address, uint8_t data) {
    enableChip();
    xferSPI(op | (address & ADDR_MASK));
    xferSPI(data);
    disableChip();
}

void EthernetClass::initSPI() {
    CS_OFF;
    Set_SCK;
    Set_DO;
    Set_DI;
    Set_CS;
    int rData;
    IEC1CLR = 0xE0; // disable all interrupts
    SPI2CON = 0; // Stops and resets the SPI1.
    rData = SPI2BUF; // clears the receive buffer
    IFS1CLR = 0xE0; // clear any existing event
    IPC5CLR = 0x1f000000; // clear the priority
    IPC5SET = 0x0d000000; // Set IPL=3, Subpriority 1
    SPI2BRG = 0x2; // use FPB/4 clock frequency
    SPI2STATCLR = 0x40; // clear the Overflow
    SPI2CONbits.MODE32 = 0;
    SPI2CONbits.MODE16 = 0;
    SPI2CONbits.MSTEN = 1; //Master mode   
    SPI2CONbits.SSEN = 0; //Not slave mode     
    SPI2CONbits.CKP = 0; //Low idle, high active     
    SPI2CONbits.CKE = 1; //Change output on falling edge     
    SPI2CONbits.SMP = 0; //Sample MISO at middle of clock pulse     
    SPI2CONbits.DISSDO = 0; //MISO is enabled     
    //Must be final command     
    SPI2CONbits.ON = 1;
    //Ready to transmit or receive via SPI2BUF 
}

void EthernetClass::enableChip() {
    CS_ON;
}

void EthernetClass::disableChip() {

    CS_OFF;
}

uint8_t EthernetClass::readRegByte(uint8_t address) {
    SetBank(address);
    return readOp(ENC28J60_READ_CTRL_REG, address);
}

uint8_t EthernetClass::rxSPI() {
    uint8_t value = 0;
    SPI2STATbits.SPIROV = 0;
    SPI2BUF = 0x00;
    while (!SPI2STATbits.SPITBE);
    delay_uS(1);
    value = SPI2BUF;
    return value;
}

uint8_t EthernetClass::readOp(uint8_t op, uint8_t address) {

    enableChip();
    SPI2STATbits.SPIROV = 0;
    uint8_t result;
    xferSPI(op | (address & ADDR_MASK));
    if (address & 0x80)
        xferSPI(0x00);
    result = rxSPI();
    disableChip();
    return result;
}

void EthernetClass::writePhy(uint8_t address, uint16_t data) {
    writeRegByte(MIREGADR, address);
    writeReg(MIWR, data);
    while (readRegByte(MISTAT) & MISTAT_BUSY);
}

void EthernetClass::readBuf(uint16_t len, uint8_t* data) {
    uint8_t nextbyte;
    enableChip();
    if (len != 0) {
        xferSPI(ENC28J60_READ_BUF_MEM);
        while (--len) {
            nextbyte = rxSPI();
            *data++ = nextbyte;
        }
        *data++ = rxSPI();
    }
    disableChip();
}

void EthernetClass::writeBuf(uint16_t len, const uint8_t* data) {
    enableChip();
    if (len != 0) {
        xferSPI(ENC28J60_WRITE_BUF_MEM);
        xferSPI(*data++);
        while (--len) {
            uint8_t nextbyte = *data++;
            xferSPI(nextbyte);
        };
    }
    disableChip();
}

bool EthernetClass::isLinkUp() {
    return (readPhyByte(PHSTAT2) >> 2) & 1;
}

uint16_t EthernetClass::readPhyByte(uint8_t address) {
    writeRegByte(MIREGADR, address);
    writeRegByte(MICMD, MICMD_MIIRD);
    while (readRegByte(MISTAT) & MISTAT_BUSY);
    writeRegByte(MICMD, 0x00);
    return readRegByte(MIRD + 1);
}

void EthernetClass::client_arp_whohas(uint8_t *ip_we_search) {
    setMACs(allOnes);
    gPB[ETH_TYPE_H_P] = ETHTYPE_ARP_H_V;
    gPB[ETH_TYPE_L_P] = ETHTYPE_ARP_L_V;
    memcpy(gPB + ETH_ARP_P, arpreqhdr, sizeof arpreqhdr);
    memset(gPB + ETH_ARP_DST_MAC_P, 0, ETH_LEN);
    copyMac(gPB + ETH_ARP_SRC_MAC_P, mymac);
    copyIp(gPB + ETH_ARP_DST_IP_P, ip_we_search);
    copyIp(gPB + ETH_ARP_SRC_IP_P, myip);
    packetSend(42);
}

void EthernetClass::client_syn(uint8_t srcport, uint8_t dstport_h, uint8_t dstport_l) {
    if (is_lan(myip, hisip)) {
        setMACandIPs(destmacaddr, hisip);
    } else {
        setMACandIPs(gwmacaddr, hisip);
    }
    gPB[ETH_TYPE_H_P] = ETHTYPE_IP_H_V;
    gPB[ETH_TYPE_L_P] = ETHTYPE_IP_L_V;
    memcpy(gPB + IP_P, iphdr, sizeof iphdr);
    gPB[IP_TOTLEN_L_P] = 44; // good for syn
    gPB[IP_PROTO_P] = IP_PROTO_TCP_V;
    fill_ip_hdr_checksum();
    gPB[TCP_DST_PORT_H_P] = dstport_h;
    gPB[TCP_DST_PORT_L_P] = dstport_l;
    gPB[TCP_SRC_PORT_H_P] = TCPCLIENT_SRC_PORT_H;
    gPB[TCP_SRC_PORT_L_P] = srcport; // lower 8 bit of src port
    memset(gPB + TCP_SEQ_H_P, 0, 8);
    gPB[TCP_SEQ_H_P + 2] = seqnum;
    seqnum += 3;
    gPB[TCP_HEADER_LEN_P] = 0x60; // 0x60=24 len: (0x60>>4) * 4
    gPB[TCP_FLAGS_P] = TCP_FLAGS_SYN_V;
    gPB[TCP_WIN_SIZE] = 0x3; // 1024 = 0x400 768 = 0x300, initial window
    gPB[TCP_WIN_SIZE + 1] = 0x0;
    gPB[TCP_CHECKSUM_H_P] = 0;
    gPB[TCP_CHECKSUM_L_P] = 0;
    gPB[TCP_CHECKSUM_L_P + 1] = 0;
    gPB[TCP_CHECKSUM_L_P + 2] = 0;
    gPB[TCP_OPTIONS_P] = 2;
    gPB[TCP_OPTIONS_P + 1] = 4;
    gPB[TCP_OPTIONS_P + 2] = (CLIENTMSS >> 8);
    gPB[TCP_OPTIONS_P + 3] = (uint8_t) CLIENTMSS;
    fill_checksum(TCP_CHECKSUM_H_P, IP_SRC_P, 8 + TCP_HEADER_LEN_PLAIN + 4, 2);
    // 4 is the tcp mss option:
    packetSend(IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + ETH_HEADER_LEN + 4);
}

void EthernetClass::setMACandIPs(const uint8_t *mac, const uint8_t *dst) {
    setMACs(mac);
    copyIp(gPB + IP_DST_P, dst);
    copyIp(gPB + IP_SRC_P, myip);
}

void EthernetClass::setMACs(const uint8_t *mac) {
    copyMac(gPB + ETH_DST_MAC, mac);
    copyMac(gPB + ETH_SRC_MAC, mymac);
}

void EthernetClass::copyIp(uint8_t *dst, const uint8_t *src) {
    memcpy(dst, src, IP_LEN);
}

void EthernetClass::copyMac(uint8_t *dst, const uint8_t *src) {
    memcpy(dst, src, ETH_LEN);
}

bool EthernetClass::is_lan(const uint8_t source[IP_LEN], const uint8_t destination[IP_LEN]) {
    if (source[0] == 0 || destination[0] == 0) {
        return false;
    }
    for (int i = 0; i < IP_LEN; i++)
        if ((source[i] & netmask[i]) != (destination[i] & netmask[i])) {
            return false;
        }
    return true;
}

void EthernetClass::fill_ip_hdr_checksum() {
    gPB[IP_CHECKSUM_P] = 0;
    gPB[IP_CHECKSUM_P + 1] = 0;
    gPB[IP_FLAGS_P] = 0x40; // don't fragment
    gPB[IP_FLAGS_P + 1] = 0; // fragement offset
    gPB[IP_TTL_P] = 64; // ttl
    fill_checksum(IP_CHECKSUM_P, IP_P, IP_HEADER_LEN, 0);
}

void EthernetClass::fill_checksum(uint8_t dest, uint8_t off, uint16_t len, uint8_t type) {
    const uint8_t* ptr = gPB + off;
    uint32_t sum = type == 1 ? IP_PROTO_UDP_V + len - 8 :
            type == 2 ? IP_PROTO_TCP_V + len - 8 : 0;
    while (len > 1) {
        sum += (uint16_t) (((uint32_t) * ptr << 8) | *(ptr + 1));
        ptr += 2;
        len -= 2;
    }
    if (len)
        sum += ((uint32_t) * ptr) << 8;
    while (sum >> 16)
        sum = (uint16_t) sum + (sum >> 16);
    uint16_t ck = ~(uint16_t) sum;
    gPB[dest] = ck >> 8;
    gPB[dest + 1] = ck;
}
//

uint8_t EthernetClass::eth_type_is_arp_and_my_ip(uint16_t len) {
    return len >= 41 && gPB[ETH_TYPE_H_P] == ETHTYPE_ARP_H_V &&
            gPB[ETH_TYPE_L_P] == ETHTYPE_ARP_L_V &&
            memcmp(gPB + ETH_ARP_DST_IP_P, myip, IP_LEN) == 0;
}

void EthernetClass::make_arp_answer_from_request() {
    setMACs(gPB + ETH_SRC_MAC);
    gPB[ETH_ARP_OPCODE_H_P] = ETH_ARP_OPCODE_REPLY_H_V;
    gPB[ETH_ARP_OPCODE_L_P] = ETH_ARP_OPCODE_REPLY_L_V;
    copyMac(gPB + ETH_ARP_DST_MAC_P, gPB + ETH_ARP_SRC_MAC_P);
    copyMac(gPB + ETH_ARP_SRC_MAC_P, mymac);
    copyIp(gPB + ETH_ARP_DST_IP_P, gPB + ETH_ARP_SRC_IP_P);
    copyIp(gPB + ETH_ARP_SRC_IP_P, myip);
    packetSend(42);
}

uint8_t EthernetClass::client_store_mac(uint8_t *source_ip, uint8_t *mac) {
    if (memcmp(gPB + ETH_ARP_SRC_IP_P, source_ip, IP_LEN) != 0)
        return 0;
    copyMac(mac, gPB + ETH_ARP_SRC_MAC_P);
    return 1;
}

void EthernetClass::setGwIp(const uint8_t *gwipaddr) {
    delaycnt = 0; //request gateway ARP lookup
    waitgwmac = WGW_INITIAL_ARP; // causes an arp request in the packet loop
    copyIp(gwip, gwipaddr);
}

uint8_t EthernetClass::eth_type_is_ip_and_my_ip(uint16_t len) {
    return len >= 42 && gPB[ETH_TYPE_H_P] == ETHTYPE_IP_H_V &&
            gPB[ETH_TYPE_L_P] == ETHTYPE_IP_L_V &&
            gPB[IP_HEADER_LEN_VER_P] == 0x45 &&
            (memcmp(gPB + IP_DST_P, myip, IP_LEN) == 0 //not my IP
            || (memcmp(gPB + IP_DST_P, broadcastip, IP_LEN) == 0) //not subnet broadcast
            || (memcmp(gPB + IP_DST_P, allOnes, IP_LEN) == 0)); //not global broadcasts
    //!@todo Handle multicast
}

void EthernetClass::make_echo_reply_from_request(uint16_t len) {
    make_eth_ip();
    gPB[ICMP_TYPE_P] = ICMP_TYPE_ECHOREPLY_V;
    if (gPB[ICMP_CHECKSUM_P] > (0xFF - 0x08))
        gPB[ICMP_CHECKSUM_P + 1]++;
    gPB[ICMP_CHECKSUM_P] += 0x08;
    packetSend(len);
}

void EthernetClass::make_eth_ip() {
    setMACs(gPB + ETH_SRC_MAC);
    copyIp(gPB + IP_DST_P, gPB + IP_SRC_P);
    copyIp(gPB + IP_SRC_P, myip);
    fill_ip_hdr_checksum();
}

bool EthernetClass::udpServerListening() {
    return numListeners > 0;
}

bool EthernetClass::udpServerHasProcessedPacket(uint16_t plen) {
    bool packetProcessed = false;
    for (int i = 0; i < numListeners; i++) {
        if (gPB[UDP_DST_PORT_H_P] == (listeners[i].port >> 8) && gPB[UDP_DST_PORT_L_P] == ((uint8_t) listeners[i].port) && listeners[i].listening) {
            uint16_t datalen = (uint16_t) (gPB[UDP_LEN_H_P] << 8) + gPB[UDP_LEN_L_P] - UDP_HEADER_LEN;
            listeners[i].callback(
                    listeners[i].port,
                    gPB + IP_SRC_P,
                    (gPB[UDP_SRC_PORT_H_P] << 8) | gPB[UDP_SRC_PORT_L_P],
                    (const char *) (gPB + UDP_DATA_P),
                    datalen);
            packetProcessed = true;
        }
    }
    return packetProcessed;
}

uint16_t EthernetClass::accept(const uint16_t port, uint16_t plen) {
    uint16_t pos;
    if (gPB[TCP_DST_PORT_H_P] == (port >> 8) &&
            gPB[TCP_DST_PORT_L_P] == ((uint8_t) port)) { //Packet targetted at specified port
        if (gPB[TCP_FLAGS_P] & TCP_FLAGS_SYN_V)
            make_tcp_synack_from_syn(); //send SYN+ACK
        else if (gPB[TCP_FLAGS_P] & TCP_FLAGS_ACK_V) { //This is an acknowledgement to our SYN+ACK so let's start processing that payload
            info_data_len = getTcpPayloadLength();
            if (info_data_len > 0) { //Got some data
                pos = TCP_DATA_START; // TCP_DATA_START is a formula
                //!@todo no idea what this check pos<=plen-8 does; changed this to pos<=plen as otw. perfectly valid tcp packets are ignored; still if anybody has any idea please leave a comment
                if (pos <= plen)
                    return pos;
            } else if (gPB[TCP_FLAGS_P] & TCP_FLAGS_FIN_V)
                make_tcp_ack_from_any(0, 0); //No data so close connection
        }
    }
    return 0;

}

void EthernetClass::make_tcp_synack_from_syn() {
    gPB[IP_TOTLEN_H_P] = 0;
    gPB[IP_TOTLEN_L_P] = IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + 4;
    make_eth_ip();
    gPB[TCP_FLAGS_P] = TCP_FLAGS_SYNACK_V;
    make_tcphead(1, 0);
    gPB[TCP_SEQ_H_P + 0] = 0;
    gPB[TCP_SEQ_H_P + 1] = 0;
    gPB[TCP_SEQ_H_P + 2] = seqnum;
    gPB[TCP_SEQ_H_P + 3] = 0;
    seqnum += 3;
    gPB[TCP_OPTIONS_P] = 2;
    gPB[TCP_OPTIONS_P + 1] = 4;
    gPB[TCP_OPTIONS_P + 2] = 0x05;
    gPB[TCP_OPTIONS_P + 3] = 0x0;
    gPB[TCP_HEADER_LEN_P] = 0x60;
    gPB[TCP_WIN_SIZE] = 0x5; // 1400=0x578
    gPB[TCP_WIN_SIZE + 1] = 0x78;
    fill_checksum(TCP_CHECKSUM_H_P, IP_SRC_P, 8 + TCP_HEADER_LEN_PLAIN + 4, 2);
    packetSend(IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + 4 + ETH_HEADER_LEN);
}

void EthernetClass::make_tcphead(uint16_t rel_ack_num, uint8_t cp_seq) {
    uint8_t i = gPB[TCP_DST_PORT_H_P];
    gPB[TCP_DST_PORT_H_P] = gPB[TCP_SRC_PORT_H_P];
    gPB[TCP_SRC_PORT_H_P] = i;
    uint8_t j = gPB[TCP_DST_PORT_L_P];
    gPB[TCP_DST_PORT_L_P] = gPB[TCP_SRC_PORT_L_P];
    gPB[TCP_SRC_PORT_L_P] = j;
    step_seq(rel_ack_num, cp_seq);
    gPB[TCP_CHECKSUM_H_P] = 0;
    gPB[TCP_CHECKSUM_L_P] = 0;
    gPB[TCP_HEADER_LEN_P] = 0x50;
}

void EthernetClass::step_seq(uint16_t rel_ack_num, uint8_t cp_seq) {
    uint8_t i;
    uint8_t tseq;
    i = 4;
    while (i > 0) {
        rel_ack_num = gPB[TCP_SEQ_H_P + i - 1] + rel_ack_num;
        tseq = gPB[TCP_SEQACK_H_P + i - 1];
        gPB[TCP_SEQACK_H_P + i - 1] = rel_ack_num;
        if (cp_seq)
            gPB[TCP_SEQ_H_P + i - 1] = tseq;
        else
            gPB[TCP_SEQ_H_P + i - 1] = 0; // some preset value
        rel_ack_num = rel_ack_num >> 8;
        i--;
    }
}

uint8_t EthernetClass::check_ip_message_is_from(const uint8_t *ip) {
    return memcmp(gPB + IP_SRC_P, ip, IP_LEN) == 0;
}

uint16_t EthernetClass::getTcpPayloadLength() {
    int16_t i = (((int16_t) gPB[IP_TOTLEN_H_P]) << 8) | gPB[IP_TOTLEN_L_P];
    i -= IP_HEADER_LEN;
    i -= (gPB[TCP_HEADER_LEN_P] >> 4)*4; // generate len in bytes;
    if (i <= 0)
        i = 0;
    return (uint16_t) i;
}

void EthernetClass::make_tcp_ack_from_any(int16_t datlentoack, uint8_t addflags) {
    gPB[TCP_FLAGS_P] = TCP_FLAGS_ACK_V | addflags;
    if (addflags != TCP_FLAGS_RST_V && datlentoack == 0)
        datlentoack = 1;
    make_tcphead(datlentoack, 1); // no options
    uint16_t j = IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN;
    gPB[IP_TOTLEN_H_P] = j >> 8;
    gPB[IP_TOTLEN_L_P] = j;
    make_eth_ip();
    gPB[TCP_WIN_SIZE] = 0x4; // 1024=0x400, 1280=0x500 2048=0x800 768=0x300
    gPB[TCP_WIN_SIZE + 1] = 0;
    fill_checksum(TCP_CHECKSUM_H_P, IP_SRC_P, 8 + TCP_HEADER_LEN_PLAIN, 2);
    packetSend(IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + ETH_HEADER_LEN);
}

uint32_t EthernetClass::getBigEndianLong(uint8_t offs) { //get the sequence number of packets after an ack from GET
    return (((unsigned long) gPB[offs]*256 + gPB[offs + 1])*256 + gPB[offs + 2])*256 + gPB[offs + 3];
} //thanks to mstuetz for the missing (unsigned long)

uint32_t EthernetClass::getSequenceNumber() {
    return getBigEndianLong(TCP_SEQ_H_P);
}

void EthernetClass::httpServerReplyAck() {
    make_tcp_ack_from_any(getTcpPayloadLength(), 0); // send ack for http request
    SEQ = getSequenceNumber(); //get the sequence number of packets after an ack from GET
}

void EthernetClass::make_tcp_ack_with_data_noflags(uint16_t dlen) {
    uint16_t j = IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + dlen;
    gPB[IP_TOTLEN_H_P] = j >> 8;
    gPB[IP_TOTLEN_L_P] = j;
    fill_ip_hdr_checksum();
    gPB[TCP_CHECKSUM_H_P] = 0;
    gPB[TCP_CHECKSUM_L_P] = 0;
    fill_checksum(TCP_CHECKSUM_H_P, IP_SRC_P, 8 + TCP_HEADER_LEN_PLAIN + dlen, 2);
    packetSend(IP_HEADER_LEN + TCP_HEADER_LEN_PLAIN + dlen + ETH_HEADER_LEN);
}

uint8_t EthernetClass::readReg(uint8_t address) {
    return readRegByte(address) + (readRegByte(address + 1) << 8);
}

void EthernetClass::updateBroadcastAddress() {
    for (uint8_t i = 0; i < IP_LEN; i++)
        broadcastip[i] = myip[i] | ~netmask[i];

}

void EthernetClass::DhcpStateMachine(uint16_t len) {

#ifdef DHCPDEBUG
    if (dhcpState != DHCP_STATE_BOUND) {
        Serial.print(millis());
        Serial.print(" State: ");
    }
    switch (dhcpState) {
        case DHCP_STATE_INIT:
            Serial.println("Init");
            break;
        case DHCP_STATE_SELECTING:
            Serial.println("Selecting");
            break;
        case DHCP_STATE_REQUESTING:
            Serial.println("Requesting");
            break;
        case DHCP_STATE_RENEWING:
            Serial.println("Renew");
            break;
    }
#endif

    switch (dhcpState) {

        case DHCP_STATE_BOUND:
            //!@todo Due to millis() wrap-around, DHCP renewal may not work if leaseTime is larger than 49days
            if (leaseTime != DHCP_INFINITE_LEASE && millis() - leaseStart >= leaseTime) {
                send_dhcp_message(myip);
                dhcpState = DHCP_STATE_RENEWING;
                stateTimer = millis();
            }
            break;

        case DHCP_STATE_INIT:
            currentXid = millis();
            memset(myip, 0, IP_LEN); // force ip 0.0.0.0
            send_dhcp_message(NULL);
            enableBroadcast(true); //Temporarily enable broadcasts
            dhcpState = DHCP_STATE_SELECTING;
            stateTimer = millis();
            break;

        case DHCP_STATE_SELECTING:
            if (dhcp_received_message_type(len, DHCP_OFFER)) {
                uint8_t offeredip[IP_LEN];
                process_dhcp_offer(len, offeredip);
                send_dhcp_message(offeredip);
                dhcpState = DHCP_STATE_REQUESTING;
                stateTimer = millis();
            } else {
                if (millis() - stateTimer > DHCP_REQUEST_TIMEOUT) {
                    dhcpState = DHCP_STATE_INIT;
                }
            }
            break;

        case DHCP_STATE_REQUESTING:
        case DHCP_STATE_RENEWING:
            if (dhcp_received_message_type(len, DHCP_ACK)) {
                disableBroadcast(true); //Disable broadcast after temporary enable
                process_dhcp_ack(len);
                leaseStart = millis();
                if (gwip[0] != 0) setGwIp(gwip); // why is this? because it initiates an arp request
                dhcpState = DHCP_STATE_BOUND;
            } else {
                if (millis() - stateTimer > DHCP_REQUEST_TIMEOUT) {
                    dhcpState = DHCP_STATE_INIT;
                }
            }
            break;

    }

}

void EthernetClass::send_dhcp_message(uint8_t *requestip) {
    memset(gPB, 0, UDP_DATA_P + sizeof ( DHCPdata));

    ether.udpPrepare(DHCP_CLIENT_PORT,
            (dhcpState == DHCP_STATE_BOUND ? dhcpip : allOnes),
            DHCP_SERVER_PORT);

    // If we ever don't do this, the DHCP renewal gets sent to whatever random
    // destmacaddr was used by other code. Rather than cache the MAC address of
    // the DHCP server, just force a broadcast here in all cases.
    copyMac(gPB + ETH_DST_MAC, allOnes); //force broadcast mac

    // Build DHCP Packet from buf[UDP_DATA_P]
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);
    dhcpPtr->op = DHCP_BOOTREQUEST;
    dhcpPtr->htype = 1;
    dhcpPtr->hlen = 6;
    dhcpPtr->xid = currentXid;
    if (dhcpState == DHCP_STATE_BOUND) {
        copyIp(dhcpPtr->ciaddr, myip);
    }
    copyMac(dhcpPtr->chaddr, mymac);

    // options defined as option, length, value
    bufPtr = gPB + UDP_DATA_P + sizeof ( DHCPdata);
    // DHCP magic cookie
    uint8_t cookie[] = {0x63, 0x82, 0x53, 0x63};
    //	for (uint8_t i = 0; i < sizeof(cookie); i++)
    //	addToBuf(&cookie[i]);
    addToBuf(DHCP_OPT_MESSAGE_TYPE); // DHCP_STATE_SELECTING, DHCP_STATE_REQUESTING
    addToBuf(1); // Length
    addToBuf(dhcpState == DHCP_STATE_INIT ? DHCP_DISCOVER : DHCP_REQUEST);

    // Client Identifier Option, this is the client mac address
    addToBuf(DHCP_OPT_CLIENT_IDENTIFIER);
    addToBuf(1 + ETH_LEN); // Length (hardware type + client MAC)
    addToBuf(DHCP_HTYPE_ETHER);
    addBytes(ETH_LEN, mymac);

    if (hostname[0]) {
        addOption(DHCP_OPT_HOSTNAME, strlen(hostname), (uint8_t*) hostname);
    }

    if (requestip != NULL) {
        addOption(DHCP_OPT_REQUESTED_ADDRESS, IP_LEN, requestip);
        addOption(DHCP_OPT_SERVER_IDENTIFIER, IP_LEN, dhcpip);
    }

    // Additional info in parameter list - minimal list for what we need
    uint8_t len = 3;
    if (dhcpCustomOptionNum)
        len++;
    addToBuf(DHCP_OPT_PARAMETER_REQUEST_LIST);
    addToBuf(len); // Length
    addToBuf(DHCP_OPT_SUBNET_MASK);
    addToBuf(DHCP_OPT_ROUTERS);
    addToBuf(DHCP_OPT_DOMAIN_NAME_SERVERS);
    if (dhcpCustomOptionNum)
        addToBuf(dhcpCustomOptionNum); // Custom option

    addToBuf(DHCP_OPT_END);

    // packet size will be under 300 bytes
    udpTransmit((bufPtr - gPB) - UDP_DATA_P);

}

void EthernetClass::udpPrepare(uint16_t sport, const uint8_t *dip, uint16_t dport) {

    if (is_lan(myip, dip)) { // this works because both dns mac and destinations mac are stored in same variable - destmacaddr
        setMACandIPs(destmacaddr, dip); // at different times. The program could have separate variable for dns mac, then here should be
    } else { // checked if dip is dns ip and separately if dip is hisip and then use correct mac.
        setMACandIPs(gwmacaddr, dip);
    }
    // see http://tldp.org/HOWTO/Multicast-HOWTO-2.html
    // multicast or broadcast address, https://github.com/jcw/ethercard/issues/59
    if ((dip[0] & 0xF0) == 0xE0 || *((unsigned long*) dip) == 0xFFFFFFFF || !memcmp(broadcastip, dip, IP_LEN))
        copyMac(gPB + ETH_DST_MAC, allOnes);
    gPB[ETH_TYPE_H_P] = ETHTYPE_IP_H_V;
    gPB[ETH_TYPE_L_P] = ETHTYPE_IP_L_V;
    memcpy(gPB + IP_P, iphdr, sizeof iphdr);
    gPB[IP_TOTLEN_H_P] = 0;
    gPB[IP_PROTO_P] = IP_PROTO_UDP_V;
    gPB[UDP_DST_PORT_H_P] = (dport >> 8);
    gPB[UDP_DST_PORT_L_P] = dport;
    gPB[UDP_SRC_PORT_H_P] = (sport >> 8);
    gPB[UDP_SRC_PORT_L_P] = sport;
    gPB[UDP_LEN_H_P] = 0;
    gPB[UDP_CHECKSUM_H_P] = 0;
    gPB[UDP_CHECKSUM_L_P] = 0;

}

void EthernetClass::enableBroadcast(bool temporary) {
    writeRegByte(ERXFCON, readRegByte(ERXFCON) | ERXFCON_BCEN);
    if (!temporary)
        broadcast_enabled = true;

}

bool EthernetClass::dhcp_received_message_type(uint16_t len, uint8_t msgType) {
    // Map struct onto payload
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    if (len >= 70 && gPB[UDP_SRC_PORT_L_P] == DHCP_SERVER_PORT &&
            dhcpPtr->xid == currentXid) {

        uint8_t *ptr = (uint8_t*) (dhcpPtr + 1) + 4;
        do {
            uint8_t option = *ptr++;
            uint8_t optionLen = *ptr++;
            if (option == DHCP_OPT_MESSAGE_TYPE && *ptr == msgType) {
                return true;
            }
            ptr += optionLen;
        } while (ptr < gPB + len);
    }
    return false;
}

void EthernetClass::addToBuf(uint8_t b) {
    *bufPtr++ = b;
}

void EthernetClass::addBytes(uint8_t len, const uint8_t* data) {
    while (len-- > 0)
        addToBuf(*data++);
}

void EthernetClass::addOption(uint8_t opt, uint8_t len, const uint8_t* data) {
    addToBuf(opt);
    addToBuf(len);
    addBytes(len, data);
}

void EthernetClass::udpTransmit(uint16_t datalen) {

    gPB[IP_TOTLEN_H_P] = (IP_HEADER_LEN + UDP_HEADER_LEN + datalen) >> 8;
    gPB[IP_TOTLEN_L_P] = IP_HEADER_LEN + UDP_HEADER_LEN + datalen;
    fill_ip_hdr_checksum();
    gPB[UDP_LEN_H_P] = (UDP_HEADER_LEN + datalen) >> 8;
    gPB[UDP_LEN_L_P] = UDP_HEADER_LEN + datalen;
    fill_checksum(UDP_CHECKSUM_H_P, IP_SRC_P, 16 + datalen, 1);
    packetSend(UDP_HEADER_LEN + IP_HEADER_LEN + ETH_HEADER_LEN + datalen);

}

void EthernetClass::process_dhcp_offer(uint16_t len, uint8_t *offeredip) {
    // Map struct onto payload
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    // Offered IP address is in yiaddr
    copyIp(offeredip, dhcpPtr->yiaddr);

    // Search for the server IP
    uint8_t *ptr = (uint8_t*) (dhcpPtr + 1) + 4;
    do {
        uint8_t option = *ptr++;
        uint8_t optionLen = *ptr++;
        if (option == DHCP_OPT_SERVER_IDENTIFIER) {
            copyIp(dhcpip, ptr);
            break;
        }
        ptr += optionLen;
    } while (ptr < gPB + len);

}

void EthernetClass::disableBroadcast(bool temporary) {
    if (!temporary)
        broadcast_enabled = false;
    if (!broadcast_enabled)
        writeRegByte(ERXFCON, readRegByte(ERXFCON) & ~ERXFCON_BCEN);

}

void EthernetClass::process_dhcp_ack(uint16_t len) {
    // Map struct onto payload
    DHCPdata *dhcpPtr = (DHCPdata*) (gPB + UDP_DATA_P);

    // Allocated IP address is in yiaddr
    copyIp(myip, dhcpPtr->yiaddr);

    // Scan through variable length option list identifying options we want
    uint8_t *ptr = (uint8_t*) (dhcpPtr + 1) + 4;
    bool done = false;
    do {
        uint8_t option = *ptr++;
        uint8_t optionLen = *ptr++;
        switch (option) {
            case DHCP_OPT_SUBNET_MASK:
                copyIp(netmask, ptr);
                break;
            case DHCP_OPT_ROUTERS:
                copyIp(gwip, ptr);
                break;
            case DHCP_OPT_DOMAIN_NAME_SERVERS:
                copyIp(dnsip, ptr);
                break;
            case DHCP_OPT_LEASE_TIME:
            case DHCP_OPT_RENEWAL_TIME:
                leaseTime = 0;
                for (uint8_t i = 0; i < 4; i++)
                    leaseTime = (leaseTime << 8) + ptr[i];
                if (leaseTime != DHCP_INFINITE_LEASE) {
                    leaseTime *= 1000; // milliseconds
                }
                break;
            case DHCP_OPT_END:
                done = true;
                break;
            default:
            {
                // Is is a custom configured option?
                if (dhcpCustomOptionCallback && option == dhcpCustomOptionNum) {
                    dhcpCustomOptionCallback(option, ptr, optionLen);
                }
            }
        }
        ptr += optionLen;
    } while (!done && ptr < gPB + len);

}

uint16_t EthernetClass::millis() {
    uint16_t ret = 0;
    uint32_t StartTime = _CP0_GET_COUNT();
    ret = (uint16_t) (StartTime / (SYS_FREQ / 1000));
    return ret;
}

void EthernetClass::setSequenceNumber(uint32_t seq) {
    gPB[TCP_SEQ_H_P] = (seq & 0xff000000) >> 24;
    gPB[TCP_SEQ_H_P + 1] = (seq & 0xff0000) >> 16;
    gPB[TCP_SEQ_H_P + 2] = (seq & 0xff00) >> 8;
    gPB[TCP_SEQ_H_P + 3] = (seq & 0xff);
}

uint8_t EthernetClass::initialize(const uint8_t* macaddr) {

    initSPI();

    disableChip();

    writeOp(ENC28J60_SOFT_RESET, 0, ENC28J60_SOFT_RESET);
    delay(2); // errata B7/2
    // while (!readOp(ENC28J60_READ_CTRL_REG, ESTAT) & ESTAT_CLKRDY);
    while (!readOp(ENC28J60_READ_CTRL_REG, ESTAT));

    writeReg(ERXST, RXSTART_INIT);
    writeReg(ERXRDPT, RXSTART_INIT);
    writeReg(ERXND, RXSTOP_INIT);
    writeReg(ETXST, TXSTART_INIT);
    writeReg(ETXND, TXSTOP_INIT);
    writeRegByte(ERXFCON, ERXFCON_UCEN | ERXFCON_CRCEN | ERXFCON_PMEN | ERXFCON_BCEN);
    writeReg(EPMM0, 0x303f);
    writeReg(EPMCS, 0xf7f9);
    writeRegByte(MACON1, MACON1_MARXEN | MACON1_TXPAUS | MACON1_RXPAUS);
    writeRegByte(MACON2, 0x00);
    writeOp(ENC28J60_BIT_FIELD_SET, MACON3,
            MACON3_PADCFG0 | MACON3_TXCRCEN | MACON3_FRMLNEN);
    writeReg(MAIPG, 0x0C12);
    writeRegByte(MABBIPG, 0x12);
    writeReg(MAMXFL, MAX_FRAMELEN);
    writeRegByte(MAADR5, macaddr[0]);
    writeRegByte(MAADR4, macaddr[1]);
    writeRegByte(MAADR3, macaddr[2]);
    writeRegByte(MAADR2, macaddr[3]);
    writeRegByte(MAADR1, macaddr[4]);
    writeRegByte(MAADR0, macaddr[5]);
    writePhy(PHCON2, PHCON2_HDLDIS);
    SetBank(ECON1);
    writeOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE | EIE_PKTIE);
    writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);

    uint8_t rev = readRegByte(EREVID);
    // microchip forgot to step the number on the chip when they
    // released the revision B7. 6 is now rev B7. We still have
    // to see what they do when they release B8. At the moment
    // there is no B8 out yet
    if (rev > 5) ++rev;
    return rev;
}

uint16_t EthernetClass::packetReceive() {
    static uint16_t gNextPacketPtr = RXSTART_INIT;
    static bool unreleasedPacket = false;
    uint16_t len = 0;

    if (unreleasedPacket) {
        if (gNextPacketPtr == 0)
            writeReg(ERXRDPT, RXSTOP_INIT);
        else
            writeReg(ERXRDPT, gNextPacketPtr - 1);
        unreleasedPacket = false;
    }

    if (readRegByte(EPKTCNT) > 0) {
        writeReg(ERDPT, gNextPacketPtr);

        struct {
            uint16_t nextPacket;
            uint16_t byteCount;
            uint16_t status;
        } header;

        readBuf(sizeof header, (uint8_t*) & header);

        gNextPacketPtr = header.nextPacket;
        len = header.byteCount - 4; //remove the CRC count
        if (len > bufferSize - 1)
            len = bufferSize - 1;
        if ((header.status & 0x80) == 0)
            len = 0;
        else
            readBuf(len, buffer);
        buffer[len] = 0;
        unreleasedPacket = true;

        writeOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);
    }
    return len;

}

uint16_t EthernetClass::packetLoop(uint16_t plen) {
    uint16_t len;
#if ETHERCARD_DHCP
    if (using_dhcp) {
        DhcpStateMachine(plen);
    }
#endif

    if (plen == 0) {
        //Check every 65536 (no-packet) cycles whether we need to retry ARP request for gateway
        if ((waitgwmac & WGW_INITIAL_ARP || waitgwmac & WGW_REFRESHING) && delaycnt == 0 && isLinkUp()) {
            client_arp_whohas(gwip);
            waitgwmac |= WGW_ACCEPT_ARP_REPLY;
        }
        delaycnt++;

#if ETHERCARD_TCPCLIENT
        //Initiate TCP/IP session if pending
        if (tcp_client_state == TCP_STATE_SENDSYN && (waitgwmac & WGW_HAVE_GW_MAC)) { // send a syn
            tcp_client_state = TCP_STATE_SYNSENT;
            tcpclient_src_port_l++; // allocate a new port
            client_syn(((tcp_fd << 5) | (0x1f & tcpclient_src_port_l)), tcp_client_port_h, tcp_client_port_l);
        }
#endif

        //!@todo this is trying to find mac only once. Need some timeout to make another call if first one doesn't succeed.
        if (is_lan(myip, dnsip) && !has_dns_mac && !waiting_for_dns_mac) {
            client_arp_whohas(dnsip);
            waiting_for_dns_mac = true;
        }

        //!@todo this is trying to find mac only once. Need some timeout to make another call if first one doesn't succeed.
        if (is_lan(myip, hisip) && !has_dest_mac && !waiting_for_dest_mac) {
            client_arp_whohas(hisip);
            waiting_for_dest_mac = true;
        }
        return (uint16_t) 0;
    }
    if (eth_type_is_arp_and_my_ip(plen)) {
        //Service ARP request
        if (gPB[ETH_ARP_OPCODE_L_P] == ETH_ARP_OPCODE_REQ_L_V)
            make_arp_answer_from_request();
        if (waitgwmac & WGW_ACCEPT_ARP_REPLY && (gPB[ETH_ARP_OPCODE_L_P] == ETH_ARP_OPCODE_REPLY_L_V) && client_store_mac(gwip, gwmacaddr))
            waitgwmac = WGW_HAVE_GW_MAC;
        if (!has_dns_mac && waiting_for_dns_mac && client_store_mac(dnsip, destmacaddr)) {
            has_dns_mac = true;
            waiting_for_dns_mac = false;
        }
        if (!has_dest_mac && waiting_for_dest_mac && client_store_mac(hisip, destmacaddr)) {
            has_dest_mac = true;
            waiting_for_dest_mac = false;
        }
        return (uint16_t) 0;
    }

    if (eth_type_is_ip_and_my_ip(plen) == 0) { //Not IP so ignoring
        //!@todo Add other protocols (and make each optional at compile time)
        return (uint16_t) 0;
    }

#if ETHERCARD_ICMP
    if (gPB[IP_PROTO_P] == IP_PROTO_ICMP_V && gPB[ICMP_TYPE_P] == ICMP_TYPE_ECHOREQUEST_V) { //Service ICMP echo request (ping)
        if (icmp_cb)
            (*icmp_cb)(&(gPB[IP_SRC_P]));
        make_echo_reply_from_request(plen);
        return (uint16_t) 0;
    }
#endif

#if ETHERCARD_UDPSERVER
    if (udpServerListening() && gPB[IP_PROTO_P] == IP_PROTO_UDP_V) { //Call UDP server handler (callback) if one is defined for this packet
        if (udpServerHasProcessedPacket(plen))
            return (uint16_t) 0; //An UDP server handler (callback) has processed this packet
    }
#endif

    if (plen < 54 || gPB[IP_PROTO_P] != IP_PROTO_TCP_V)
        return (uint16_t) 0; //from here on we are only interested in TCP-packets; these are longer than 54 bytes

#if ETHERCARD_TCPCLIENT
    if (gPB[TCP_DST_PORT_H_P] == TCPCLIENT_SRC_PORT_H) { //Source port is in range reserved (by EtherCard) for client TCP/IP connections
        if (check_ip_message_is_from(hisip) == 0)
            return (uint16_t) 0; //Not current TCP/IP connection (only handle one at a time)
        if (gPB[TCP_FLAGS_P] & TCP_FLAGS_RST_V) { //TCP reset flagged
            if (client_tcp_result_cb)
                (*client_tcp_result_cb)((gPB[TCP_DST_PORT_L_P] >> 5)&0x7, 3, 0, 0);
            tcp_client_state = TCP_STATE_CLOSING;
            return (uint16_t) 0;
        }

        len = getTcpPayloadLength();
        if (tcp_client_state == TCP_STATE_SYNSENT) { //Waiting for SYN-ACK
            if ((gPB[TCP_FLAGS_P] & TCP_FLAGS_SYN_V) && (gPB[TCP_FLAGS_P] & TCP_FLAGS_ACK_V)) { //SYN and ACK flags set so this is an acknowledge to our SYN
                make_tcp_ack_from_any(0, 0);
                gPB[TCP_FLAGS_P] = TCP_FLAGS_ACK_V | TCP_FLAGS_PUSH_V;
                if (client_tcp_datafill_cb)
                    len = (*client_tcp_datafill_cb)((gPB[TCP_SRC_PORT_L_P] >> 5)&0x7);
                else
                    len = 0;
                tcp_client_state = TCP_STATE_ESTABLISHED;
                make_tcp_ack_with_data_noflags(len);
            } else { //Expecting SYN+ACK so reset and resend SYN
                tcp_client_state = TCP_STATE_SENDSYN; // retry
                len++;
                if (gPB[TCP_FLAGS_P] & TCP_FLAGS_ACK_V)
                    len = 0;
                make_tcp_ack_from_any(len, TCP_FLAGS_RST_V);
            }
            return (uint16_t) 0;
        }
        if (tcp_client_state == TCP_STATE_ESTABLISHED && len > 0) { //TCP connection established so read data
            if (client_tcp_result_cb) {
                uint16_t tcpstart = TCP_DATA_START; // TCP_DATA_START is a formula
                if (tcpstart > plen - 8)
                    tcpstart = plen - 8; // dummy but save
                uint16_t save_len = len;
                if (tcpstart + len > plen)
                    save_len = plen - tcpstart;
                (*client_tcp_result_cb)((gPB[TCP_DST_PORT_L_P] >> 5)&0x7, 0, tcpstart, save_len); //Call TCP handler (callback) function

                if (persist_tcp_connection) { //Keep connection alive by sending ACK
                    make_tcp_ack_from_any(len, TCP_FLAGS_PUSH_V);
                } else { //Close connection
                    make_tcp_ack_from_any(len, TCP_FLAGS_PUSH_V | TCP_FLAGS_FIN_V);
                    tcp_client_state = TCP_STATE_CLOSED;
                }
                return (uint16_t) 0;
            }
        }
        if (tcp_client_state != TCP_STATE_CLOSING) { //
            if (gPB[TCP_FLAGS_P] & TCP_FLAGS_FIN_V) {
                if (tcp_client_state == TCP_STATE_ESTABLISHED) {
                    return (uint16_t) 21; // In some instances FIN is received *before* DATA.  If that is the case, we just return here and keep looking for the data packet
                }
                make_tcp_ack_from_any(len + 1, TCP_FLAGS_PUSH_V | TCP_FLAGS_FIN_V);
                tcp_client_state = TCP_STATE_CLOSED; // connection terminated
            } else if (len > 0) {
                make_tcp_ack_from_any(len, 0);
            }
        }
        return (uint16_t) 0;
    }
#endif

#if ETHERCARD_TCPSERVER
    //If we are here then this is a TCP/IP packet targetted at us and not related to our client connection so accept
    return (uint16_t) accept(hisport, plen);
#endif
}

void EthernetClass::packetSend(uint16_t len) {
    uint8_t retry = 0;
#if ETHERCARD_SEND_PIPELINING
    goto resume_last_transmission;
#endif
    while (1) {
        // latest errata sheet: DS80349C
        // always reset transmit logic (Errata Issue 12)
        // the Microchip TCP/IP stack implementation used to first check
        // whether TXERIF is set and only then reset the transmit logic
        // but this has been changed in later versions; possibly they
        // have a reason for this; they don't mention this in the errata
        // sheet
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRST);
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRST);
        writeOp(ENC28J60_BIT_FIELD_CLR, EIR, EIR_TXERIF | EIR_TXIF);

        // prepare new transmission
        if (retry == 0) {
            writeReg(EWRPT, TXSTART_INIT);
            writeReg(ETXND, TXSTART_INIT + len);
            writeOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);
            writeBuf(len, buffer);
        }

        // initiate transmission
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
#if ETHERCARD_SEND_PIPELINING
        if (retry == 0) return;
#endif

resume_last_transmission:

        // wait until transmission has finished; referrring to the data sheet and
        // to the errata (Errata Issue 13; Example 1) you only need to wait until either
        // TXIF or TXERIF gets set; however this leads to hangs; apparently Microchip
        // realized this and in later implementations of their tcp/ip stack they introduced
        // a counter to avoid hangs; of course they didn't update the errata sheet
        uint16_t count = 0;
        while ((readRegByte(EIR) & (EIR_TXIF | EIR_TXERIF)) == 0 && ++count < 1000U);

        if (!(readRegByte(EIR) & EIR_TXERIF) && count < 1000U) {
            // no error; start new transmission
            BREAKORCONTINUE
        }

        // cancel previous transmission if stuck
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);

#if ETHERCARD_RETRY_LATECOLLISIONS == 0
        BREAKORCONTINUE
#endif

        // Check whether the chip thinks that a late collision ocurred; the chip
        // may be wrong (Errata Issue 13); therefore we retry. We could check
        // LATECOL in the ESTAT register in order to find out whether the chip
        // thinks a late collision ocurred but (Errata Issue 15) tells us that
        // this is not working. Therefore we check TSV
        transmit_status_vector tsv;

        uint16_t etxnd = readReg(ETXND);
        writeReg(ERDPT, etxnd + 1);
        readBuf(sizeof (transmit_status_vector), (uint8_t*) & tsv);
        // LATECOL is bit number 29 in TSV (starting from 0)

        if (!((readRegByte(EIR) & EIR_TXERIF) && (tsv.bytes[3] & 1 << 5) /*tsv.transmitLateCollision*/) || retry > 16U) {
            // there was some error but no LATECOL so we do not repeat
            BREAKORCONTINUE;
        }
        retry++;
    }
}

void EthernetClass::httpServerReply(uint16_t dlen) {
    make_tcp_ack_from_any(info_data_len, 0); // send ack for http get
    gPB[TCP_FLAGS_P] = TCP_FLAGS_ACK_V | TCP_FLAGS_PUSH_V | TCP_FLAGS_FIN_V;
    make_tcp_ack_with_data_noflags(dlen); // send data

}

void EthernetClass::httpServerReply_with_flags(uint16_t dlen, uint8_t flags) {
    setSequenceNumber(SEQ);
    gPB[TCP_FLAGS_P] = flags; // final packet
    make_tcp_ack_with_data_noflags(dlen); // send data
    SEQ = SEQ + dlen;
}

void EthernetClass::printIp(const char* msg, const uint8_t *buf) {

    //Serial.print(msg);
    printIp(buf);
    //Serial.println();

}

void EthernetClass::printIp(const uint8_t *buf) {
    for (uint8_t i = 0; i < IP_LEN; ++i) {
        //	Serial.print( buf[i], DEC );
        //	if (i < 3)
        //	Serial.print('.');
    }
}

uint8_t EthernetClass::begin(const uint8_t* macaddr, uint8_t csPin) {
    using_dhcp = false;
    TRISEbits.TRISE5 = 0;
    delay(100);
    LATEbits.LATE5 = 0;
    delay(1000);
    copyMac(mymac, macaddr);
    return initialize(mymac);
}

bool EthernetClass::staticSetup(const uint8_t* my_ip, const uint8_t* gw_ip, const uint8_t* dns_ip) {
    using_dhcp = false;
    if (my_ip != 0)
        copyIp(myip, my_ip);
    if (gw_ip != 0)
        setGwIp(gw_ip);
    if (dns_ip != 0)
        copyIp(dnsip, dns_ip);
    updateBroadcastAddress();
    delaycnt = 0; //request gateway ARP lookup
    return true;
}

uint8_t EthernetClass::GET_OR_POST(uint16_t position, uint16_t data_len) {

    char b[512];
    char request[20];
    uint16_t dl1 = data_len;

    memcpy(b, buffer + position, data_len - position);
    int bi = 0;
    //   do{Serial.print(b[bi]);bi++;}while(bi<data_len - position);
    if (strncmp(b, "GET", 3) == 0) {
        uint16_t index = indexof(b, '/', 0);
        uint16_t index1 = indexof(b, ' ', index) + 1;
        memcpy(request, b + index, index1 - index);
        if (strncmp(request, "/data ", 6) == 0) return 5;
        return 1;
    }
    if (strncmp(b, "POST", 4) == 0) {
        uint16_t index = indexof(b, '/', 0);
        uint16_t index1 = indexof(b, ' ', index) + 1;
        memcpy(request, b + index, index1 - index);
        if (strncmp(request, "/refresh ", 9) == 0) return 2;
        if (strncmp(request, "/update ", 8) == 0) return 3;
        if (strncmp(request, "/data ", 6) == 0) return 4;

    }
    return 0;
}

void EthernetClass::delay(uint16_t mS) {
    while (mS--) {
        uint32_t startTime = _CP0_GET_COUNT(); // Read the Core Timer
        while ((_CP0_GET_COUNT() - startTime) < MS_TO_CT_TICKS); // wait for timer to expire
    }
}

void EthernetClass::delay_uS(uint16_t uS) {
    uS *= US_TO_CT_TICKS;
    uint32_t startTime = _CP0_GET_COUNT(); // Read the Core Timer
    while ((_CP0_GET_COUNT() - startTime) < uS); // wait for timer to expire
}

uint16_t EthernetClass::indexof(char *str, char c, uint16_t start) {
    uint16_t ind = start;
    char t;
    do {
        t = (char) str[ind];
        if (t == c) return ind;
        ind++;
    } while (ind < 20);
    return 0;
}

uint8_t EthernetClass::clientWaitingDns() {
    if (is_lan(myip, dnsip))
        return !has_dns_mac;
    return !(waitgwmac & WGW_HAVE_GW_MAC);
}

void EthernetClass::dnsRequest(const char *hostname, bool fromRam) {
    ++dnstid_l; // increment for next request, finally wrap
    if (ether.dnsip[0] == 0)
        memset(ether.dnsip, 8, IP_LEN); // use 8.8.8.8 Google DNS as default
    ether.udpPrepare((DNSCLIENT_SRC_PORT_H << 8) | dnstid_l, ether.dnsip, DNS_PORT);
    memset(gPB + UDP_DATA_P, 0, 12);

    uint8_t *p = gPB + UDP_DATA_P + 12;
    char c;
    do {
        uint8_t n = 0;
        for (;;) {
            c = fromRam ? *hostname : *hostname;
            ++hostname;
            if (c == '.' || c == 0)
                break;
            p[++n] = c;
        }
        *p++ = n;
        p += n;
    } while (c != 0);

    *p++ = 0; // terminate with zero, means root domain.
    *p++ = 0;
    *p++ = DNS_TYPE_A;
    *p++ = 0;
    *p++ = DNS_CLASS_IN;
    uint8_t i = p - gPB - UDP_DATA_P;
    gPB[UDP_DATA_P] = i;
    gPB[UDP_DATA_P + 1] = dnstid_l;
    gPB[UDP_DATA_P + 2] = 1; // flags, standard recursive query
    gPB[UDP_DATA_P + 5] = 1; // 1 question
    ether.udpTransmit(i);
}

bool EthernetClass::checkForDnsAnswer(uint16_t plen) {
    uint8_t *p = gPB + UDP_DATA_P; //start of UDP payload
    if (plen < 70 || gPB[UDP_SRC_PORT_L_P] != DNS_PORT || //from DNS source port
            gPB[UDP_DST_PORT_H_P] != DNSCLIENT_SRC_PORT_H || //response to same port as we sent from (MSB)
            gPB[UDP_DST_PORT_L_P] != dnstid_l || //response to same port as we sent from (LSB)
            p[1] != dnstid_l) //message id same as we sent
        return false; //not our DNS response
    if ((p[3] & 0x0F) != 0)
        return true; //DNS response received with error

    p += *p; // we encoded the query len into tid
    for (;;) {
        if (*p & 0xC0)
            p += 2;
        else
            while (++p < gPB + plen) {
                if (*p == 0) {
                    ++p;
                    break;
                }
            }
        if (p + 14 > gPB + plen)
            break;
        if (p[1] == DNS_TYPE_A && p[9] == 4) { // type "A" and IPv4
            ether.copyIp(ether.hisip, p + 10);
            break;
        }
        p += p[9] + 10;
    }
    return false; //No error
}

bool EthernetClass::dnsLookup(const char* name, bool fromRam) {
    uint16_t start = millis();

    while (!isLinkUp()) {
        if (millis() - start >= 30000)
            return false; //timeout waiting for link
    }
    while (clientWaitingDns()) {
        packetLoop(packetReceive());
        if (millis() - start >= 30000)
            return false; //timeout waiting for gateway ARP
    }

    memset(hisip, 0, IP_LEN);
    ether.dnsRequest(name, fromRam);

    start = millis();
    while (hisip[0] == 0) {
        if (millis() - start >= 10000)
            return false; //timout waiting for dns response
        uint16_t len = packetReceive();
        if (len > 0 && packetLoop(len) == 0) //packet not handled by tcp/ip packet loop
            if (ether.checkForDnsAnswer(len))
                return false; //DNS response recieved with error
    }

    return true;
}

void EthernetClass::copyout(uint8_t page, const uint8_t* data) {
    uint16_t destPos = SCRATCH_START + (page << SCRATCH_PAGE_SHIFT);
    if (destPos < SCRATCH_START || destPos > SCRATCH_LIMIT - SCRATCH_PAGE_SIZE)
        return;
    ether.writeReg(EWRPT, destPos);
    ether.writeBuf(SCRATCH_PAGE_SIZE, data);
}

void EthernetClass::copyin(uint8_t page, uint8_t* data) {
    uint16_t destPos = SCRATCH_START + (page << SCRATCH_PAGE_SHIFT);
    if (destPos < SCRATCH_START || destPos > SCRATCH_LIMIT - SCRATCH_PAGE_SIZE)
        return;
    ether.writeReg(ERDPT, destPos);
    ether.readBuf(SCRATCH_PAGE_SIZE, data);
}


uint8_t EthernetClass::tcp_result_cb(uint8_t fd, uint8_t status, uint16_t datapos, uint16_t datalen) {
    if (status == 0) {
        result_fd = fd; // a valid result has been received, remember its session id
        result_ptr = (char*) ether.buffer + datapos;
        // result_ptr[datalen] = 0;
    }
    return 1;
}



uint8_t EthernetClass::tcpSend() {
    www_fd = ether.clientTcpReq(&tcp_result_cb, &tcp_datafill_cb, hisport);
    return www_fd;
}

 
 uint16_t  EthernetClass::tcp_datafill_cb(uint8_t fd) {
    uint16_t len = Stash::length();
    stash.extract(0, len, ether.tcpOffset());
    stash.cleanup();
    ether.tcpOffset()[len] = 0;
#if SERIAL
    Serial.print("REQUEST: ");
    Serial.println(len);
    Serial.println((char*) EtherCard::tcpOffset());
#endif
    result_fd = 123; // bogus value
    return len;
}

 uint8_t EthernetClass::clientTcpReq(uint8_t(*result_cb)(uint8_t, uint8_t, uint16_t, uint16_t),
        uint16_t(*datafill_cb)(uint8_t), uint16_t port) {
    client_tcp_result_cb = result_cb;
    client_tcp_datafill_cb = datafill_cb;
    tcp_client_port_h = port >> 8;
    tcp_client_port_l = port;
    tcp_client_state = TCP_STATE_SENDSYN; // Flag to packetloop to initiate a TCP/IP session by send a syn
    tcp_fd = (tcp_fd + 1) & 7;
    return tcp_fd;
}
 
 
 
const char* EthernetClass::tcpReply (uint8_t fd) {
    if (result_fd != fd)
        return 0;
    result_fd = 123; // set to a bogus value to prevent future match
    return result_ptr;
}


// Srash Class

// save the metadata of current block into the first block

void Stash::save() {
       load(WRITEBUF, first);
      memcpy(bufs[WRITEBUF].bytes, (StashHeader*) this, sizeof (StashHeader));
      if (bufs[READBUF].bnum == first)
          load(READBUF, 0); // invalidates original in case it was the same block
}

// load a page/block either into the write or into the readbuffer

void Stash::load(uint8_t idx, uint8_t blk) {
    if (blk != bufs[idx].bnum) {
        if (idx == WRITEBUF) {
            ether.copyout(bufs[idx].bnum, bufs[idx].bytes);
            if (blk == bufs[READBUF].bnum)
                bufs[READBUF].bnum = 255; // forget read page if same
        } else if (blk == bufs[WRITEBUF].bnum) {
            // special case: read page is same as write buffer
            memcpy(&bufs[READBUF], &bufs[WRITEBUF], sizeof bufs[0]);
            return;
        }
        bufs[idx].bnum = blk;
        ether.copyin(bufs[idx].bnum, bufs[idx].bytes);
    }
}



// create a new stash; make it the active stash; return the first block as a handle 

uint8_t Stash::create() {
    uint8_t blk = allocBlock();
    load(WRITEBUF, blk);
    bufs[WRITEBUF].head.count = 0;
    bufs[WRITEBUF].head.first = bufs[0].head.last = blk;
    bufs[WRITEBUF].tail = sizeof (StashHeader);
    bufs[WRITEBUF].next = 0;
    return open(blk); // you are now the active stash 
}

uint8_t Stash::allocBlock() {
    for (uint8_t i = 0; i < sizeof map; ++i)
        if (map[i] != 0)
            for (uint8_t j = 0; j < 8; ++j)
                if (bitRead(map[i], j)) {
                    bitClear(map[i], j);
                    return (i << 3) +j;
                }
    return 0;
}


// the stashheader part only contains reasonable data if we are the first block

uint8_t Stash::open(uint8_t blk) {
    curr = blk;
    offs = sizeof (StashHeader); // goto first byte
    load(READBUF, curr);
    memcpy((StashHeader*) this, bufs[READBUF].bytes, sizeof (StashHeader));
    return curr;
}

// write information about the fmt string and the arguments into special page/block 0    
// block 0 is initially marked as allocated and never returned by allocateBlock 

void Stash::prepare(char fmt[], uint16_t len) {
    int i = 0;
    Stash::load(WRITEBUF, 0);
    uint16_t* segs = Stash::bufs[WRITEBUF].words;
    *segs++ = len;
    *segs++ = (uint16_t) fmt[i++];
    for (;;) {
        char c = fmt[i++];
        if (c == 0)
            break;
    }
}

// write information about the fmt string and the arguments into special page/block 0    
// block 0 is initially marked as allocated and never returned by allocateBlock 
void Stash::prepare (char fmt, ...) {
    Stash::load(WRITEBUF, 0);
    uint16_t* segs = Stash::bufs[WRITEBUF].words;
    *segs++ = strlen(fmt);
#ifdef __AVR__
    *segs++ = (uint16_t) fmt;
#else
    *segs++ = (uint32_t) fmt;
    *segs++ = (uint32_t) fmt >> 16;
#endif
    va_list ap;
    va_start(ap, fmt);
    for (;;) {
        char c = pgm_read_byte(fmt++);
        if (c == 0)
            break;
        if (c == '$') {
#ifdef __AVR__
            uint16_t argval = va_arg(ap, uint16_t), arglen = 0;
#else
            uint32_t argval = va_arg(ap, int), arglen = 0;
#endif
            switch (pgm_read_byte(fmt++)) {
            case 'D': {
                char buf[7];
                wtoa(argval, buf);
                arglen = strlen(buf);
                break;
            }
            case 'S':
                arglen = strlen((const char*) argval);
                break;
            case 'F':
                arglen = strlen_P((const char*) argval);
                break;
            case 'E': {
                byte* s = (byte*) argval;
                char d;
                while ((d = eeprom_read_byte(s++)) != 0)
                    ++arglen;
                break;
            }
            case 'H': {
                Stash stash (argval);
                arglen = stash.size();
                break;
            }
            }
#ifdef __AVR__
            *segs++ = argval;
#else
            *segs++ = argval;
            *segs++ = argval >> 16;
#endif
            Stash::bufs[WRITEBUF].words[0] += arglen - 2;
        }
    }
    va_end(ap);
}


uint16_t Stash::length() {
    stash.load(WRITEBUF, 0);
    return Stash::bufs[WRITEBUF].words[0];
}

void Stash::extract(uint16_t offset, uint16_t count, void* buf) {

}

void Stash::cleanup() {
    Stash::load(WRITEBUF, 0);
    uint16_t* segs = Stash::bufs[WRITEBUF].words;
}

// fetchbyte(last, 62) is tail, i.e., number of characters in last block 
uint16_t Stash::size () {
    return 63 * count + fetchByte(last, 62) - sizeof (StashHeader);
}