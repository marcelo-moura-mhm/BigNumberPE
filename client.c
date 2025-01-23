#include "bignumber.h"
#include <stdio.h>

int main() {
    BigNumber a = bignumber_read();
    BigNumber b = bignumber_read();
    
    BigNumber c = bignumber_division(a, b);
    
    bignumber_free(a);
    bignumber_free(b);
    
    bignumber_print(c);
    
    bignumber_free(c);
    
    return 0;
}
