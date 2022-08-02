// Operaciones sobre pilas

/* Estructura: Nodo */
template <typename T>
struct Nodo
{
  T info;        //valor que contiene el nodo
  Nodo<T>* sig;  //puntero al siguiente nodo
};

/* Funcion: push
  Apilar el valor v a la pila direccionada por p. */
template <typename T> void push(Nodo<T>*& p, T v);

/* Funcion: pop
  Remueve y retorna el valor que se encuentra en la cima de la pila direccionada por p. */
template <typename T> T pop(Nodo<T>*& p);

