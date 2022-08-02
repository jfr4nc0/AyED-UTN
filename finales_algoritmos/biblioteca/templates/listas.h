// Operaciones sobre Listas
/* Estructura: Nodo */
template <typename T>
struct Nodo
{
  T info;        //valor que contiene el nodo
  Nodo<T>* sig;  //puntero al siguiente nodo
};

/* Funcion: agregar
  Agrega un nodo con valor v al final de la lista direccionada por p*/
template <typename T> void agregar(Nodo<T>*& p, T v);

/* Funcion: liberar
  Libera la memoria que insumen todos los nodos de la lista direccionada por p; finalmente asigna NULL a p.*/
template <typename T> void liberar(Nodo<T>*& p);

/* Funcion: buscar
  Retorna un puntero al primer nodo de la lista direccionada por p cuyo valor coincida con v, o NULL si ninguno de los nodos contiene a dicho valor. La funcion "criterio" debe comparar dos elementos t y k de tipo T y K respectivamente y retornar un valor menor, igual o mayor que creo segun: t<k, t=k o t>k.*/
template <typename T,typename K>
Nodo<T>* buscar(Nodo<T>* p, K v, int (*criterio)(T,K));

/* Funcion: eliminar
  Elimina el primer nodo de la lista direccionada por p cuyo valor coincida con v. El valor buscado puede no existir. Retorna (ok? True:False).*/
template <typename T, typename K>
bool eliminar(Nodo<T>*& p, K v, int (*criterio)(T,K));

/* Funcion: eliminarDoble
  Elimina el primer nodo de la lista doblemente enlazada direccionada por p en el inicio y q en el final cuyo valor coincida con v. El valor buscado puede no existir. Retorna (ok? True:False).*/
template <typename T,typename K>
bool eliminar(Nodo<T>*& p, Nodo<T>*& q, K v, int (*criterio)(T,K));

/* Funcion: eliminarPrimerNodo
  Elimina el primer nodo de la lista direccionada por p y retorna su valor. Si la lista contiene un unico nodo entonces luego de eliminarlo asignara NULL a p.*/
template <typename T> T eliminarPrimerNodo(Nodo<T>*& p);

/* Funcion: insertarOrdenado
  Inserta un nodo en la lista direccionada por p respetando el criterio de ordenamiento que establece la funcion criterio.*/
template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& p, T v, int (*criterio)(T,T));


/* Funcion: insertarDoble
  Idem para una lista doblemente enlazada direccionada por p. */
template <typename T>
Nodo<T>* insertarDoble(Nodo<T>*& p, Nodo<T>*& q, T v, int (*criterio)(T,T));

/* Funcion: ordenar
  Ordena la lista direccionada por p; el criterio de ordenamiento sera el que establece la funcion criterio. */
template <typename T> void ordenar(Nodo<T>*& p, int (*criterio)(T,T));

/* Funcion: buscarEInsertarOrdenado
  Busca en la lista direccionada por p la ocurrencia del primer nodo cuyo valor sea v. Si existe dicho nodo entonces retorna su direccion; de lo contrario lo inserta respetando el criterio de ordenamiento establecido por la funcion criterio y retorna la direccion del nodo insertado. Finalmente asigna true o false al parametro enc segun el valor v haya sido encontrado o insertado. */
template <typename T>
Nodo<T>* buscarEInsertarOrdenado(Nodo<T>*& p, T v, bool& enc, int (*criterio)(T,T));
