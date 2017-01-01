CC = g++
CFLAGS = -Wvla -Wall -Wextra -std=c++11
DNDEBUG = -DNDEBUG

ex1: 
	$(CC) $(CFLAGS) MySet.cpp SetBinaryOperations.cpp -o ex1

tar: 
	tar cvf ex1.tar MySet.cpp MySet.h SetBinaryOperations.cpp Makefile

clean:
	rm -f ex1.tar ex1

