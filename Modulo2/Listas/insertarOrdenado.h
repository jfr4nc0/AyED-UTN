//
// Created by neur0tik on 18/11/21.
//

#ifndef LISTAS_INSERTARORDENADO_H
#define LISTAS_INSERTARORDENADO_H

#include <iostream>
#include "nodo.h"
using namespace std;

void insertarOrdenado(Nodo *&lista, int ainsertar)
{
    Nodo *paux = lista;
    Nodo *anterior =NULL;
    while (paux && paux->info < ainsertar)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if ( paux!= lista)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;

    }
    else
    {
        lista= new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }
    return;
}

void borrarLista(Nodo *&inicio)
{
    Nodo *paux;
    // borra de adelante hacia atras
    while (inicio)
    {
        paux = inicio;
        if (paux->sgte != NULL)
        {
            inicio = inicio-> sgte;
            delete paux;
        }
        else
        {
            delete inicio;
            inicio = NULL;
        }
    }
    return;
}

void listar(Nodo *paux)
{
    while (paux)//Es equivalente a while (paux!=NULL)
    {
        cout << "Direccion del nodo: " << paux << endl;
        cout << "Info: " << paux->info << endl;
        cout << "Siguiente en: " << paux->sgte << endl;
        cout << "================" << endl;
        paux = paux->sgte;
    }
    return;
}

#endif //LISTAS_INSERTARORDENADO_H
