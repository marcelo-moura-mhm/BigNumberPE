#include "bignumber.h"

int main() {
    BigNumber a = bignumber_read();
    BigNumber b = bignumber_read();
    
    BigNumber c = bignumber_minus(a, b);
    bignumber_free(a);
    bignumber_free(b);
    
    bignumber_print(c);
    
    bignumber_free(c);
    
    return 0;
}
