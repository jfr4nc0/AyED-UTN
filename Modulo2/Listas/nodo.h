//
// Created by neur0tik on 18/11/21.
//

#ifndef LISTAS_NODO_H
#define LISTAS_NODO_H
#include "iostream"

using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};

#endif //LISTAS_NODO_H
