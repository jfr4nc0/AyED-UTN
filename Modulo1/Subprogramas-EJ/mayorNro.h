//
// Created by neur0tik on 9/11/21.
//

#ifndef SUBPROGRAMAS_EJ_MAYORNRO_H
#define SUBPROGRAMAS_EJ_MAYORNRO_H
#include "iostream"

using namespace std;

void mayorNro(float n1,float n2,float &mayor)
{
    if(n1>n2) mayor=n1;
    else if (n1<n2) mayor=n2;
    else mayor=0;
    return;
}



#endif //SUBPROGRAMAS_EJ_MAYORNRO_H
