#Build Lib and Sandbox
FLAGS = -Wall -std=c++20

FILES = $(wildcard Source/Math/*.cpp)  $(wildcard CMate-Core/Source/*.cpp) $(wildcard CMate-Core/Source/Math/*.cpp)  
FILES_OBJ = $(FILES:.cpp=.o)

FILES_SANDBOX = Sandbox.cpp  
FILES_OBJ_SANDBOX = Sandbox.o

ALL = LIB SANDBOX

LIB = cmate-core-game-extended.o
SANDBOX = Sandbox

lib: $(LIB)

$(LIB): $(FILES_OBJ)
		ar rcs $@ $^


Sandbox: $(SANDBOX)

$(SANDBOX): $(FILES_OBJ_SANDBOX) $(LIB)
		g++ $(FLAGS) -o $(SANDBOX) $(FILES_OBJ_SANDBOX) $(LIB)

%.o: %.cpp
		g++ $(FLAGS) -c $< -o $@

clean:
		rm $(LIB) $(FILES_OBJ) $(SANDBOX) 
