#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Arr.hpp"
using namespace std;

char* dias[] = {"Sabado","Domingo","Jueves","Lunes","Martes","Miercoles","Jueves","Viernes","Lunes"};
char* colores[] = {"Negro","Amarillo","Blanco","Rojo","Verde","Gris","Violeta","Celeste","Azul"};
char* caracteristicas[] = {"Emprendedor","Pasivo","Optimista","Practico","Inestable","Confiable","Culto","Organizado","Docente"};

struct Nodo
{
  char info;
  Nodo* sig;
};

Nodo* cargarNombre(){
  
  char c;

  // puntero al primer nodo
  Nodo* p=NULL;
  
  cin >> c;
  while(c != '*'){
    Nodo* nuevo = new Nodo();
    nuevo->info = c;
    nuevo->sig = p;
    p = nuevo;
    cin >> c; 
  }

  return p;
}

int contarDigitos(int n){
    
    double res;
    for(int i=1; ; i++)
    {
        res = (double)n/pow(10,i);
        if( res<=1 )
        {
          return i;
        }
    }
    return 0;
}

int obtenerDigito(int n, int i)
{
    int x = n%(int)pow(10,i+1);
    return x/pow(10,i);
}

int numeroAfortunado(const Nodo* ret)
{  
  int sum = 0;
  while (ret!=NULL){
    int valor = ret->info-'A'+1;
    sum+=valor;
    ret=ret->sig;
  }
  
  int x = 0;
  while (contarDigitos(sum) > 1)
  {
    for(int i=0; i<contarDigitos(sum); i++){
        int d = obtenerDigito(sum,i);
        x += d;
    }
    sum = x;
  }
  
  return sum;
}

void mostrarResultado(int n)
{
    cout << "Su numero afortunado es: " << n << endl;
    cout << "Dia: " << dias[n-1] << endl;
    cout << "Color: " << colores[n-1] << endl;
    cout << "Caracteristica: " << caracteristicas[n-1] << endl;
}

int main() 
{
    Nodo* p = cargarNombre();
    int nro = numeroAfortunado(p);
    mostrarResultado(nro);
    return 0;
}