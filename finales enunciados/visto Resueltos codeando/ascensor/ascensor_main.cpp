// ----- 1 ----- //
struct Piso{
  int piso;
  int bajan;
  int suben;
};
struct Nodo{
  Piso info;
  Nodo* arriba;
  Nodo* abajo;
};
// ----- 2 ----- //
int insertarPisoArribaDeActualYMedir(Nodo*,Nodo*,unsigned&,unsigned&);
// ----- 3 ----- //
int insertarPisoArribaDelActualYMedir(Nodo* pisoActual,Nodo* unNuevoPiso,unsigned& masAlto,unsigned& masBajo){
Nodo* aux = pisoActual->arriba;
int i = 0;

  pisoActual->arriba = unNuevoPiso;
  unNuevoPiso->abajo = pisoActual;
  unNuevoPiso->arriba = aux;
  aux->abajo = unNuevoPiso;

  medirDistanciaAPisosExtremos(unNuevoPiso,masBajo,masAlto);

  aux = unNuevoPiso;
  if(unNuevoPiso->info.piso < 0){
    while(aux->info.piso != 0){
      i++;
      aux = aux->arriba;
    }
  } else {
    if(unNuevoPiso->info.piso > 0){
      while(aux->info.piso != 0){
        i++;
        aux = aux->abajo;
      }
    }
  }

return i;
}
// ----- 4 ----- //
void medirDistanciaAPisosExtremos(Nodo* unPiso,unsigned& masBajo,unsigned& masAlto){ // suponiendo que existen un trailer y cabecera
Nodo* aux = unPiso;
unsigned i = 0;
unsigned j = 0;

  while(aux->arriba != NULL){
    i++;
    aux = aux->arriba;
  }
  aux = unPiso;
  while(aux->abajo != NULL){
    j++;
    aux = aux->abajo;
  }
masAlto = i;
masBajo = j;
}
// ----- 5 ----- //
void inicializar(Nodo*& subsuelo,Nodo*& techo){ // en ejercicio no lo pide como necesario, pero igual se lo agrego
subsuelo->abajo = NULL;
subsuelo->arriba = techo;
techo->abajo = subsuelo;
techo->arriba = NULL;
}
int main(){ // suponiendo que el punteo unPiso está apuntando a algún piso de la estructura.
Nodo*& subsuelo = NULL;
Nodo*& techo = NULL;
inicializar(subsuelo,techo);
unsigned masAlto = 0;
unsigned masBajo = 0;
medirDistanciaAPisosExtremos(unPiso,masBajo,masAlto);
return 0;
}
