
#include <math.h>
#include "matrix.h"
#include <stdlib.h>

//create a new matrix 
//recreate a new array in the matrix
//so you can free the **value passe in arguments
matrix new_matrix(int collumn,int row,float**value){
    matrix x;
    x.row=row;
    x.collumn=collumn;
    x.value=malloc(sizeof(float[collumn])*row);
    for(int i=0;i<row;i++){
        for(int k=0;k<collumn;k++){
            x.value[i][k]=value[i][k];
        }
    }
    return x;
}




vector new_vector(float x,float y,float z){
    return (vector){x,y,z};
}

vector from_polar(polar_vector v){
    return (vector){
        v.r*sin(v.th)*cos(v.ph),
        v.r*sin(v.th)*sin(v.ph),
        v.r*cos(v.th)};
}
int sgn(float x){
    if(x){
        return x>0?1:-1;
    }
    return 0;
}


float Q_rsqrt(float x){
    long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2=x*0.5F;
	y=x;
	i=*(long*)&y;                    
	i=0x5f3759df-(i>>1);                
	y=*(float*)&i;
	y=y*(threehalfs-(x2*y*y));
	return y;
}
polar_vector to_polar(vector v){
    float o=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
    return (polar_vector){
        sqrt(v.x*v.x+v.y*v.y+v.z*v.z),
        acos(v.z*Q_rsqrt(v.x*v.x+v.y*v.y+v.z*v.z)),
        sgn(v.x)*acos(v.x*Q_rsqrt(v.x*v.x+v.y*v.y))
    };
}

