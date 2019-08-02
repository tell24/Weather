#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Include/WF_Config.c "../Microchip/TCPIP Stack/ARCFOUR.c" "../Microchip/TCPIP Stack/ARP.c" "../Microchip/TCPIP Stack/Announce.c" "../Microchip/TCPIP Stack/AutoIP.c" "../Microchip/TCPIP Stack/BerkeleyAPI.c" "../Microchip/TCPIP Stack/BigInt.c" "../Microchip/TCPIP Stack/DHCP.c" "../Microchip/TCPIP Stack/DHCPs.c" "../Microchip/TCPIP Stack/DNS.c" "../Microchip/TCPIP Stack/DNSs.c" "../Microchip/TCPIP Stack/Delay.c" "../Microchip/TCPIP Stack/DynDNS.c" "../Microchip/TCPIP Stack/ENC28J60.c" "../Microchip/TCPIP Stack/ENCX24J600.c" "../Microchip/TCPIP Stack/ETH97J60.c" "../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c" "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83640.c" "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c" "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8700.c" "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8720.c" "../Microchip/TCPIP Stack/ETHPIC32IntMac.c" "../Microchip/TCPIP Stack/FTP.c" "../Microchip/TCPIP Stack/FileSystem.c" "../Microchip/TCPIP Stack/HTTP2.c" "../Microchip/TCPIP Stack/Hashes.c" "../Microchip/TCPIP Stack/Helpers.c" "../Microchip/TCPIP Stack/ICMP.c" "../Microchip/TCPIP Stack/IP.c" "../Microchip/TCPIP Stack/LCDBlocking.c" "../Microchip/TCPIP Stack/MPFS2.c" "../Microchip/TCPIP Stack/NBNS.c" "../Microchip/TCPIP Stack/RSA.c" "../Microchip/TCPIP Stack/Random.c" "../Microchip/TCPIP Stack/Reboot.c" "../Microchip/TCPIP Stack/SMTP.c" "../Microchip/TCPIP Stack/SNMP.c" "../Microchip/TCPIP Stack/SNMPv3.c" "../Microchip/TCPIP Stack/SNMPv3USM.c" "../Microchip/TCPIP Stack/SNTP.c" "../Microchip/TCPIP Stack/SPIEEPROM.c" "../Microchip/TCPIP Stack/SPIFlash.c" "../Microchip/TCPIP Stack/SPIRAM.c" "../Microchip/TCPIP Stack/SSL.c" "../Microchip/TCPIP Stack/StackTsk.c" "../Microchip/TCPIP Stack/TCP.c" "../Microchip/TCPIP Stack/TCPPerformanceTest.c" "../Microchip/TCPIP Stack/TFTPc.c" "../Microchip/TCPIP Stack/Telnet.c" "../Microchip/TCPIP Stack/Tick.c" "../Microchip/TCPIP Stack/UART.c" "../Microchip/TCPIP Stack/UART2TCPBridge.c" "../Microchip/TCPIP Stack/UDP.c" "../Microchip/TCPIP Stack/UDPPerformanceTest.c" "../Microchip/TCPIP Stack/ZeroconfHelper.c" "../Microchip/TCPIP Stack/ZeroconfLinkLocal.c" "../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c" "../Microchip/TCPIP Stack/eth_pic32_ext_phy_rtl8201FL.c" main.c CustomHTTPApp.c MPFSImg2.c GenericTCPServer.c MyUart.c UARTConfig.c I2C.c eeprom.c HTU21D.c BMP180.c ST7735.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Include/WF_Config.o ${OBJECTDIR}/_ext/867694782/ARCFOUR.o ${OBJECTDIR}/_ext/867694782/ARP.o ${OBJECTDIR}/_ext/867694782/Announce.o ${OBJECTDIR}/_ext/867694782/AutoIP.o ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o ${OBJECTDIR}/_ext/867694782/BigInt.o ${OBJECTDIR}/_ext/867694782/DHCP.o ${OBJECTDIR}/_ext/867694782/DHCPs.o ${OBJECTDIR}/_ext/867694782/DNS.o ${OBJECTDIR}/_ext/867694782/DNSs.o ${OBJECTDIR}/_ext/867694782/Delay.o ${OBJECTDIR}/_ext/867694782/DynDNS.o ${OBJECTDIR}/_ext/867694782/ENC28J60.o ${OBJECTDIR}/_ext/867694782/ENCX24J600.o ${OBJECTDIR}/_ext/867694782/ETH97J60.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o ${OBJECTDIR}/_ext/867694782/FTP.o ${OBJECTDIR}/_ext/867694782/FileSystem.o ${OBJECTDIR}/_ext/867694782/HTTP2.o ${OBJECTDIR}/_ext/867694782/Hashes.o ${OBJECTDIR}/_ext/867694782/Helpers.o ${OBJECTDIR}/_ext/867694782/ICMP.o ${OBJECTDIR}/_ext/867694782/IP.o ${OBJECTDIR}/_ext/867694782/LCDBlocking.o ${OBJECTDIR}/_ext/867694782/MPFS2.o ${OBJECTDIR}/_ext/867694782/NBNS.o ${OBJECTDIR}/_ext/867694782/RSA.o ${OBJECTDIR}/_ext/867694782/Random.o ${OBJECTDIR}/_ext/867694782/Reboot.o ${OBJECTDIR}/_ext/867694782/SMTP.o ${OBJECTDIR}/_ext/867694782/SNMP.o ${OBJECTDIR}/_ext/867694782/SNMPv3.o ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o ${OBJECTDIR}/_ext/867694782/SNTP.o ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o ${OBJECTDIR}/_ext/867694782/SPIFlash.o ${OBJECTDIR}/_ext/867694782/SPIRAM.o ${OBJECTDIR}/_ext/867694782/SSL.o ${OBJECTDIR}/_ext/867694782/StackTsk.o ${OBJECTDIR}/_ext/867694782/TCP.o ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o ${OBJECTDIR}/_ext/867694782/TFTPc.o ${OBJECTDIR}/_ext/867694782/Telnet.o ${OBJECTDIR}/_ext/867694782/Tick.o ${OBJECTDIR}/_ext/867694782/UART.o ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o ${OBJECTDIR}/_ext/867694782/UDP.o ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o ${OBJECTDIR}/main.o ${OBJECTDIR}/CustomHTTPApp.o ${OBJECTDIR}/MPFSImg2.o ${OBJECTDIR}/GenericTCPServer.o ${OBJECTDIR}/MyUart.o ${OBJECTDIR}/UARTConfig.o ${OBJECTDIR}/I2C.o ${OBJECTDIR}/eeprom.o ${OBJECTDIR}/HTU21D.o ${OBJECTDIR}/BMP180.o ${OBJECTDIR}/ST7735.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Include/WF_Config.o.d ${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d ${OBJECTDIR}/_ext/867694782/ARP.o.d ${OBJECTDIR}/_ext/867694782/Announce.o.d ${OBJECTDIR}/_ext/867694782/AutoIP.o.d ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d ${OBJECTDIR}/_ext/867694782/BigInt.o.d ${OBJECTDIR}/_ext/867694782/DHCP.o.d ${OBJECTDIR}/_ext/867694782/DHCPs.o.d ${OBJECTDIR}/_ext/867694782/DNS.o.d ${OBJECTDIR}/_ext/867694782/DNSs.o.d ${OBJECTDIR}/_ext/867694782/Delay.o.d ${OBJECTDIR}/_ext/867694782/DynDNS.o.d ${OBJECTDIR}/_ext/867694782/ENC28J60.o.d ${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d ${OBJECTDIR}/_ext/867694782/ETH97J60.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d ${OBJECTDIR}/_ext/867694782/FTP.o.d ${OBJECTDIR}/_ext/867694782/FileSystem.o.d ${OBJECTDIR}/_ext/867694782/HTTP2.o.d ${OBJECTDIR}/_ext/867694782/Hashes.o.d ${OBJECTDIR}/_ext/867694782/Helpers.o.d ${OBJECTDIR}/_ext/867694782/ICMP.o.d ${OBJECTDIR}/_ext/867694782/IP.o.d ${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d ${OBJECTDIR}/_ext/867694782/MPFS2.o.d ${OBJECTDIR}/_ext/867694782/NBNS.o.d ${OBJECTDIR}/_ext/867694782/RSA.o.d ${OBJECTDIR}/_ext/867694782/Random.o.d ${OBJECTDIR}/_ext/867694782/Reboot.o.d ${OBJECTDIR}/_ext/867694782/SMTP.o.d ${OBJECTDIR}/_ext/867694782/SNMP.o.d ${OBJECTDIR}/_ext/867694782/SNMPv3.o.d ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d ${OBJECTDIR}/_ext/867694782/SNTP.o.d ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d ${OBJECTDIR}/_ext/867694782/SPIFlash.o.d ${OBJECTDIR}/_ext/867694782/SPIRAM.o.d ${OBJECTDIR}/_ext/867694782/SSL.o.d ${OBJECTDIR}/_ext/867694782/StackTsk.o.d ${OBJECTDIR}/_ext/867694782/TCP.o.d ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d ${OBJECTDIR}/_ext/867694782/TFTPc.o.d ${OBJECTDIR}/_ext/867694782/Telnet.o.d ${OBJECTDIR}/_ext/867694782/Tick.o.d ${OBJECTDIR}/_ext/867694782/UART.o.d ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d ${OBJECTDIR}/_ext/867694782/UDP.o.d ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/CustomHTTPApp.o.d ${OBJECTDIR}/MPFSImg2.o.d ${OBJECTDIR}/GenericTCPServer.o.d ${OBJECTDIR}/MyUart.o.d ${OBJECTDIR}/UARTConfig.o.d ${OBJECTDIR}/I2C.o.d ${OBJECTDIR}/eeprom.o.d ${OBJECTDIR}/HTU21D.o.d ${OBJECTDIR}/BMP180.o.d ${OBJECTDIR}/ST7735.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Include/WF_Config.o ${OBJECTDIR}/_ext/867694782/ARCFOUR.o ${OBJECTDIR}/_ext/867694782/ARP.o ${OBJECTDIR}/_ext/867694782/Announce.o ${OBJECTDIR}/_ext/867694782/AutoIP.o ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o ${OBJECTDIR}/_ext/867694782/BigInt.o ${OBJECTDIR}/_ext/867694782/DHCP.o ${OBJECTDIR}/_ext/867694782/DHCPs.o ${OBJECTDIR}/_ext/867694782/DNS.o ${OBJECTDIR}/_ext/867694782/DNSs.o ${OBJECTDIR}/_ext/867694782/Delay.o ${OBJECTDIR}/_ext/867694782/DynDNS.o ${OBJECTDIR}/_ext/867694782/ENC28J60.o ${OBJECTDIR}/_ext/867694782/ENCX24J600.o ${OBJECTDIR}/_ext/867694782/ETH97J60.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o ${OBJECTDIR}/_ext/867694782/FTP.o ${OBJECTDIR}/_ext/867694782/FileSystem.o ${OBJECTDIR}/_ext/867694782/HTTP2.o ${OBJECTDIR}/_ext/867694782/Hashes.o ${OBJECTDIR}/_ext/867694782/Helpers.o ${OBJECTDIR}/_ext/867694782/ICMP.o ${OBJECTDIR}/_ext/867694782/IP.o ${OBJECTDIR}/_ext/867694782/LCDBlocking.o ${OBJECTDIR}/_ext/867694782/MPFS2.o ${OBJECTDIR}/_ext/867694782/NBNS.o ${OBJECTDIR}/_ext/867694782/RSA.o ${OBJECTDIR}/_ext/867694782/Random.o ${OBJECTDIR}/_ext/867694782/Reboot.o ${OBJECTDIR}/_ext/867694782/SMTP.o ${OBJECTDIR}/_ext/867694782/SNMP.o ${OBJECTDIR}/_ext/867694782/SNMPv3.o ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o ${OBJECTDIR}/_ext/867694782/SNTP.o ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o ${OBJECTDIR}/_ext/867694782/SPIFlash.o ${OBJECTDIR}/_ext/867694782/SPIRAM.o ${OBJECTDIR}/_ext/867694782/SSL.o ${OBJECTDIR}/_ext/867694782/StackTsk.o ${OBJECTDIR}/_ext/867694782/TCP.o ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o ${OBJECTDIR}/_ext/867694782/TFTPc.o ${OBJECTDIR}/_ext/867694782/Telnet.o ${OBJECTDIR}/_ext/867694782/Tick.o ${OBJECTDIR}/_ext/867694782/UART.o ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o ${OBJECTDIR}/_ext/867694782/UDP.o ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o ${OBJECTDIR}/main.o ${OBJECTDIR}/CustomHTTPApp.o ${OBJECTDIR}/MPFSImg2.o ${OBJECTDIR}/GenericTCPServer.o ${OBJECTDIR}/MyUart.o ${OBJECTDIR}/UARTConfig.o ${OBJECTDIR}/I2C.o ${OBJECTDIR}/eeprom.o ${OBJECTDIR}/HTU21D.o ${OBJECTDIR}/BMP180.o ${OBJECTDIR}/ST7735.o

