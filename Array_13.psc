Algoritmo Array_13
	// Ingresar por consola 10 nombres de alumnos en un array y sus apellidos en otro,
	// concatenar de la forma "nombre apellido" para cada uno, y mostrar por consola.
	Definir nombre, apellido, nom_y_ap Como Caracter
	Definir i, p Como Entero
	Dimension nombre[10], apellido[10], nom_y_ap[10]
	Para i=0 hasta 9 Con Paso i+1
		Escribir "Ingrese el nombre del la persona numero ", i+1
		Leer nombre[i]
		Escribir "Ingrese el apellido del la persona numero ", i+1
		leer apellido[i]
		nom_y_ap[i]=concatenar(nombre[i]," ")
		nom_y_ap[i]=concatenar(nom_y_ap[i],apellido[i])
	FinPara
	Para p=0 hasta 9 Con Paso p+1
		
		Escribir i," - Nombre y apellido: ", nom_y_ap[p]

	FinPara
FinAlgoritmo
