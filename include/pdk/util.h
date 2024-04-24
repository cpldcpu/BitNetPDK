/*
  util.h: Macros to allow using defines in assembler strings, and definitions for built-in opcodes.

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

#ifndef __PDK_UTIL_H__
#define __PDK_UTIL_H__

//macros so we can use defines in assembler strings
#define _STRINGIFY(x)         #x
#define _STR(x)               _STRINGIFY(x)
#define _STR_VAR(x)           "_"_STRINGIFY(x)
#define _VAR(x)               _ ## x

//definitions for built in opcodes
#define __nop()               __asm__("nop\n")
#define __engint()            __asm__("engint\n")
#define __disgint()           __asm__("disgint\n")
#define __stopsys()           __asm__("stopsys\n")
#define __stopexe()           __asm__("stopexe\nnop\n")
#define __reset()             __asm__("reset\n")
#define __wdreset()           __asm__("wdreset\n")
#define __set0(var,bit)       __asm__("set0 "_STR_VAR(var)", #"_STR(bit)"\n")
#define __set1(var,bit)       __asm__("set1 "_STR_VAR(var)", #"_STR(bit)"\n")

// BIT definitions
#define BIT0	               (1<<0)
#define BIT1	               (1<<1)
#define BIT2	               (1<<2)
#define BIT3	               (1<<3)
#define BIT4	               (1<<4)
#define BIT5	               (1<<5)
#define BIT6	               (1<<6)
#define BIT7	               (1<<7)

#endif //__PDK_UTIL_H__
