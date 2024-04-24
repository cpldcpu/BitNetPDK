/*
  timer_16.h: Definitions for the Timer 16 related registers used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_TIMER_16_H__
#define __PDK_DEVICE_PERIPH_TIMER_16_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/timer_16.h" by itself."
#endif

// __sfr definitions
__sfr __at(T16M_ADDR)         _t16m;
__sfr16                       _t16c;

#define T16M                  _t16m
#define T16C                  _t16c

// T16M (Timer16 Mode) register definitions
#define T16M_INT_SRC_BIT0            0
#define T16M_CLK_DIV_BIT0            3
#define T16M_CLK_SRC_BIT0            5

// Interrupt source
#define T16M_INTSRC_8BIT             0x00
#define T16M_INTSRC_9BIT             (1 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_10BIT            (2 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_11BIT            (3 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_12BIT            (4 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_13BIT            (5 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_14BIT            (6 << T16M_INT_SRC_BIT0)
#define T16M_INTSRC_15BIT            (7 << T16M_INT_SRC_BIT0)

// Clock divider
#define T16M_CLK_DIV1                0x00
#define T16M_CLK_DIV4                (1 << T16M_CLK_DIV_BIT0)
#define T16M_CLK_DIV16               (2 << T16M_CLK_DIV_BIT0)
#define T16M_CLK_DIV64               (3 << T16M_CLK_DIV_BIT0)

// Clock source
#define T16M_CLK_DISABLE             0x00
#define T16M_CLK_SYSCLK              (1 << T16M_CLK_SRC_BIT0)
//0x02 reserved
#define T16M_CLK_PA4_FALL            (3 << T16M_CLK_SRC_BIT0)
#define T16M_CLK_IHRC                (4 << T16M_CLK_SRC_BIT0)
#if defined(__PDK_HAS_EOSC)
  #define T16M_CLK_EOSC                (5 << T16M_CLK_SRC_BIT0)
#endif
#define T16M_CLK_ILRC                (6 << T16M_CLK_SRC_BIT0)
#define T16M_CLK_PA0_FALL            (7 << T16M_CLK_SRC_BIT0)

#endif //__PDK_DEVICE_PERIPH_TIMER_16_H__
