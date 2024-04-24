#ifndef __DELAY_H__
#define __DELAY_H__

#if !defined(F_CPU)
  #error "F_CPU is not defined!"
#endif

#include <stdint.h>

#if !defined(MAX)
  #define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#define NS_TO_CYCLES(ns)        ((ns)/(1000000000L/F_CPU))
#define US_TO_CYCLES(us)        (NS_TO_CYCLES(us*1000L))
#define MS_TO_CYCLES(ms)        (NS_TO_CYCLES(ms*1000000L))

#define LOOP_CTR(cycles,ovh,lp) (MAX(0,(cycles-ovh-lp)/lp)+1)
#define LOOP_CTR_8(cycles)      LOOP_CTR(cycles,7,3)
#define LOOP_CTR_16(cycles)     LOOP_CTR(cycles,9,8)
#define LOOP_CTR_32(cycles)     LOOP_CTR(cycles,13,12)

#define _delay_us(us)           \
	(LOOP_CTR_8(US_TO_CYCLES(us)) < 256L) ? \
	_delay_loop_8((uint8_t)LOOP_CTR_8(US_TO_CYCLES(us))) : \
	_delay_loop_16((uint16_t)LOOP_CTR_16(US_TO_CYCLES(us)))

#define _delay_ms(ms)           \
	(LOOP_CTR_16(MS_TO_CYCLES(ms)) < 65536L) ? \
	_delay_loop_16((uint16_t)LOOP_CTR_16(MS_TO_CYCLES(ms))) : \
	_delay_loop_32((uint32_t)LOOP_CTR_32(MS_TO_CYCLES(ms)))

// 3 cycles per loop, 7 cycles overhead
void _delay_loop_8(uint8_t loop_ctr) {
  loop_ctr; // Ignore unreferenced function argument warning
__asm
  // mov    a, #(loop_ctr)                ; 1 cycle
  // mov    __delay_loop_8_PARM_1, a      ; 1 cycle
  // call   __delay_loop_8                ; 2 cycles
00001$:                                   ; 4 cycles per loop
  dzsn   __delay_loop_8_PARM_1            ;   1 cycle + 1 cycle for final skip
    goto 00001$                           ;   2 cycles
  // ret                                  ; 2 cycles
__endasm;
}

// 8 cycles per loop, 9 cycles overhead
void _delay_loop_16(uint16_t loop_ctr) {
  loop_ctr; // Ignore unreferenced function argument warning
__asm
  // mov    a, #(loop_ctr)                ; 1 cycle
  // mov    __delay_loop_16_PARM_1+0, a   ; 1 cycle
  // mov    a, #(loop_ctr<<8)             ; 1 cycle
  // mov    __delay_loop_16_PARM_1+1, a   ; 1 cycle
  // call   __delay_loop_16               ; 2 cycles
00001$:                                   ; 8 cycles per loop
  nop                                     ;   1 cycle
  dec   __delay_loop_16_PARM_1+0          ;   1 cycle
  subc  __delay_loop_16_PARM_1+1          ;   1 cycle
  mov   a, __delay_loop_16_PARM_1+0       ;   1 cycle
  or    a, __delay_loop_16_PARM_1+1       ;   1 cycle
  t1sn  f, z                              ;   1 cycle + 1 cycle for final skip
    goto 00001$                           ;   2 cycles
  // ret                                  ; 2 cycles
__endasm;
}

// 12 cycles per loop, 13 cycles overhead
void _delay_loop_32(uint32_t loop_ctr) {
  loop_ctr; // Ignore unreferenced function argument warning
__asm
  // mov    a, #(loop_ctr)                ; 1 cycle
  // mov    __delay_loop_32_PARM_1+0, a   ; 1 cycle
  // mov    a, #(loop_ctr<<8)             ; 1 cycle
  // mov    __delay_loop_32_PARM_1+1, a   ; 1 cycle
  // mov    a, #(loop_ctr<<16)            ; 1 cycle
  // mov    __delay_loop_32_PARM_1+1, a   ; 1 cycle
  // mov    a, #(loop_ctr<<24)            ; 1 cycle
  // mov    __delay_loop_32_PARM_1+1, a   ; 1 cycle
  // call   __delay_loop_32               ; 2 cycles
00001$:                                   ; 12 cycles per loop
  nop                                     ;   1 cycle
  dec   __delay_loop_32_PARM_1+0          ;   1 cycle
  subc  __delay_loop_32_PARM_1+1          ;   1 cycle
  subc  __delay_loop_32_PARM_1+2          ;   1 cycle
  subc  __delay_loop_32_PARM_1+3          ;   1 cycle
  mov   a, __delay_loop_32_PARM_1+0       ;   1 cycle
  or    a, __delay_loop_32_PARM_1+1       ;   1 cycle
  or    a, __delay_loop_32_PARM_1+2       ;   1 cycle
  or    a, __delay_loop_32_PARM_1+3       ;   1 cycle
  t1sn  f, z                              ;   1 cycle + 1 cycle for final skip
    goto 00001$                           ;   2 cycles
  // ret                                  ; 2 cycles
__endasm;
}

#endif //__DELAY_H__
