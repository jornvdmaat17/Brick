CC = g++
# CFLAGS = -pthread
DEPS = Brick/Brick.h Brick/EntryPoint.h src/Application.h src.ApplicationWindows.h
OBJ = App/App.cpp Brick/src/*.cpp

program : $(OBJ)
	$(CC) -o  $@ $^ $(DEPS) 
# $(CFLAGS)

stdafx : 
	$(CC) -c Brick/stdafx.h -o stdafx.h.gch