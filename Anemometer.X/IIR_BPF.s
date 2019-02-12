; *****************************************************************************
; Section: Constants
; *****************************************************************************
; *****************************************************************************

                .equ BPFNumSections, 5

; ..............................................................................
;
; Allocate and initialize filter coefficients
;
; These coefficients have been designed for use in the Transpose filter only

                .section .xdata, xmemory, data  ;THIS line was modified
                                                ;to be compatible with C30 v1.3x

BPFCoefs:
; 40KHz BP Filter
		
.hword	0x06EE	 ;	 b( 0,0)/2
.hword	0x0000	 ;	 b( 0,1)/2
.hword	0x640D	 ;	aA( 0,1)/2
.hword	0xF912	 ;	 b(0,2)/2
.hword	0xCDDE	 ;	a( 0,2)/2
.hword	0x1CAF	 ;	 b( 1,0)/2
.hword	0xC956	 ;	 b( 1,1)/2
.hword	0x6BD9	 ;	 a( 1,1)/2
.hword	0x1CAF	 ;	 b( 1,2)/2
.hword	0xC939	 ;	 a( 1,2)/2
.hword	0x1B52	 ;	 b( 2,0)/2
.hword	0xD9F2	 ;	 b( 2,1)/2
.hword	0x610F	 ;	 a( 2,1)/2
.hword	0x1B52	 ;	 b( 2,2)/2
.hword	0xCBD4	 ;	 a( 2,2)/2
.hword	0x1228	 ;	 b( 3,0)/2
.hword	0xDCB4	 ;	 b( 3,1)/2
.hword	0x72BB	 ;	 a( 3,1)/2
.hword	0x1228	 ;	 b( 3,2)/2
.hword	0xC30F	 ;	 a( 3,2)/2
.hword	0x11C0	 ;	 b( 4,0)/2
.hword	0xED15	 ;	 b( 4,1)/2
.hword	0x64D0	 ;	 a( 4,1)/2
.hword	0x11C0	 ;	 b( 4,2)/2
.hword	0xC46B	 ;	 a( 4,2)/2
    
    
; ..............................................................................
; Allocate states buffers in (uninitialized) Y data space

                .section .yconst
;		.section .ybss, bss, ymemory

BPFStates1:
                .space BPFNumSections*2

BPFStates2:
                .space BPFNumSections*2

; ..............................................................................
; Allocate and intialize filter structure

                .section .data
                .global _BPFFilter

_BPFFilter:
.hword BPFNumSections-1
.hword BPFCoefs
.hword 0xFF00
.hword BPFStates1
.hword BPFStates2
.hword 0x0000






