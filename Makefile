all: test_dollar test_currency test_bank
	./test_dollar
	./test_currency
	./test_bank


test_bank: test_bank.o money.o bank.o sum.o
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_bank.o: test_bank.c money.h bank.h sum.h
	gcc -Wall -Werror -c -o $@ $<

test_dollar: test_dollar.o money.o bank.o sum.o
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c money.h bank.h
	gcc -Wall -Werror -c -o $@ $<


test_currency: test_currency.o money.o sum.o
	gcc -Wall -Werror -o $@ $^ -lcmockery

test_currency.o: test_currency.c
	gcc -Wall -Werror -c -o $@ $<


money.o: money.c money.h money_protected.h sum.h
	gcc -Wall -Werror -c -o $@ $<

bank.o: bank.c bank.h
	gcc -Wall -Werror -c -o $@ $<

sum.o: sum.c sum.h
	gcc -Wall -Werror -c -o $@ $<

clean:
	-rm *.o *~
	-rm test_currency
	-rm test_dollar
	-rm test_bank
