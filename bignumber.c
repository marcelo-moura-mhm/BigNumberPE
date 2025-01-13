#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

struct _bignumber_node {
    char data;
    BNNode next;
    BNNode previous;
};

struct _bignumber {
    BNNode head;
    BNNode tail;
};

BNNode bignumber_node(char data) {
    BNNode node = malloc(sizeof(struct _bignumber_node));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

BigNumber bignumber() {
    BigNumber number = malloc(sizeof(struct _bignumber));
    number->head = NULL;
    number->tail = NULL;
    return number;
}

void bignumber_push_front(BigNumber number, char data) {
    BNNode new = bignumber_node(data);
    if(number->tail == NULL) {
        number->tail = new;
        number->head = new;
    } else {
        number->head->previous = new;
        number->head->previous->next = number->head;
        number->head = number->head->previous;
    }
}

BigNumber bignumber_read() {
    BigNumber number = bignumber();
    char next_digit = getchar();
    while(next_digit != '\n') {
        bignumber_push_front(number, next_digit);
        next_digit = getchar();
    }
    return number;
}

void bignumber_print(BigNumber number) {
    BNNode digit = number->tail;
    while(digit != NULL) {
        printf("%c", digit->data);
        digit = digit->previous;
    }
    printf("\n");
}