# Source Files
SOURCEFILES=Include/WF_Config.c ../Microchip/TCPIP Stack/ARCFOUR.c ../Microchip/TCPIP Stack/ARP.c ../Microchip/TCPIP Stack/Announce.c ../Microchip/TCPIP Stack/AutoIP.c ../Microchip/TCPIP Stack/BerkeleyAPI.c ../Microchip/TCPIP Stack/BigInt.c ../Microchip/TCPIP Stack/DHCP.c ../Microchip/TCPIP Stack/DHCPs.c ../Microchip/TCPIP Stack/DNS.c ../Microchip/TCPIP Stack/DNSs.c ../Microchip/TCPIP Stack/Delay.c ../Microchip/TCPIP Stack/DynDNS.c ../Microchip/TCPIP Stack/ENC28J60.c ../Microchip/TCPIP Stack/ENCX24J600.c ../Microchip/TCPIP Stack/ETH97J60.c ../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c ../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83640.c ../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c ../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8700.c ../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8720.c ../Microchip/TCPIP Stack/ETHPIC32IntMac.c ../Microchip/TCPIP Stack/FTP.c ../Microchip/TCPIP Stack/FileSystem.c ../Microchip/TCPIP Stack/HTTP2.c ../Microchip/TCPIP Stack/Hashes.c ../Microchip/TCPIP Stack/Helpers.c ../Microchip/TCPIP Stack/ICMP.c ../Microchip/TCPIP Stack/IP.c ../Microchip/TCPIP Stack/LCDBlocking.c ../Microchip/TCPIP Stack/MPFS2.c ../Microchip/TCPIP Stack/NBNS.c ../Microchip/TCPIP Stack/RSA.c ../Microchip/TCPIP Stack/Random.c ../Microchip/TCPIP Stack/Reboot.c ../Microchip/TCPIP Stack/SMTP.c ../Microchip/TCPIP Stack/SNMP.c ../Microchip/TCPIP Stack/SNMPv3.c ../Microchip/TCPIP Stack/SNMPv3USM.c ../Microchip/TCPIP Stack/SNTP.c ../Microchip/TCPIP Stack/SPIEEPROM.c ../Microchip/TCPIP Stack/SPIFlash.c ../Microchip/TCPIP Stack/SPIRAM.c ../Microchip/TCPIP Stack/SSL.c ../Microchip/TCPIP Stack/StackTsk.c ../Microchip/TCPIP Stack/TCP.c ../Microchip/TCPIP Stack/TCPPerformanceTest.c ../Microchip/TCPIP Stack/TFTPc.c ../Microchip/TCPIP Stack/Telnet.c ../Microchip/TCPIP Stack/Tick.c ../Microchip/TCPIP Stack/UART.c ../Microchip/TCPIP Stack/UART2TCPBridge.c ../Microchip/TCPIP Stack/UDP.c ../Microchip/TCPIP Stack/UDPPerformanceTest.c ../Microchip/TCPIP Stack/ZeroconfHelper.c ../Microchip/TCPIP Stack/ZeroconfLinkLocal.c ../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c ../Microchip/TCPIP Stack/eth_pic32_ext_phy_rtl8201FL.c main.c CustomHTTPApp.c MPFSImg2.c GenericTCPServer.c MyUart.c UARTConfig.c I2C.c eeprom.c HTU21D.c BMP180.c ST7735.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX440F256H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Include/WF_Config.o: Include/WF_Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Include" 
	@${RM} ${OBJECTDIR}/Include/WF_Config.o.d 
	@${RM} ${OBJECTDIR}/Include/WF_Config.o 
	@${FIXDEPS} "${OBJECTDIR}/Include/WF_Config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/Include/WF_Config.o.d" -o ${OBJECTDIR}/Include/WF_Config.o Include/WF_Config.c  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ARCFOUR.o: ../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARCFOUR.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/867694782/ARCFOUR.o "../Microchip/TCPIP Stack/ARCFOUR.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ARP.o: ../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ARP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ARP.o.d" -o ${OBJECTDIR}/_ext/867694782/ARP.o "../Microchip/TCPIP Stack/ARP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Announce.o: ../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Announce.o.d" -o ${OBJECTDIR}/_ext/867694782/Announce.o "../Microchip/TCPIP Stack/Announce.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/AutoIP.o: ../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/AutoIP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/AutoIP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/AutoIP.o.d" -o ${OBJECTDIR}/_ext/867694782/AutoIP.o "../Microchip/TCPIP Stack/AutoIP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o: ../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o "../Microchip/TCPIP Stack/BerkeleyAPI.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/BigInt.o: ../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/BigInt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/BigInt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/BigInt.o.d" -o ${OBJECTDIR}/_ext/867694782/BigInt.o "../Microchip/TCPIP Stack/BigInt.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DHCP.o: ../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DHCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DHCP.o.d" -o ${OBJECTDIR}/_ext/867694782/DHCP.o "../Microchip/TCPIP Stack/DHCP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DHCPs.o: ../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCPs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DHCPs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DHCPs.o.d" -o ${OBJECTDIR}/_ext/867694782/DHCPs.o "../Microchip/TCPIP Stack/DHCPs.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DNS.o: ../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DNS.o.d" -o ${OBJECTDIR}/_ext/867694782/DNS.o "../Microchip/TCPIP Stack/DNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DNSs.o: ../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNSs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DNSs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DNSs.o.d" -o ${OBJECTDIR}/_ext/867694782/DNSs.o "../Microchip/TCPIP Stack/DNSs.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Delay.o: ../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Delay.o.d" -o ${OBJECTDIR}/_ext/867694782/Delay.o "../Microchip/TCPIP Stack/Delay.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DynDNS.o: ../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DynDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DynDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DynDNS.o.d" -o ${OBJECTDIR}/_ext/867694782/DynDNS.o "../Microchip/TCPIP Stack/DynDNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ENC28J60.o: ../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENC28J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ENC28J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/867694782/ENC28J60.o "../Microchip/TCPIP Stack/ENC28J60.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ENCX24J600.o: ../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENCX24J600.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/867694782/ENCX24J600.o "../Microchip/TCPIP Stack/ENCX24J600.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETH97J60.o: ../Microchip/TCPIP\ Stack/ETH97J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETH97J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETH97J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETH97J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETH97J60.o.d" -o ${OBJECTDIR}/_ext/867694782/ETH97J60.o "../Microchip/TCPIP Stack/ETH97J60.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83640.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83640.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83848.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhySMSC8700.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8700.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhySMSC8720.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8720.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o: ../Microchip/TCPIP\ Stack/ETHPIC32IntMac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o "../Microchip/TCPIP Stack/ETHPIC32IntMac.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/FTP.o: ../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/FTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/FTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/FTP.o.d" -o ${OBJECTDIR}/_ext/867694782/FTP.o "../Microchip/TCPIP Stack/FTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/FileSystem.o: ../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/FileSystem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/FileSystem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/FileSystem.o.d" -o ${OBJECTDIR}/_ext/867694782/FileSystem.o "../Microchip/TCPIP Stack/FileSystem.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/HTTP2.o: ../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/HTTP2.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/HTTP2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/HTTP2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/HTTP2.o.d" -o ${OBJECTDIR}/_ext/867694782/HTTP2.o "../Microchip/TCPIP Stack/HTTP2.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Hashes.o: ../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Hashes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Hashes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Hashes.o.d" -o ${OBJECTDIR}/_ext/867694782/Hashes.o "../Microchip/TCPIP Stack/Hashes.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Helpers.o: ../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Helpers.o.d" -o ${OBJECTDIR}/_ext/867694782/Helpers.o "../Microchip/TCPIP Stack/Helpers.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ICMP.o: ../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ICMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ICMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ICMP.o.d" -o ${OBJECTDIR}/_ext/867694782/ICMP.o "../Microchip/TCPIP Stack/ICMP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/IP.o: ../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/IP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/IP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/IP.o.d" -o ${OBJECTDIR}/_ext/867694782/IP.o "../Microchip/TCPIP Stack/IP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/LCDBlocking.o: ../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/867694782/LCDBlocking.o "../Microchip/TCPIP Stack/LCDBlocking.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/MPFS2.o: ../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/MPFS2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/MPFS2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/MPFS2.o.d" -o ${OBJECTDIR}/_ext/867694782/MPFS2.o "../Microchip/TCPIP Stack/MPFS2.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/NBNS.o: ../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/NBNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/NBNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/NBNS.o.d" -o ${OBJECTDIR}/_ext/867694782/NBNS.o "../Microchip/TCPIP Stack/NBNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/RSA.o: ../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/RSA.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/RSA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/RSA.o.d" -o ${OBJECTDIR}/_ext/867694782/RSA.o "../Microchip/TCPIP Stack/RSA.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Random.o: ../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Random.o.d" -o ${OBJECTDIR}/_ext/867694782/Random.o "../Microchip/TCPIP Stack/Random.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Reboot.o: ../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Reboot.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Reboot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Reboot.o.d" -o ${OBJECTDIR}/_ext/867694782/Reboot.o "../Microchip/TCPIP Stack/Reboot.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SMTP.o: ../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SMTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SMTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SMTP.o.d" -o ${OBJECTDIR}/_ext/867694782/SMTP.o "../Microchip/TCPIP Stack/SMTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMP.o: ../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMP.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMP.o "../Microchip/TCPIP Stack/SNMP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMPv3.o: ../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMPv3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMPv3.o "../Microchip/TCPIP Stack/SNMPv3.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMPv3USM.o: ../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o "../Microchip/TCPIP Stack/SNMPv3USM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNTP.o: ../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNTP.o.d" -o ${OBJECTDIR}/_ext/867694782/SNTP.o "../Microchip/TCPIP Stack/SNTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIEEPROM.o: ../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o "../Microchip/TCPIP Stack/SPIEEPROM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIFlash.o: ../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIFlash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIFlash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIFlash.o "../Microchip/TCPIP Stack/SPIFlash.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIRAM.o: ../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIRAM.o "../Microchip/TCPIP Stack/SPIRAM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SSL.o: ../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SSL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SSL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SSL.o.d" -o ${OBJECTDIR}/_ext/867694782/SSL.o "../Microchip/TCPIP Stack/SSL.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/StackTsk.o: ../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/StackTsk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/StackTsk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/StackTsk.o.d" -o ${OBJECTDIR}/_ext/867694782/StackTsk.o "../Microchip/TCPIP Stack/StackTsk.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TCP.o: ../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TCP.o.d" -o ${OBJECTDIR}/_ext/867694782/TCP.o "../Microchip/TCPIP Stack/TCP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o: ../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o "../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TFTPc.o: ../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TFTPc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TFTPc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TFTPc.o.d" -o ${OBJECTDIR}/_ext/867694782/TFTPc.o "../Microchip/TCPIP Stack/TFTPc.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Telnet.o: ../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Telnet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Telnet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Telnet.o.d" -o ${OBJECTDIR}/_ext/867694782/Telnet.o "../Microchip/TCPIP Stack/Telnet.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Tick.o: ../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Tick.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Tick.o.d" -o ${OBJECTDIR}/_ext/867694782/Tick.o "../Microchip/TCPIP Stack/Tick.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UART.o: ../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UART.o.d" -o ${OBJECTDIR}/_ext/867694782/UART.o "../Microchip/TCPIP Stack/UART.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o: ../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o "../Microchip/TCPIP Stack/UART2TCPBridge.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UDP.o: ../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UDP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UDP.o.d" -o ${OBJECTDIR}/_ext/867694782/UDP.o "../Microchip/TCPIP Stack/UDP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o: ../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o "../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o: ../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o "../Microchip/TCPIP Stack/ZeroconfHelper.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o: ../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o "../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o: ../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o "../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o: ../Microchip/TCPIP\ Stack/eth_pic32_ext_phy_rtl8201FL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d" -o ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o "../Microchip/TCPIP Stack/eth_pic32_ext_phy_rtl8201FL.c"  -legacy-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  -legacy-libc
	
