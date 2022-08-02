#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
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
//template <typename T> void lecturaMain(FILE*);

int main(){
FILE* f = fopen("departamentos.DAT","rb+");
Departamento d;

	d = read<Departamento>(f);
	while( !feof(f) ){
		
		cout << d.id_departamento << ", " << d.metrosCuadrados_departamento << ", " << d.piso_departamento << ", " << d.prop_departamento << endl;
			 
		d = read<Departamento>(f);
	}

fclose(f);
	
return 0;
}

template <typename T> T read(FILE* f){
	T buff;
	fread(&buff,sizeof(T),1,f);
	return buff;
}

//template <typename T> void lecturaMain(){
//FILE* f = fopen("departamentos.DAT","rb+");
//
//
//	fclose(f);
//
//}
