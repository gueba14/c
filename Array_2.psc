Algoritmo Array_2
	// Declarar un array de tipo entero de 5 componentes, asignarles un valor, mostrar la
	// suma de sus componentes y el promedio. 
	definir cualquiera Como Entero
	Definir suma, prom Como Real
	suma=0
	prom=0
	Dimension cualquiera[5]
	cualquiera[0]=25
	cualquiera[1]=86
	cualquiera[2]=34
	cualquiera[3]=47
	cualquiera[4]=10
	Para i=0 Hasta 4 Con Paso 1
		suma=suma+cualquiera[i]
	FinPara
	prom=suma/5
	mostrar "La suma es igual a: ", suma," y el promedio es igual a: ", prom
FinAlgoritmo
