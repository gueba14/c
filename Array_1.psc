Algoritmo Array_1
	//. Declarar un array de tipo entero de 5 elementos, asignarles un valor, mostrar de la
	// forma: "Índice: X, Valor: Y" en el orden ingresado y de atrás hacia adelante.
	definir cualquiera Como Entero
	Dimension cualquiera[5]
	cualquiera[0]=7
	cualquiera[1]=45
	cualquiera[2]=99
	cualquiera[3]=-2
	cualquiera[4]=55
	Mostrar "De adelante para atrás"
	Para i=0 Hasta 4 Con Paso 1
		mostrar "Índice:", i, ", Valor:",cualquiera[i]
		
	FinPara
	Mostrar "De atrás para delante"
	Para i=4 Hasta 0 Con Paso -1
		mostrar "Índice:", i, ", Valor:",cualquiera[i]
	FinPara
	
FinAlgoritmo
