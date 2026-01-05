Algoritmo triangulo
	Definir Lado1, Lado2, Lado3 Como Real
	Escribir "Ingrese uno de los lados del triangulo"
	Leer Lado1
	Escribir "Ingrese otro de los lados del triangulo"
	Leer Lado2
	Escribir "Ingrese otro de los lados del triangulo"
	Leer Lado3
	si ((Lado1=Lado2)y(Lado2=Lado3))
		escribir "Triangulo Equilátero"
	SiNo
		si((Lado1=Lado2)o(Lado1=Lado3)o(Lado2=Lado3))
			Escribir "Triangulo Isósceles"
		SiNo
			Escribir "Triangulo Escaleno"
		FinSi
	FinSi
FinAlgoritmo