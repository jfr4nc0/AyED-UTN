#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Materia{
	string nombre;
	int nota;
	bool promocion;
};

template <typename T> struct Nodo{
	Materia info;
	Nodo<T>* sig;
};

template <typename T> void agregarFinalLista(Nodo<T>* &p, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	if(p != NULL){
		Nodo<T>* aux = p;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	} else {
		p = nuevo;
	}
}

template <typename T> void mostrar(Nodo<T>* p){
	Nodo<T>* aux = p;
	while(aux != NULL){
		cout << aux->info.nombre << ": " << aux->info.nota << endl;
		cout << "Promocion: ";
		if(aux->info.promocion == 1){
			cout << "SI" << endl;
		} else {
			cout << "NO" << endl;
		}
	aux = aux->sig;
	}
}

template <typename T> T read(FILE* f){
	T buff;
	fread(&buff,sizeof(T),1,f);
	return buff;
}

template <typename T> void write(FILE* f, T v){
	fwrite(&v,sizeof(T),1,f);
}

Materia crearMateria(){
Materia m;
string nombre;
int nota;
bool promocion;

	cout << "Nombre de materia: ";
	cin >> nombre;
	cout << "Nota: ";
	cin >> nota;
	cout << "Promocion: ";
	cin >> promocion;
	
	m.nombre = nombre;
	m.nota = nota;
	m.promocion = promocion;
	
return m;
}

int main(){
Materia m;
Nodo<Materia>* p = NULL;
int opc;

	do{
		
		cout << "1. Cargar materia" << endl;
		cout << "2. Mostrar materias" << endl;
//		cout << "3. " << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				m = crearMateria();
				agregarFinalLista(p,m);
			break;
			
			case 2:
				if(p != NULL){
					mostrar(p);
				} else {
					cout << "Lista vacia..." << endl;
				}
			break;
			
			case 0:
				cout << "Fin del programa..." << endl;
			break;
			
			default:
				cout << "Opcion invalida... vuelva a intentarlo" << endl;
		}
		system("pause");
		system("cls");
	}while(opc != 0);

return 0;
}
