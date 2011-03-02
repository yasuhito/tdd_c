test_dollar: test_dollar.o dollar.o
	gcc -o $@ $^ -lcmockery

test_dollar.o: test_dollar.c
	gcc -Wall -c -o $@ $<

dollar.o: dollar.c dollar.h
	gcc -Wall -c -o $@ $<

clean:
	-rm *.o *~
	-rm test_dollar
