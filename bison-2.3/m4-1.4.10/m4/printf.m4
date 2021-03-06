# printf.m4 serial 15
dnl Copyright (C) 2003, 2007 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Test whether the *printf family of functions supports the 'j', 'z', 't',
dnl 'L' size specifiers. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_sizes_c99.

AC_DEFUN([gl_PRINTF_SIZES_C99],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gl_AC_HEADER_STDINT_H])
  AC_REQUIRE([gl_AC_HEADER_INTTYPES_H])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports size specifiers as in C99],
    [gl_cv_func_printf_sizes_c99],
    [
      AC_TRY_RUN([
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#if HAVE_STDINT_H_WITH_UINTMAX
# include <stdint.h>
#endif
#if HAVE_INTTYPES_H_WITH_UINTMAX
# include <inttypes.h>
#endif
static char buf[100];
int main ()
{
#if HAVE_STDINT_H_WITH_UINTMAX || HAVE_INTTYPES_H_WITH_UINTMAX
  buf[0] = '\0';
  if (sprintf (buf, "%ju %d", (uintmax_t) 12345671, 33, 44, 55) < 0
      || strcmp (buf, "12345671 33") != 0)
    return 1;
#endif
  buf[0] = '\0';
  if (sprintf (buf, "%zu %d", (size_t) 12345672, 33, 44, 55) < 0
      || strcmp (buf, "12345672 33") != 0)
    return 1;
  buf[0] = '\0';
  if (sprintf (buf, "%tu %d", (ptrdiff_t) 12345673, 33, 44, 55) < 0
      || strcmp (buf, "12345673 33") != 0)
    return 1;
  buf[0] = '\0';
  if (sprintf (buf, "%Lg %d", (long double) 1.5, 33, 44, 55) < 0
      || strcmp (buf, "1.5 33") != 0)
    return 1;
  return 0;
}], [gl_cv_func_printf_sizes_c99=yes], [gl_cv_func_printf_sizes_c99=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_printf_sizes_c99="guessing yes";;
                               # Guess yes on FreeBSD >= 5.
         freebsd[1-4]*)        gl_cv_func_printf_sizes_c99="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_printf_sizes_c99="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_printf_sizes_c99="guessing no";;
         darwin*)              gl_cv_func_printf_sizes_c99="guessing yes";;
                               # Guess yes on OpenBSD >= 3.9.
         openbsd[1-2].* | openbsd3.[0-8] | openbsd3.[0-8].*)
                               gl_cv_func_printf_sizes_c99="guessing no";;
         openbsd*)             gl_cv_func_printf_sizes_c99="guessing yes";;
                               # Guess yes on Solaris >= 2.10.
         solaris2.[0-9]*)      gl_cv_func_printf_sizes_c99="guessing no";;
         solaris*)             gl_cv_func_printf_sizes_c99="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_printf_sizes_c99="guessing no";;
         netbsd*)              gl_cv_func_printf_sizes_c99="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_printf_sizes_c99="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports 'long double'
dnl arguments together with the 'L' size specifier. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_long_double.

AC_DEFUN([gl_PRINTF_LONG_DOUBLE],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports 'long double' arguments],
    [gl_cv_func_printf_long_double],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  buf[0] = '\0';
  if (sprintf (buf, "%Lf %d", 1.75L, 33, 44, 55) < 0
      || strcmp (buf, "1.750000 33") != 0)
    return 1;
  buf[0] = '\0';
  if (sprintf (buf, "%Le %d", 1.75L, 33, 44, 55) < 0
      || strcmp (buf, "1.750000e+00 33") != 0)
    return 1;
  buf[0] = '\0';
  if (sprintf (buf, "%Lg %d", 1.75L, 33, 44, 55) < 0
      || strcmp (buf, "1.75 33") != 0)
    return 1;
  return 0;
}], [gl_cv_func_printf_long_double=yes], [gl_cv_func_printf_long_double=no],
      [
changequote(,)dnl
       case "$host_os" in
         beos*)        gl_cv_func_printf_long_double="guessing no";;
         mingw* | pw*) gl_cv_func_printf_long_double="guessing no";;
         *)            gl_cv_func_printf_long_double="guessing yes";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports infinite and NaN
dnl 'double' arguments in the %f, %e, %g directives. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_infinite.

AC_DEFUN([gl_PRINTF_INFINITE],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports infinite 'double' arguments],
    [gl_cv_func_printf_infinite],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static int
