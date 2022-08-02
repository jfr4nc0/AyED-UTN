// ----- 1 ----- //
struct Nodo{
  char info;
  Nodo* sig;
};
int N = 10000;
int inicio = 0;
int fin = 0;
Nodo* p = NULL;
char arrayFIFO[N];
FILE* f = fopen("archivo.txt","rt+");
// ----- 2 ----- //
void push(Nodo*& p, char c){
  Nodo* nuevo = new Nodo();
  nuevo->info = c;
  nuevo->sig = NULL;
  p = nuevo;
}
char pop(Nodo*& p){
  Nodo* aux = p;
  char c = aux->info;
  p = aux->sig;
  delete aux;
  return c;
}
// ----- 3 ----- //
void agregarA_FIFO(char arrayFIFO[N],char c,int fin){
  arrayFIFO[fin] = c;
  fin++;
}
// ----- 4 ----- //
char suprimirDe_FIFO(char arrayFIFO[N],int inicio){ // Al ser una estructura FIFO, se debe tener en cuenta que inicio debe tender a fin
char c = arrayFIFO[inicio];                         // y no viceversa. Puesto que en dicho caso se estaría eliminando progresivamente los
inicio++;                                           // datos/valores que se van cargando a la estructura. Pensar que es como una cola, pero
return c;                                           // en arrays.
}
// ----- 5 ----- //
void ingresarCaracteres(FILE* f,Nodo*& p,char arrayFIFO[N],int fin){ // suponiendo que se le pasa el archivo ya abierto en modo
                                                                     // lectura de texto, y que el fclose se realizará en la función main
int c;
  while(c = fgetc(f)){
    push(p,c);
    agregarA_FIFO(arrayFifo,c,fin);
  }
}
// ----- 6 ----- //
bool esPalindromo(Nodo* p,char arrayFifo[N],int inicio){
Nodo* aux = p;
char charFIFO = suprimirDe_FIFO(arrayFifo,inicio);
char charLIFO = pop(p);
  while(aux != NULL){
    if(charLIFO != charFIFO){
      return false;
    }
  }
return true;
}
