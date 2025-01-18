#include "bignumber.h"

int main() {
    BigNumber a = bignumber_read();
    BigNumber b = bignumber_read();
    
    bignumber_print(a);
    bignumber_print(b);
    
    bignumber_free(a);
    bignumber_free(b);
    
    return 0;
}
