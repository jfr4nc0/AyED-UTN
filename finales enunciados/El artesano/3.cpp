#include <iostream>
#include <stdio.h>
using namespace std;

struct Departamento{
	int id_departamento;
	int piso_departamento;
	string prop_departamento;
	int metrosCuadrados_departamento;
};

template <typename T> struct Nodo{
	Departamento info;
	Nodo<T>* sig;
};

template <typename T> T read(FILE*);
template <typename T> void write(FILE*,T);
template <typename T> long fileSize(FILE*);
template <typename T> long filePos(FILE*);
template <typename T> void enlistar(Nodo<T>* &,T);
template <typename T> void mostrar(Nodo<T>*);
template <typename T> void leer(const char[]);
template <typename T> void escribir(const char[],T);
Departamento crearDepartamento();

int main(){
Nodo<Departamento>* p = NULL;
Departamento d;
const char ruta[] = "departamentos.DAT";
int x;
int opc;
int id;

	do{
		
		cout << "1. Add to list" << endl;
		cout << "2. Show list" << endl;
		cout << "3. Read file" << endl;
		cout << "0. Exit" << endl;
		cout << "Option: ";
		cin >> opc;
		
		switch(opc){
			
			case 1:
				d = crearDepartamento();
				enlistar<Departamento>(p,d);
				escribir<Departamento>(ruta,d);
			break;
			
			case 2:
				mostrar<Departamento>(p);
			break;

			case 3:
				leer<Departamento>(ruta);
			break;

			case 0:
				cout << "End of program..." << endl;
			break;
			
			default:
				cout << "Invalid option... try again..." << endl;
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(opc != 0);

return 0;
}

template <typename T> void enlistar(Nodo<T>* &p, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	if(p == NULL){
		p = nuevo;
	} else {
		Nodo<T>* aux = p;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

template <typename T> void mostrar(Nodo<T>* p){
	Nodo<T>* aux = p;
	cout << "------------------------" << endl;
	while(aux != NULL){
		cout << "Departamento numero: " << aux->info.id_departamento << endl;
		cout << "Piso: " << aux->info.piso_departamento << endl;
		cout << "Propietario: " << aux->info.prop_departamento << endl;
		cout << aux->info.metrosCuadrados_departamento << " metros cuadrados" << endl;
		if(aux->sig == NULL){
			cout << "------------------------" << endl;
		} else {
			cout << endl;
		}
		aux = aux->sig;
	}
}

template <typename T> T read(FILE* f){
	T buff;
	fread(&buff,sizeof(T),1,f);
	return buff;
}

template <typename T> void leer(const char ruta[]){
FILE* f = fopen(ruta,"rb+");
Departamento d;

	d = read<Departamento>(f);
		while(!feof(f)){
			cout << "Department: " << d.id_departamento << endl;
			cout << "Floor: " << d.piso_departamento << endl;
			cout << "Owner: " << d.prop_departamento << endl;
			cout << d.metrosCuadrados_departamento << " metres squared" << endl;
			d = read<Departamento>(f);
		}

	fclose(f);
}

template <typename T> void write(FILE* f, T v){
	fwrite(&v,sizeof(T),1,f);
}

template <typename T> void escribir(const char ruta[], T v){
FILE* f = fopen("departamentos.DAT","wb+");

	write<T>(f,v);
	
fclose(f);
}

template <typename T> long fileSize(FILE* f){
	long current = ftell(f);
	fseek(f,0,SEEK_END);
	long last = ftell(f);
	fseek(f,current,SEEK_SET);
	return last/sizeof(T);
}

template <typename T> long filePos(FILE* f){
	return ftell(f)/sizeof(T);
}

Departamento crearDepartamento(){
Departamento d;
int id;
int piso;
string propietario;
int metrosCuadrados;

	cout << "ID del departamento: ";
	cin >> id;
	cout << "Piso: ";
	cin >> piso;
	cout << "Propietario: ";
	cin >> propietario;
	cout << "Metros cuadrados: ";
	cin >> metrosCuadrados;
	
	d.id_departamento = id;
	d.piso_departamento = piso;
	d.prop_departamento = propietario;
	d.metrosCuadrados_departamento = metrosCuadrados;
	
return d;
}
