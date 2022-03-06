all:
	@echo choose a homework to build, e.g.: make hw1

src = *.c

hw1_src = hw1*.c
hw1: $(hw1_src)
	gcc hw1_1and2.c -o hw1_1and2
	gcc hw1_3and4.c -o hw1_3and4
hw1.clean:
	@rm $(patsubst %.c, %, $(wildcard $(hw1_src)))


clean:
	@rm $(patsubst %.c, %, $(wildcard $(src)))