${OBJECTDIR}/CustomHTTPApp.o: CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/CustomHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/CustomHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/CustomHTTPApp.o.d" -o ${OBJECTDIR}/CustomHTTPApp.o CustomHTTPApp.c  -legacy-libc
	
${OBJECTDIR}/MPFSImg2.o: MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPFSImg2.o.d 
	@${RM} ${OBJECTDIR}/MPFSImg2.o 
	@${FIXDEPS} "${OBJECTDIR}/MPFSImg2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/MPFSImg2.o.d" -o ${OBJECTDIR}/MPFSImg2.o MPFSImg2.c  -legacy-libc
	
${OBJECTDIR}/GenericTCPServer.o: GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/GenericTCPServer.o 
	@${FIXDEPS} "${OBJECTDIR}/GenericTCPServer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/GenericTCPServer.o.d" -o ${OBJECTDIR}/GenericTCPServer.o GenericTCPServer.c  -legacy-libc
	
${OBJECTDIR}/MyUart.o: MyUart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MyUart.o.d 
	@${RM} ${OBJECTDIR}/MyUart.o 
	@${FIXDEPS} "${OBJECTDIR}/MyUart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/MyUart.o.d" -o ${OBJECTDIR}/MyUart.o MyUart.c  -legacy-libc
	