strisnan (const char *string, size_t start_index, size_t end_index)
{
  if (start_index < end_index)
    {
      if (string[start_index] == '-')
        start_index++;
      if (start_index + 3 <= end_index
          && memcmp (string + start_index, "nan", 3) == 0)
        {
          start_index += 3;
          if (start_index == end_index
              || (string[start_index] == '(' && string[end_index - 1] == ')'))
            return 1;
        }
    }
  return 0;
}
static char buf[100];
static double zero = 0.0;
int main ()
{
  if (sprintf (buf, "%f", 1.0 / 0.0) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%f", -1.0 / 0.0) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%f", zero / zero) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
  if (sprintf (buf, "%e", 1.0 / 0.0) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%e", -1.0 / 0.0) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%e", zero / zero) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
  if (sprintf (buf, "%g", 1.0 / 0.0) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%g", -1.0 / 0.0) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%g", zero / zero) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
  return 0;
}], [gl_cv_func_printf_infinite=yes], [gl_cv_func_printf_infinite=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_printf_infinite="guessing yes";;
                               # Guess yes on FreeBSD >= 6.
         freebsd[1-5]*)        gl_cv_func_printf_infinite="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_printf_infinite="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_printf_infinite="guessing no";;
         darwin*)              gl_cv_func_printf_infinite="guessing yes";;
                               # Guess yes on HP-UX >= 11.
         hpux[7-9]* | hpux10*) gl_cv_func_printf_infinite="guessing no";;
         hpux*)                gl_cv_func_printf_infinite="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_printf_infinite="guessing no";;
         netbsd*)              gl_cv_func_printf_infinite="guessing yes";;
                               # Guess yes on BeOS.
         beos*)                gl_cv_func_printf_infinite="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_printf_infinite="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports infinite and NaN
dnl 'long double' arguments in the %f, %e, %g directives. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_infinite_long_double.

