all: test_franc test_dollar
	./test_franc
	./test_dollar

test_franc: test_franc.o franc.o
	gcc -o $@ $^ -lcmockery

test_franc.o: test_franc.c
	gcc -Wall -c -o $@ $<

test_franc.o: franc.h

franc.o: franc.c
	gcc -Wall -c -o $@ $<

franc.o: franc.h

test_dollar: test_dollar.o dollar.o money.o
	gcc -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c
	gcc -Wall -c -o $@ $<

test_dollar.o: dollar.h

dollar.o: dollar.c
	gcc -Wall -c -o $@ $<

dollar.o: dollar.h money.h

money.o: money.c
	gcc -Wall -c -o $@ $<

money.o: money.h


clean:
	-rm *.o *~
	-rm test_dollar
	-rm test_franc
