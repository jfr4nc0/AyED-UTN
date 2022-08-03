#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
using namespace std;

template<typename T>
struct Coll
{
    string s;
    char sep;
    int pos;
};

/* Funcion: coll
    Descripción: Crea una colección vacía, preparada para contener elementos de tipo T;
utilizando el carácter sep como separador de la cadena tokenizada sobre la que se
implementa la colección.
Parámetro: char sep – Carácter separador.
Retorna: Coll<T> - Una colección vacía preparada para contener elementos tipo T. */
template<typename T>
Coll<T> coll(char sep)
{
    Coll<T> c;
    c.s="";
    c.sep=sep;
    return c;
}

template<typename T>
Coll<T> coll()
{
    Coll<T> c;
    c.s="";
    c.sep='|';
    return c;
}

template<typename T>
int collSize(Coll<T> c)
{
    int cont = tokenCount(c.s,c.sep);
    return cont;
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
    c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
    removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
    addToken(c.s,c.sep,tToString(t));
    return collSize(c)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
    setTokenAt(c.s,c.sep,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
    string k = getTokenAt(c.s,c.sep,p);
    T t=tFromString(k);
    return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
    int a=-1,b=-1;
    for( int i=0; i<collSize(c) && a!=0 ;i++ )
    {
        T t=collGetAt(c,i,tFromString);
        a=cmpTK(t,k);
        if(a==0)
        {
            b=i;
        }
    }
    return b;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
    string s=c.s;
    int n = collSize(c);
    collRemoveAll(c);
    int b=0;
    while(n>collSize(c))
    {
        T primero=tFromString(getTokenAt(s,c.sep,0));
        int a=0;
        for(int i=0;i<n-b;i++)
        {
            T t=tFromString(getTokenAt(s,c.sep,i));
            if(cmpTT(primero,t)>0)
            {
                primero=t;
                a=i;
            }
        }
        collAdd(c,primero,tToString);
        removeTokenAt(s,c.sep,a);
        b++;
    }
}

template<typename T>
bool collHasNext(Coll<T> c)
{
    return collSize<T>(c)>c.pos;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
    T t=collGetAt(c,c.pos,tFromString);
    c.pos++;
    return t;
}

/*
 * template<typename T>
 * T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
 * {
 * T t;
 * return t;
 * }
 */


template<typename T>
void collReset(Coll<T>& c)
{
    c.pos=0;
}

template<typename T>
string collToString(Coll<T> c)
{
    return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
    Coll<T> c;
    c.sep=s[0];
    c.s=substring(s,1);
    return c;
}

template<typename T>
Coll<int> collIntFromString(string s)
{
    Coll<int> x = coll<int>(',');
    for(int i=0; i<tokenCount(s,','); i++)
    {
        int p = stringToInt(getTokenAt(s,',',i));
        collAdd<int>(x,p,intToString);
    }

    return x;
}

#endif