AC_DEFUN([gl_PRINTF_INFINITE_LONG_DOUBLE],
[
  AC_REQUIRE([gl_PRINTF_LONG_DOUBLE])
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_C_BIGENDIAN])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  dnl The user can set or unset the variable gl_printf_safe to indicate
  dnl that he wishes a safe handling of non-IEEE-754 'long double' values.
  if test -n "$gl_printf_safe"; then
    AC_DEFINE([CHECK_PRINTF_SAFE], 1,
      [Define if you wish *printf() functions that have a safe handling of
       non-IEEE-754 'long double' values.])
  fi
  case "$gl_cv_func_printf_long_double" in
    *yes)
      AC_CACHE_CHECK([whether printf supports infinite 'long double' arguments],
        [gl_cv_func_printf_infinite_long_double],
        [
          AC_TRY_RUN([
#include <float.h>
#include <stdio.h>
#include <string.h>
static int
strisnan (const char *string, size_t start_index, size_t end_index)
{
  if (start_index < end_index)
    {
      if (string[start_index] == '-')
        start_index++;
      if (start_index + 3 <= end_index
          && memcmp (string + start_index, "nan", 3) == 0)
        {
          start_index += 3;
          if (start_index == end_index
              || (string[start_index] == '(' && string[end_index - 1] == ')'))
            return 1;
        }
    }
  return 0;
}
static char buf[100];
static long double zeroL = 0.0L;
int main ()
{
  if (sprintf (buf, "%Lf", 1.0L / 0.0L) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%Lf", -1.0L / 0.0L) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%Lf", zeroL / zeroL) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
  if (sprintf (buf, "%Le", 1.0L / 0.0L) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%Le", -1.0L / 0.0L) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%Le", zeroL / zeroL) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
  if (sprintf (buf, "%Lg", 1.0L / 0.0L) < 0
      || (strcmp (buf, "inf") != 0 && strcmp (buf, "infinity") != 0))
    return 1;
  if (sprintf (buf, "%Lg", -1.0L / 0.0L) < 0
      || (strcmp (buf, "-inf") != 0 && strcmp (buf, "-infinity") != 0))
    return 1;
  if (sprintf (buf, "%Lg", zeroL / zeroL) < 0
      || !strisnan (buf, 0, strlen (buf)))
    return 1;
#if CHECK_PRINTF_SAFE && ((defined __ia64 && LDBL_MANT_DIG == 64) || (defined __x86_64__ || defined __amd64__) || (defined __i386 || defined __i386__ || defined _I386 || defined _M_IX86 || defined _X86_))
/* Representation of an 80-bit 'long double' as an initializer for a sequence
   of 'unsigned int' words.  */
# ifdef WORDS_BIGENDIAN
#  define LDBL80_WORDS(exponent,manthi,mantlo) \
     { ((unsigned int) (exponent) << 16) | ((unsigned int) (manthi) >> 16), \
       ((unsigned int) (manthi) << 16) | (unsigned int) (mantlo) >> 16),    \
       (unsigned int) (mantlo) << 16                                        \
     }
# else
#  define LDBL80_WORDS(exponent,manthi,mantlo) \
     { mantlo, manthi, exponent }
# endif
  { /* Quiet NaN.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0xFFFF, 0xC3333333, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  {
    /* Signalling NaN.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0xFFFF, 0x83333333, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  { /* Pseudo-NaN.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0xFFFF, 0x40000001, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  { /* Pseudo-Infinity.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0xFFFF, 0x00000000, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  { /* Pseudo-Zero.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0x4004, 0x00000000, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  { /* Unnormalized number.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0x4000, 0x63333333, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
  { /* Pseudo-Denormal.  */
    static union { unsigned int word[4]; long double value; } x =
      { LDBL80_WORDS (0x0000, 0x83333333, 0x00000000) };
    if (sprintf (buf, "%Lf", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Le", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
    if (sprintf (buf, "%Lg", x.value) < 0
        || !strisnan (buf, 0, strlen (buf)))
      return 1;
  }
#endif
  return 0;
}],
          [gl_cv_func_printf_infinite_long_double=yes],
          [gl_cv_func_printf_infinite_long_double=no],
          [
changequote(,)dnl
           case "$host_cpu" in
                                   # Guess no on ia64, x86_64, i386.
             ia64 | x86_64 | i*86) gl_cv_func_printf_infinite_long_double="guessing no";;
             *)
               case "$host_os" in
                                       # Guess yes on glibc systems.
                 *-gnu*)               gl_cv_func_printf_infinite_long_double="guessing yes";;
                                       # Guess yes on FreeBSD >= 6.
                 freebsd[1-5]*)        gl_cv_func_printf_infinite_long_double="guessing no";;
                 freebsd* | kfreebsd*) gl_cv_func_printf_infinite_long_double="guessing yes";;
                                       # Guess yes on MacOS X >= 10.3.
                 darwin[1-6].*)        gl_cv_func_printf_infinite_long_double="guessing no";;
                 darwin*)              gl_cv_func_printf_infinite_long_double="guessing yes";;
                                       # Guess yes on HP-UX >= 11.
                 hpux[7-9]* | hpux10*) gl_cv_func_printf_infinite_long_double="guessing no";;
                 hpux*)                gl_cv_func_printf_infinite_long_double="guessing yes";;
                                       # Guess yes on NetBSD >= 3.
                 netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                                       gl_cv_func_printf_infinite_long_double="guessing no";;
                 netbsd*)              gl_cv_func_printf_infinite_long_double="guessing yes";;
                                       # If we don't know, assume the worst.
                 *)                    gl_cv_func_printf_infinite_long_double="guessing no";;
               esac
               ;;
           esac
changequote([,])dnl
          ])
        ])
      ;;
    *)
      gl_cv_func_printf_infinite_long_double="irrelevant"
      ;;
  esac
])

