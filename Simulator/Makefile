#Copilation
CC       := g++

#Output and test
FOLDER   := ../examples
EXEC     := $(FOLDER)/simulator

#Files
SRC      := $(wildcard *.cpp) $(wildcard View/*.cpp)
OBJ      := $(SRC:.cpp=.o)
HEADER   := $(wildcard *.hpp) $(wildcard View/*.hpp)

#If you want to optimize the compilation
#CEXTRA   := -O3 -march=native 
#CEXTRA   := -fsanitize=address -g

#Flags
LIBS     := -lglut -lGLU -lGL 
CFLAGS   := -Wall -std=c++17  $(CEXTRA) $(LIBS)
RMFLAGS  := -f -v

.PHONY: all compile clean

#Actions
all: $(EXEC)

compile: clean $(EXEC)

clean:
	rm $(OBJ) $(RMFLAGS)
	rm $(EXEC) $(RMFLAGS)

test: compile
	./$(EXEC) example.bin

#Compile
$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
