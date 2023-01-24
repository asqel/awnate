#ifndef MATRIX_H
#define MATRIX_H


#include <math.h>
#include <stdlib.h>

typedef struct matrix{
    int collumn;
    int row;
    float**value;
}matrix;


//create a new matrix 
//recreate a new array in the matrix
//so you can free the **value passe in arguments
matrix new_matrix(int collumn,int row,float**value);

typedef  struct vector{
    float x;
    float y;
    float z;
}vector;

typedef  struct polar_vector{
    float r;
    float th;
    float ph;
}polar_vector;



vector new_vector(float x,float y,float z);

vector from_polar(polar_vector v);
int sgn(float x);


float Q_rsqrt(float x);
polar_vector to_polar(vector v);

#endif