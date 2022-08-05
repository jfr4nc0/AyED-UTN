#include <iostream>
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/strings.hpp"

using namespace std;

// Tema: WhatsApp. Analizador de mensajes en que detecta palabras de "riesgo"

// Problema: Desarrollar el procesamiento de los mensajes pendientes y enviar o alterar segun el caso.

// 1) Declaracion de estructuras de datos

struct InfoMensaje
{
    int idMensaje;
    int idConversacion;
    int idEmisor;
    int idReceptor;
    NodoPalabra* texto;
};

struct NodoMensaje
{
    InfoMensaje info;
    NodoMensaje* sgte;
};

struct NodoPalabra
{
    string palabra;
    NodoPalabra* sgte;
};

// Funcion: obtenerProximo
// En caso de haber msj para procesar, devuelve en m y retorna true.
// Caso contrario, retorna false y no modifica m
bool obtenerProximo(NodoMensaje& m); 

// Los mensajes sin palabras de riesgo se envian al receptor -> void Enviar(Mensaje m, int idReceptor)
// Caso contrario, se envia al emisor una alerta -> void Alertar(int idEmisor)

// Funcion: crearPilaDePalabras
// Recibe un texto y retorna una pila de las palabras del texto
NodoPalabra* crearPilaDePalabras(string texto);

// Variable global: in
// Conexion abierta a un archivo binario, contiene 1000 palabras ordenadas alfabeticamente y ascendentemente,
// longitud maxima de la palabra es N. Con esas palabras se determina si los mensajes son riesgos
// Con la variable in se accede al archivo binario y busca si alguna palabra esta incluida en el Mensaje.
FILE* in = fopen("palabras_riesgo.dat","r+b");


// TODO Funcion: esRiesgoso
// retorna true si 3 o mas palabras del texto son inapropiadas, si no , false. Invoca a "crearPilaDePalabras"

// TODO Funcion: procesarPendientes
// invoca a "obtenerProximo" hasta que no queden mensajes pendientes para procesar.
// para cada mensaje se usa "esRiesgoso" y envie o alerte segun corresponda.

// TODO Desarrollar cualquier funcion que invoque:
/* -> obtenerProximo
-> crearPilaDePalabras
-> enviar
-> alerta
-> esRiesgoso
-> procesarPendiente
 */

// Analisis de solucion: 
// Declaramos un array de palabras con longitud de 30 para que conforme un mensaje
// Ciclo de iteracion para recorrer el archivo binario por palabra y encontrar alguna en el array de palabras
// Si se encuentra una palabra de riesgo, enviar alerta al emisor. Caso contrario, enviar mensajer al receptor
// Longitud maxima de palabra es N
template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET); 
}

int stringToInt(string s)
{
   int num=0;
   int digits = length(s)-1, digito;

   for(int i=0 ; s[i]!='\0' ; i++){
      digito = charToInt((char)s[i]);
      num += (digito* pow(10,digits));
      digits--;
   }

   return num;
}

string desapilar(NodoPalabra*& p)
{
    NodoPalabra* aux = p;
    p = p->sgte;
    string v = aux->palabra;
    delete aux;
    return v;
}

void Enviar(NodoMensaje m, int idReceptor);

void Alertar(int idEmisor);

bool palabraRiesgosa(NodoPalabra* p, FILE* in) 
{
    // TODO cuerpo de la funcion
};

int esRiesgoso(NodoMensaje* mensaje)
{
    NodoPalabra* p = crearPilaDePalabras(mensaje->info.texto->palabra);
    bool riesgo = false;
    while (!isEmpty(p) && riesgo!=true)
    {
       if(!palabraRiesgosa(p))
       {
        desapilar(p);
       } 
       else
       {
        riesgo = true;
       }
    }
    return riesgo==true?1:-1;       // Retorna 1 (true), -1 (false)
};

// Asumo que existe una pila de mensajes
void procesarPendiente(NodoMensaje* p);
{
    NodoMensaje* pila_mensajes = p;
    while (!isEmpty(pila_mensajes))
    {
        if(esRiesgoso(pila_mensajes)==1)
        {
            Alertar(pila_mensajes->info.idEmisor);
            desapilar(pila_mensajes);
        }
        else if( esRiesgoso(pila_mensajes)==-1 )
        {
            Enviar(pila_mensajes->info.idReceptor);
            desapilar(pila_mensajes);
        }
        else
        {
            cout << "Error de control de riesgo, mensaje: " << pila_mensajes.top();
            desapilar(pila_mensajes);
        }
    }
    return;
};