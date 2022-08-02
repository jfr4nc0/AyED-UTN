/* Funcion: agregar
Agrega el valor v al final del array arr e incrementa su longitud len */
template <typename T> void agregar(T arr[], int& len, T v);

/* Funcion: buscar
  Busca la primer ocurrencia de v en arr; retorna su posicion o un valor negativo si arr no contiene a v. La funcion "criterio" debe recibir dos parametros t y k de tipo T y K respectivamente y retornar un valor negativo, cero o positivo segun t sea menor, igual o mayor que k */
template <typename T,typename K>
int buscar(T arr[], int len, K v, int (*criterio)(T,K));

/* Funcion: eliminar
  Elimina el valor ubicado en la posicion pos del array arr, decrementando su longitud len */
template <typename T> void eliminar(T arr[], int& len, int pos);

/* Funcion: insertar
  Inserta el valor v en la posicion pos del array arr, incrementando su longitud len */
template <typename T> void insertar(T arr[], int& len, T v, int pos);

/* Funcion: insertarOrdenado
  Inserta el valor v en el array arr en la posicion que corresponda segun el criterio de precedencia que estableca la funcion criterio; esta funcion recibe dos parametros v1 y v2 ambos tipo T y retorna un valor negativo, cero o positivo segun v1 sea menor, igual o mayor que v2 respectivamente. */
template <typename T>
int insertarOrdenado(T arr[], int& len, T v, int (*criterio)(T,T));

/* Funcion: buscarEInsertarOrdenado
  Busca el valor v en el array arr; si lo encuentra entonces retorna su posicion y asigna true al parametro enc. De lo contrario lo inserta donde corresponda segun el criterio "criterio", asigna false al parametro enc y retorna la posicion en donde finalmente quedo ubicado el nuevo valor. */
template <typename T>
int buscarEInsertarOrdenado(T arr[], int& len, T v, bool& enc, int (*criterio)(T,T));

/* Funcion: ordenar
  Ordena el array arr segun el criterio de precedencia que establece la funcion "criterio".*/
template <typename T> void ordenar(T arr[], int len, int (*criterio)(T,T));

/* Funcion: busquedaBinaria
  Busca el elemento v en el array arr que debe estar ordenado segun el criterio "criterio". Retorna la posicion en donde se encontro el elemento (si se encontro) o la posicion en donde dicho elemento podria ser insertado manteniendo el criterio que establece la funcion "criterio" que recibe como parametro.*/
template <typename T, typename K>
int busquedaBinaria(T arr[], int len, K v, int (*criterio)(T,K), bool& enc);