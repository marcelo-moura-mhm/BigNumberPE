#include "bignumber.h"

int main() {
    BigNumber a = bignumber_read();
    BigNumber b = bignumber_read();
    
    BigNumber c = bignumber_sum(a, b);
    bignumber_print(c);
    
    return 0;
}
