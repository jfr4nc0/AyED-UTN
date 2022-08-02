//
// Created by neur0tik on 9/11/21.
//

#ifndef SUBPROGRAMAS_EJ_MENU_H
#define SUBPROGRAMAS_EJ_MENU_H
#include "iostream"
#include "string"
using namespace std;

void menu(float n1,float n2,float &ret) {
    char opcion;
    string exit = "Menu finalizado.";
    cout << "Menu de seleccion:\na - Sumar los numeros\nb - Restar los numeros\nc - Multiplicarlos"
            "\nd - Realizar la division n1/n2\nOpcion: ";
    cin >> opcion;
    switch (opcion) {
        case 'a':
            ret = n1 + n2;
            break;
        case 'b':
            ret = n1 - n2;
            break;
        case 'c':
            ret = n1 * n2;
            break;
        case 'd':
            ret = n1 / n2;
            break;
        default:
            cout << "Opcion invalida. Menu finalizado. ";
            return;
    } cout << "---------------------\n" << ret << "\n---------------------\n" << exit;
    return;
}

#endif //SUBPROGRAMAS_EJ_MENU_H
