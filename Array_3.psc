hhAlgoritmo Array_3
	// Declarar un array de tipo entero de 5 componentes, asignarles un valor por consola,
	// mostrar cu�ntas veces se repite el n�mero 5. 
	definir cualquiera, rep, i Como Entero
	Dimension cualquiera[5]
	rep=0
	Para i=0 Hasta 4 Con Paso 1
		escribir "Ingrese ", i+1,"� numero: "
		Leer cualquiera[i]
		si(cualquiera[i]==5)
			rep=rep+1
		FinSi
	FinPara
	mostrar "El numero 5 se repite: ", rep," veces"
	
FinAlgoritmo
