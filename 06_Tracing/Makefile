all: move libmove.so

move: move.c
	cc $< -o $@

libmove.so: move_so.c
	cc -shared $< -o $@

test: all
	seq -f "123456789%g" 1 400  > in_PROTECT.txt
	LD_PRELOAD=./libmove.so ./move in_PROTECT.txt out.txt > out_so.txt 2>&1
	wc -c < out_so.txt > output_so.txt
	echo "0" > output_so_standart.txt
	cmp output_so.txt output_so_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=openat -e inject=openat:error=EACCES -P in_PROTECT.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "2" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=openat -e inject=openat:error=EACCES -P out.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "3" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=read -e inject=read:error=EIO -P in_PROTECT.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "4" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=write -e inject=write:error=EIO -P out.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "5" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=close -e inject=close:error=EIO -P out.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "6" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=close -e inject=close:error=EIO -P in_PROTECT.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "7" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null
	
	strace -e trace=unlink -e inject=unlink:error=EIO -P in_PROTECT.txt ./move in_PROTECT.txt out.txt > /dev/null 2>&1; echo $$? > strace.txt; true
	echo "8" > strace_standart.txt
	cmp strace.txt strace_standart.txt
	stat in_PROTECT.txt > /dev/null

clean:
	rm -rf in_PROTECT.txt out.txt out_so.txt output_so.txt output_so_standart.txt strace.txt strace_standart.txt
	rm -rf move libmove.so