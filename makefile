FLAGS = -std=c++11 -Werror -o main # These are the flags for the .cpp files, and you can add more
COMP = g++ $(FLAGS)

all: compile

compile: main.cpp 
	@echo "Compilacion exitosa"
	@$(COMP) main.cpp 

clean:
	@echo "Se removieron los archivos"
	@rm main
