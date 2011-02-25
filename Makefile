test_multiply: test_multiply.o doller.o
	gcc -o $@ $^ -lcmockery

test_multiply.o: test_multiply.c
	gcc -Wall -c -o $@ $<

doller.o: doller.c doller.h
	gcc -Wall -c -o $@ $<

clean:
	-rm *.o
	-rm test_multiply
