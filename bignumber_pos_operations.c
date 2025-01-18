#include "bignumber.h"
#include <stddef.h>

BigNumber bignumber_pos_sum(BigNumber a, BigNumber b) {
	BigNumber c = bignumber();
	BigNumber_Node digit_a = a->head;
	BigNumber_Node digit_b = b->head;
	
	char carry = 0;
	
	while(digit_a != NULL || digit_b != NULL) {
	
		char sum_digits;
		
		//Nunca serão os dois NULL
		if(digit_a == NULL) {
			sum_digits = digit_b->data - '0';
		} else if(digit_b == NULL) {
			sum_digits = digit_a->data - '0';
		} else {
			sum_digits = digit_a->data - '0' + digit_b->data - '0';
		}
	
		bignumber_push_back(c, digit_to_char((sum_digits + carry)%10));
		
		carry = (sum_digits + carry)/10;
		
		if(digit_a != NULL)
			digit_a = digit_a->next;
		if(digit_b != NULL)
			digit_b = digit_b->next;
	}
	
	if(carry != 0) {
		bignumber_push_back(c, digit_to_char(carry));
	}
	
	return c;
}

BigNumber bignumber_pos_minus(BigNumber a, BigNumber b) {
	BigNumber c = bignumber();
	BigNumber_Node digit_a = a->head;
	BigNumber_Node digit_b = b->head;
	
	char carry = 0;
	while(digit_a != NULL || digit_b != NULL) {
		if(!digit_b) {
			if(digit_a->data == '0') {
				if(carry == 1) {
					bignumber_push_back(c, '9');
				} else {
					bignumber_push_back(c, '0');
				}
			} else {
			bignumber_push_back(c, digit_a->data - carry);
			carry = 0;
			}
		} else if(digit_a->data - carry >= digit_b->data) {
			bignumber_push_back(c, digit_to_char(digit_a->data - carry - digit_b->data));
			carry = 0;
		} else {
			bignumber_push_back(c, digit_to_char(digit_a->data+10 - carry - digit_b->data));
			carry = 1;
		}
		if(digit_a != NULL)
			digit_a = digit_a->next;
		if(digit_b != NULL)
			digit_b = digit_b->next;
	}
	
	remove_left_zeros(c);
	
	return c;
}
