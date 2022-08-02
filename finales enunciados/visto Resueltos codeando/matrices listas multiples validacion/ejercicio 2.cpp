struct Nodo{
  char info;
  Nodo* sig;
};

char pop(Nodo*&);
void push(Nodo*&p,char);
bool validar(Nodo*p,char);

int main(){

return 0;
}

char pop(Nodo*& p){
  char caracterAPop;
  Nodo* aux = p;
  caracterAPop = aux->info;
  p = aux->sig;
  delete aux;
  return caracterAPop;
}

void push(Nodo*& p,char caracter){
  Nodo* nuevo = new Nodo();
  nuevo->info = caracter;
  nuevo->sig = p;
  p = nuevo;
}

bool validar(Nodo*& p,char expresion[]){
char caracterPop;

  for(int i = 0; i < LONGITUD; i++){
    if(esIzquierdo(expresion[i])){
      push(p,expresion[i]);
    } else {
      if(esDerecho(expresion[i])){
        caracterPop = pop(p);
        if(expresion[i] != caracterOpuesto(caracterPop)){
          return false;
        }
      }
    }

    if(i > 0){
      if(esIzquierdo(expresion[i-1]) || esOperador(expresion[i-1])){
        if(esOperador(expresion[i]) || esDerecho(expresion[i])){
          return false;
        }
      } else {
        if(esLetra(expresion[i-1]) || esDerecho(expresion[i-1])){
          if(esLetra(expresion[i])){
            return false;
          }
          if(esLetra(expresion[i-1]) && esIzquierdo(expresion[i])){
            return false;
          } else {
            if(esDerecho(expresion[i-1]) && esDerecho(expresion[i])){
              return false;
            }
          }
        }
      }
    }
  }

return true;
}
