




all:#ca marche
	gcc main.c libs/*.c -o main -lmingw32 -lSDL2main -lSDL2
	./main


clean:#ca marcche pas 
	rm -f main.exe
