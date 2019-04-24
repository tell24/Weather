/* 
 * File:   EthernetClass.h
 * Author: te
 *
 * Created on 22 December 2018, 15:25
 */
#include "Globals.h"

#ifndef ETHERNETCLASS_H
#define	ETHERNETCLASS_H


class EthernetClass {
    
public:
    EthernetClass();
    EthernetClass(const EthernetClass& orig);
    virtual ~EthernetClass();
    bool persist_tcp_connection = false;
    bool using_dhcp;
    uint16_t(*client_tcp_datafill_cb)(uint8_t);
    UdpServerListener listeners[UDPSERVER_MAXLISTENERS];
    uint8_t Enc28j60Bank;
    uint16_t hisport = HTTP_PORT;
    ;
    uint8_t selectPin = 10;
    uint8_t numListeners;
    uint16_t bufferSize = DATA_BUFFER_SIZE;
    uint8_t broadcastip[IP_LEN]; // broadcast address
    uint16_t info_data_len; // Length of TCP/IP payload
    uint8_t dhcpState = DHCP_STATE_INIT;

    uint32_t leaseTime;
    uint32_t leaseStart;
    uint32_t stateTimer;
    uint32_t currentXid;
    bool broadcast_enabled; //!< True if broadcasts 



    uint16_t packetReceive();

    uint16_t packetLoop(uint16_t plen);

    void packetSend(uint16_t len);
    void httpServerReply(uint16_t dlen);
    void httpServerReply_with_flags(uint16_t dlen, uint8_t flags);
    void httpServerReplyAck();
    void printIp(const char* msg, const uint8_t *buf);
    void printIp(const uint8_t *buf);
    uint8_t begin(const uint8_t* macaddr, uint8_t csPin);
    bool staticSetup(const uint8_t* my_ip, const uint8_t* gw_ip);
    uint8_t* tcpOffset();
    uint8_t GET_OR_POST(uint16_t pos, uint16_t data_len);
    void delay(uint16_t mS);
    void delay_uS(uint16_t uS);
    uint8_t buffer[DATA_BUFFER_SIZE];
    uint16_t indexof(char *str, char c, uint16_t start);
    
private:
    void xferSPI(uint8_t data);
    void writeRegByte(uint8_t address, uint8_t data);
    void writeReg(uint8_t address, uint16_t data);
    void SetBank(uint8_t address);
    void writeOp(uint8_t op, uint8_t address, uint8_t data);
    void initSPI();
    uint8_t initialize(const uint8_t* macaddr);
    void enableChip();
    void disableChip();
    uint8_t readRegByte(uint8_t address);
    uint8_t readOp(uint8_t op, uint8_t address);
    void writePhy(uint8_t address, uint16_t data);
    void readBuf(uint16_t len, uint8_t* data);
    void writeBuf(uint16_t len, const uint8_t* data);
    uint8_t rxSPI();
    bool isLinkUp();
    uint16_t readPhyByte(uint8_t address);
    void client_arp_whohas(uint8_t *ip_we_search);
    void client_syn(uint8_t srcport, uint8_t dstport_h, uint8_t dstport_l);
    void setMACandIPs(const uint8_t *mac, const uint8_t *dst);
    void setMACs(const uint8_t *mac);
    void copyIp(uint8_t *dst, const uint8_t *src);
    void copyMac(uint8_t *dst, const uint8_t *src);
    bool is_lan(const uint8_t source[IP_LEN], const uint8_t destination[IP_LEN]);
    void fill_ip_hdr_checksum();
    void fill_checksum(uint8_t dest, uint8_t off, uint16_t len, uint8_t type);
    uint8_t eth_type_is_arp_and_my_ip(uint16_t len);
    void make_arp_answer_from_request();
    uint8_t client_store_mac(uint8_t *source_ip, uint8_t *mac);
    void setGwIp(const uint8_t *gwipaddr);
    uint8_t eth_type_is_ip_and_my_ip(uint16_t len);
    void make_echo_reply_from_request(uint16_t len);
    void make_eth_ip();
    bool udpServerListening();
    bool udpServerHasProcessedPacket(uint16_t plen);
    uint16_t accept(const uint16_t port, uint16_t plen);
    void make_tcp_synack_from_syn();
    void make_tcphead(uint16_t rel_ack_num, uint8_t cp_seq);
    void step_seq(uint16_t rel_ack_num, uint8_t cp_seq);
    uint8_t check_ip_message_is_from(const uint8_t *ip);
    uint16_t getTcpPayloadLength();
    void make_tcp_ack_from_any(int16_t datlentoack, uint8_t addflags);
    void make_tcp_ack_with_data_noflags(uint16_t dlen);
    uint8_t readReg(uint8_t address);
    void updateBroadcastAddress();
    void DhcpStateMachine(uint16_t len);
    void send_dhcp_message(uint8_t *requestip);
    void udpPrepare(uint16_t sport, const uint8_t *dip, uint16_t dport);
    void enableBroadcast(bool temporary);
    bool dhcp_received_message_type(uint16_t len, uint8_t msgType);
    void addToBuf(uint8_t b);
    void addBytes(uint8_t len, const uint8_t* data);
    void addOption(uint8_t opt, uint8_t len, const uint8_t* data);
    void udpTransmit(uint16_t datalen);
    void process_dhcp_offer(uint16_t len, uint8_t *offeredip);
    void disableBroadcast(bool temporary);
    void process_dhcp_ack(uint16_t len);
    void setSequenceNumber(uint32_t seq);
    uint32_t millis();
    uint32_t getBigEndianLong(uint8_t offs);
    uint32_t getSequenceNumber();
};

extern EthernetClass ether;

#endif	/* ETHERNETCLASS_H */
