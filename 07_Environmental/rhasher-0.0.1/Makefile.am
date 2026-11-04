CFLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=rhasher_test.sh

rhasher_test.sh:
	echo 'test "`sha1sum rhasher.c | awk '{print $1}' | tr '[:lower:]' '[:upper:]'`" = "`echo "SHA1 rhasher.c" | ./rhasher | awk '/^[0-9A-F]+$/ {print $1}'`"' > $@
	echo 'test "`md5sum rhasher.c | awk '{print $1}' | tr '[:lower:]' '[:upper:]'`" = "`echo "MD5 rhasher.c" | ./rhasher | awk '/^[0-9A-F]+$/ {print $1}'`"' > $@
	chmod +x $@

clean:
	rm -rf Makefile configure autoscan-default.log aclocal.m4 compile config.h.in config.log depcomp install-sh Makefile.in missing rhasher rhasher.o stamp-h1 config.h config.status autom4te.cache rhasher_test.sh rhasher_test.sh.log rhasher_test.sh.trs test-driver test-suite.log