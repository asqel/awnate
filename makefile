SRCS = $(wildcard libs/*.c src/*.c) main.c
OBJ = $(SRCS:.c=.o)
RM = rm -rf
MKDIR = mkdir -p
#check if windows
ifeq ($(OS),Windows_NT)
	RM = powershell -NoProfile -Command rm -r -force
	MKDIR = powershell -NoProfile -Command mkdir -Force
endif

all: $(OBJ)
	gcc $(OBJ) -o main -lSDL2 -lm -fopenmp -std=c99

%.o: %.c
	gcc -c $< -o $@ -Iinclude -DSDL_MAIN_HANDLED

run: main
	./main

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) main
