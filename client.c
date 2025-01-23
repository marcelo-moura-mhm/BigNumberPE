#include "bignumber.h"
#include <stdio.h>

int main() {
	while(1) {
		BigNumber a = bignumber_read();
		BigNumber b = bignumber_read();
		
		char op = getchar();
		getchar();
		
		if(op == '+') {
			BigNumber c = bignumber_sum(a, b);
			bignumber_print(c);
			bignumber_free(c);
		} else if(op == '-') {
			BigNumber c = bignumber_minus(a, b);
			bignumber_print(c);
			bignumber_free(c);
		} else if(op == '*') {
			BigNumber c = bignumber_product(a, b);
			bignumber_print(c);
			bignumber_free(c);
		} else if(op == '/') {
			BigNumber c = bignumber_division(a, b);
			bignumber_print(c);
			bignumber_free(c);
		}
		bignumber_free(a);
		bignumber_free(b);
	}
	return 0;
}
