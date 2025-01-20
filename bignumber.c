#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

char digit_to_char(char n) {
	return n+'0';
}

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
	if(number->signal == '-' && number->tail->data != '0') { //evita imprimir -0
		printf("%c", '-');
	}	
    BigNumber_Node digit = number->tail;
    while(digit != NULL) {
        printf("%c", digit->data);
        digit = digit->previous;
    }
    printf("\n");
}

int is_module_less_than(BigNumber a, BigNumber b) {
	BigNumber_Node digit_a = a->head;
	BigNumber_Node digit_b = b->head;
	
	while(digit_a != NULL || digit_b != NULL) {
		if(!digit_a) {
			return 1;
		}
		if(!digit_b) {
			return 0;
		}
		digit_a = digit_a->next;
		digit_b = digit_b->next;
	}
	
	digit_a = a->tail;
	digit_b = b->tail;
	
	while(digit_a != NULL) {
		if(digit_a->data < digit_b->data) {
			return 1;
		} else if(digit_a->data > digit_b->data) {
			return 0;
		}
		digit_a = digit_a->previous;
		digit_b = digit_b->previous;
	}
	return 0; //são iguais
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

void bignumber_free(BigNumber number) {
	BigNumber_Node p = number->head;
	while(p != NULL) {
		free(p->previous);
		p = p->next;
	}
	free(number->tail);
	free(number);
}
