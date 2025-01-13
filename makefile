prog: client.o bignumber.o
	gcc -std=c99 -Wall -Wextra -Wvla -g client.o bignumber.o -o prog
    
client.o: client.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g client.c -c
    
bignumber.o: bignumber.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g bignumber.c -c
