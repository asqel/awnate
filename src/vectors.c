#include "vectors.h"
#include <math.h>
vec3_t rotateY(vec3_t point, double angle) {
    double cosA = cos(angle);
    double sinA = sin(angle);
    return (vec3_t){
        .x = point.x * cosA - point.z * sinA,
        .y = point.y,
        .z = point.x * sinA + point.z * cosA};
}

vec3_t rotateX(vec3_t point, double angle) {
    double cosA = cos(angle);
    double sinA = sin(angle);
    return (vec3_t){
        .x = point.x,
        .y = point.y * cosA - point.z * sinA,
        .z = point.y * sinA + point.z * cosA};
}