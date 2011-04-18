#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "dollar.h"
#include "franc.h"
#include "money.h"

Money *
create_dollar( unsigned int amount ) {
  MoneyPrivate *dollar = malloc( sizeof( MoneyPrivate ) );
  dollar->amount = amount;
  return ( Money * ) dollar;
}

Money *
create_franc( unsigned int amount ) {
  MoneyPrivate *franc = malloc( sizeof( MoneyPrivate ) );
  franc->amount = amount;
  return ( Money * ) franc;
}


Money *
multiply_money(Money * money, CurrencyType money_type, int multiplier){
        switch(money_type){
        case USD:
                return  multiply_dollar((Dollar *) money, multiplier);
        case CHF:
                return  multiply_franc((Franc *) money, multiplier);
        default:
		assert(false);
        }
}

bool
equal( const void *money, CurrencyType money_type, const void *other, CurrencyType other_type ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( money_type == other_type );
}