dnl Test whether the *printf family of functions supports the 'a' and 'A'
dnl conversion specifier for hexadecimal output of floating-point numbers.
dnl (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_directive_a.

AC_DEFUN([gl_PRINTF_DIRECTIVE_A],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports the 'a' and 'A' directives],
    [gl_cv_func_printf_directive_a],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  if (sprintf (buf, "%a %d", 3.1416015625, 33, 44, 55) < 0
      || (strcmp (buf, "0x1.922p+1 33") != 0
          && strcmp (buf, "0x3.244p+0 33") != 0
          && strcmp (buf, "0x6.488p-1 33") != 0
          && strcmp (buf, "0xc.91p-2 33") != 0))
    return 1;
  if (sprintf (buf, "%A %d", -3.1416015625, 33, 44, 55) < 0
      || (strcmp (buf, "-0X1.922P+1 33") != 0
          && strcmp (buf, "-0X3.244P+0 33") != 0
          && strcmp (buf, "-0X6.488P-1 33") != 0
          && strcmp (buf, "-0XC.91P-2 33") != 0))
    return 1;
  /* This catches a FreeBSD 6.1 bug: it doesn't round.  */
  if (sprintf (buf, "%.2a %d", 1.51, 33, 44, 55) < 0
      || (strcmp (buf, "0x1.83p+0 33") != 0
          && strcmp (buf, "0x3.05p-1 33") != 0
          && strcmp (buf, "0x6.0ap-2 33") != 0
          && strcmp (buf, "0xc.14p-3 33") != 0))
    return 1;
  /* This catches a FreeBSD 6.1 bug.  See
     <http://lists.gnu.org/archive/html/bug-gnulib/2007-04/msg00107.html> */
  if (sprintf (buf, "%010a %d", 1.0 / 0.0, 33, 44, 55) < 0
      || buf[0] == '0')
    return 1;
  /* This catches a MacOS X 10.3.9 (Darwin 7.9) bug.  */
  if (sprintf (buf, "%.1a", 1.999) < 0
      || (strcmp (buf, "0x1.0p+1") != 0
          && strcmp (buf, "0x2.0p+0") != 0
          && strcmp (buf, "0x4.0p-1") != 0
          && strcmp (buf, "0x8.0p-2") != 0))
    return 1;
  /* This catches the same MacOS X 10.3.9 (Darwin 7.9) bug and also a
     glibc 2.4 bug <http://sourceware.org/bugzilla/show_bug.cgi?id=2908>.  */
  if (sprintf (buf, "%.1La", 1.999L) < 0
      || (strcmp (buf, "0x1.0p+1") != 0
          && strcmp (buf, "0x2.0p+0") != 0
          && strcmp (buf, "0x4.0p-1") != 0
          && strcmp (buf, "0x8.0p-2") != 0))
    return 1;
  return 0;
}], [gl_cv_func_printf_directive_a=yes], [gl_cv_func_printf_directive_a=no],
      [
       case "$host_os" in
                               # Guess yes on glibc >= 2.5 systems.
         *-gnu*)
           AC_EGREP_CPP([BZ2908], [
             #include <features.h>
             #ifdef __GNU_LIBRARY__
              #if (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 5) || (__GLIBC__ > 2)
               BZ2908
              #endif
             #endif
             ],
             [gl_cv_func_printf_directive_a="guessing yes"],
             [gl_cv_func_printf_directive_a="guessing no"])
           ;;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_printf_directive_a="guessing no";;
       esac
      ])
    ])
])

dnl Test whether the *printf family of functions supports the %F format
dnl directive. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_directive_f.

AC_DEFUN([gl_PRINTF_DIRECTIVE_F],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports the 'F' directive],
    [gl_cv_func_printf_directive_f],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  if (sprintf (buf, "%F %d", 1234567.0, 33, 44, 55) < 0
      || strcmp (buf, "1234567.000000 33") != 0)
    return 1;
  if (sprintf (buf, "%F", 1.0 / 0.0) < 0
      || (strcmp (buf, "INF") != 0 && strcmp (buf, "INFINITY") != 0))
    return 1;
  /* This catches a Cygwin 2007 bug.  */
  if (sprintf (buf, "%.F", 1234.0) < 0
      || strcmp (buf, "1234") != 0)
    return 1;
  return 0;
}], [gl_cv_func_printf_directive_f=yes], [gl_cv_func_printf_directive_f=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_printf_directive_f="guessing yes";;
                               # Guess yes on FreeBSD >= 6.
         freebsd[1-5]*)        gl_cv_func_printf_directive_f="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_printf_directive_f="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_printf_directive_f="guessing no";;
         darwin*)              gl_cv_func_printf_directive_f="guessing yes";;
                               # Guess yes on Solaris >= 2.10.
         solaris2.[0-9]*)      gl_cv_func_printf_directive_f="guessing no";;
         solaris*)             gl_cv_func_printf_directive_f="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_printf_directive_f="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports the %n format
dnl directive. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_printf_directive_n.

AC_DEFUN([gl_PRINTF_DIRECTIVE_N],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports the 'n' directive],
    [gl_cv_func_printf_directive_n],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  int count = -1;
  if (sprintf (buf, "%d %n", 123, &count, 33, 44, 55) < 0
      || strcmp (buf, "123 ") != 0
      || count != 4)
    return 1;
  return 0;
}], [gl_cv_func_printf_directive_n=yes], [gl_cv_func_printf_directive_n=no],
      [
changequote(,)dnl
       case "$host_os" in
         *)     gl_cv_func_printf_directive_n="guessing yes";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports POSIX/XSI format
