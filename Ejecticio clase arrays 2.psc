Algoritmo sin_titulo
// 2. Escriba un algoritmo que lea un arreglo de N x 5 indicando que una empresa tiene N vendedores cada uno de los cuales vende 5
// productos. El arreglo almacena los ingresos obtenidos por cada vendedor en cada producto, imprimir el total de cada vendedor y
// obtener los ingresos totales de la tienda.
	Definir n Como Entero
	Definir ingresos, ingresos_tot Como real
	definir Vendedores Como Real
	ingresos=0
	ingresos_tot=0
	Escribir "Ingrese el numero de vendedors: "
	leer n
	Dimension Vendedores[n,5]
	Para p=0 Hasta n-1 Con Paso 1
		Para i=0 Hasta 4 Con Paso 1
			Escribir "Introdusca los ingresos del vendedor ",p+1," del producto ",i+1
			leer Vendedores[p,i]
		FinPara
	FinPara
	Para p=0 Hasta n-1 Con Paso 1
		Para i=0 Hasta 4 Con Paso 1
			ingresos = ingresos+vendedores[p,i]
		FinPara
		Escribir "Los ingresos del vendedor ",p+1," son: ",ingresos
		ingresos_tot=ingresos_tot+ingresos
		ingresos=0
	FinPara
	Escribir "Los ingresos total de la tienda son: ",ingresos_tot
	
FinAlgoritmo
