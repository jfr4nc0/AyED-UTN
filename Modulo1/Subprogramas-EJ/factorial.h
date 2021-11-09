//
// Created by neur0tik on 9/11/21.
//

#ifndef SUBPROGRAMAS_EJ_FACTORIAL_H
#define SUBPROGRAMAS_EJ_FACTORIAL_H

long factorialRecursivo(short n)
{
    if(n<=1) {return 1;}
    return n*factorialRecursivo(n-1);
}

#endif //SUBPROGRAMAS_EJ_FACTORIAL_H