dnl strings with positions. (POSIX:2001)
dnl Result is gl_cv_func_printf_positions.

AC_DEFUN([gl_PRINTF_POSITIONS],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports POSIX/XSI format strings with positions],
    [gl_cv_func_printf_positions],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
/* The string "%2$d %1$d", with dollar characters protected from the shell's
   dollar expansion (possibly an autoconf bug).  */
static char format[] = { '%', '2', '$', 'd', ' ', '%', '1', '$', 'd', '\0' };
static char buf[100];
int main ()
{
  sprintf (buf, format, 33, 55);
  return (strcmp (buf, "55 33") != 0);
}], [gl_cv_func_printf_positions=yes], [gl_cv_func_printf_positions=no],
      [
changequote(,)dnl
       case "$host_os" in
         netbsd[1-3]* | netbsdelf[1-3]* | netbsdaout[1-3]* | netbsdcoff[1-3]*)
                       gl_cv_func_printf_positions="guessing no";;
         beos*)        gl_cv_func_printf_positions="guessing no";;
         mingw* | pw*) gl_cv_func_printf_positions="guessing no";;
         *)            gl_cv_func_printf_positions="guessing yes";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports POSIX/XSI format
dnl strings with the ' flag for grouping of decimal digits. (POSIX:2001)
dnl Result is gl_cv_func_printf_flag_grouping.

AC_DEFUN([gl_PRINTF_FLAG_GROUPING],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports the grouping flag],
    [gl_cv_func_printf_flag_grouping],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  if (sprintf (buf, "%'d %d", 1234567, 99) < 0
      || buf[strlen (buf) - 1] != '9')
    return 1;
  return 0;
}], [gl_cv_func_printf_flag_grouping=yes], [gl_cv_func_printf_flag_grouping=no],
      [
changequote(,)dnl
       case "$host_os" in
         cygwin*)      gl_cv_func_printf_flag_grouping="guessing no";;
         netbsd*)      gl_cv_func_printf_flag_grouping="guessing no";;
         mingw* | pw*) gl_cv_func_printf_flag_grouping="guessing no";;
         *)            gl_cv_func_printf_flag_grouping="guessing yes";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the *printf family of functions supports padding of non-finite
dnl values with the 0 flag correctly. (ISO C99 + TC1 + TC2.) See
dnl <http://lists.gnu.org/archive/html/bug-gnulib/2007-04/msg00107.html>
dnl Result is gl_cv_func_printf_flag_zero.

AC_DEFUN([gl_PRINTF_FLAG_ZERO],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether printf supports the zero flag correctly],
    [gl_cv_func_printf_flag_zero],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  if (sprintf (buf, "%010f", 1.0 / 0.0, 33, 44, 55) < 0
      || (strcmp (buf, "       inf") != 0
          && strcmp (buf, "  infinity") != 0))
    return 1;
  return 0;
}], [gl_cv_func_printf_flag_zero=yes], [gl_cv_func_printf_flag_zero=no],
      [
changequote(,)dnl
       case "$host_os" in
                 # Guess yes on glibc systems.
         *-gnu*) gl_cv_func_printf_flag_zero="guessing yes";;
                 # Guess yes on BeOS.
         beos*)  gl_cv_func_printf_flag_zero="guessing yes";;
                 # If we don't know, assume the worst.
         *)      gl_cv_func_printf_flag_zero="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the snprintf function exists. (ISO C99, POSIX:2001)
dnl Result is ac_cv_func_snprintf.

AC_DEFUN([gl_SNPRINTF_PRESENCE],
[
  AC_CHECK_FUNCS_ONCE([snprintf])
])

dnl Test whether the string produced by the snprintf function is always NUL
dnl terminated. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_snprintf_truncation_c99.

