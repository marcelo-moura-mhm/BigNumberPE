#ifndef BIGNUMBER_H
#define BIGNUMBER_H

char digit_to_char(char n);

struct _bignumber_node {
    char data;
    struct _bignumber_node *next;
    struct _bignumber_node *previous;
};

typedef struct _bignumber_node *BigNumber_Node;

typedef struct _bignumber {
    BigNumber_Node head;
    BigNumber_Node tail;
    char signal;
}* BigNumber;

BigNumber_Node bignumber_node(char data);

BigNumber bignumber();
void bignumber_push_back(BigNumber number, char data);
void bignumber_push_front(BigNumber number, char data);
BigNumber bignumber_read();
void bignumber_print(BigNumber number);
void remove_left_zeros(BigNumber number);

int is_module_less_than(BigNumber a, BigNumber b);

BigNumber bignumber_pos_sum(BigNumber a, BigNumber b);
BigNumber bignumber_pos_minus(BigNumber a, BigNumber b);

BigNumber bignumber_sum(BigNumber a, BigNumber b);
BigNumber bignumber_minus(BigNumber a, BigNumber b);

void bignumber_free(BigNumber number);

#endif
