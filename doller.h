typedef struct {
  unsigned int amount;
} Doller;


Doller *create_doller( unsigned int amount );
void multiply( Doller **doller, unsigned int multiplier );