AC_DEFUN([gl_SNPRINTF_TRUNCATION_C99],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether snprintf truncates the result as in C99],
    [gl_cv_func_snprintf_truncation_c99],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  strcpy (buf, "ABCDEF");
  snprintf (buf, 3, "%d %d", 4567, 89);
  if (memcmp (buf, "45\0DEF", 6) != 0)
    return 1;
  return 0;
}], [gl_cv_func_snprintf_truncation_c99=yes], [gl_cv_func_snprintf_truncation_c99=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on FreeBSD >= 5.
         freebsd[1-4]*)        gl_cv_func_snprintf_truncation_c99="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_snprintf_truncation_c99="guessing no";;
         darwin*)              gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on OpenBSD >= 3.9.
         openbsd[1-2].* | openbsd3.[0-8] | openbsd3.[0-8].*)
                               gl_cv_func_snprintf_truncation_c99="guessing no";;
         openbsd*)             gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on Solaris >= 2.6.
         solaris2.[0-5]*)      gl_cv_func_snprintf_truncation_c99="guessing no";;
         solaris*)             gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on AIX >= 4.
         aix[1-3]*)            gl_cv_func_snprintf_truncation_c99="guessing no";;
         aix*)                 gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on HP-UX >= 11.
         hpux[7-9]* | hpux10*) gl_cv_func_snprintf_truncation_c99="guessing no";;
         hpux*)                gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on IRIX >= 6.5.
         irix6.5)              gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on OSF/1 >= 5.
         osf[3-4]*)            gl_cv_func_snprintf_truncation_c99="guessing no";;
         osf*)                 gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_snprintf_truncation_c99="guessing no";;
         netbsd*)              gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # Guess yes on BeOS.
         beos*)                gl_cv_func_snprintf_truncation_c99="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_snprintf_truncation_c99="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the return value of the snprintf function is the number
dnl of bytes (excluding the terminating NUL) that would have been produced
dnl if the buffer had been large enough. (ISO C99, POSIX:2001)
dnl For example, this test program fails on IRIX 6.5:
dnl     ---------------------------------------------------------------------
dnl     #include <stdio.h>
dnl     int main()
dnl     {
dnl       static char buf[8];
dnl       int retval = snprintf (buf, 3, "%d", 12345);
dnl       return retval >= 0 && retval < 3;
dnl     }
dnl     ---------------------------------------------------------------------
dnl Result is gl_cv_func_snprintf_retval_c99.

AC_DEFUN([gl_SNPRINTF_RETVAL_C99],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether snprintf returns a byte count as in C99],
    [gl_cv_func_snprintf_retval_c99],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  strcpy (buf, "ABCDEF");
  if (snprintf (buf, 3, "%d %d", 4567, 89) != 7)
    return 1;
  return 0;
}], [gl_cv_func_snprintf_retval_c99=yes], [gl_cv_func_snprintf_retval_c99=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on FreeBSD >= 5.
         freebsd[1-4]*)        gl_cv_func_snprintf_retval_c99="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_snprintf_retval_c99="guessing no";;
         darwin*)              gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on OpenBSD >= 3.9.
         openbsd[1-2].* | openbsd3.[0-8] | openbsd3.[0-8].*)
                               gl_cv_func_snprintf_retval_c99="guessing no";;
         openbsd*)             gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on Solaris >= 2.6.
         solaris2.[0-5]*)      gl_cv_func_snprintf_retval_c99="guessing no";;
         solaris*)             gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on AIX >= 4.
         aix[1-3]*)            gl_cv_func_snprintf_retval_c99="guessing no";;
         aix*)                 gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_snprintf_retval_c99="guessing no";;
         netbsd*)              gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # Guess yes on BeOS.
         beos*)                gl_cv_func_snprintf_retval_c99="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_snprintf_retval_c99="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the snprintf function supports the %n format directive
dnl also in truncated portions of the format string. (ISO C99, POSIX:2001)
dnl Result is gl_cv_func_snprintf_directive_n.

