/* Test of <sys/stat.h> substitute.
   Copyright (C) 2007 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/* Written by Bruno Haible <bruno@clisp.org>, 2007.  */

#include <config.h>

#include <sys/stat.h>

#include "verify.h"

/* Check the existence of some macros.  */
int a[] =
  {
    S_IFMT,
    S_IFBLK, S_IFCHR, S_IFDIR, S_IFIFO, S_IFREG,
#ifdef S_IFLNK /* missing on mingw and djgpp */
    S_IFLNK,
#endif
#ifdef S_IFSOCK /* missing on mingw and djgpp */
    S_IFSOCK,
#endif
    S_IRWXU, S_IRUSR, S_IWUSR, S_IXUSR,
    S_IRWXG, S_IRGRP, S_IWGRP, S_IXGRP,
    S_IRWXO, S_IROTH, S_IWOTH, S_IXOTH,
    S_ISUID, S_ISGID, S_ISVTX,
    S_ISBLK (S_IFREG),
    S_ISCHR (S_IFREG),
    S_ISDIR (S_IFREG),
    S_ISFIFO (S_IFREG),
    S_ISREG (S_IFREG),
    S_ISLNK (S_IFREG),
    S_ISSOCK (S_IFREG),
    S_ISDOOR (S_IFREG),
    S_ISMPB (S_IFREG),
    S_ISNAM (S_IFREG),
    S_ISNWK (S_IFREG),
    S_ISPORT (S_IFREG),
    S_ISCTG (S_IFREG),
    S_ISOFD (S_IFREG),
    S_ISOFL (S_IFREG),
    S_ISWHT (S_IFREG)
  };

/* Sanity checks.  */

verify (S_IRWXU == (S_IRUSR | S_IWUSR | S_IXUSR));
verify (S_IRWXG == (S_IRGRP | S_IWGRP | S_IXGRP));
verify (S_IRWXO == (S_IROTH | S_IWOTH | S_IXOTH));

verify (S_ISBLK (S_IFBLK));
verify (!S_ISBLK (S_IFCHR));
verify (!S_ISBLK (S_IFDIR));
verify (!S_ISBLK (S_IFIFO));
verify (!S_ISBLK (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISBLK (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISBLK (S_IFSOCK));
#endif

verify (!S_ISCHR (S_IFBLK));
verify (S_ISCHR (S_IFCHR));
verify (!S_ISCHR (S_IFDIR));
verify (!S_ISCHR (S_IFIFO));
verify (!S_ISCHR (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISCHR (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISCHR (S_IFSOCK));
#endif

verify (!S_ISDIR (S_IFBLK));
verify (!S_ISDIR (S_IFCHR));
verify (S_ISDIR (S_IFDIR));
verify (!S_ISDIR (S_IFIFO));
verify (!S_ISDIR (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISDIR (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISDIR (S_IFSOCK));
#endif

verify (!S_ISFIFO (S_IFBLK));
verify (!S_ISFIFO (S_IFCHR));
verify (!S_ISFIFO (S_IFDIR));
verify (S_ISFIFO (S_IFIFO));
verify (!S_ISFIFO (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISFIFO (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISFIFO (S_IFSOCK));
#endif

verify (!S_ISREG (S_IFBLK));
verify (!S_ISREG (S_IFCHR));
verify (!S_ISREG (S_IFDIR));
verify (!S_ISREG (S_IFIFO));
verify (S_ISREG (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISREG (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISREG (S_IFSOCK));
#endif

verify (!S_ISLNK (S_IFBLK));
verify (!S_ISLNK (S_IFCHR));
verify (!S_ISLNK (S_IFDIR));
verify (!S_ISLNK (S_IFIFO));
verify (!S_ISLNK (S_IFREG));
#ifdef S_IFLNK
verify (S_ISLNK (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISLNK (S_IFSOCK));
#endif

verify (!S_ISSOCK (S_IFBLK));
verify (!S_ISSOCK (S_IFCHR));
verify (!S_ISSOCK (S_IFDIR));
verify (!S_ISSOCK (S_IFIFO));
verify (!S_ISSOCK (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISSOCK (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (S_ISSOCK (S_IFSOCK));
#endif

verify (!S_ISDOOR (S_IFBLK));
verify (!S_ISDOOR (S_IFCHR));
verify (!S_ISDOOR (S_IFDIR));
verify (!S_ISDOOR (S_IFIFO));
verify (!S_ISDOOR (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISDOOR (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISDOOR (S_IFSOCK));
#endif

verify (!S_ISMPB (S_IFBLK));
verify (!S_ISMPB (S_IFCHR));
verify (!S_ISMPB (S_IFDIR));
verify (!S_ISMPB (S_IFIFO));
verify (!S_ISMPB (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISMPB (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISMPB (S_IFSOCK));
#endif

verify (!S_ISNAM (S_IFBLK));
verify (!S_ISNAM (S_IFCHR));
verify (!S_ISNAM (S_IFDIR));
verify (!S_ISNAM (S_IFIFO));
verify (!S_ISNAM (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISNAM (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISNAM (S_IFSOCK));
#endif

verify (!S_ISNWK (S_IFBLK));
verify (!S_ISNWK (S_IFCHR));
verify (!S_ISNWK (S_IFDIR));
verify (!S_ISNWK (S_IFIFO));
verify (!S_ISNWK (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISNWK (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISNWK (S_IFSOCK));
#endif

verify (!S_ISPORT (S_IFBLK));
verify (!S_ISPORT (S_IFCHR));
verify (!S_ISPORT (S_IFDIR));
verify (!S_ISPORT (S_IFIFO));
verify (!S_ISPORT (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISPORT (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISPORT (S_IFSOCK));
#endif

verify (!S_ISCTG (S_IFBLK));
verify (!S_ISCTG (S_IFCHR));
verify (!S_ISCTG (S_IFDIR));
verify (!S_ISCTG (S_IFIFO));
verify (!S_ISCTG (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISCTG (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISCTG (S_IFSOCK));
#endif

verify (!S_ISOFD (S_IFBLK));
verify (!S_ISOFD (S_IFCHR));
verify (!S_ISOFD (S_IFDIR));
verify (!S_ISOFD (S_IFIFO));
verify (!S_ISOFD (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISOFD (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISOFD (S_IFSOCK));
#endif

verify (!S_ISOFL (S_IFBLK));
verify (!S_ISOFL (S_IFCHR));
verify (!S_ISOFL (S_IFDIR));
verify (!S_ISOFL (S_IFIFO));
verify (!S_ISOFL (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISOFL (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISOFL (S_IFSOCK));
#endif

verify (!S_ISWHT (S_IFBLK));
verify (!S_ISWHT (S_IFCHR));
verify (!S_ISWHT (S_IFDIR));
verify (!S_ISWHT (S_IFIFO));
verify (!S_ISWHT (S_IFREG));
#ifdef S_IFLNK
verify (!S_ISWHT (S_IFLNK));
#endif
#ifdef S_IFSOCK
verify (!S_ISWHT (S_IFSOCK));
#endif

int
main ()
{
  return 0;
}
