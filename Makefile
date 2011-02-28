test_multiply: test_multiply.o dollar.o
	gcc -o $@ $^ -lcmockery

test_multiply.o: test_multiply.c
	gcc -Wall -c -o $@ $<

dollar.o: dollar.c dollar.h
	gcc -Wall -c -o $@ $<

clean:
	-rm *.o *~
	-rm test_multiply
