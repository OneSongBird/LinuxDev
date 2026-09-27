GENERATES = prog prog-a prog-so liboutput.so
TRASH = *.o liboutput_static.a *.txt

%.o: %.c
		cc $< -fPIC -c -o $@

test: prog prog-a prog-so
		./prog > outfile_0.txt 2>&1
		./prog-a > outfile_a_0.txt 2>&1
		LD_LIBRARY_PATH=`pwd` ./prog-so > outfile_so_0.txt 2>&1
		./prog abc > outfile_1.txt 2>&1
		./prog-a abc > outfile_a_1.txt 2>&1
		LD_LIBRARY_PATH=`pwd` ./prog-so abc > outfile_so_1.txt 2>&1
		./prog abc cde asdq > outfile_3.txt 2>&1
		./prog-a abc cde asdq > outfile_a_3.txt 2>&1
		LD_LIBRARY_PATH=`pwd` ./prog-so abc cde asdq > outfile_so_3.txt 2>&1
		cmp outfile_0.txt outfile_a_0.txt
		cmp outfile_0.txt outfile_so_0.txt
		cmp outfile_1.txt outfile_a_1.txt
		cmp outfile_1.txt outfile_so_1.txt
		cmp outfile_3.txt outfile_a_3.txt
		cmp outfile_3.txt outfile_so_3.txt

prog: const.o fun.o prog.o
		cc $^ -o $@

fun.o:  outlib.h

prog.o: outlib.h

liboutput_static.a: const.o fun.o
		ar -rcs $@ $^

prog-a: prog.o liboutput_static.a
		cc -L. $< -loutput_static -o $@

liboutput.so: const.o fun.o
		cc -shared $^ -o $@

prog-so: prog.o liboutput.so
		cc -L. $< -loutput -o $@

clean:
		rm -f $(TRASH)

distclean: clean
		rm -rf $(GENERATES)