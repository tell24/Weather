
/*****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************/


 ; Local inclusions.
 .nolist
 .include "dspcommon.inc"  ; FIR filter structure
 .list

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

# .section .libdsp, code

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; _FIRDelayInit: initialization to zero of FIR filter delay.
;
; Operation:
; firfilter->delayBase[m] = 0, 0 <= m < firfilter->numCoeffs (= M)
;
; Input:
; w0 = h, ptr FIR filter structure (see included file)
; Return:
; (void)
;
; System resources usage:
; {w0..w2} used, not restored
;
; DO and REPEAT instruction usage.
; no DO instructions
; 1 level REPEAT intruction
;
; Program words (24-bit instructions):
; 7
;
; Cycles (including C-function call and return overheads):
; 11 + M
;............................................................................

 .global _FIRDelayInit ; export
_FIRDelayInit:

;............................................................................

 ; Prepare operation.
 mov [w0+oNumCoeffs],w1  ; w1 = M
 dec w1,w2    ; w2 = M-1
 mov [w0+oDelayBase],w1  ; w1-> delayBase[0]
 mov #0,w0    ; w0 = 0

;............................................................................

 ; Perform operation.
 repeat w2    ; do (M-1)+1 times
 mov w0,[w1++]   ; delayBase[m] = 0
      ; w1-> delayBase[m+1]

;............................................................................

 return 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 .end

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; OEF






