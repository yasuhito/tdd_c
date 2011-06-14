#ifndef MONEY_PROTECTED_H
#define MONEY_PROTECTED_H
/*
 * NOTE: This is a protected header file.
         Do not distribute this header file to developers
 */


typedef struct {
  unsigned int amount;
  Currency currency;
} MoneyProtected;

#endif
