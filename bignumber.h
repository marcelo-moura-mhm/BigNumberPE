#ifndef BIGNUMBER_H
#define BIGNUMBER_H

char digit_to_char(char n);

typedef struct _bignumber_node* BigNumber_Node;
typedef struct _bignumber* BigNumber;

BigNumber_Node bignumber_node(char data);

BigNumber bignumber();
void bignumber_push_front(BigNumber number, char data);
BigNumber bignumber_read();
void bignumber_print(BigNumber number);

BigNumber bignumber_sum(BigNumber a, BigNumber b);

void bignumber_free(BigNumber number);

#endif
