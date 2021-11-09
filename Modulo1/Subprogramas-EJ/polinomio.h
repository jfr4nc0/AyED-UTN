//
// Created by neur0tik on 9/11/21.
//

#ifndef SUBPROGRAMAS_EJ_POLINOMIO_H
#define SUBPROGRAMAS_EJ_POLINOMIO_H
#include "iostream"
#include "string"
#include "math.h"

using namespace std;

bool cuadratica(float a,float b,float c)
{
    if((b*b-4*a*c) >= 0) return true;
    return false;
}

string raicesPolinomioGrado2(float a, float b, float c, float &r1, float &r2)
{
    string error = "No se pudo encontrar raices.";
    if(!cuadratica(a,b,c)) return error;
    r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    string ret;
    ret = to_string(r1) + " y " + to_string(r2);
    return ret;
}


#endif //SUBPROGRAMAS_EJ_POLINOMIO_H
