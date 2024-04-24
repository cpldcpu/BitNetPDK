/*
  device.h: Factory to pull in appropriate device/xxx.h (and other common) include files.

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

#ifndef __PDK_DEVICE_H__
#define __PDK_DEVICE_H__

#if defined(PFS154)
  #include "device/pfs154.h"
#elif defined(PFS172)
  #include "device/pfs172.h"
#elif defined(PFS173)
  #include "device/pfs173.h"
#elif defined(PMS131)
  #include "device/pms131.h"
#elif defined(PMS150C)
  #include "device/pms150c.h"
#elif defined(PMS15A)
  #include "device/pms150c.h"
#elif defined(PMS152)
  #include "device/pms152.h"
#elif defined(PMS154B)
  #include "device/pms154b.h"
#elif defined(PMS154C)
  #include "device/pms154c.h"
#elif defined(PMS171B)
  #include "device/pms171b.h"
#else
	#error "Unknown device. Please define device!"
#endif

#include "util.h"
#include "fuse.h"
#include "factory_calibration.h"
#include "sysclock.h"

#endif //__PDK_DEVICE_H__
