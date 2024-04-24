/*
  misclvr.h: Definitions for the MISCLVR register used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_MISCLVR_H__
#define __PDK_DEVICE_PERIPH_MISCLVR_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/misclvr.h" by itself."
#endif

// __sfr definitions
__sfr __at(MISCLVR_ADDR)      _misclvr;

#define MISCLVR               _misclvr

// MISCLVR register definitions
#define MISCLVR_BANDGAP_DIV_BIT0     0
#define MISCLVR_LVR_BIT0             4

#define MISCLVR_BANDGAP_ON           0x00
#define MISCLVR_BANDGAP_DIV4         (1 << MISCLVR_BANDGAP_DIV_BIT0)
#define MISCLVR_BANDGAP_DIV32        (2 << MISCLVR_BANDGAP_DIV_BIT0)
#define MISCLVR_BANDGAP_AUTO         (3 << MISCLVR_BANDGAP_DIV_BIT0)

#define MISCLVR_1V8                  0x00
#define MISCLVR_1V9                  (1 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V                   (2 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V1                  (3 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V2                  (4 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V3                  (5 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V4                  (6 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V5                  (7 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V7                  (8 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V                   (9 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V15                 (10 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V3                  (11 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V5                  (12 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V75                 (13 << MISCLVR_LVR_BIT0)
#define MISCLVR_4V                   (14 << MISCLVR_LVR_BIT0)
#define MISCLVR_4V5                  (15 << MISCLVR_LVR_BIT0)

#endif //__PDK_DEVICE_PERIPH_MISCLVR_H__
