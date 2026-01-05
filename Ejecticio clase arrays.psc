Algoritmo sin_titulo
	//	1. Realice un pseudocódigo que permita sumar los elementos de dos arreglos y guarde el resultado en otro arreglo. Deberá imprimir
	//	el arreglo resultante, el tamaño del arreglo será introducido por el usuario, se debe comprobar que el tamaño del arreglo sea válido,
	//	es decir, no permitir valores negativos y que sea mayor que 2.
	definir tamanio Como Entero
	
	repetir
		Escribir "Ingrese el tamaño del arrgelo a ingresar"
		leer tamanio
		si(tamanio<2)
			Escribir "valor incorrecto tamaño muy pequeño"
		FinSi
	Hasta Que (tamanio>=2)
	
	Dimensionar arreglo[tamanio]
	
	Dimensionar arreglo_2[tamanio]
	
	Dimensionar arreglo_3[tamanio]
	
	Para i=0 hasta tamanio-1 Con Paso 1
		Escribir "ingrese el valor del arreglo 1 espacio ",i+1
		leer arreglo[i]
	FinPara
	
	Para d=0 hasta tamanio-1 Con Paso 1
		Escribir "ingrese el valor del arreglo 2 espacio ",d+1
		leer arreglo_2[d]
	FinPara
	
	Escribir "Los valores del tercer arreglo son:"
	
	Para c=0 hasta tamanio-1 con paso 1
		arreglo_3[c]=arreglo[c]+arreglo_2[c]
		Escribir "Espacio ",c+1," - ",arreglo_3[c]
	FinPara
	
FinAlgoritmo
