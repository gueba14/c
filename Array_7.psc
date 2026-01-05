Algoritmo Array_7
	// Declarar un array de tipo decimal, que el usuario ingrese la cantidad de notas a cargar,
	// leer las notas por consola, mostrar la suma de sus componentes y el promedio.
	Definir cantidad, i Como Entero
	Definir suma, prom Como Real
	Escribir "ingrese la cantidad de notas a ingresar"
	Leer cantidad
	Definir array Como Real
	Dimension array[cantidad]
	Para i=0 Hasta cantidad-1 con paso 1
		Escribir "ingrese el ", i+1,"° numero"
		Leer array[i]
	FinPara
	Para i=0 Hasta cantidad-1 con paso 1
		suma=suma+array[i]
	FinPara
	prom=suma/cantidad
	Escribir "La suma de los numeros es: ", suma," y su promedio es: ", prom
FinAlgoritmo
