#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
using namespace std;

template <typename T> struct Nodo{
	T info;
	Nodo<T>* sig;
};

template <typename T> bool empty(Nodo<T>*);
template <typename T> long size(Nodo<T>*);
template <typename T> void mostrarUltimo(Nodo<T>*);
template <typename T> T read(FILE*);
template <typename T> void write(FILE*f, T);
template <typename T> void seek(FILE*, int);
template <typename T> long fileSize(FILE*);
template <typename T> long filePos(FILE*);
template <typename T> void push(Nodo<T>*&, T);
template <typename T> T pop(Nodo<T>*&);

int main(){
	Nodo<string>* p = NULL;
	int opcion;
	string pagina;
	
	do{
		
		cout << "Tamanio de pila - " << size<string>(p) << " -" << endl;
		cout << "Pila vacia - " << empty(p) << " -" << endl;
		cout << "1. Ingresar pagina web" << endl;
		cout << "2. Mostrar ultimo" << endl;
		cout << "3. Borrar ultimo" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion){
			
			case 1:
			cout << "Ingresar pagina web: ";
			cin >> pagina;
			push<string>(p,pagina);
			break;
			
			case 2:
				if(p != NULL){
					mostrarUltimo(p);
				} else {
					cout << "Historial vacio..." << endl;
				}
			break;
			
			case 3:
				if(p != NULL){
					pop<string>(p);
					cout << "Ultima pagina borrada..." << endl;
				} else {
					cout << "Historial vacio..." << endl;
				}
			break;
			
			case 0:
			cout << "Fin del programa..." << endl;
			break;
			
			default:
			cout << "Opcion invalida... vuelva a intentarlo" << endl;			
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(opcion != 0);

return 0;	
}

template <typename T> bool empty(Nodo<T>* p){
	return p != NULL;
}

template <typename T> long size(Nodo<T>* p){
	long contador = 0;
	while(p != NULL){
		contador++;
		p = p->sig;
	}
	return contador;
}

template <typename T> void mostrarUltimo(Nodo<T>* p){
	Nodo<T>* aux = p;
	string x = pop<string>(p);
	cout << "Ultimo: " << x << endl;
	push<string>(p,x);
}

template <typename T> T read(FILE* f){
	T buff;
	fread(&buff,sizeof(T),1,f);
	return buff;
}

template <typename T> void write(FILE* f, T v){
	fwrite(&v,sizeof(T),1,f);
}

template <typename T> void seek(FILE* f, int n){
	fseek(f,n*sizeof(T),SEEK_SET);
}

template <typename T> long fileSize(FILE* f){
	long curr = ftell(f);
	fseek(f,0,SEEK_END);
	long last = ftell(f);
	fseek(f,curr,SEEK_SET);
	return last/sizeof(T);
}

template <typename T> long filePos(FILE* f){
	return ftell(f)/sizeof(T);
}

template <typename T> void push(Nodo<T>* &p, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}

template <typename T> T pop(Nodo<T>* &p){
	Nodo<T>* aux = p;
	T v = aux->info;
	p = p->sig;
	delete aux;
	return v;
}
