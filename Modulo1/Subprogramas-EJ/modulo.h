//
// Created by neur0tik on 9/11/21.
//

#ifndef SUBPROGRAMAS_EJ_MODULO_H
#define SUBPROGRAMAS_EJ_MODULO_H
#include "iostream"

using namespace std;

float modulo(float n)
{
    if (n < 0) { n *= -1; }
    return n;
}

void moduloVoid(float &n)
{
    if (n < 0) { n *= -1; }
    return;

}
#endif //SUBPROGRAMAS_EJ_MODULO_H