AC_DEFUN([gl_SNPRINTF_DIRECTIVE_N],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether snprintf fully supports the 'n' directive],
    [gl_cv_func_snprintf_directive_n],
    [
      AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
static char buf[100];
int main ()
{
  int count = -1;
  snprintf (buf, 4, "%d %n", 12345, &count, 33, 44, 55);
  if (count != 6)
    return 1;
  return 0;
}], [gl_cv_func_snprintf_directive_n=yes], [gl_cv_func_snprintf_directive_n=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on FreeBSD >= 5.
         freebsd[1-4]*)        gl_cv_func_snprintf_directive_n="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_snprintf_directive_n="guessing no";;
         darwin*)              gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on Solaris >= 2.6.
         solaris2.[0-5]*)      gl_cv_func_snprintf_directive_n="guessing no";;
         solaris*)             gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on AIX >= 4.
         aix[1-3]*)            gl_cv_func_snprintf_directive_n="guessing no";;
         aix*)                 gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on IRIX >= 6.5.
         irix6.5)              gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on OSF/1 >= 5.
         osf[3-4]*)            gl_cv_func_snprintf_directive_n="guessing no";;
         osf*)                 gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_snprintf_directive_n="guessing no";;
         netbsd*)              gl_cv_func_snprintf_directive_n="guessing yes";;
                               # Guess yes on BeOS.
         beos*)                gl_cv_func_snprintf_directive_n="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_snprintf_directive_n="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl Test whether the vsnprintf function, when passed a zero size, produces no
dnl output. (ISO C99, POSIX:2001)
dnl For example, snprintf nevertheless writes a NUL byte in this case
dnl on OSF/1 5.1:
dnl     ---------------------------------------------------------------------
dnl     #include <stdio.h>
dnl     int main()
dnl     {
dnl       static char buf[8] = "DEADBEEF";
dnl       snprintf (buf, 0, "%d", 12345);
dnl       return buf[0] != 'D';
dnl     }
dnl     ---------------------------------------------------------------------
dnl And vsnprintf writes any output without bounds in this case, behaving like
dnl vsprintf, on HP-UX 11 and OSF/1 5.1:
dnl     ---------------------------------------------------------------------
dnl     #include <stdarg.h>
dnl     #include <stdio.h>
dnl     static int my_snprintf (char *buf, int size, const char *format, ...)
dnl     {
dnl       va_list args;
dnl       int ret;
dnl       va_start (args, format);
dnl       ret = vsnprintf (buf, size, format, args);
dnl       va_end (args);
dnl       return ret;
dnl     }
dnl     int main()
dnl     {
dnl       static char buf[8] = "DEADBEEF";
dnl       my_snprintf (buf, 0, "%d", 12345);
dnl       return buf[0] != 'D';
dnl     }
dnl     ---------------------------------------------------------------------
dnl Result is gl_cv_func_vsnprintf_zerosize_c99.

AC_DEFUN([gl_VSNPRINTF_ZEROSIZE_C99],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether vsnprintf respects a zero size as in C99],
    [gl_cv_func_vsnprintf_zerosize_c99],
    [
      AC_TRY_RUN([
#include <stdarg.h>
#include <stdio.h>
static int my_snprintf (char *buf, int size, const char *format, ...)
{
  va_list args;
  int ret;
  va_start (args, format);
  ret = vsnprintf (buf, size, format, args);
  va_end (args);
  return ret;
}
int main()
{
  static char buf[8] = "DEADBEEF";
  my_snprintf (buf, 0, "%d", 12345);
  return buf[0] != 'D';
}],
      [gl_cv_func_vsnprintf_zerosize_c99=yes],
      [gl_cv_func_vsnprintf_zerosize_c99=no],
      [
changequote(,)dnl
       case "$host_os" in
                               # Guess yes on glibc systems.
         *-gnu*)               gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on FreeBSD >= 5.
         freebsd[1-4]*)        gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
         freebsd* | kfreebsd*) gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on MacOS X >= 10.3.
         darwin[1-6].*)        gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
         darwin*)              gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on Cygwin.
         cygwin*)              gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on Solaris >= 2.6.
         solaris2.[0-5]*)      gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
         solaris*)             gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on AIX >= 4.
         aix[1-3]*)            gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
         aix*)                 gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on IRIX >= 6.5.
         irix6.5)              gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on NetBSD >= 3.
         netbsd[1-2]* | netbsdelf[1-2]* | netbsdaout[1-2]* | netbsdcoff[1-2]*)
                               gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
         netbsd*)              gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on BeOS.
         beos*)                gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # Guess yes on mingw.
         mingw* | pw*)         gl_cv_func_vsnprintf_zerosize_c99="guessing yes";;
                               # If we don't know, assume the worst.
         *)                    gl_cv_func_vsnprintf_zerosize_c99="guessing no";;
       esac
changequote([,])dnl
      ])
    ])
])

