CC = g++
# CFLAGS = -pthread
DEPS = Brick/Brick.h Brick/src/*.h
OBJ = App/App.cpp Brick/src/*.cpp

program : $(OBJ)
	$(CC) -o  $@ $^ $(DEPS) 
# $(CFLAGS)