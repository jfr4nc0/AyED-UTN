// Operaciones sobre archivos

/* Funcion: read
  Lee un registro de tipo T desde el archivo f. Para determinar si llego o no el eof se debe utilizar la funcion feof. */
template <typename T> T read(FILE* f);

/* Funcion: write
  Escribe el contenido del registro v, de tipo T, en el archivo f. */
template <typename T> void write(FILE* f, T v);

/* Funcion: seek
  Mueve el indicador de posicion del archivo f hacia el registro numero n. */
template <typename T> void seek(FILE* f, int n);

/* Funcion: fileSize
  Retorna la cantidad de registros que tiene el archivo f. */
template <typename T> long fileSize(FILE *f);

/* Funcion: filePos
  Retorna el numero de registro que esta siedo apuntado por el indicador de posicion del archivo. */
template <typename T> long filePos(FILE* f);

/* Funcion: busquedaBinaria
  Busca el valor v en el archivo f; retorna la posicion del registro que lo contiene o -1 si no se encuentra el valor. */
template <typename T, typename K>
int busquedaBinaria(FILE* f, K v, int (*criterio)(T,K));