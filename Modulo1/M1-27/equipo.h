//
// Created by neur0tik on 6/11/21.
//

#ifndef M1_27_EQUIPO_H
#define M1_27_EQUIPO_H
#include <iostream>
using namespace std;

struct Equipo
{
    int nro;
    int cod;
};

bool comprobarCod(char c)
{
    bool ret = false;
    if (c == 'P' || c == 'E' || c == 'G')
        ret = true;
    return ret;
}

int cargarCod(char c)
{
    int ret=0;
    switch (c)
    {
        case 'P':
            ret = 1;
            break;
        case 'E':
            break;
        case 'G':
            ret = 3;
            break;
        default:
            break;
    }
    return ret;
}


#endif //M1_27_EQUIPO_H
