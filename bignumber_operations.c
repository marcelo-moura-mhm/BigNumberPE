#include "bignumber.h"

BigNumber bignumber_sum(BigNumber a, BigNumber b) {
	if (a->signal == '+' && b->signal == '+') {
		return bignumber_pos_sum(a, b);
	} else if (a->signal == '-' && b->signal == '-') {
		BigNumber c = bignumber_pos_sum(a, b);
		c->signal = '-';
		return c;
	} else if (a->signal == '+' && b->signal == '-') {
		if(is_module_less_than(a, b)) {
			BigNumber c = bignumber_pos_minus(b, a);
			c->signal = '-';
			return c;
		} else {
			return bignumber_pos_minus(a, b);
		}
	} else if (a->signal == '-' && b->signal == '+') {
		if(is_module_less_than(a, b)) {
			return bignumber_pos_minus(b, a);
		} else {
			BigNumber c = bignumber_pos_minus(a, b);
			c->signal = '-';
			return c;
		}
	}
}
