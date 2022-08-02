// ----- 1 ----- /
struct Examenes{
  int parcial1[3];
  int parcial2[3];
  int integrador;
  int trabajoPractico;
}; // justificacion: se ha declarado dos arreglos enteros de tamaño 3, suponiendo que para los dos arreglos, la posición cero
// representa la nota del parcial en sí, la posición uno para el primer recuperatorio de dicho parcial, y la posición 2 para la
// nota del segundo recuperatorio. El integrador se ha colocado aparte, puesto que es una nota única y el trabajo práctico también.
// ----- 2 ----- //
struct Alumno{
  int legajo;
  char nombreApellido[20];
  Examenes info;
  Alumno* sig;
};
struct Nodo{ // el curso
  Alumno* frente;
  Alumno* fin;
};
struct Escritura{
  int legajo;
  char nombreApellido[20];
  int curso;
};
struct Lista{
  Escritura info;
  Lista* sig;
};
FILE* f; // archivo a generar
Nodo* cursos[N] = {NULL};
// ----- 3 ----- //
void informarPromocionados(Nodo*[]);
// ----- 4 ----- //
void informarPromocionados(Nodo* cursos[N]){
FILE* f = fopen("Promocionados.dat","rb+");
Lista* p = NULL;
int i = 0;
Alumno a;
Escritura e;

  while(i < N){
    while(cursos[i].frente != NULL){
      a = desencolar(cursos[i].frente,cursos[i].fin);
      if(isPromocionado(a.info)){
        e.legajo = a.legajo;
        strcpy(e.nombreApellido,a.nombreApellido.c_str());
        e.curso = getCurso(i);
        insertarOrdenado(p,e); // inserta con criterio ascendente legajo 0 a 9 en la lista p
      }
    }
    i++;
  }

Lista* aux = p;

  while(aux != NULL){ // ya teniendo en la lista p SOLAMENTE los alumnos que promocionan
    write<Escritura>(f,aux->info);
    aux = aux->sig;
  }

fclose(f);
return;
}
// ----- funciones que no piden pero igual los dejo por acá ----- //
Alumno desencolar(Alumno*& frente,Alumno*& fin){ // función para desencolar un registro de una estructura de colas
Alumno* aux = frente;
Alumno a = aux->info;
frente = aux->sig;
  if(frente == NULL){
    fin == NULL;
  }
delete aux;
return a;
}
void insertarOrdenado(Lista*& p,Escritura e){ // función que inserta ordenado en lista, en este caso, según criterio legajo (forma ascendente 0 a 9)
Lista* nuevo = new Lista();
nuevo->info = e;
nuevo->sig = NULL;
  if(p == NULL){
    p = nuevo;
  } else {
    Lista* aux = p;
    Lista* ant = NULL;
    while(aux->info.legajo <= e.legajo){
      ant = aux;
      aux = aux->sig;
    }
    ant->sig = nuevo;
    nuevo->sig = aux;
  }
return;
}
template <typename T> void write(FILE* f,T e){ // plantilla de escritura en archivo binario
  fwrite(&e,sizeof(T),1,f);
}
template <typename T> long seek(FILE* f){ // plantilla para saber la cantidad de registros en un archivo binario
  int inicio = ftell(f);                  // pd: no tiene nada que ver con el ejercicio
  fseek(f,0,SEEK_END);
  int final = ftell(f);
  fseek(f,inicio,SEEK_SET);
  return final/sizeof(T);
}
