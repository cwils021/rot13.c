all: rot13
	
rot13: rot13.o functions.o	
	gcc -Wall -o rot13 rot13.o functions.o

rot13.o: rot13.c functions.h
	gcc -Wall -c rot13.c functions.h

functions.o: functions.c functions.h
	gcc -Wall -c functions.c functions.h

clean:
	rm rot13 *.gch *.o