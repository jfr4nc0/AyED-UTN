template <typename T> void agregar(T arr[], T v, int &len){
	arr[len] = v;
	len++;
}

template <typename T, typename K> int buscar(T arr[], int len, K v, int (*criterio)(T,K)){
	int i = 0;
	while(i < len && criterio(arr[i],v) != 0){
		i++;
	}
	return i<len ? i : -1;
}
