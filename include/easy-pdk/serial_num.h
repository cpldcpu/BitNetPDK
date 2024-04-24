/*
  serial_num.h: Macros to allow Easy PDK Programmer to insert serial numbers without re-compilation.

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

#ifndef __EASY_PDK_SERIAL_NUM_H__
#define __EASY_PDK_SERIAL_NUM_H__

// Placeholder for serial number inserted by easypdkprog
#define EASY_PDK_SERIAL_NUM(sname) static const uint8_t sname[8] = {'F','P','S','E','R','I','A','L'}

#endif //__EASY_PDK_SERIAL_NUM_H__
