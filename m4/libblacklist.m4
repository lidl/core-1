AC_DEFUN([DOVECOT_LIBBLACKLIST],[
 if test $want_libblacklist != no; then
   AC_CHECK_LIB(blacklist, blacklist_open, [
     AC_DEFINE(HAVE_LIBBLACKLIST,, [libblacklist is installed for blacklist_open()])
     LIBBLACKLIST="-lblacklist"
     AC_SUBST(LIBBLACKLIST)
   ], [
     if test "$want_libblacklist" = "yes"; then
       AC_ERROR([Can't build with libblacklist support: libblacklist not found])
     fi
   ])
 fi
])
