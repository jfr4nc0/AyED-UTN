//
// Created by neur0tik on 9/11/21.
//
#ifndef M1_26_CONTENEDOR_H
#define M1_26_CONTENEDOR_H

#include <iostream>
using namespace std;


struct Contenedor // Cant de Contenedores: 100
{
    int id;
    int peso; // en Kg
    int puerto; // Cant de Puertos: 3
};
void cargarDatosContenedor(int id, int peso, int puerto)
{
    Contenedor c;
    c.id = id;
    c.peso = peso;
    c.puerto = puerto;
}

bool comprobarPuerto(int p)
{
    bool ret=true;
    if(p>3 || p<1) ret=false;
    return ret;
}

int cargarPuerto(int p)
{
    if (!comprobarPuerto(p)) {
        cout << "Error: Nro de Puerto invalido\nOpciones de puerto validas (1, 2 o 3): ";
        cin >> p;
        cargarPuerto(p);
    }
    return p;
}

#endif //M1_26_CONTENEDOR_H