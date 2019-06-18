/* 
 * File:   EthernetClass.h
 * Author: te
 *
 * Created on 22 December 2018, 15:25
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <xc.h>
#include "Globals.h"

#ifndef ETHERNETCLASS_H
#define	ETHERNETCLASS_H


#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

class Print{
    
};

#define SCRATCH_START       0x1200  // start of scratch area
#define SCRATCH_LIMIT       0x2000  // past end of area, i.e. 3 Kb
#define SCRATCH_PAGE_SHIFT  6       // addressing is in pages of 64 bytes
#define SCRATCH_PAGE_SIZE   (1 << SCRATCH_PAGE_SHIFT)
#define SCRATCH_PAGE_NUM    ((SCRATCH_LIMIT-SCRATCH_START) >> SCRATCH_PAGE_SHIFT)
#define SCRATCH_MAP_SIZE    (((SCRATCH_PAGE_NUM % 8) == 0) ? (SCRATCH_PAGE_NUM / 8) : (SCRATCH_PAGE_NUM/8+1))

#define WRITEBUF  0
#define READBUF   1
#define BUFCOUNT  2

/** This structure describes the structure of memory used within the ENC28J60 network interface. */
typedef struct {
    uint8_t count;     ///< Number of allocated pages
    uint8_t first;     ///< First allocated page
    uint8_t last;      ///< Last allocated page
} StashHeader;

class Stash :  private Print, private StashHeader{
    uint8_t curr;      //!< Current page
    uint8_t offs;      //!< Current offset in page
    
     typedef struct {
        union {
            uint8_t bytes[64];
            uint16_t words[32];
            struct {
                StashHeader head; // StashHeader is only stored in first block 
                uint8_t filler[59];
                uint8_t tail;     // only meaningful if bnum==last; number of bytes in last block 
                uint8_t next;     // pointer to next block 
            };
        };
        uint8_t bnum;
    } Block;
    
    
   //static  uint8_t allocBlock ();
   //static  void freeBlock (uint8_t block);
   //static  uint8_t fetchByte (uint8_t blk, uint8_t off);

    static Block bufs[2];
    static uint8_t map[SCRATCH_MAP_SIZE];
    static void load (uint8_t idx, uint8_t blk);
    static uint8_t allocBlock ();
public:  
    
    void save();
    uint8_t create ();
    uint8_t open (uint8_t blk);
    void prepare (char fmt[], uint16_t len );    
    static uint16_t length ();
    void extract (uint16_t offset, uint16_t count, void* buf);
    void cleanup ();
    uint16_t size ();
    
private:
};

extern Stash stash;

class EthernetClass {  

public:
    EthernetClass();
    EthernetClass(const EthernetClass& orig);
    virtual ~EthernetClass();
    bool persist_tcp_connection = false;
    bool using_dhcp;
    uint16_t(*client_tcp_datafill_cb)(uint8_t);

    uint8_t buffer[DATA_BUFFER_SIZE];

#define gPB ether.buffer


    UdpServerListener listeners[UDPSERVER_MAXLISTENERS];
    uint8_t Enc28j60Bank;
    uint16_t hisport = HTTP_PORT;
    ;
    uint8_t selectPin = 10;
    uint8_t numListeners;
    uint16_t bufferSize = DATA_BUFFER_SIZE;
    uint8_t broadcastip[IP_LEN]; // broadcast address
    uint8_t dnsip[IP_LEN]; ///< DNS server IP address
    uint8_t hisip[IP_LEN]; ///< DNS lookup result
    uint16_t info_data_len; // Length of TCP/IP payload
    uint8_t dhcpState = DHCP_STATE_INIT;

    uint32_t leaseTime;
    uint32_t leaseStart;
    uint32_t stateTimer;
    uint32_t currentXid;
    bool broadcast_enabled; //!< True if broadcasts 

    uint8_t (*client_tcp_result_cb)(uint8_t,uint8_t,uint16_t,uint16_t); // Pointer to callback function to handle response to current TCP/IP request
  
 


// end of added when start of webClient


    uint16_t packetReceive();

    uint16_t packetLoop(uint16_t plen);

    void packetSend(uint16_t len);
    void httpServerReply(uint16_t dlen);
    void httpServerReply_with_flags(uint16_t dlen, uint8_t flags);
    void httpServerReplyAck();
    void printIp(const char* msg, const uint8_t *buf);
    void printIp(const uint8_t *buf);
    uint8_t begin(const uint8_t* macaddr, uint8_t csPin);
    bool staticSetup(const uint8_t* my_ip, const uint8_t* gw_ip, const uint8_t* dns_ip);
    uint8_t* tcpOffset();
    uint8_t GET_OR_POST(uint16_t pos, uint16_t data_len);
    void delay(uint16_t mS);
    void delay_uS(uint16_t uS);
    uint16_t indexof(char *str, char c, uint16_t start);
    bool dnsLookup(const char* name, bool fromRam = false);
    void udpPrepare(uint16_t sport, const uint8_t *dip, uint16_t dport);
    void udpTransmit(uint16_t datalen);
    void dnsRequest(const char *hostname, bool fromRam);
    bool checkForDnsAnswer(uint16_t plen);

    static void copyout (uint8_t page, const uint8_t* data);
     static void copyin (uint8_t page, uint8_t* data);
    uint8_t tcpSend ();
    
    uint8_t clientTcpReq (uint8_t (*result_cb)(uint8_t,uint8_t,uint16_t,uint16_t),
                                 uint16_t (*datafill_cb)(uint8_t),uint16_t port);
    const char* tcpReply (uint8_t fd);
    static uint8_t tcp_result_cb(uint8_t fd, uint8_t status, uint16_t datapos, uint16_t datalen);
    static uint16_t tcp_datafill_cb(uint8_t fd);

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
    void enableBroadcast(bool temporary);
    bool dhcp_received_message_type(uint16_t len, uint8_t msgType);
    void addToBuf(uint8_t b);
    void addBytes(uint8_t len, const uint8_t* data);
    void addOption(uint8_t opt, uint8_t len, const uint8_t* data);
    void process_dhcp_offer(uint16_t len, uint8_t *offeredip);
    void disableBroadcast(bool temporary);
    void process_dhcp_ack(uint16_t len);
    void setSequenceNumber(uint32_t seq);
    uint16_t millis();
    uint32_t getBigEndianLong(uint8_t offs);
    uint32_t getSequenceNumber();
    uint8_t clientWaitingDns();
    
  
};

extern EthernetClass ether;

#endif	/* ETHERNETCLASS_H */

