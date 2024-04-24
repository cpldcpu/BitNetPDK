/*
  accumulator.h: Definitions for the Accumulator related register (FLAG) used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_ACCUMULATOR_H__
#define __PDK_DEVICE_PERIPH_ACCUMULATOR_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/accumulator.h" by itself."
#endif

// __sfr definitions
__sfr __at(FLAG_ADDR)         _flag;

#define FLAG                  _flag

// FLAG (ACC Status Flag) register definitions
#define FLAG_Z_BIT                   0
#define FLAG_C_BIT                   1
#define FLAG_AC_BIT                  2
#define FLAG_OV_BIT                  3

#define FLAG_Z                       (1 << FLAG_Z_BIT)
#define FLAG_C                       (1 << FLAG_C_BIT)
#define FLAG_AC                      (1 << FLAG_AC_BIT)
#define FLAG_OV                      (1 << FLAG_OV_BIT)

#endif //__PDK_DEVICE_PERIPH_ACCUMULATOR_H__
