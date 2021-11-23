#include <iostream>
#include "constructorLIstasMod.h"
#include "insertarOrdenado.h"
#include "PrimitivasListasSE.h"
#include "nodo.h"

using namespace std;

// Main InsertarOrdenado
/*
int main()
{
    Nodo *inicio = NULL;
    inicio= new Nodo();
    inicio->info=5;  //(*inicio).info= 5;
    inicio->sgte =NULL; //(*inicio).sgte = NULL;
    cout << "Cada nodo ocupa " << sizeof(Nodo) << "bytes" << endl;
    cout << "La info de inicio es:" << (*inicio).info << endl;
    inicio->sgte = new Nodo();
    inicio->sgte->info=27;//(*inicio->sgte).info = 27;
    inicio->sgte->sgte =NULL;
    // CREAMOS UN TERCER NODO
    Nodo *paux;
    paux= inicio->sgte;
    paux->sgte=new Nodo();
    paux = paux->sgte;
    paux->info= 32;
    paux->sgte=NULL;
    //vamos a mostrar el contenido de la lista

    insertarOrdenado(inicio,50);
    insertarOrdenado(inicio,3);
    insertarOrdenado(inicio,4);
    insertarOrdenado(inicio,30);
    cout << "Lista toda la lista:" << endl;
    listar(inicio);
    getch();
    borrarLista(inicio);
    listar(inicio);
    getch();

    return 0;
}
*/




// Main Constructor Listas Mod con Subprogramas
/*
int main()
{
    Nodo *inicio=NULL;
    Nodo *paux;
    cout << "Cada nodo ocupa " << sizeof(Nodo) << "bytes" << endl;
    AgregarNodoAlFinalMod(inicio,5);
    AgregarNodoAlFinalMod(inicio,27);
    AgregarNodoAlFinalMod(inicio,32);
    // vamos a mostrar el contenido de la lista
    cout << "Lista toda la lista:" << endl;
    paux = inicio;
    while (paux)//Es equivalente a while (paux!=NULL)
    {
        cout << "Info: " << paux->info << endl;
        cout << "Siguiente en: " << paux->sgte << endl;
        cout << "================" << endl;
        paux = paux->sgte;
    }

    borrarListaMod(inicio);
    cout << "Lista apunta a " << inicio << endl;
    getch();
    return 0;
}
*/




// Listas SE
/*
int main()
{

    NodoListaSE *milista = NULL;
    NodoListaSE *aux;
    NodoListaSE *x;
    InsertarAlFinal(milista,5);
    InsertarAlFinal(milista,8);
    InsertarAlFinal(milista,3);
    InsertarAlFinal(milista,12);
    MostrarLista(milista);
    //Probamos obtener el ultimo
    x = ObtenerUltimo(milista);
    cout << "Usando ObtenerUltimo encontramos que el ultimo dato es: " << x->info << endl;
    //Probamos buscar el elemento d
    cout << "Buscamos un 3 con BuscarNodo."<< endl;
    x = BuscarNodo(milista,3);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    //Probamos buscar un elemento que no existe
    cout << "Probamos buscar un elemento que no existe, se busca un 27." << endl;
    x = BuscarNodo(milista,27);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    cout  << "Agregamos un 9 al lado del 8" << endl;
    x = BuscarNodo(milista,8);
    if (x)
        InsertarSiguiente(x,9);
    MostrarLista(milista);
    cout << "Probamos buscar nodo anterior al que contiene 3, para luego, desde este nodo encontrado, borrar el que contiene 3" << endl;
    x = BuscarNodoAnterior(milista,BuscarNodo(milista,3));
    BorrarSiguiente(x);
    MostrarLista(milista);
    //borra toda la lista para liberar memoria
    cout << "Borramos toda la lista con borrarLista, este procedimiento se encarga de hacer delete de todos los nodos." << endl;
    borrarLista(milista);
    char c;
    cin >> c;
    return 0;
}
*/

//---------------------------------------------------------------- G U I A -------------------------------------------------------------------------------------

// Ejercicio 1 -------------------------------------------------------------------------------------------------------------------------------------------------
/*  Utilizando las funciones de ListasSE provistas en clase haga un programa que permita al usuario:
 * - Insertar un elemento ordenadamente en la lista
 * - Buscar el mayor elemento
 * - Calcular el promedio de la lista
 * */

