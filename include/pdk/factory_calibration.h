/*
  factory_calibration.h: Macros to allow using factory calibration values for internal oscillator (IHCR), and bandgap (BG).

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

#ifndef __PDK_FACTORY_CALIBRATION_H__
#define __PDK_FACTORY_CALIBRATION_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/factory_calibration.h" by itself."
#endif

typedef unsigned char (*getfactorycalibration_funcptr)(void);

// Factory Calibration macros
#if defined(FACTORY_IHRCR_ADDR)
  #define GET_FACTORY_IHRCR ((getfactorycalibration_funcptr)FACTORY_IHRCR_ADDR)
  #define PDK_USE_FACTORY_IHRCR_16MHZ() \
    IHRCR = GET_FACTORY_IHRCR()
#endif

#if defined(FACTORY_BGTR_ADDR)
  #define GET_FACTORY_BGTR ((getfactorycalibration_funcptr)FACTORY_BGTR_ADDR)
  #define PDK_USE_FACTORY_BGTR() \
    BGTR = GET_FACTORY_BGTR()
#endif

#endif //__PDK_FACTORY_CALIBRATION_H__
