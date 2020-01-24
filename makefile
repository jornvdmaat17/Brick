CC = g++
<<<<<<< HEAD
# CFLAGS = -pthread
DEPS = Brick/Brick.h Brick/src/*.h
OBJ = App/App.cpp Brick/src/*.cpp

program : $(OBJ)
	$(CC) -o  $@ $^ $(DEPS) 
# $(CFLAGS)
=======
CFLAGS = -lglfw -lGL -lm -lX11 -pthread -lXrandr -ldl
DEPS = Brick/Brick.h Brick/src/EntryPoint.h Brick/src/Application.h Brick/src/ApplicationWindows.h 
OBJ = App/App.cpp Brick/src/*.cpp

program : $(OBJ)
	$(CC) -o  $@ $^ $(DEPS) $(CFLAGS)

stdafx : 
	$(CC) -c Brick/stdafx.h -o stdafx.h.gch
>>>>>>> 025627b... event dispathcer done
