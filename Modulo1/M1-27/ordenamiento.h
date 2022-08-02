//
// Created by neur0tik on 6/11/21.
//

#ifndef M1_27_ORDENAMIENTO_H
#define M1_27_ORDENAMIENTO_H
#include "equipo.h"

/*Ordenamiento por burbujeo mejorado,
Considera las posiciones vacías al final
*/
void burbuja(Equipo v[], int k)
{
    Equipo aux;
    for (int i = 1; i < k ; i++)
    {
        for (int j = 0; j < k-i; j++)
        {
            if (v[j].nro > v[j+1].nro)
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    return;
}


#endif //M1_27_ORDENAMIENTO_H