${OBJECTDIR}/UARTConfig.o: UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/UARTConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/UARTConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/UARTConfig.o.d" -o ${OBJECTDIR}/UARTConfig.o UARTConfig.c  -legacy-libc
	
${OBJECTDIR}/I2C.o: I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C.o.d 
	@${RM} ${OBJECTDIR}/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/I2C.o.d" -o ${OBJECTDIR}/I2C.o I2C.c  -legacy-libc
	
${OBJECTDIR}/eeprom.o: eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/eeprom.o.d 
	@${RM} ${OBJECTDIR}/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/eeprom.o.d" -o ${OBJECTDIR}/eeprom.o eeprom.c  -legacy-libc
	
${OBJECTDIR}/HTU21D.o: HTU21D.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HTU21D.o.d 
	@${RM} ${OBJECTDIR}/HTU21D.o 
	@${FIXDEPS} "${OBJECTDIR}/HTU21D.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/HTU21D.o.d" -o ${OBJECTDIR}/HTU21D.o HTU21D.c  -legacy-libc
	
${OBJECTDIR}/BMP180.o: BMP180.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BMP180.o.d 
	@${RM} ${OBJECTDIR}/BMP180.o 
	@${FIXDEPS} "${OBJECTDIR}/BMP180.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/BMP180.o.d" -o ${OBJECTDIR}/BMP180.o BMP180.c  -legacy-libc
	
