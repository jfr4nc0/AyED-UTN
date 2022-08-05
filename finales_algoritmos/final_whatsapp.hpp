#include <iostream>
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/strings.hpp"
#include <chrono>
#include <ctime>
using namespace std;

struct InfoMensaje
{
    int fecha; // AAMMDDHHMM
    int idMensaje;
    bool leido;
    string mensaje;
};

struct NodoMensaje
{
    InfoMensaje info;
    NodoMensaje* sgte;
};

struct InfoConversacion
{
    int idConversacion;
    int idEmisor;
    int idReceptor;
    int fecha; // AAMMDDHHMM
    NodoMensaje* losMensajesRecibidos;
    NodoMensaje* losMensajesEnviados;
};

struct NodoConversacion
{
    InfoConversacion info;
    NodoConversacion* sgte;
};

struct infoUsuario
{
    int idUsuario;
    bool recibido;
    bool entregado;
    string otrosDatos;
};

struct NodoUsuario
{
    infoUsuario info;
    NodoUsuario* sgte;
};


void eliminarNodo(NodoConversacion*& p, int v)
{
   NodoConversacion* aux=p;
   NodoConversacion* ant=NULL;

   while( aux!=NULL && aux->info.idConversacion!=v)
   {
      ant=aux;
      aux=aux->sgte;
   }

   if( ant==NULL )
   {
      p=aux->sgte;
   }
   else if( aux == NULL )
   {
     aux = NULL;
   }
   else
   {
      ant->sgte = aux->sgte;  
   }
   delete aux;
};

NodoUsuario* buscarEnListaUsuario(NodoUsuario* q, int w)
{
    NodoUsuario* aux = q;
    NodoConversacion* p;
    p->info.idEmisor = w;
    int id_emisor = p->info.idEmisor;
    while( aux!=NULL && id_emisor!=w )
    {
        aux = aux->sgte;
    }

    return aux;
};


int fechaToEntero()
{
    time_t t = time(0);
    string f = ctime(&t);
    int fecha = stringToInt(f);
    return fecha;
};

NodoMensaje* buscarEnListaMensaje(NodoMensaje* p, int v)
{
    NodoMensaje* aux = p;
    while ( aux!=NULL && aux->info.idMensaje!=v)
    {
        aux = aux->sgte;
    }
    
    return aux;
};

int numeroMensaje(int p)
{
    NodoMensaje* w = new NodoMensaje();
    w->info.idMensaje = p;
    int q = 0;
    if ( buscarEnListaMensaje(w,q) == NULL )
    {
        w->info.idMensaje = q;
    }
    else
    {
        w->info.idMensaje = q+1;
    }
    return w->info.idMensaje;
};

void mostrarMensajesRecibidos(NodoConversacion* p)
{
    NodoConversacion* aux = p;
    while( aux != NULL )
    {
        cout << aux->info.fecha << endl;
        cout << aux->info.idConversacion << endl;
/*      cout << aux->info.idEmisor << endl;
        cout << aux->info.idReceptor << endl; */
        cout << aux->info.losMensajesRecibidos->info.fecha << endl;
        cout << aux->info.losMensajesRecibidos->info.idMensaje << endl;
        cout << aux->info.losMensajesRecibidos->info.leido << endl;
        cout << aux->info.losMensajesRecibidos->info.mensaje << endl;
        aux = aux->sgte;
    }
    return;
};

NodoMensaje* insertarOrdenado(NodoMensaje*& p, InfoMensaje msj)
{
    NodoMensaje* nuevo = new NodoMensaje();
    nuevo->info = msj;

    NodoMensaje* ant = NULL;
    NodoMensaje* aux = p;
    while( aux!=NULL && aux->info.idMensaje<msj.idMensaje)
    {
        ant = aux;
        aux = aux->sgte;
    }

    if(ant==NULL)
    {
        nuevo->sgte = p;
        p = nuevo;
    }
    else
    {
        ant->sgte = nuevo;
        if(aux==NULL)
        {
            nuevo->sgte = NULL;
        }
        else
        {
            nuevo->sgte=aux;
        }
    }

    return nuevo;
};

void losMensajesRecibidos(NodoConversacion*& lc, NodoUsuario* lu, int idConversacion, string mensaje)
{
    InfoMensaje info; // Actualiza la info del mensaje
    NodoConversacion* p = lc; 
    eliminarNodo(p,idConversacion); // Inicializa nodo p para eliminarlo
    NodoUsuario* q = buscarEnListaUsuario(lu,p->info.idReceptor); // Inicializa nodo q para buscar el idReceptor
    q->info.recibido = true; // Notifica al usuario que el mensaje fue recibido
    p->sgte = lc;   // Asigna la direccion siguiente de p al principio de la lista de conversaciones
    lc = p; // Asigna el valore de p como principio de la lista de conversaciones
   /*  p->info.fecha = fechaToEntero();    
    info.fecha = p->info.fecha; */      // TODO Error stringToint de la funcion fechaToEntero()
/*     info.idMensaje = numeroMensaje(lc->info.losMensajesRecibidos->info.idMensaje);  TODO Error de Segmentacion en numeroMensaje()*/
    info.mensaje = mensaje;
    insertarOrdenado(p->info.losMensajesRecibidos,info); 
    return;
};


