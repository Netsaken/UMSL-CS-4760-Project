CC = g++
CFLAGS = -g -Wshadow -std=c++11
DEPS = simplechain.c
OBJ = simplechain.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

chain: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	/bin/rm -f *.o $(TARGET)