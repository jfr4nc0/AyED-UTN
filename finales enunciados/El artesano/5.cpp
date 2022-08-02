#include <iostream>
#include <stdio.h>
using namespace std;

struct Dato{
	int dato1;
	int dato2;
};

template <typename T> struct Nodo{
	Dato info;
	Nodo<T>* sig;
	Nodo<T>* ant;
};

template <typename T> void inicializacion(Nodo<T>* &cabecera, Nodo<T>* &trailer){
	cabecera = new Nodo<T>();
	trailer = new Nodo<T>();
	cabecera->ant = NULL;
	trailer->sig = NULL;
	cabecera->sig = trailer;
	trailer->ant = cabecera;
}

template <typename T> void cargar(Nodo<T>* trailer, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = trailer;
	nuevo->ant = trailer->ant;
	Nodo<T>* aux = trailer->ant;
	aux->sig = nuevo;
	trailer->ant = nuevo;
}

template <typename T> void mostrar(Nodo<T>* cabecera){
	Nodo<T>* aux = cabecera->sig;
	while(aux != NULL){
		if(aux->sig != NULL){
			cout << "Dato 1: " << aux->info.dato1 << endl;
			cout << "Dato 2: " << aux->info.dato2 << endl;
			aux = aux->sig;
		} else {
			aux = aux->sig;
		}
	}
}

template <typename T> void frente(Nodo<T>* cabecera){
	Nodo<T>* aux = cabecera->sig;
	cout << "Dato 1: " << aux->info.dato1 << endl;
	cout << "Dato 2: " << aux->info.dato2 << endl;
}

template <typename T> bool vacia(Nodo<T>* cabecera){
	return cabecera->sig->sig == NULL;
}

Dato crearDato(){
Dato d;
int dato1;
int dato2;

	cout << "Dato 1: ";
	cin >> dato1;
	cout << "Dato 2: ";
	cin >> dato2;
	
	d.dato1 = dato1;
	d.dato2 = dato2;

return d;	
}

int criterio09(Dato d1, Dato d11){
	return d1.dato1-d11.dato1;
}

template <typename T> void insertar(Nodo<T>* &cabecera, Dato v, int (*criterio09)(T,T)){
	Nodo<T>* aux = cabecera;
	while(aux->sig != NULL && aux->info.dato1 < v.dato1 ){
		aux = aux->sig;
	}
	cargar(aux,v);
}

int main(){
Dato d;
Nodo<Dato>* cabecera = NULL;
Nodo<Dato>* trailer = NULL;
int opc;

inicializacion<Dato>(cabecera,trailer);

	do{
		
		cout << "1. Cargar datos" << endl;
		cout << "2. Mostrar" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		
		switch(opc){
			
			case 1:
				d = crearDato();
				insertar<Dato>(cabecera,d,criterio09);
			break;
			
			case 2:
				if(vacia<Dato>(cabecera) == 1){
					cout << "Lista vacia..." << endl;
				} else {
					mostrar<Dato>(cabecera);
				}
			break;
			
			case 0:
				cout << "Fin del programa..." << endl;
			break;
			
			default:
				cout << "Opcion invalida..." << endl;
		}
		system("PAUSE");
		system("CLS");
	}while(opc!=0);

//cout << "Vacia?: ";
//if(vacia<Dato>(cabecera) == 1){
//	cout << "SI" << endl;
//} else {
//	cout << "NO" << endl;
//}
//
//d = crearDato();
//cargar<Dato>(trailer,d);
//
//cout << "Vacia?: ";
//if(vacia<Dato>(cabecera) == 1){
//	cout << "SI" << endl;
//} else {
//	cout << "NO" << endl;
//}
//
//d = crearDato();
//cargar<Dato>(trailer,d);
//
//cout << "Vacia?: ";
//if(vacia<Dato>(cabecera) == 1){
//	cout << "SI" << endl;
//} else {
//	cout << "NO" << endl;
//}
//
//cout << endl;
//
//mostrar<Dato>(cabecera);
//
//cout << endl;
//cout << "Contenido del frente: " << endl;
//frente<Dato>(cabecera);

return 0;
}
