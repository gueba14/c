Algoritmo Array_8
	// Leer 10 números por teclado, 5 para un array y 5 para otro array distinto. Mostrar los
	// 10 números en pantalla mediante un solo array. 
	Definir array1, array2, array3, i Como Entero
	Dimension array1[5], array2[5], array3[10]
	
	Para i=1 Hasta 5 Con Paso 1
		Escribir "ingrese el ", i,"° numero"
		Leer array1[i-1]
	FinPara
	
	Para i=1 Hasta 5 Con Paso 1
		Escribir "ingrese el ", i+5,"° numero"
		Leer array2[i-1]
	FinPara
	
	Para i=0 Hasta 9 con paso 1
		si i<5
			array3[i]=array1[i]
		SiNo 
			array3[i]=array2[i-5]
		FinSi
	FinPara
	
	Para i=0 Hasta 9 con paso 1
		Escribir array3[i]
		
	FinPara
FinAlgoritmo
