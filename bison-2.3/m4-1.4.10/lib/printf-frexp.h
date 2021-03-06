/* Split a double into fraction and mantissa, for hexadecimal printf.
   Copyright (C) 2007 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/* Write a finite, positive number x as
     x = mantissa * 2^exp
   where exp >= DBL_MIN_EXP - 1,
         mantissa < 2.0,
         if x is not a denormalized number then mantissa >= 1.0.
   Store exp and return mantissa.  */
extern double printf_frexp (double x, int *exp);
