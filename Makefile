all: test_franc test_dollar
	./test_franc
	./test_dollar

test_franc: test_franc.o franc.o
	gcc -o $@ $^ -lcmockery

test_franc.o: test_franc.c
	gcc -Wall -c -o $@ $<

franc.o: franc.c franc.h
	gcc -Wall -c -o $@ $<

test_dollar: test_dollar.o dollar.o
	gcc -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c
	gcc -Wall -c -o $@ $<

dollar.o: dollar.c dollar.h
	gcc -Wall -c -o $@ $<


clean:
	-rm *.o *~
	-rm test_dollar
	-rm test_franc
