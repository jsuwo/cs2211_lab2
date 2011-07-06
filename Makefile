DEPENDENCIES=main.c inventory.o input_helper.o
BIN=main
CFLAGS=-c
LFLAGS=-o
CC=gcc

part1: $(DEPENDENCIES)
	$(CC) $(LFLAGS) $(BIN) $^ 

part2: $(DEPENDENCIES)
	$(CC)	-DPART2 $(LFLAGS) $(BIN) $^

part3: $(DEPENDENCIES)
	$(CC)	-DPART2 -DPART3 $(LFLAGS) $(BIN) $^

part4: $(DEPENDENCIES)
	$(CC)	-DPART2 -DPART3 -DPART4 $(LFLAGS) $(BIN) $^

part5: $(DEPENDENCIES)
	$(CC) -DPART2 -DPART3 -DPART4 -DPART5 $(LFLAGS) $(BIN) $^

part6: $(DEPENDENCIES)
	$(CC) -DPART2 -DPART3 -DPART4 -DPART5 -DPART6 $(LFLAGS) $(BIN) $^

part7: $(DEPENDENCIES)
	$(CC) -DPART2 -DPART3 -DPART4 -DPART5 -DPART6 -DPART7 $(LFLAGS) $(BIN) $^

%.o: %.c %.h
	$(CC) $(CFLAGS) $<

realclean: clean
	rm -f $(BIN) 

clean:	
	rm -f *.o
