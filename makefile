CC=gcc  #compiler
TARGET=main #target file name
 
all:
    $(CC) main.c cube.c matrix.c 2dscreen.c -o $(TARGET)
 
clean:
    rm $(TARGET)