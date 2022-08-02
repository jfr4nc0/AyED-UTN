// ---------- pre ---------- //
struct Dato{
  unsigned campo2;
  unsigned campo3;
  unsigned campo4;
};
struct R1{
  unsigned campo1;
  Dato info;
};
struct R2{
  Dato info;
  Dato* sig;
};
struct Nodo{
  R2* frente;
  R2* fin;
};
const int N = 20;
FILE* f;
Nodo* cola[N] = {NULL};
// ---------- 1 ---------- //
void cargarAMemoria(Nodo*& cola[N],FILE* f){
f = fopen("registros.dat","rb+");
Dato d;

  R1 r1 = read<R1>(f);
    while(!feof(f)){
      d.campo2 = r1.info.campo2;
      d.campo3 = r1.info.campo3;
      d.campo4 = r1.info.campo4;
      encolar(cola[r1.campo1].frente,cola[r1.campo1].fin,d);
      r1 = read<R1>(f);
    }
return;
}
// ---------- 2 ---------- //
void cambiarDeCola(Nodo*& cola[N],int origen,int destino){
  Dato info = desencolar(cola[origen].frente,cola[origen].fin);
  encolar(cola[destino].frente,cola[destino].fin,info);
return;
}
// ---------- 3 ---------- //
void mostrar(Nodo* cola[N]){
Dato info;
int i = 0;

  while(i < N){
    while(cola[i].frente != NULL){
      info = desencolar(cola[i].frente,cola[i].fin);
      cout << info.campo2 << ", " << info.campo3 << ", " << info.campo4 << endl;
    }
    i++;
  }
return;
}