${OBJECTDIR}/ST7735.o: ST7735.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ST7735.o.d 
	@${RM} ${OBJECTDIR}/ST7735.o 
	@${FIXDEPS} "${OBJECTDIR}/ST7735.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/ST7735.o.d" -o ${OBJECTDIR}/ST7735.o ST7735.c  -legacy-libc
	
else
${OBJECTDIR}/Include/WF_Config.o: Include/WF_Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Include" 
	@${RM} ${OBJECTDIR}/Include/WF_Config.o.d 
	@${RM} ${OBJECTDIR}/Include/WF_Config.o 
	@${FIXDEPS} "${OBJECTDIR}/Include/WF_Config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/Include/WF_Config.o.d" -o ${OBJECTDIR}/Include/WF_Config.o Include/WF_Config.c  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ARCFOUR.o: ../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARCFOUR.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/867694782/ARCFOUR.o "../Microchip/TCPIP Stack/ARCFOUR.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ARP.o: ../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ARP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ARP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ARP.o.d" -o ${OBJECTDIR}/_ext/867694782/ARP.o "../Microchip/TCPIP Stack/ARP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Announce.o: ../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Announce.o.d" -o ${OBJECTDIR}/_ext/867694782/Announce.o "../Microchip/TCPIP Stack/Announce.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/AutoIP.o: ../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/AutoIP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/AutoIP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/AutoIP.o.d" -o ${OBJECTDIR}/_ext/867694782/AutoIP.o "../Microchip/TCPIP Stack/AutoIP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o: ../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/867694782/BerkeleyAPI.o "../Microchip/TCPIP Stack/BerkeleyAPI.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/BigInt.o: ../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/BigInt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/BigInt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/BigInt.o.d" -o ${OBJECTDIR}/_ext/867694782/BigInt.o "../Microchip/TCPIP Stack/BigInt.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DHCP.o: ../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DHCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DHCP.o.d" -o ${OBJECTDIR}/_ext/867694782/DHCP.o "../Microchip/TCPIP Stack/DHCP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DHCPs.o: ../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DHCPs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DHCPs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DHCPs.o.d" -o ${OBJECTDIR}/_ext/867694782/DHCPs.o "../Microchip/TCPIP Stack/DHCPs.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DNS.o: ../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DNS.o.d" -o ${OBJECTDIR}/_ext/867694782/DNS.o "../Microchip/TCPIP Stack/DNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DNSs.o: ../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DNSs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DNSs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DNSs.o.d" -o ${OBJECTDIR}/_ext/867694782/DNSs.o "../Microchip/TCPIP Stack/DNSs.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Delay.o: ../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Delay.o.d" -o ${OBJECTDIR}/_ext/867694782/Delay.o "../Microchip/TCPIP Stack/Delay.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/DynDNS.o: ../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/DynDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/DynDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/DynDNS.o.d" -o ${OBJECTDIR}/_ext/867694782/DynDNS.o "../Microchip/TCPIP Stack/DynDNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ENC28J60.o: ../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENC28J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ENC28J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/867694782/ENC28J60.o "../Microchip/TCPIP Stack/ENC28J60.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ENCX24J600.o: ../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ENCX24J600.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/867694782/ENCX24J600.o "../Microchip/TCPIP Stack/ENCX24J600.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETH97J60.o: ../Microchip/TCPIP\ Stack/ETH97J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETH97J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETH97J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETH97J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETH97J60.o.d" -o ${OBJECTDIR}/_ext/867694782/ETH97J60.o "../Microchip/TCPIP Stack/ETH97J60.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhy.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83640.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83640.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83640.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83848.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhyDP83848.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhySMSC8700.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8700.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8700.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o: ../Microchip/TCPIP\ Stack/ETHPIC32ExtPhySMSC8720.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32ExtPhySMSC8720.o "../Microchip/TCPIP Stack/ETHPIC32ExtPhySMSC8720.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o: ../Microchip/TCPIP\ Stack/ETHPIC32IntMac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o.d" -o ${OBJECTDIR}/_ext/867694782/ETHPIC32IntMac.o "../Microchip/TCPIP Stack/ETHPIC32IntMac.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/FTP.o: ../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/FTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/FTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/FTP.o.d" -o ${OBJECTDIR}/_ext/867694782/FTP.o "../Microchip/TCPIP Stack/FTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/FileSystem.o: ../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/FileSystem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/FileSystem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/FileSystem.o.d" -o ${OBJECTDIR}/_ext/867694782/FileSystem.o "../Microchip/TCPIP Stack/FileSystem.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/HTTP2.o: ../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/HTTP2.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/HTTP2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/HTTP2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/HTTP2.o.d" -o ${OBJECTDIR}/_ext/867694782/HTTP2.o "../Microchip/TCPIP Stack/HTTP2.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Hashes.o: ../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Hashes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Hashes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Hashes.o.d" -o ${OBJECTDIR}/_ext/867694782/Hashes.o "../Microchip/TCPIP Stack/Hashes.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Helpers.o: ../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Helpers.o.d" -o ${OBJECTDIR}/_ext/867694782/Helpers.o "../Microchip/TCPIP Stack/Helpers.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ICMP.o: ../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ICMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ICMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ICMP.o.d" -o ${OBJECTDIR}/_ext/867694782/ICMP.o "../Microchip/TCPIP Stack/ICMP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/IP.o: ../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/IP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/IP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/IP.o.d" -o ${OBJECTDIR}/_ext/867694782/IP.o "../Microchip/TCPIP Stack/IP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/LCDBlocking.o: ../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/867694782/LCDBlocking.o "../Microchip/TCPIP Stack/LCDBlocking.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/MPFS2.o: ../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/MPFS2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/MPFS2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/MPFS2.o.d" -o ${OBJECTDIR}/_ext/867694782/MPFS2.o "../Microchip/TCPIP Stack/MPFS2.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/NBNS.o: ../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/NBNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/NBNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/NBNS.o.d" -o ${OBJECTDIR}/_ext/867694782/NBNS.o "../Microchip/TCPIP Stack/NBNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/RSA.o: ../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/RSA.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/RSA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/RSA.o.d" -o ${OBJECTDIR}/_ext/867694782/RSA.o "../Microchip/TCPIP Stack/RSA.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Random.o: ../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Random.o.d" -o ${OBJECTDIR}/_ext/867694782/Random.o "../Microchip/TCPIP Stack/Random.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Reboot.o: ../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Reboot.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Reboot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Reboot.o.d" -o ${OBJECTDIR}/_ext/867694782/Reboot.o "../Microchip/TCPIP Stack/Reboot.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SMTP.o: ../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SMTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SMTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SMTP.o.d" -o ${OBJECTDIR}/_ext/867694782/SMTP.o "../Microchip/TCPIP Stack/SMTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMP.o: ../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMP.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMP.o "../Microchip/TCPIP Stack/SNMP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMPv3.o: ../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMPv3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMPv3.o "../Microchip/TCPIP Stack/SNMPv3.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNMPv3USM.o: ../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/867694782/SNMPv3USM.o "../Microchip/TCPIP Stack/SNMPv3USM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SNTP.o: ../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SNTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SNTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SNTP.o.d" -o ${OBJECTDIR}/_ext/867694782/SNTP.o "../Microchip/TCPIP Stack/SNTP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIEEPROM.o: ../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIEEPROM.o "../Microchip/TCPIP Stack/SPIEEPROM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIFlash.o: ../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIFlash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIFlash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIFlash.o "../Microchip/TCPIP Stack/SPIFlash.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SPIRAM.o: ../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SPIRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SPIRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/867694782/SPIRAM.o "../Microchip/TCPIP Stack/SPIRAM.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/SSL.o: ../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/SSL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/SSL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/SSL.o.d" -o ${OBJECTDIR}/_ext/867694782/SSL.o "../Microchip/TCPIP Stack/SSL.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/StackTsk.o: ../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/StackTsk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/StackTsk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/StackTsk.o.d" -o ${OBJECTDIR}/_ext/867694782/StackTsk.o "../Microchip/TCPIP Stack/StackTsk.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TCP.o: ../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TCP.o.d" -o ${OBJECTDIR}/_ext/867694782/TCP.o "../Microchip/TCPIP Stack/TCP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o: ../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/867694782/TCPPerformanceTest.o "../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/TFTPc.o: ../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/TFTPc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/TFTPc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/TFTPc.o.d" -o ${OBJECTDIR}/_ext/867694782/TFTPc.o "../Microchip/TCPIP Stack/TFTPc.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Telnet.o: ../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Telnet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Telnet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Telnet.o.d" -o ${OBJECTDIR}/_ext/867694782/Telnet.o "../Microchip/TCPIP Stack/Telnet.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/Tick.o: ../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/Tick.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/Tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/Tick.o.d" -o ${OBJECTDIR}/_ext/867694782/Tick.o "../Microchip/TCPIP Stack/Tick.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UART.o: ../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UART.o.d" -o ${OBJECTDIR}/_ext/867694782/UART.o "../Microchip/TCPIP Stack/UART.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o: ../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/867694782/UART2TCPBridge.o "../Microchip/TCPIP Stack/UART2TCPBridge.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UDP.o: ../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UDP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UDP.o.d" -o ${OBJECTDIR}/_ext/867694782/UDP.o "../Microchip/TCPIP Stack/UDP.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o: ../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/867694782/UDPPerformanceTest.o "../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o: ../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfHelper.o "../Microchip/TCPIP Stack/ZeroconfHelper.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o: ../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfLinkLocal.o "../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o: ../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/867694782/ZeroconfMulticastDNS.o "../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  -legacy-libc
	
