/* Configuration header file for MS-DOS/Watt-32
   Copyright (C) 2007 Free Software Foundation, Inc.

   This file is part of GNU Wget.

   GNU Wget is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   GNU Wget is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Wget.  If not, see <http://www.gnu.org/licenses/>.

   Additional permission under GNU GPL version 3 section 7

   If you modify this program, or any covered work, by linking or
   combining it with the OpenSSL project's OpenSSL library (or a
   modified version of that library), containing parts covered by the
   terms of the OpenSSL or SSLeay licenses, the Free Software Foundation
   grants you additional permission to convey the resulting work.
   Corresponding Source for a non-source form of such a combination
   shall include the source code for the parts of OpenSSL used as well
   as that of the covered work.  */


#ifndef CONFIG_DOS_H
#define CONFIG_DOS_H

#include <stdlib.h>
#include <limits.h>
#include <tcp.h>
#include <malloc.h>

#ifdef __DJGPP__
#include <sys/config.h>
#endif

#include <sys/errno.h>

#if defined(__WATCOMC__) && (__WATCOMC__ >= 1250)  /* OW 1.5+ */
  #define OPENWATCOM_15
#endif

#if defined(__HIGHC__)
  #define inline
  #define HAVE_UNISTD_H 1
  #define HAVE_UTIME_H 1
#endif

#if defined(__WATCOMC__) || defined(__BORLANDC__)
  #define inline
#endif

#ifdef HAVE_SSL
  #define OPENSSL_NO_KRB5
#endif

#define STDC_HEADERS 1
#define RETSIGTYPE void

#define USE_OPIE 1
#define USE_DIGEST 1
#define DEBUG

#ifdef __DJGPP__
  #define HAVE_STRUCT_UTIMBUF 1
  #define HAVE_UNAME 1
  #define HAVE_UTIME_H 1
  #define HAVE_STRCASECMP 1
  #define HAVE_STRNCASECMP 1
  #define HAVE_SYS_SELECT_H 1
  #define HAVE_USLEEP 1
  #define HAVE_SIGNAL 1
  #define HAVE_BASENAME 1
  #define HAVE_SIGSETJMP 1
  #define HAVE_SIGBLOCK 1
  #define HAVE__BOOL 1

  #if (DJGPP_MINOR >= 4)
    #include <stdbool.h>
    #define HAVE_SNPRINTF 1
    #define HAVE_VSNPRINTF 1
    #define HAVE_UINT32_T 1
  #endif
#endif

#ifdef __HIGHC__
  #define HAVE_STRUCT_UTIMBUF 1
  #define HAVE_UTIME_H 1
#endif

#ifdef OPENWATCOM_15
  #define HAVE_STRCASECMP
  #define HAVE_STRNCASECMP
#endif

#define HAVE_GETHOSTBYNAME 1
#define HAVE_GETHOSTNAME 1
#define HAVE_SELECT 1
#define HAVE_STRDUP 1
#define HAVE_STRERROR 1
#define HAVE_STRSTR 1
#define HAVE_MKTIME 1
#define HAVE_STDARG_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_MD5 1
#define HAVE_BUILTIN_MD5 1
#define HAVE_ISATTY 1
#define HAVE_MEMMOVE 1

#define OS_TYPE "DOS"
#define CTRLBREAK_BACKGND 1
#define PROTOTYPES 1

#define WGET_USE_STDARG

#define lookup_host  wget_lookuphost
#define select       select_s
#define socklen_t    int

#define sock_read    wget_sock_read
#define sock_write   wget_sock_write
#define sock_close   wget_sock_close

#if defined(__DJGPP__)
  #define MKDIR(p,a) mkdir(p,a)
#else
  #define strcasecmp stricmp
  #define MKDIR(p,a) mkdir(p)
#endif

#if !defined(MSDOS)
#define MSDOS
#endif

#endif  /* CONFIG_DOS_H */
