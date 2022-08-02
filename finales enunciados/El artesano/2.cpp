#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Cajon{
	int id_cajon;
	int cant_ropa_cajon;
	int prioridad_cajon;
	string matricula_cajon;
};

template <typename T> struct Nodo{
	T Cajon;
	Nodo<T>* sig;
};

template <typename T> void encolar(Nodo<T>* &, Nodo<T>* &, T);
template <typename T> T desencolar(Nodo<T>* &, Nodo<T>* &);
template <typename T> long size(Nodo<T>*, Nodo<T>*);
template <typename T> void mostrarProximo(Nodo<T>*, Nodo<T>*);
Cajon crearCajon();


int main(){
Nodo<Cajon>* p = NULL;
Nodo<Cajon>* q = NULL;
Cajon c;
int opc;

	do{
		
		cout << "Cajones por atender - " << size<Cajon>(p,q) << " -" << endl;
		cout << "1. Poner en espera cajon" << endl;
		cout << "2. Atender cajon" << endl;
		cout << "3. Mostrar cajon proximo" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				c = crearCajon();
				encolar<Cajon>(p,q,c);
			break;
			
			case 2:
			if(p != NULL && q != NULL){
				c = desencolar<Cajon>(p,q);
				cout << "Se atendio caja id: " << c.id_cajon << endl;
				cout << "Cantidad de ropa que tenia: " << c.cant_ropa_cajon << endl;
				cout << "Prioridad del cajon: " << c.prioridad_cajon << endl;
				cout << "Matricula del cajon: " << c.matricula_cajon << endl;
			} else {
				cout << "No hay cajones por atender... Intente en agregar cajon(?)" << endl;
			}
			break;
			
			case 3:
			if (p != NULL && q != NULL){
				mostrarProximo(p,q);
			} else {
				cout << "No hay cajones en lista... Intente en agregar cajon(?)" << endl;
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
	}while(opc != 0);
	
return 0;
}

template <typename T> void encolar(Nodo<T>* &p, Nodo<T>* &q, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->Cajon = v;
	nuevo->sig = NULL;
	if(p == NULL){
		p = nuevo;
	} else {
		q->sig = nuevo;
	}
	q = nuevo;
}

template <typename T> T desencolar(Nodo<T>* &p, Nodo<T>* &q){
	T v = p->Cajon;
	Nodo<T>* aux = p;
	p = p->sig;
	if(p == NULL){
		q = NULL;
	}
	delete aux;
	return v;
}

template <typename T> long size(Nodo<T>* p, Nodo<T>* q){
	Nodo<T>* aux = p;
	long contador = 0;
	while(p != NULL){
		contador++;
		p = p->sig;
	}
	return contador;
}

Cajon crearCajon(){
Cajon c;
int id;
int cant_ropa;
int prioridad;
string matricula;

	cout << "ID cajon: ";
	cin >> id;
	cout << "Cantidad de ropa del cajon: ";
	cin >> cant_ropa;
	cout << "Prioridad de cajon: ";
	cin >> prioridad;
	cout << "Matricula del cajon: ";
	cin >> matricula;
	
	c.id_cajon = id;
	c.cant_ropa_cajon = cant_ropa;
	c.prioridad_cajon = prioridad;
	c.matricula_cajon = matricula;
	
return c;
}

template <typename T> void mostrarProximo(Nodo<T>* p, Nodo<T>* q){
	cout << "Cajon id: " << p->Cajon.id_cajon << endl;
	cout << "Cantidad de ropa: " << p->Cajon.cant_ropa_cajon << endl;
	cout << "Prioridad del cajon: " << p->Cajon.prioridad_cajon << endl;
	cout << "Matricula del cajon: " << p->Cajon.matricula_cajon << endl;
}
