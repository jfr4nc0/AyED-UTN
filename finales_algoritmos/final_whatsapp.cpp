#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "principal_template.hpp"
#include "final_whatsapp.hpp"
using namespace std;



int main()
{
    NodoConversacion* lc = new NodoConversacion();
    NodoUsuario* lu = new NodoUsuario();
    string msj;
    int id_conver;
    string res;
    cout << "Procesamiento de mensajes nuevos (Final UTN)" << endl;
    do
    {
        cout << "Ingrese el ID de la conversacion que desea enviar un mensaje: " << endl;
        cin >> id_conver;
        cout << "Ingrese un mensaje (maximo 50 caracteres): " << endl << endl;
        cin >> msj;
        losMensajesRecibidos(lc,lu,id_conver,msj); // TODO iniciar lista 
        cout << "Desea agregar otro mensaje? S (si), N (no)" << endl;
        cin >> res;
    } while (res=="S");
    
    if(res=="N")
    {
        mostrarMensajesRecibidos(lc);
    }
    else
    {
        cout << "Opcion invalida." << endl;
    }

    return 0;
}




#endif