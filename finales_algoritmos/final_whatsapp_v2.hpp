#include <iostream>
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/strings.hpp"

using namespace std;

struct Conversacion
{
    int idConversacion;
    string nombre; // nombre del grupo o "" si es comunicacion p2p
    bool notificar;
    bool vistaPrevia;
};

struct Nodo
{
    Conversacion info;
    Nodo* sgte;
};

struct Contacto
{
    int idUsuario;
    string nombreContacto;
    bool bloqueado;
};

Contacto contacto(string id, string nombre, bool bloqueo)
{
    return {id,nombre,bloqueo};
};

// funciones auxiliares

// Asumo que la conversacion existe
Nodo* buscarConversacion(Nodo* conversaciones, int idConversacion) //TODO busqueda de Lista E    ok
{
    Nodo* aux = conversaciones;
    while (aux != NULL && aux->info.idConversacion != idConversacion ) 
    {
        aux = aux->sgte;
    }
    return aux;
};

int buscarContacto(Contacto contacto[], int len, int idContacto)//TODO busqueda de array
{
    int i=0;
    while (i<len && contacto[i].idUsuario!=idContacto)
    {
        i++;
    }
    return i<len?i:-1;
};

// funciones sin desarrollar
void emitirNotificacion(string titulo, string descripcion);

string numeroTelefonicoDelUsuario(int idEmisor);

string vistaPreviaMensaje(string mensaje);

void notificarMensajeRecibido(Nodo* conversaciones, Contacto contactos[],int cantContactos ,int idConversacion, int idUsuarioEmisor, Mensaje mensaje)
{
    // Buscar la conversacion
    Nodo* conversacion = buscarConversacion(conversaciones,idConversacion);

    // Buscar el contacto, -1 si no existe
    int pos = buscarContacto(contactos,cantContactos,idUsuarioEmisor);
    bool bloqueado;
    string NombreContacto;

    // TODO Caso 1: Usuario existe y no esta bloqueado

    if(pos>=0) 
    {   
        bloqueado = contactos[pos].bloqueado;
        NombreContacto = contactos[pos].nombreContacto;
    }
    else // Caso 2: Usuario no existe
    {
        NombreContacto = numeroTelefonicoDelUsuario(idUsuarioEmisor);
    }

    if(bloqueado==false && conversacion->info.notificar==true)
    {
        if(conversacion->info.nombre!="")       // Conversacion grupal
        {
            string titulo = conversacion->info.nombre;
            if(conversacion->info.vistaPrevia==true)    // Con Vista Previa
            {
                string descripcion = NombreContacto+" Vista Previa:\n"+mensaje;     // el tipo Mensaje no hace falta definirlo
                emitirNotificacion(titulo,descripcion);
            }
            else
            {
                string descripcion = "Nuevo mensaje de: "+NombreContacto;
                emitirNotificacion(titulo,descripcion);     // Sin Vista Previa
            }
        }
        else        // Conversacion Directa
        {
            string titulo = NombreContacto;
            if(conversacion->info.vistaPrevia==true)
            {
                string descripcion = " Vista Previa:\n"+mensaje;     // el tipo Mensaje no hace falta definirlo
                emitirNotificacion(titulo,descripcion);     // Con Vista Previa
            }
            else
            {
                string descripcion = "Nuevo mensaje";
                emitirNotificacion(titulo,descripcion);     // Sin Vista Previa
            }
        }
    }

    return;
};




