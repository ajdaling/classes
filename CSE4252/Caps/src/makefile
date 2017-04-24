SHELL=/bin/sh


OBJS = Capitals.o Game.o User.o UserDB.o UI.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
SRCS = Capitals.cpp Game.cpp User.cpp UserDB.cpp UI.cpp

caps.x : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o caps.x
	
Capitals.o : Capitals.cpp
	$(CC) $(CFLAGS) Capitals.cpp
	
Game.o : Game.h Game.cpp User.h UserDB.h
	$(CC) $(CFLAGS) Game.cpp
	
User.o : User.h User.cpp
	$(CC) $(CFLAGS) User.cpp
	
UserDB.o : UserDB.h UserDB.cpp User.h
	$(CC) $(CFLAGS) UserDB.cpp
	
UI.o : UI.h UI.cpp Game.h UserDB.h
	$(CC) $(CFLAGS) UI.cpp
	
clean:
	\rm *.o caps.x
	

