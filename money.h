#include <stdbool.h>

typedef struct {
} Money;

typedef struct {
  unsigned int amount;
} MoneyPrivate;

bool equal( const void *money, const void *other );
