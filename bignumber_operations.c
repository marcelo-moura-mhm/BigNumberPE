#include "bignumber.h"
#include <stdlib.h>

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
	} else {
		if(is_module_less_than(a, b)) {
			return bignumber_pos_minus(b, a);
		} else {
			BigNumber c = bignumber_pos_minus(a, b);
			c->signal = '-';
			return c;
		}
	}
}

BigNumber bignumber_minus(BigNumber a, BigNumber b) {
	if (a->signal == '+' && b->signal == '+') {
		if(is_module_less_than(a, b)) {
			BigNumber c = bignumber_pos_minus(b, a);
			c->signal = '-';
			return c;
		} else {
			return bignumber_pos_minus(a, b);
		}
	} else if (a->signal == '-' && b->signal == '-') {
		if(is_module_less_than(a, b)) {
			return bignumber_pos_minus(b, a);
		} else {
			BigNumber c = bignumber_pos_minus(a, b);
			c->signal = '-';
			return c;
		}
	} else if (a->signal == '+' && b->signal == '-') {
		return bignumber_pos_sum(a, b);
	} else {
		BigNumber c = bignumber_pos_sum(a, b);
		c->signal = '-';
		return c;
	}
}

BigNumber bignumber_product(BigNumber a, BigNumber b) {
	if((a->signal == '+' && b->signal == '+') || (a->signal == '-' && b->signal == '-')) {
		return bignumber_pos_product(a->head, b->head);
	} else {
		BigNumber c = bignumber_pos_product(a->head, b->head);
		c->signal = '-';
		return c;
	}
}

BigNumber bignumber_division(BigNumber a, BigNumber b) {
	BigNumber c = bignumber_copy(a);
	BigNumber d = bignumber_copy(b);
	
	BigNumber res;
	
	if((a->signal == '+' && b->signal == '+') || (a->signal == '-' && b->signal == '-')) {
		res = bignumber_pos_slow_division(c, d);
	} else {
		res = bignumber_pos_slow_division(c, d);
		res->signal = '-';
	}
	free(c);
	free(d);
	return res;
}
