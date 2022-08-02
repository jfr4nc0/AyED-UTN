// ----- 1 ----- //
struct Piso{
  int piso;
  int suben;
  int bajan;
};
struct Escritura{
  int piso;
  int diferencia;
};
struct Nodo{
  Piso info;
  Nodo* arriba;
  Nodo* abajo;
};
// ----- 2 ----- //
int eliminarLosPisosPrimosArribaDe(Nodo*&,FILE*);
// ----- 3 ----- //
bool esPrimo(int piso){
  for(int i = 2; i < piso; i++){
    if(piso % i == 0){
      return false;
    }
  }
return true;
}
// ----- 4 ----- //
void eliminarPiso(Nodo*& unPiso){
Nodo* aux = unPiso->arriba;
Nodo* ant = unPiso->abajo;
aux->abajo = ant;
ant->arriba = aux;
delete unPiso;
}
// ----- 5 ----- //
int eliminarLosPisosPrimosArribaDe(Nodo*& unPiso,FILE* f){
f = fopen("PisosPrimosEliminados.dat","wb+");
Nodo* aux = unPiso->arriba;
int pisosElim = 0;
Escritura e;

  while(aux->arriba != NULL){
    Nodo* unoArriba = aux->arriba;
    if(esPrimo(aux->info.piso)){
      e.piso = aux->info.piso;
      e.diferencia = (aux->info.suben - aux->info.bajan); // si da negativo, quiere decir que hay más personas que están bajando de piso
      eliminarPiso(aux);
      write<Escritura>(f,e);
      pisosElim++;
    }
    aux = unoArriba;
  }
fclose(f);
return pisosElim;
}
