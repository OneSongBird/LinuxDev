#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT([Rhasher], [0.0.1], [eliza.pevts721@yandex.ru])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([Rhash is needed])])
AC_CHECK_LIB([readline],[readline],[have_readline=yes
									LIBS="-lreadline $LIBS"],[have_readline=no])

# Checks for header files.
AC_CHECK_HEADERS([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Enable readline library]),
    AS_IF([test "$enable_readline" = "yes"],
          AC_DEFINE(READLINE,[],[Convenient input])),
    AS_IF([test "$have_readline" = "yes"],
          AC_DEFINE(READLINE,[],[Convenient input]))
)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
