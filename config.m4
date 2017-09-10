dnl $Id$
dnl config.m4 for extension murmurhash

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(murmurhash, for murmurhash support,
dnl Make sure that the comment is aligned:
dnl [  --with-murmurhash             Include murmurhash support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(murmurhash, whether to enable murmurhash support,
Make sure that the comment is aligned:
[  --enable-murmurhash           Enable murmurhash support])

if test "$PHP_MURMURHASH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-murmurhash -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/murmurhash.h"  # you most likely want to change this
  dnl if test -r $PHP_MURMURHASH/$SEARCH_FOR; then # path given as parameter
  dnl   MURMURHASH_DIR=$PHP_MURMURHASH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for murmurhash files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MURMURHASH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MURMURHASH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the murmurhash distribution])
  dnl fi

  dnl # --with-murmurhash -> add include path
  dnl PHP_ADD_INCLUDE($MURMURHASH_DIR/include)

  dnl # --with-murmurhash -> check for lib and symbol presence
  dnl LIBNAME=murmurhash # you may want to change this
  dnl LIBSYMBOL=murmurhash # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MURMURHASH_DIR/$PHP_LIBDIR, MURMURHASH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MURMURHASHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong murmurhash lib version or lib not found])
  dnl ],[
  dnl   -L$MURMURHASH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MURMURHASH_SHARED_LIBADD)

  PHP_REQUIRE_CXX()
  PHP_SUBST(MURMURHASH_SHARED_LIBADD)
  PHP_ADD_LIBRARY(stdc++, 1, MURMUR_HASH_SHARED_LIBADD)
  MURMURHASH_SOURCES="\
    MurmurHash3.cpp \ 
    MurmurHash2.cpp \
    MurmurHash1.cpp \
    murmurhash.cpp"

  PHP_NEW_EXTENSION(murmurhash, $MURMURHASH_SOURCES, $ext_shared)
fi
