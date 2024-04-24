/*
  fuse.h: Macros to allow setting the FUSE word at the appropriate location in the output file.

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

#ifndef __PDK_FUSE_H__
#define __PDK_FUSE_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/fuse.h" by itself."
#endif

// FUSE macros
#if defined(FUSE_WORD_ADDR) && defined(FUSE_RES_BITS_HIGH)
  #define PDK_SET_FUSE(f) \
    __asm__( \
      ".area FUSE (ABS)                               \n" \
      ".org ("_STR(FUSE_WORD_ADDR)"*2)                \n" \
      ".word ("_STR(FUSE_RES_BITS_HIGH)"|"_STR(f)")   \n" \
      ".area CODE                                     \n" \
    )
#endif

#endif //__PDK_FUSE_H__
