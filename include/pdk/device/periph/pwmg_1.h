/*
  pwmg_1.h: Definitions for the PWMG1 related registers used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_PWMG_1_H__
#define __PDK_DEVICE_PERIPH_PWMG_1_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/pwmg_1.h" by itself."
#endif

// __sfr definitions
__sfr __at(PWMG1C_ADDR)       _pwmg1c;
__sfr __at(PWMG1S_ADDR)       _pwmg1s;
__sfr __at(PWMG1DTH_ADDR)     _pwmg1dth;
__sfr __at(PWMG1DTL_ADDR)     _pwmg1dtl;
__sfr __at(PWMG1CUBH_ADDR)    _pwmg1cubh;
__sfr __at(PWMG1CUBL_ADDR)    _pwmg1cubl;

#define PWMG1C                _pwmg1c
#define PWMG1S                _pwmg1s
#define PWMG1DTH              _pwmg1dth
#define PWMG1DTL              _pwmg1dtl
#define PWMG1CUBH             _pwmg1cubh
#define PWMG1CUBL             _pwmg1cubl

// PWMG1C (PWMG1 Control) register definitions
#define PWMG1C_CLK_SRC_BIT           0
#define PWMG1C_OUT_PIN_SEL_BIT0      1
#define PWMG1C_CTR_RST_BIT           4
#define PWMG1C_INVERT_OUT_BIT        5
#define PWMG1C_STATUS_OUT_BIT        6
#define PWMG1C_ENABLE_BIT            7

#define PWMG1C_CLK_SYSCLK            0x00
#define PWMG1C_CLK_IHRC              (1 << PWMG1C_CLK_SRC_BIT)

#define PWMG1C_OUT_NONE              0x00
#define PWMG1C_OUT_PB6               (1 << PWMG1C_OUT_PIN_SEL_BIT0)
#define PWMG1C_OUT_PA4               (2 << PWMG1C_OUT_PIN_SEL_BIT0)
#define PWMG1C_OUT_PB7               (3 << PWMG1C_OUT_PIN_SEL_BIT0)

#define PWMG1C_RESET_COUNTER         (1 << PWMG1C_CTR_RST_BIT)
#define PWMG1C_INVERT_OUT            (1 << PWMG1C_INVERT_OUT_BIT)
#define PWMG1C_STATUS_OUT            (1 << PWMG1C_STATUS_OUT_BIT)
#define PWMG1C_ENABLE                (1 << PWMG1C_ENABLE_BIT)

// PWMG1S (PWMG1 Scalar) register definitions
#define PWMG1S_SCALE_BIT0            0
#define PWMG1S_PRESCALE_BIT0         5
#define PWMG1S_INT_MODE_BIT          7

#define PWMG1S_SCALE_NONE            0x00
#define PWMG1S_SCALE_DIV2            (1 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV3            (2 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV4            (3 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV5            (4 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV6            (5 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV7            (6 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV8            (7 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV9            (8 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV10           (9 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV11           (10 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV12           (11 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV13           (12 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV14           (13 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV15           (14 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV16           (15 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV17           (16 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV18           (17 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV19           (18 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV20           (19 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV21           (20 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV22           (21 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV23           (22 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV24           (23 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV25           (24 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV26           (25 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV27           (26 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV28           (27 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV29           (28 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV30           (29 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV31           (30 << PWMG1S_SCALE_BIT0)
#define PWMG1S_SCALE_DIV32           (31 << PWMG1S_SCALE_BIT0)

#define PWMG1S_PRESCALE_NONE         0x00
#define PWMG1S_PRESCALE_DIV4         (1 << PWMG1S_PRESCALE_BIT0)
#define PWMG1S_PRESCALE_DIV16        (2 << PWMG1S_PRESCALE_BIT0)
#define PWMG1S_PRESCALE_DIV64        (3 << PWMG1S_PRESCALE_BIT0)

#define PWMG1_INT_AT_DUTY            0x00
#define PWMG1_INT_AT_0               (1 << PWMG1S_INT_MODE_BIT)

#endif //__PDK_DEVICE_PERIPH_PWMG_1_H__
