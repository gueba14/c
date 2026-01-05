Algoritmo Integrador_empleados
	Definir empleados, opc, a, legajos, pos, sueldos Como Entero
	Definir nombre Como Caracter
	Dimension empleados[3,40]
	Dimension nombre[41,40]
	opc=0
	Mientras(opc<>5)
		Escribir"1-Cargar empleados"
		Escribir"2-Mostrar empleados"
		Escribir"3-Mostrar el sueldo de un empleado"
		Escribir"4-Modificar la categoria de un empleado"
		Escribir"5-Salir"
		Leer opc
	
		Segun opc Hacer
			1:
				para a=0 hasta 39 con paso 1
					Escribir "Ingrese el Legajo del empleado numero ", a+1,": "
					leer empleados[0,a]	
					Mientras (empleados[0,a]<10000 o empleados[0,a]>99999)
						Escribir "Ingrese el Legajo del empleado numero ", a+1,": "
						leer empleados[0,a]
					FinMientras
					Escribir "Ingrese el Nombre del empleado numero ", a+1,": "
                    leer nombre[,a]
					Escribir "Ingrese las Horas Trabajadas del empleado numero ", a+1,": "
					leer empleados[1,a] 
					Mientras (empleados[1,a]<0)
						Escribir "Ingrese las Horas Trabajadas del empleado numero ", a+1,": "
						leer empleados[1,a] 
					FinMientras
					Escribir "Ingrese la Categoria del empleado numero ", a+1,": "
					leer empleados[2,a] 
					Mientras (empleados[2,a]<0)
						Escribir "Ingrese la Categoria del empleado numero ", a+1,": "
						leer empleados[2,a] 
					FinMientras
				FinPara
			2:
				para a=0 hasta 39 con paso 1
					Escribir "o Legajo. ",empleados[0,a]
					Escribir "o Nombre. ",nombre[0,a]
					Escribir "o Horas trabajadas. ",empleados[1,a]
				
					segun empleados[2,a] hacer
						1:
							Escribir "o Categoria ", empleados[2,a]," - Planta"
						2:
							Escribir "o Categoria ", empleados[2,a]," - Administrativo"
						3:
							Escribir "o Categoria ", empleados[2,a]," - Vendedor"
					FinSegun
				FinPara
			3:
				pos=-1
				sueldo=0
				Escribir "Ingrese el legajo del empleado a buscar: "
				leer legajos
				Para a=0 hasta 39 con paso 1
					si(legajos=empleados[0,a])
						pos=a
					FinSi
				FinPara
				
				si(pos<>-1)
					Escribir "o Legajo. ",empleados[0,pos]
					Escribir "o Nombre. ",nombre[0,pos]
					segun empleados[2,pos] hacer
						1:
							sueldo=empleados[1,pos]*2000
						2:
							sueldo=empleados[1,pos]*1500
						3:
							sueldo=empleados[1,pos]*1000
					FinSegun
					
					Escribir "o Sueldo del empleado. ", sueldo
				SiNo
					Escribir "Empleado no encontrado"
				FinSi
				
			4:
				pos=-1
				Escribir "Ingrese el legajo del empleado a Modificar: "
				leer legajos
				Para a=0 hasta 39 con paso 1
					si(legajos=empleados[0,a])
						pos=a
					FinSi
				FinPara
				si(pos<>-1)
					Escribir "Ingrese la Categoria nueva del empleado numero ", pos+1,": "
					leer empleados[2,pos] 
					Mientras (empleados[2,pos]<0)
						Escribir "Ingrese la Categoria nueva del empleado numero ", pos+1,": "
						leer empleados[2,pos] 
					FinMientras
					Escribir "Dato modificado exitosamente"
				SiNo
					Escribir "Empleado no encontrado"
				FinSi
		Fin Segun
	FinMientras
FinAlgoritmo
