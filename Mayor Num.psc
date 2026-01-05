Algoritmo sin_titulo
	Definir Num1, Num2, Num3 Como Entero
	
	Escribir "Ingrese el Primer numero"
	Leer Num1
	Escribir "Ingrese el Segundo numero"
	Leer Num2
	Escribir "Ingrese el Tercer numero"
	Leer Num3
	si(Num1>Num2 o Num1==Num2)
		si(Num2>Num3 o Num2==Num3)
			Escribir "El numero ",Num1 ," es el mayor"
		SiNo
			Si(Num1>num3 o Num1==Num3)
				Escribir "El numero ",Num1 ," es el mayor"
			SiNo
				Escribir "El numero ",Num3 ," es el mayor"
			FinSi
		FinSi
	SiNo
		si(Num2>Num3 o Num2==Num3)
			Escribir "El numero ",Num2 ," es el mayor"
		SiNo
			Escribir "El numero ",Num3 ," es el mayor"
		FinSi
		
	FinSi
FinAlgoritmo
