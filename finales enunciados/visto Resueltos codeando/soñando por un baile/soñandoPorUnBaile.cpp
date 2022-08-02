
// ********** NOTA ********* //
// Las funciones otorgadas por las consignas, solamente fueron declarados sus prototipos.
// ----------- (Estructuras por consigna) ----------- //
struct DatoPareja{
  int id;
  char integrante1[50+1];
  char integrante2[50+1];
  int puntaje;
};
struct Nodo{
  DatoPareja info;
  Nodo* sig;
};
// ----------- (Variables globales) ----------- //
const int CANT_SENTENCIADOS = 2;
const int CANT_PAREJAS = 30;
// ----------- (Prototipos de las funciones) ----------- //
void enlistar(Nodo*&,DatoPareja);
template <typename T> void write(FILE*,T);
int ejecutarRitmo(int,Nodo*&);
void bailarRitmo(Nodo*,int);
unsigned getPuntajeCorte(Nodo*,int);
void abrirVotacionDePublico();
int bailarDuelo(Nodo*);
void removerParejaSalvada(Nodo*,int);
int cierreVotacionPublico();
// ----------- (1) ----------- //
int ejecutarRitmo(int ritmo,Nodo*& parejas){ // suponiendo que en la funcion main, a la función
unsigned puntajeCorte;                       // ejecutar ritmo le pasan por parámetro los 26 ritmos,
Nodo* aux = parejas;                         // uno por uno, mediante una estructura for.
int i = 0;
FILE* f = fopen("gruposAFase2.dat","wb+");

  while(aux != NULL){
    bailarRitmo(aux,ritmo);
    aux = aux->sig;
  }

  aux = parejas;
  puntajeCorte = getPuntajeDeCorte(aux,ritmo);

  while(aux != NULL){
    if(aux->info.puntaje < puntajeCorte){
      i++;
    }
    aux = aux->sig;
  }

  aux = parejas;
  Nodo* sentenciados = getSentenciados(parejas,puntajeCorte);
  int j = i;

  if(i >= 2){
    abrirVotacionPublico();
    while(j > 1){
      parejaSalvada = bailarDuelo(sentenciados);
      removerParejaSalvada(sentenciados,parejaSalvada);
      j--;
    }
  }

  aux = parejas;

  while(aux != NULL){
    write<DatoPareja>(f,aux->info);
    aux = aux->sig;
  }

fclose(f);
return cierreVotacionPublico();
}
// ----------- (2) ----------- //
Nodo* getSentenciados(Nodo* parejas,unsigned puntajeCorte){
Nodo* lista = NULL;
Nodo* aux = parejas;

  while(aux != NULL){
    if(aux->info.puntaje < puntajeCorte){
      enlistar(lista,aux->info);
    }
    aux = aux->sig;
  }

return lista;
}
// ----------- (Funciones para los dos ejercicios) ----------- //
template <typename T> void write(FILE* f, T v){
  fwrite(&v,sizeof(T),1,f);
}

void enlistar(Nodo*& p,DatoPareja datosDeLaPareja){
  Nodo* nuevo = new Nodo();
  nuevo->info = datosDeLaPareja;
  nuevo->sig = NULL;
  if(p == NULL){
    p = nuevo;
  } else {
    Nodo* aux = p;
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
}
