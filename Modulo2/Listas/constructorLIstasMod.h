//
// Created by neur0tik on 18/11/21.
//

#ifndef LISTAS_CONSTRUCTORLISTASMOD_H
#define LISTAS_CONSTRUCTORLISTASMOD_H

#include <iostream>
#include "nodo.h"
using namespace std;

Nodo *obtenerUltimo(Nodo *lista)
{
    while (lista && lista->sgte)
    {
        lista= lista->sgte;
    }
    return lista;
}
/* Recibe la raíz de la lista (ptro a primer nodo) */
void AgregarNodoAlFinalMod(Nodo *&lista, int x)
{
    Nodo *paux;
    if (lista)
    {
        paux= obtenerUltimo(lista);
        paux->sgte= new Nodo();
        paux= paux->sgte;
        paux->info= x;
        paux->sgte=NULL;
    }
    else//CREAR EL PRIMER NODO
    {
        lista= new Nodo();
        lista->info=x;
        lista->sgte=NULL;
    }
    return;
}

void borrarListaMod(Nodo *&lista)
{
    Nodo *anterior;
    Nodo *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
}

#endif //LISTAS_CONSTRUCTORLISTASMOD_H
