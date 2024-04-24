/*
  rfc.h: Definitions for the RFC related registers.

  Copyright (C) 2020  freepdk  https://free-pdk.github.io

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

#ifndef __PDK_DEVICE_PERIPH_RFC_H__
#define __PDK_DEVICE_PERIPH_RFC_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/adc.h" by itself."
#endif

// __sfr definitions
__sfr __at(RFCC_ADDR)           _rfcc;
__sfr __at(RFCCRH_ADDR)         _rfccrh;
__sfr __at(RFCCRL_ADDR)         _rfccrl;

#define RFCC                  _rfcc
#define RFCCRH                _rfccrh
#define RFCCRL                _rfccrl

#define RFCC_OUTPUT_ENABLE          (1 << 1)
#define RFCC_OVERFLOW               (1 << 2)
#define RFCC_R_TYPE                 0
#define RFCC_C_TYPE                 (1 << 3)
#define RFCC_START                  (1 << 4)

#define RFCC_CH_RFC0_PA4            ((0 << 5) | 0 )
#define RFCC_CH_RFC1_PA0            ((1 << 5) | 0 )
#define RFCC_CH_RFC2_PA3            ((4 << 5) | 0 )
#define RFCC_CH_RFC3_PB7            ((5 << 5) | 0 )
#define RFCC_CH_RFC4_PB6            ((6 << 5) | 0 )
#define RFCC_CH_DISABLE             ((7 << 5) | 0 )
#define RFCC_CH_RFC5_PB4            ((0 << 5) | 1 )
#define RFCC_CH_RFC6_PB3            ((1 << 5) | 1 )
#define RFCC_CH_RFC7_PB2            ((2 << 5) | 1 )
#define RFCC_CH_RFC8_PB1            ((3 << 5) | 1 )
#define RFCC_CH_RFC9_PB0            ((4 << 5) | 1 )


#endif //__PDK_DEVICE_PERIPH_RFC_H__
