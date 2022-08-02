// Operaciones sobre colas

/* Estructura: Nodo */
template <typename T>
struct Nodo
{
  T info;        //valor que contiene el nodo
  Nodo<T>* sig;  //puntero al siguiente nodo
};

/* Funcion: encolar
  Encola el valor v en la cola direccionada por p y q implementada sobre enlazada. */
template <typename T> void encolar(Nodo<T>*& p, Nodo<T>*& q, T v);

/* Funcion: desencolar
  Desencola y retorna el proximo valor de la cola direccionada por p y q implementada sobre una lista enlazada. */
template <typename T> T desencolar(Nodo<T>*& p, Nodo<T>*& q);
