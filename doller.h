typedef struct {
  unsigned int amount;
} Doller;


Doller *create_doller( unsigned int amount );
Doller *multiply( const Doller *doller, unsigned int multiplier );
