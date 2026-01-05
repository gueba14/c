Algoritmo Peso
	Definir Peso_Kg, Peso_final Como Real
	Definir Opcion_usuario Como Caracter
	Escribir "ingrese el peso en Kg"
	Leer Peso_Kg
	Escribir "ingrese a que unidad quiere convertir (Gramo, Libra, Tonelada, Onza)"
	Leer Opcion_usuario
	Segun Opcion_usuario Hacer
		'Gramo':
			Peso_final=Peso_Kg*1000
			Escribir Peso_final," g"
		'Libra':
			Peso_final=Peso_Kg*2.20462
			Escribir Peso_final," Lib"
		'Tonelada':
			Peso_final=Peso_Kg*0.001
			Escribir Peso_final," Ton"
		'Onza':
			Peso_final=Peso_Kg*35.274
			Escribir Peso_final," Onz"
		De Otro Modo:
			Escribir "opcion incorrecta"
	Fin Segun
FinAlgoritmo
