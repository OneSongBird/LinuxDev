#!/bin/sh
seq -f "123456789%g" 1 400  > in_PROTECT.txt
LD_PRELOAD=/usr/lib64/libmove.so move in_PROTECT.txt out.txt
