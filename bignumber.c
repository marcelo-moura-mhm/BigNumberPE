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

void bignumber_free(BigNumber number) {
	BigNumber_Node p = number->head;
	while(p != NULL) {
		free(p->previous);
		p = p->next;
	}
	free(number->tail);
	free(number);
}