/*
char mostrarmenu()
{
    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Ingresar un nuevo elemento" << endl;
    cout << "2 - Mostrar lista" << endl;
    cout << "3 - Buscar mayor" << endl;
    cout << "4 - Calcular promedio" << endl;
    cout << "5 - Salir" << endl;
    char opcion;
    do
    {
        cin >> opcion;
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5'));
    return opcion;
}


int main()
{
    cout << "Manejo de Listas SE" << endl; // Inicio del programa

    NodoListaSE *ListaUsuario = NULL;
    NodoListaSE *aux = NULL;
    char eleccion;
    int nro;
    do {
        eleccion = mostrarmenu();
        switch (eleccion) {
            case '1':
                cout << "Ingrese un nro" << endl;
                cin >> nro;
                insertarOrdenadoSE(ListaUsuario, nro);
                break;
            case '2':
                MostrarLista(ListaUsuario);
                break;
            case '3':
                aux = ListaUsuario;
                while (aux && aux->sgte)
                    aux = ObtenerSiguiente(aux);
                if (aux)
                    cout << "El mayor es: " << aux->info << endl;
                else
                    cout << "Lista vacía" << endl;
                break;
            case '4':
                float sum = 0, cont = 0;
                aux = ListaUsuario;
                if (!aux)
                    cout << "La lista está vacía" << endl;
                else {
                    while (aux) {
                        sum += aux->info;
                        cont++;
                        aux = ObtenerSiguiente(aux);
                    }
                    cout << "Promedio es " << sum / cont << endl;
                }
                break;

        }
    }
    while (eleccion!='5');
    return 0;
}

*/

// Ejercicio 2 -------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Realice un procedimiento o función que al recibir dos listas como parámetro, devuelva una tercer lista que concatene las mismas.
*/


int main()
{

    NodoListaSE *lista1=NULL;
    NodoListaSE *lista2=NULL;
    NodoListaSE *aux=NULL;
    int dato;

    // Agregamos nodos en la lista 1
    cout << "LISTA 1" << endl;
    cout << "Ingrese el dato a cargar o '0' para finalizar: ";
    cin >> dato;
    if(dato!=0) {
        InsertarSiguiente(lista1, dato);
        aux = ObtenerUltimo(lista1);
        do {
            cout << "Ingrese el dato a cargar o '0' para finalizar: ";
            cin >> dato;
            if(dato!=0) {
                InsertarSiguiente(aux, dato);
                aux = ObtenerUltimo(lista1);
            }
        } while (dato != 0);
        cout << "Carga de datos finalizada..." << endl;
    }

    // Ahora agregamos en la lista 2, pero usando InsertarAlFinal
    cout << "LISTA 2" << endl;
    do {
        cout << "Ingrese el dato a cargar o '0' para finalizar: ";
        cin >> dato;
        if(dato!=0) {
            InsertarAlFinal(lista2, dato);
        }
    } while (dato != 0);
    cout << "Carga de datos finalizada..." << endl;

    char tecla;
    cout << "Presione una tecla para mostrar las listas cargadas" << endl;
    cin.get(tecla);
    cout << "----------LISTA 1----------" << endl;
    MostrarLista(lista1);
    cout << "----------LISTA 2----------" << endl;
    MostrarLista(lista2);
    concatenarListas(lista1, lista2);

    return 0;
}

    /* Concatenamos redireccionando memoria */
    /*aux = ObtenerUltimo(lista1);
    aux->sgte = lista2;
    cout << "Presione una tecla para mostrar las listas concatenadas" << endl;
    cin.get(tecla);
    MostrarLista(lista1);
    cout << "Qué pasa si se cambia un valor de un nodo de la lista2?" << endl;
    cout << "Presione una tecla:" << endl;
    cin.get(tecla);
    cout << "Lista 2 (direccion primer nodo " << lista2 << "):";
    lista2->sgte->info=856;
    MostrarLista(lista2);
    cout << "Lista 1:";
    MostrarLista(lista1);
    cin.get(tecla);
    /*Este método concatenó las listas redireccionando el ultimo puntero
    de la lista 1, como todavía tenemos el puntero lista2 apuntando al que,
    originalmente era el primer nodo de la lista2, podemos desconcatenarlas:
    cout << "Desconcatena listas (presione una tecla)" << endl;
    cin.get(tecla);
    aux =lista1;
    if (aux!=NULL)
    {
        while(aux->sgte!=lista2)
        {
            aux=aux->sgte;
        }
        aux->sgte=NULL;
    }
    cout << "Lista 1 desconcatenada:" << endl;
    MostrarLista(lista1);
    cout << "Lista 2 desconcatenada:" << endl;
    MostrarLista(lista2);
    /*Concatenación de listas creando los nodos respectivos
    NodoListaSE *lista3 = NULL;
    cout << "Lista 3 concatenada nuevamente pero con nodos propios:" << endl;
    aux=lista1;
    while (aux!=NULL)
    {
        InsertarAlFinal(lista3,aux->info);
        aux=aux->sgte;
    }
    aux=lista2;
    while (aux!=NULL)
    {
        InsertarAlFinal(lista3,aux->info);
        aux=aux->sgte;
    }
    cout << "lista 3: ";
    MostrarLista(lista3);
    cin.get(tecla);
    */

//---------------------------------- EJERCICIO 4 ----------------------------
//Realice un programa que lea de un archivo datos de alumnos de un curso. A medida
//que el archivo se va leyendo va insertando los registros en una lista. Liste finalmente
//todos los nodos para verificar que la operación fue exitosa.