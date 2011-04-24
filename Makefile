all: test_franc test_dollar
	./test_franc
	./test_dollar

test_franc: test_franc.o franc.o money.o dollar.o
	gcc -o $@ $^ -lcmockery

test_franc.o: test_franc.c franc.h
	gcc -Wall -Wextra -c -o $@ $<

franc.o: franc.c franc.h money.h
	gcc -Wall -Wextra -c -o $@ $<


test_dollar: test_dollar.o dollar.o franc.o money.o 
	gcc -Wall -Wextra -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c dollar.h
	gcc -Wall -Wextra -c -o $@ $<

dollar.o: dollar.c dollar.h money.h
	gcc -Wall -Wextra -c -o $@ $<


money.o: money.c money.h
	gcc -Wall -Wextra -c -o $@ $<


clean:
	-rm *.o *~
	-rm test_dollar
	-rm test_franc