${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o: ../Microchip/TCPIP\ Stack/eth_pic32_ext_phy_rtl8201FL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/867694782" 
	@${RM} ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d 
	@${RM} ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o.d" -o ${OBJECTDIR}/_ext/867694782/eth_pic32_ext_phy_rtl8201FL.o "../Microchip/TCPIP Stack/eth_pic32_ext_phy_rtl8201FL.c"  -legacy-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  -legacy-libc
	
${OBJECTDIR}/CustomHTTPApp.o: CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/CustomHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/CustomHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/CustomHTTPApp.o.d" -o ${OBJECTDIR}/CustomHTTPApp.o CustomHTTPApp.c  -legacy-libc
	
${OBJECTDIR}/MPFSImg2.o: MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPFSImg2.o.d 
	@${RM} ${OBJECTDIR}/MPFSImg2.o 
	@${FIXDEPS} "${OBJECTDIR}/MPFSImg2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/MPFSImg2.o.d" -o ${OBJECTDIR}/MPFSImg2.o MPFSImg2.c  -legacy-libc
	
${OBJECTDIR}/GenericTCPServer.o: GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/GenericTCPServer.o 
	@${FIXDEPS} "${OBJECTDIR}/GenericTCPServer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/GenericTCPServer.o.d" -o ${OBJECTDIR}/GenericTCPServer.o GenericTCPServer.c  -legacy-libc
	
${OBJECTDIR}/MyUart.o: MyUart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MyUart.o.d 
	@${RM} ${OBJECTDIR}/MyUart.o 
	@${FIXDEPS} "${OBJECTDIR}/MyUart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/MyUart.o.d" -o ${OBJECTDIR}/MyUart.o MyUart.c  -legacy-libc
	
${OBJECTDIR}/UARTConfig.o: UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/UARTConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/UARTConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/UARTConfig.o.d" -o ${OBJECTDIR}/UARTConfig.o UARTConfig.c  -legacy-libc
	
${OBJECTDIR}/I2C.o: I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C.o.d 
	@${RM} ${OBJECTDIR}/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/I2C.o.d" -o ${OBJECTDIR}/I2C.o I2C.c  -legacy-libc
	
${OBJECTDIR}/eeprom.o: eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/eeprom.o.d 
	@${RM} ${OBJECTDIR}/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/eeprom.o.d" -o ${OBJECTDIR}/eeprom.o eeprom.c  -legacy-libc
	
${OBJECTDIR}/HTU21D.o: HTU21D.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HTU21D.o.d 
	@${RM} ${OBJECTDIR}/HTU21D.o 
	@${FIXDEPS} "${OBJECTDIR}/HTU21D.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/HTU21D.o.d" -o ${OBJECTDIR}/HTU21D.o HTU21D.c  -legacy-libc
	
${OBJECTDIR}/BMP180.o: BMP180.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BMP180.o.d 
	@${RM} ${OBJECTDIR}/BMP180.o 
	@${FIXDEPS} "${OBJECTDIR}/BMP180.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/BMP180.o.d" -o ${OBJECTDIR}/BMP180.o BMP180.c  -legacy-libc
	
${OBJECTDIR}/ST7735.o: ST7735.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ST7735.o.d 
	@${RM} ${OBJECTDIR}/ST7735.o 
	@${FIXDEPS} "${OBJECTDIR}/ST7735.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"Microchip/Include" -I"../Microchip/Include" -I"../../Microchip/Include" -I"../Microchip/Include/TCPIP Stack" -I"../../Microchip/Include/TCPIP Stack" -I"../../../Local_Server.X/Include" -I"Include" -MMD -MF "${OBJECTDIR}/ST7735.o.d" -o ${OBJECTDIR}/ST7735.o ST7735.c  -legacy-libc
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -legacy-libc -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map" 
else
dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -legacy-libc -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Local_Server.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
