#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>

struct _bignumber_node {
    char data;
    BNNode next;
    BNNode previous;
}

struct _bignumber {
    BNNode head;
    BNNode tail;
}

BNNode bignumber_node(char data) {
    BNNode node = malloc(sizeof(struct _bignumber_node));
    node->next = NULL;
    node->previous = NULL;
    return node;
}
