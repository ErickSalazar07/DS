CPPFLAGS = -std=c++11 -Wall -Werror # These are the flags for the .cpp files, and you can add more
CFLAGS = -std=c11 -Wall -Werror # These are the flags for the .c files, and you can add more
CPPCOMP = g++ $(CPPFLAGS)
CCOMP = gcc $(CFLAGS)

all: 
	@printf "\nNot defined\n"

compile_test_c: test/test.c C/List/ListSim.c
	@$(CCOMP) -o main test/test.c C/List/ListSim.c

clean:
	@printf "\nNot defined\n"
