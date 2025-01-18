cliente: client.o bignumber.o bignumber_pos_operations.o bignumber_operations.o
	gcc -std=c99 -Wall -Wextra -Wvla -g client.o bignumber.o bignumber_pos_operations.o bignumber_operations.o -o cliente
    
client.o: client.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g client.c -c
    
bignumber.o: bignumber.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g bignumber.c -c
	
bignumber_pos_operations.o: bignumber_pos_operations.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g bignumber_pos_operations.c -c
	
bignumber_operations.o: bignumber_operations.c bignumber.h
	gcc -std=c99 -Wall -Wextra -Wvla -g bignumber_operations.c -c
