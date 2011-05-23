all: test_dollar test_currency
	./test_dollar
	./test_currency


test_dollar: test_dollar.o money.o 
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c money.h
	gcc -Wall -Werror -c -o $@ $<


test_currency: test_currency.o money.o
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_currency.o: test_currency.c
	gcc -Wall -Werror -c -o $@ $<


money.o: money.c money.h money_private.h
	gcc -Wall -Werror -c -o $@ $<


clean:
	-rm *.o *~
	-rm test_currency
	-rm test_dollar
