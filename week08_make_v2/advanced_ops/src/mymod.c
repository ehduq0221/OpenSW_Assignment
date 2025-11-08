#include "advanced_ops.h"
#include <stdio.h>
#include <math.h>

double mymod(double a, double b){
    double result;

    result = fmod(a,b);

    return result;
}