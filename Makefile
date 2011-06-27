CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu99
LDFLAGS = -lcmockery -lpthread
TARGETS = test_bank test_dollar test_currency 

SRCS_TEST_BANK = test_bank.c bank.c hash_table.c linked_list.c money.c pair.c sum.c
SRCS_TEST_DOLLAR = test_dollar.c hash_table.c linked_list.c money.c bank.c pair.c sum.c
SRCS_TEST_CURRENCY = test_currency.c hash_table.c linked_list.c bank.c money.c pair.c sum.c
SRCS = $(SRCS_TEST_BANK) $(SRCS_TEST_DOLLAR) $(SRCS_TEST_CURRENCY)

OBJS_TEST_BANK = $(SRCS_TEST_BANK:.c=.o)
OBJS_TEST_DOLLAR = $(SRCS_TEST_DOLLAR:.c=.o)
OBJS_TEST_CURRENCY = $(SRCS_TEST_CURRENCY:.c=.o)
OBJS = $(OBJS_TEST_BANK) $(OBJS_TEST_DOLLAR) $(OBJS_TEST_CURRENCY)

DEPENDS = .depends


all: depend $(TARGETS)
	./test_dollar
	./test_currency
	./test_bank


test_bank: $(OBJS_TEST_BANK)
	$(CC) $(CFLAGS) -o $@ $(OBJS_TEST_BANK) $(LDFLAGS)

test_dollar: $(OBJS_TEST_DOLLAR)
	$(CC) $(CFLAGS) -o $@ $(OBJS_TEST_DOLLAR) $(LDFLAGS)

test_currency: $(OBJS_TEST_CURRENCY)
	$(CC) $(CFLAGS) -o $@ $(OBJS_TEST_CURRENCY) $(LDFLAGS)


.c.o:
	$(CC) $(CFLAGS) -c $<

depend:
	$(CC) -MM -MG $(SRCS) > $(DEPENDS)

clean:
	@rm -f $(OBJS) $(TARGETS) *~

-include $(DEPENDS)

