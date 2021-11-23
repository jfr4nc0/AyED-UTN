#include <iostream>
#include <cstring>
int main() {
    return 0;
}

struct Tipo1
{
    char dato1[3];
};

struct Tipo2
{
    char dato2[3];
    char dato1[3];
};

struct NodoListaTipo2
{
    Tipo2 info;
    NodoListaTipo2 *sgte;
    NodoListaTipo2 *ant;
};

struct NodoListaTipo1
{
    Tipo1 info;
    NodoListaTipo1 *sgte;
    NodoListaTipo2 *sublista;
};
void punto2(char archivo[],NodoListaTipo1 *&lista)
{
    FILE *f;Tipo2 r;
    NodoListaTipo1 *aux;
    NodoListaTipo2 *auxsublista;
    if(f= fopen(archivo,"r+b"))
    {
        while(fread(&r,sizeof(r),1,f))
        {
            aux=lista;
            while(aux && strcmp(aux->info.dato1,r.dato1))
                aux = aux->sgte;
            if(aux->sublista)
            {
                auxsublista = aux->sublista;
                while (auxsublista && auxsublista->sgte)
                    auxsublista = auxsublista->sgte;
                auxsublista->sgte = new NodoListaTipo2();
                auxsublista->sgte->ant = auxsublista;
                auxsublista = aux->sublista;
                auxsublista->info = r;
                auxsublista->sgte=NULL;
            }
            else
            {
                aux->sublista = new NodoListaTipo2;
                aux->sublista->ant=NULL;
                aux->sublista->sgte=NULL;
                aux->sublista->info=r;
            }
        }
        fcloseall();
    }
    return;
}


//Desarrolle un subprograma que dados por parámetros un valor y la lista, elimine el nodo de la lista
//principal que cumpla !strcmp(dato1, valor) .
void punto3(char valor[],NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *aux;
    NodoListaTipo1 *auxant = NULL;
    NodoListaTipo2 *auxsublista;
    aux = lista;
    while(aux && strcmp(valor,aux->info.dato1))
    {
        auxant=aux;
        aux=aux->sgte;
    }
    if(aux)
    {
        while(aux->sublista)
        {
            auxsublista = aux->sublista;
            aux->sublista=aux->sublista->sgte;
            delete auxsublista;
        }
        if(auxant)
        {
            auxant->sgte=aux->sgte;
        }
        else
            lista=aux->sgte;
        delete aux;
    }
}