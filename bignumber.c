#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

char digit_to_char(char n) {
	return n+'0';
}

struct _bignumber_node {
    char data;
    BigNumber_Node next;
    BigNumber_Node previous;
};

struct _bignumber {
    BigNumber_Node head;
    BigNumber_Node tail;
    char signal;
};

BigNumber_Node bignumber_node(char data) {
    BigNumber_Node node = malloc(sizeof(struct _bignumber_node));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

BigNumber bignumber() {
    BigNumber number = malloc(sizeof(struct _bignumber));
    number->head = NULL;
    number->tail = NULL;
    number->signal = '+';
    return number;
}

void bignumber_push_front(BigNumber number, char data) {
    BigNumber_Node new = bignumber_node(data);
    if(number->tail == NULL) {
        number->tail = new;
        number->head = new;
    } else {
        number->head->previous = new;
        new->next = number->head;
        number->head = number->head->previous;
    }
}

void bignumber_push_back(BigNumber number, char data) {
	BigNumber_Node new = bignumber_node(data);
	if(number->head == NULL) {
		number->head = new;
		number->tail = new; 
	} else {
		number->tail->next = new;
		new->previous = number->tail;
		number->tail = number->tail->next;
	}
}

BigNumber bignumber_read() {
    BigNumber number = bignumber();
    char next_digit = getchar();
    if(next_digit == '+') {
    	number->signal = '+';
    	next_digit = getchar();
    } else if (next_digit == '-') {
    	number ->signal = '-';
    	next_digit = getchar();
    }
    while(next_digit != '\n') {
        bignumber_push_front(number, next_digit);
        next_digit = getchar();
    }
    return number;
}

void bignumber_print(BigNumber number) {

	if(number->signal == '-') {
		printf("%c", '-');
	}	
    BigNumber_Node digit = number->tail;
    while(digit != NULL) {
        printf("%c", digit->data);
        digit = digit->previous;
    }
    printf("\n");
}

void remove_left_zeros(BigNumber number) {
	BigNumber_Node digit = number->tail;
	while(digit->data == '0' && digit->previous != NULL) {
		digit = digit->previous;
		number->tail = digit;
		free(digit->next);
		digit->next = NULL;
	}
}

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

void bignumber_free(BigNumber number) {
	BigNumber_Node p = number->head;
	while(p != NULL) {
		free(p->previous);
		p = p->next;
	}
	free(number->tail);
	free(number);
}
