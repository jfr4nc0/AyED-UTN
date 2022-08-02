struct Estacion{
  char nombre[10];
  int fechaInicio;
  int fechaFin;
};
struct Nodo{
  Lectura info;
  Nodo* sig;
};
struct Fecha{
  int dia;
  int mes; // <--- lo he puesto como mes, porque con anio no tenia sentido el ejercicio //
};
struct Lectura{
  char zona;
  int reservas;
  fecha info;
};

const int N = 4;

Estacion EstacionDelAnio(int dia,int mes){
Estacion e;

  switch(mes){
    case 1:
      if(dia >= 1 && dia <= 31){
        e.nombre = "Verano";
        e.fechaInicio = 2112;
        e.fechaFin = 1903;
      }
    break;
    case 2:
      if(dia >= 1 && dia <= 28){
        e.nombre = "Verano";
        e.fechaInicio = 2112;
        e.fechaFin = 1903;
      }
    break;
    case 3:
      if(dia >= 1 && dia <= 19){
        e.nombre = "Verano";
        e.fechaInicio = 2112;
        e.fechaFin = 1903;
      } else {
        if(dia >= 20 && dia <= 31){
          e.nombre = "Otonio";
          e.fechaInicio = 2003;
          e.fechaFin = 2106;
        }
      }
    break;
    case 4:
      if(dia >= 1 && dia <= 30){
        e.nombre = "Otonio";
        e.fechaInicio = 2003;
        e.fechaFin = 2106;
      }
    break;
    case 5:
      if(dia >= 1 && dia <= 31){
        e.nombre = "Otonio";
        e.fechaInicio = 2003;
        e.fechaFin = 2106;
      }
    break;
    case 6:
      if(dia >= 1 && dia <= 21){
        e.nombre = "Otonio";
        e.fechaInicio = 2003;
        e.fechaFin = 2106;
      } else {
        if(dia >= 22 && dia <= 30){ // ----------------------- //
          e.nombre = "Invierno";
          e.fechaInicio = 2206;
          e.fechaFin = 2109;
        }
      }
    break;
    case 7:
      if(dia >= 1 && dia <= 31){
        e.nombre = "Invierno";
        e.fechaInicio = 2206;
        e.fechaFin = 2109;
      }
    break;
    case 8:
      if(dia >= 1 && dia <= 31){
        e.nombre = "Invierno";
        e.fechaInicio = 2206;
        e.fechaFin = 2109;
      }
    break;
    case 9:
      if(dia >= 1 && dia <= 21){
        e.nombre = "Invierno";
        e.fechaInicio = 2206;
        e.fechaFin = 2109;
      } else {
        if(dia >= 22 && dia <= 30){ // -------------------------- //
          e.nombre = "Primavera";
          e.fechaInicio = 2209;
          e.fechaFin = 2012;
        }
      }
    break;
    case 10:
      if(dia >= 1 && dia <= 31){
        e.nombre = "Primavera";
        e.fechaInicio = 2209;
        e.fechaFin = 2012;
      }
    break;
    case 11:
      if(dia >= 1 && dia <= 30){
        e.nombre = "Primavera";
        e.fechaInicio = 2209;
        e.fechaFin = 2012;
      }
    break;
    case 12:
      if(dia >= 1 && dia <= 20){
        e.nombre = "Primavera";
        e.fechaInicio = 2209;
        e.fechaFin = 2012;
      } else {
        if(dia >= 21 && dia <= 31){
          e.nombre = "Verano";
          e.fechaInicio = 2112;
          e.fechaFin = 1903;
        }
      }
    break;
    default:
      cout << "Fecha invalida" << endl;
  }
return e;
}

void cargarAMemoria(Nodo*& lista,FILE* f){
f = fopen("Reservas.dat","rb+");
Lectura l = read<Lectura>(f);
  while(!feof(f)){
    if(l.zona == 'M'){
      switch(l.mes){
        case 1:
          insertarOrdenado(lista,l);
        break;
        case 2:
          insertarOrdenado(lista,l);
        break;
        case 3:
          insertarOrdenado(lista,l);
        break;
        case 4:
          insertarOrdenado(lista,l);
        break;
        case 5:
          insertarOrdenado(lista,l);
        break;
        case 6:
          if(dia >= 1 && dia <= 21){
            insertarOrdenado(lista,l);
          }
        break;
        case 9:
          if(dia >= 22 && dia <= 30){
            insertarOrdenado(lista,l);
          }
        break;
        case 10:
          insertarOrdenado(lista,l);
        break;
        case 11:
          insertarOrdenado(lista,l);
        break;
        case 12:
          insertarOrdenado(lista,l);
        break;
      }
    }
    l = read<Lectura>(f);
  }
fclose(f);
return;
}

void insertarOrdenado(Nodo*& lista,Lectura l){
  Nodo* nuevo = new Nodo();
  nuevo->sig = NULL;
  nuevo->info = l;
    if(lista == NULL){
      lista = nuevo;
    } else {
      Nodo* aux = lista;
      Nodo* ant = NULL;
      while(aux != NULL && aux->info.dia <= l.dia){
        ant = aux;
        aux = aux->sig;
      }
      ant = nuevo;
      nuevo->sig = aux;
    }
}

template <typename T> T read(FILE* f){
  T buff;
  fread(&buff,sizeof(T),1,f);
  return buff;
}
