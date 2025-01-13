#ifndef BIGNUMBER_H
#define BIGNUMBER_H

typedef struct _bignumber_node* BNNode;
typedef struct _bignumber* BigNumber;

BNNode bignumber_node(char data);

BigNumber bignumber_read();
BigNumber bignumber_print(BigNumber number);

#endif
