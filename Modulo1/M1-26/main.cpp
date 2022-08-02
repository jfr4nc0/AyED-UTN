#include <iostream>
#include "contenedor.h"

using namespace std;

int main()
{
    // Ingreso de datos de contenedores
    cout << "Sistema de Buque de contenedores" << endl;

    Contenedor buque[3]; // Como caso de prueba se utilizan 10 contenedores en vez de 100
    for (int posicion=0;posicion<3;posicion++)
    {
        cout << "Cargar datos del Contenedor #" << posicion+1 << endl;
        cout << "Id: ";
        cin >> buque[posicion].id;
        cout << "Peso: ";
        cin >> buque[posicion].peso;
        cout << "Puerto (1, 2 o 3): ";
        cin >> buque[posicion].puerto;
    }
    // Mostrar datos del contenedor
    for (int posicion=0;posicion<3;posicion++)
    {
        int id = buque[posicion].id;
        int peso = buque[posicion].peso;
        int puerto = buque[posicion].puerto;
        cout << "\nContenedor #"<< posicion <<":\nID = "<< id <<"\nPeso = " << peso << "\nPuerto = " << puerto << endl;
        cout << "\n----------------------------" << endl;
    }

    // Suma total de los contenedores
    int sum=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        int peso = buque[posicion].peso;
        sum+=peso;
    }
    cout << "\n\nLa sumatoria de pesos de los 10 contenedores es: " << sum << endl;


    // Contenedor de mayor peso
    int idMayor=0,pesoMayor=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        int peso = buque[posicion].peso;
        int id = buque[posicion].id;
        if(peso>pesoMayor) {
            pesoMayor = peso;
            idMayor = id;
        }
    }
    cout << "El contenedor de mayor peso es el #" << idMayor << endl;

    //Puerto 1
    int cantPuerto1=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        if(buque[posicion].puerto==1)
            cantPuerto1++;
    }


    //Puerto 2
    int cantPuerto2=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        if(buque[posicion].puerto==2)
            cantPuerto2++;
    }

    //Puerto 3
    int cantPuerto3=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        if(buque[posicion].puerto==3)
            cantPuerto3++;
    }

    //Puerto sin asignacion
    int cantPuertoX=0;
    for (int posicion=0;posicion<3;posicion++)
    {
        if(buque[posicion].puerto!=1 && buque[posicion].puerto!=2 && buque[posicion].puerto!=3 )
            cantPuertoX++;
    }

    cout << "Cantidad de contenedores que debe trasladar a cada puerto" << endl;
    cout << "Puerto 1: " << cantPuerto1 << "\nPuerto 2: " << cantPuerto2 << "\nPuerto 3: " << cantPuerto3 << endl;
    cout << "Puertos fuera de rango: " << cantPuertoX << endl;

    return 0;
}