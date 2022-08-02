// ----- 1 ----- //
struct Contacto{
  int idUsuario;
  char nombreContacto[30];
  bool bloqueado;
};
struct DatoConversacion{
  int idConversacion;
  char nombre[30];
  bool notificar;
  bool vistaPrevia;
};
struct Nodo{
  DatoConversacion info;
  Nodo* sig;
};

int N = 200;
Nodo* lista = NULL;
Contacto arregloContactos[N];

// ----- 3 ----- //
void notificarMensajeRecibido(Nodo* lista,Contact arregloContactos[],int N,int idConversacion,int idUsuarioEmisor,Mensaje m){
Nodo* aux = lista
string titulo, descripcion;
int i = 200;
int j = 0;

  while(j < i && arregloContactos[j].idUsuario != idUsuarioEmisor){
    j++;
  }
  while(aux != NULL && aux->info.idConversacion != idConversacion){
    aux = aux->sig;
  }
  if(aux->info.nombre != """"){ // conversacion grupal
    if(aux->info.notificar == 1){
      titulo = aux->info.nombre;
      if(aux->info.vistaPrevia == 1){ // con vista previa
        if(j == i){
          descripcion = numeroTelefonicoDelUsuario(idUsuarioEmisor) + ": " + vistaPreviaMensaje(m);
        } else {
          descripcion = arregloContactos[j].nombreContacto + ": " + vistaPreviaMensaje(m);
        }
      } else { // sin vista previa
        if(j == i){
          descripcion = "Nuevo mensaje de: " + numeroTelefonicoDelUsuario(idUsuarioEmisor);
        } else {
          descripcion = "Nuevo mensaje de: " + arregloContactos[j].nombreContacto;
        }
      }
    }
  } else { // conversacion directa
    if(aux->info.nombre == """"){
      if(j != i && arregloContactos[j].bloqueado == 0){ // está en lista de contactos
        if(aux->info.notificar == 1){
          titulo = arregloContactos[j].nombreContacto;
          if(aux->info.vistaPrevia == 1){
            descripcion = vistaPreviaMensaje(m);
          } else {
            descripcion = "Nuevo mensaje.";
          }
        }
      } else { // no está en lista de contactos // suponiendo que no se puede elegir si se quiere o no la notificacion de numeros desconocidos
        if(j == i){                             // suponiendo que sí se puede elgir si se quiere la vista previa o no de numeros desconocidos
        titulo = numeroTelefonicoDelUsuario(idUsuarioEmisor);
          if(aux->info.vistaPrevia == 1){
            descripcion = vistaPreviaMensaje(m);
          } else {
            descripcion = "Nuevo mensaje.";
          }
        }
      }
    }
  }
emitirNotificacion(titulo,descripcion);
return;
}
