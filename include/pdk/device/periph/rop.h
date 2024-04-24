/*
  rop.h: Definitions for the ROP register used by Padauk microcontrollers.

  Copyright (C) 2020  serisman  <github@serisman.com>
  Copyright (C) 2019-2020  freepdk  https://free-pdk.github.io

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library. If not, see <http://www.gnu.org/licenses/>.

  As a special exception, if you link this library with other files,
  some of which are compiled with SDCC, to produce an executable,
  this library does not by itself cause the resulting executable to
  be covered by the GNU General Public License. This exception does
  not however invalidate any other reasons why the executable file
  might be covered by the GNU General Public License.
*/

#ifndef __PDK_DEVICE_PERIPH_ROP_H__
#define __PDK_DEVICE_PERIPH_ROP_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/rop.h" by itself."
#endif

// __sfr definitions
__sfr __at(ROP_ADDR)          _rop;

#define ROP                   _rop

// ROP register definitions

#if defined(ROP_PB0_PA4_SEL_BIT)
  #define ROP_INT_SRC_PB0              0x00
  #define ROP_INT_SRC_PA4              (1 << ROP_PB0_PA4_SEL_BIT)
#endif

#if defined(ROP_PA0_PB5_SEL_BIT)
  #define ROP_INT_SRC_PA0              0x00
  #define ROP_INT_SRC_PB5              (1 << ROP_PA0_PB5_SEL_BIT)
#endif

#if defined(ROP_TMX_BIT_SEL_BIT)
  #define ROP_TMX_6BIT                 0x00
  #define ROP_TMX_7BIT                 (1 << ROP_TMX_BIT_SEL_BIT)
#endif

#if defined(ROP_TMX_FREQ_SEL_BIT)
  #define ROP_TMX_16MHZ                0x00
  #define ROP_TMX_32MHZ                (1 << ROP_TMX_FREQ_SEL_BIT)
#endif

#if defined(ROP_PWM_SEL_BIT)
  #define ROP_PURE_PWM                 0x00
  #define ROP_GPC_PWM                  (1 << ROP_PWM_SEL_BIT)
#endif

#if defined(ROP_PWM_FREQ_SEL_BIT)
  #define ROP_PWM_16MHZ                0x00
  #define ROP_PWM_32MHZ                (1 << ROP_PWM_FREQ_SEL_BIT)
#endif

#if defined(ROP_TM2_PB2_PB0_SEL_BIT)
  #define ROP_TM2_PB2                  0x00
  #define ROP_TM2_PB0                  (1 << ROP_TM2_PB2_PB0_SEL_BIT)
#endif

#endif //__PDK_DEVICE_PERIPH_ROP_H__