dnl The results of these tests on various platforms are:
dnl
dnl 1 = gl_PRINTF_SIZES_C99
dnl 2 = gl_PRINTF_LONG_DOUBLE
dnl 3 = gl_PRINTF_INFINITE
dnl 4 = gl_PRINTF_INFINITE_LONG_DOUBLE
dnl 5 = gl_PRINTF_DIRECTIVE_A
dnl 6 = gl_PRINTF_DIRECTIVE_F
dnl 7 = gl_PRINTF_DIRECTIVE_N
dnl 8 = gl_PRINTF_POSITIONS
dnl 9 = gl_PRINTF_FLAG_GROUPING
dnl 10 = gl_PRINTF_FLAG_ZERO
dnl 11 = gl_SNPRINTF_PRESENCE
dnl 12 = gl_SNPRINTF_TRUNCATION_C99
dnl 13 = gl_SNPRINTF_RETVAL_C99
dnl 14 = gl_SNPRINTF_DIRECTIVE_N
dnl 15 = gl_VSNPRINTF_ZEROSIZE_C99
dnl
dnl 1 = checking whether printf supports size specifiers as in C99...
dnl 2 = checking whether printf supports 'long double' arguments...
dnl 3 = checking whether printf supports infinite 'double' arguments...
dnl 4 = checking whether printf supports infinite 'long double' arguments...
dnl 5 = checking whether printf supports the 'a' and 'A' directives...
dnl 6 = checking whether printf supports the 'F' directive...
dnl 7 = checking whether printf supports the 'n' directive...
dnl 8 = checking whether printf supports POSIX/XSI format strings with positions...
dnl 9 = checking whether printf supports the grouping flag...
dnl 10 = checking whether printf supports the zero flag correctly...
dnl 11 = checking for snprintf...
dnl 12 = checking whether snprintf truncates the result as in C99...
dnl 13 = checking whether snprintf returns a byte count as in C99...
dnl 14 = checking whether snprintf fully supports the 'n' directive...
dnl 15 = checking whether vsnprintf respects a zero size as in C99...
dnl
dnl . = yes, # = no.
dnl
dnl                                  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
dnl   glibc 2.5                      .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
dnl   glibc 2.3.6                    .  .  .  .  #  .  .  .  .  .  .  .  .  .  .
dnl   FreeBSD 5.4, 6.1               .  .  .  .  #  .  .  .  .  #  .  .  .  .  .
dnl   MacOS X 10.3.9                 .  .  .  .  #  .  .  .  .  #  .  .  .  .  .
dnl   OpenBSD 3.9, 4.0               .  ?  ?  ?  #  ?  .  .  ?  ?  .  .  .  ?  ?
dnl   Cygwin 2007 (= Cygwin 1.5.24)  .  .  .  .  #  #  .  .  .  #  .  .  .  .  .
dnl   Cygwin 2006 (= Cygwin 1.5.19)  #  .  .  .  #  #  .  .  #  #  .  .  .  .  .
dnl   Solaris 10                     .  .  #  #  #  .  .  .  .  #  .  .  .  .  .
dnl   Solaris 2.6 ... 9              #  .  #  #  #  #  .  .  .  #  .  .  .  .  .
dnl   Solaris 2.5.1                  #  .  #  #  #  #  .  .  .  #  #  #  #  #  #
dnl   AIX 5.2                        .  .  #  #  #  .  .  .  .  #  .  .  .  .  .
dnl   AIX 4.3.2, 5.1                 #  .  #  #  #  #  .  .  .  #  .  .  .  .  .
dnl   HP-UX 11.31                    .  .  .  .  #  .  .  .  .  #  .  .  #  #  .
dnl   HP-UX 10.20, 11.{00,11,23}     #  .  .  .  #  #  .  .  .  #  .  .  #  #  #
dnl   IRIX 6.5                       #  .  #  #  #  #  .  .  .  #  .  .  #  .  .
dnl   OSF/1 5.1                      #  .  #  #  #  #  .  .  .  #  .  .  #  .  #
dnl   OSF/1 4.0d                     #  .  #  #  #  #  .  .  .  #  #  #  #  #  #
dnl   NetBSD 4.0                     .  ?  ?  ?  ?  ?  .  .  ?  ?  .  .  .  ?  ?
dnl   NetBSD 3.0                     .  .  .  .  #  #  .  #  #  #  .  .  .  .  .
dnl   BeOS                           #  #  .  #  #  #  .  #  .  .  .  .  .  .  .
dnl   mingw                          #  #  #  #  #  #  .  #  #  #  .  #  #  #  .
