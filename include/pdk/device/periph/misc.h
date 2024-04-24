/*
  misc.h: Definitions for the MISC register used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_MISC_H__
#define __PDK_DEVICE_PERIPH_MISC_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/misc.h" by itself."
#endif

// __sfr definitions
__sfr __at(MISC_ADDR)         _misc;

#define MISC                  _misc

// MISC register definitions
#define MISC_WATCHDOG_BIT0           0
#define MISC_LVR_DISABLE_BIT         2
#define MISC_FAST_WAKEUP_ENABLE_BIT  5

#define MISC_WATCHDOG_8K_ILRC        0x00
#define MISC_WATCHDOG_16K_ILRC       (1 << MISC_WATCHDOG_BIT0)
#define MISC_WATCHDOG_64K_ILRC       (2 << MISC_WATCHDOG_BIT0)
#define MISC_WATCHDOG_256K_ILRC      (3 << MISC_WATCHDOG_BIT0)

#define MISC_LVR_ENABLE              0x00
#define MISC_LVR_DISABLE             (1 << MISC_LVR_DISABLE_BIT)

#define MISC_FAST_WAKEUP_DISABLE     0x00
#define MISC_FAST_WAKEUP_ENABLE      (1 << MISC_FAST_WAKEUP_ENABLE_BIT)

#if defined(__PDK_HAS_LCD)
  #define MISC_LCD_ENABLE_BIT          4
  #define MISC_LCD_DISABLE             0x00
  #define MISC_LCD_ENABLE              (1 << MISC_LCD_ENABLE_BIT)
#endif

#endif //__PDK_DEVICE_PERIPH_MISC_H__
