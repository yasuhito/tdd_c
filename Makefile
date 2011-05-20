all: test_franc test_dollar test_currency
	./test_franc
	./test_dollar
	./test_currency


test_franc: test_franc.o franc.o money.o dollar.o
	gcc -o $@ $^ -lcmockery

test_franc.o: test_franc.c franc.h money.h
	gcc -Wall -Werror -c -o $@ $<

franc.o: franc.c franc.h money.h
	gcc -Wall -Werror -c -o $@ $<


test_dollar: test_dollar.o dollar.o franc.o money.o 
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c dollar.h money.h
	gcc -Wall -Werror -c -o $@ $<

dollar.o: dollar.c dollar.h money.h
	gcc -Wall -Werror -c -o $@ $<


test_currency: test_currency.o money.o dollar.o franc.o
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_currency.o: test_currency.c
	gcc -Wall -Werror -c -o $@ $<


money.o: money.c money.h money_private.h
	gcc -Wall -Werror -c -o $@ $<


clean:
	-rm *.o *~
	-rm test_currency
	-rm test_dollar
	-rm test_franc
