/*
  misclvr_basic.h: Definitions for the (basic) MISCLVR register used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_MISCLVR_BASIC_H__
#define __PDK_DEVICE_PERIPH_MISCLVR_BASIC_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/misclvr_basic.h" by itself."
#endif

// __sfr definitions
__sfr __at(MISCLVR_ADDR)      _misclvr;

#define MISCLVR               _misclvr

// MISCLVR register definitions
#define MISCLVR_LVR_BIT0             5

#define MISCLVR_4V                   0x00
#define MISCLVR_3V5                  (1 << MISCLVR_LVR_BIT0)
#define MISCLVR_3V                   (2 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V75                 (3 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V5                  (4 << MISCLVR_LVR_BIT0)
#define MISCLVR_1V8                  (5 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V2                  (6 << MISCLVR_LVR_BIT0)
#define MISCLVR_2V                   (7 << MISCLVR_LVR_BIT0)

#endif //__PDK_DEVICE_PERIPH_MISCLVR_BASIC_H__
