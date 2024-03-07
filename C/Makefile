GCC=gcc

all:	test.o
	$(GCC) test.c -o test.exe
test.o:	test.c
	$(GCC) -c test.c
clean:	test.exe
	@echo "cleaning..."
	del test.o test.exe
	@echo "project cleaned"