test: range.c
	cc range.c -o0 -g -o range
	gdb --batch --quiet -x gdb_1.txt --args ./range 1 12 > gdb_1_output.txt
	gdb --batch --quiet -x gdb_2.txt --args ./range -100 100 3 > gdb_2_output.txt
	grep "@@@M" gdb_1_output.txt > gdb_1_out.txt
	grep "@@@M" gdb_2_output.txt > gdb_2_out.txt
	echo "@@@M = 1 N = 12 S = 1 i = 5" > standart_1.txt
	echo "@@@M = 1 N = 12 S = 1 i = 10" >> standart_1.txt
	cmp gdb_1_out.txt standart_1.txt
	echo "@@@M = -100 N = 100 S = 3 i = -19" > standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -16" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -13" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -10" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -7" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -4" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = -1" >> standart_2.txt
	echo "@@@M = -100 N = 100 S = 3 i = 2" >> standart_2.txt
	cmp gdb_2_out.txt standart_2.txt

clean:
	rm -f standart_1.txt
	rm -f standart_2.txt
	rm -f gdb_1_out.txt
	rm -f gdb_2_out.txt
	rm -f gdb_1_output.txt
	rm -f gdb_2_output.txt
	rm -f range
