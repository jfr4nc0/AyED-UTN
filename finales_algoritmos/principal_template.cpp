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
using namespace std;



int main()
{
    Coll<Persona> c = coll<Persona>();
    collAdd<Persona>(c,persona(1,"Joan","Allende 2255"),personaToString);
    collAdd<Persona>(c,persona(2,"Pablo","Bermudez 5432"),personaToString);
    collAdd<Persona>(c,persona(3,"Julian","Jonte 3490"),personaToString);
    collAdd<Persona>(c,persona(4,"Marta","Cordoba 4432"),personaToString);

    collReset<Persona>(c);
    while( collHasNext<Persona>(c) )
    {
        Persona p = collNext<Persona>(c,personaFromString);
        cout << personaToDebug(p) << endl;
    }

    return 0;
}




#endif