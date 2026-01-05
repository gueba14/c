Algoritmo tp_final
	Definir capacidad, pasajero_numeros, n, m, verificacion_ruta, verificacion_capacidad, cual_ruta, cual_espacio Como Entero
	Definir opc, opc_2, ruta, pasajero_nombre, ruta_ingresada, pasajero Como Caracter
	Definir pasajero_equipaje, existencia Como Logico
	Definir pasajero_precio Como Real
	opc='z'
	verificacion_ruta=0
	verificacion_capacidad=0
	Dimension ruta[4]
	Dimension capacidad[4,2]
	ruta[0] = "Buenos Aires-Bariloche"
	ruta[1] = "Buenos Aires-Salta"
	ruta[2] = "Rosario-Buenos Aires"
	ruta[3] = "Mar Del Plata-Mendoza"
	
	//ruta[X] ---- NOMBRE DEL VUELO
	
	capacidad[0,0]=120
	capacidad[1,0]=120
	capacidad[2,0]=80
	capacidad[3,0]=80
	capacidad[0,1]=capacidad[0,0]
	capacidad[1,1]=capacidad[1,0]
	capacidad[2,1]=capacidad[2,0]
	capacidad[3,1]=capacidad[3,0]
	//capacidad[N,P] ---- CANTIDAD DE ASIENTOS EN EL VUELO
	//N corresponde al vuelo
	//P=0 aca se guardan la cantidad total de asientos
	//P=1 aca se guardan la cantidad de asientos disponibles
	Dimension pasajero_nombre[120,4]
	Dimension pasajero_numeros[4,120,4]
	Dimension pasajero_equipaje[120,4]
	Dimension pasajero_precio[120,4]
	
	//pasajero_nombre[X,N] ---- NOMBRE y APELLIDO
	//pasajero_numeros[0,X,N] ---- DNI
	//pasajero_numeros[1,X,N] ---- TELÉFONO
	//pasajero_numeros[2,X,N] ---- FRECUENTE
	//pasajero_numeros[3,X,N] ---- ASIENTO
	//pasajero_equipaje[X,N] ---- EQUIPAJE EN BODEGA
	//pasajero_precio[X,N] ---- PRECIO DE BOLETO
	// X corresponde al numero del pasajero
	// N corresponde al vuelo
	Escribir "Bienvenido Usuario"
	Repetir
		
		Repetir
			Escribir "1. Venta pasaje"
			Escribir "2. Buscar pasaje vendido"
			Escribir "3. Buscar pasajero"
			Escribir "4. Ordenar y mostrar lista pasajeros"
			Escribir "5. Listado"
			Escribir " "
			Escribir "Escriba SALIR para finalizar"
			Escribir " "
			Leer opc
			
			Limpiar Pantalla
		Hasta Que opc=='1' o opc=='2' o opc=='3'o opc=='4' o opc=='5' o opc=='SALIR'
		
		Segun opc Hacer
			'1':
				
				verificacion_ruta=0
				verificacion_capacidad=0
				//ingresa ruta y verifica que exista y si tiene espacios
				//ingreso de datos del pasajere: Nombre y Apellido, 35845621, Teléfono, Equipaje en bodega y Número pasajero frecuente
				
				Lista(ruta)
				Escribir "Ingrese la ruta a viajar"
				Leer ruta_ingresada
				Limpiar Pantalla
				Para n=0 hasta 3 Con Paso 1
					si ruta[n]==ruta_ingresada
						verificacion_ruta=1
						cual_ruta=n
						si capacidad[n,1]<>0
							verificacion_capacidad=1
							cual_espacio=capacidad[n,0]-capacidad[n,1]
							capacidad[n,1]=capacidad[n,1]-1
						FinSi
					FinSi
				FinPara
				
				si verificacion_ruta==0
					
					Escribir "Vuelo no encontrado"
					
				SiNo
					
					Escribir "Vuelo encontrado"
					
					si verificacion_capacidad==0
						
						Escribir "Vuelo sin capadidad disponible"
						
					SiNo
						Escribir " "
						Escribir "Vuelo con capadidad disponible"
						
					FinSi
					
				FinSi
				
				Escribir " "
				si verificacion_ruta==1 y verificacion_capacidad==1
					Escribir "Ingrese su Nombre y Apellido"
					Leer pasajero_nombre[cual_espacio, cual_ruta]
					Escribir " "
					Repetir
						Escribir "Ingrese su DNI: "
						Leer pasajero_numeros[0, cual_espacio, cual_ruta]
						Escribir " "
					Hasta Que pasajero_numeros[0, cual_espacio, cual_ruta]>999999 y pasajero_numeros[0, cual_espacio, cual_ruta]<100000000
					Repetir
						Escribir "Ingrese su Telefono: "
						Leer pasajero_numeros[1, cual_espacio, cual_ruta]
						Escribir " "	
					Hasta Que pasajero_numeros[1, cual_espacio, cual_ruta]>999999999
					
					Escribir "Ingrese su Equipaje en bodega (Verdadero o Falso): "
					Leer pasajero_equipaje[cual_espacio, cual_ruta]
					Escribir " "
					Escribir "Ingrese su Numero de pasajero frecuente: "
					Leer pasajero_numeros[2, cual_espacio, cual_ruta]
					Escribir " "
					Limpiar Pantalla
					Boleto(ruta, cual_ruta, cual_espacio, pasajero_nombre, pasajero_numeros, pasajero_equipaje, pasajero_precio)
				FinSi
				
			'2':
				
				n=4
				existencia=FALSO
				Vuelo(cual_ruta, ruta)
				si cual_ruta>=0 y cual_ruta<=3
					Escribir "Ingrese el número de asiento del pasaje: "
					Leer cual_espacio
					Para n=0 hasta (capacidad[cual_ruta,0]-capacidad[cual_ruta,1]) con paso 1
						si pasajero_numeros[3, n, cual_ruta]==cual_espacio
							existencia=VERDADERO
						FinSi
					FinPara
					si existencia=VERDADERO
						Escribir "BOLETO: "
						Pasaje_2(ruta, pasajero_numeros, pasajero_nombre, cual_ruta, cual_espacio)
						Escribir "Pasaje no encontrado"
					FinSi
				SiNo
					Escribir "Vuelo no encontrado"
				FinSi
			'3':
				
				existencia=FALSO
				Vuelo(cual_ruta, ruta)
				si cual_ruta>=0	 y cual_ruta<=3
					Escribir "Ingrese el Nombre del pasajero: "
					Leer pasajero
					Para n=0 hasta (capacidad[cual_ruta,0]-capacidad[cual_ruta,1]) con paso 1
						si pasajero_nombre[n, cual_ruta]==pasajero
							existencia=VERDADERO
							cual_espacio=n+1
						FinSi
					FinPara
					si existencia=VERDADERO
						Escribir "PASAJERO: "
						Pasaje_2(ruta, pasajero_numeros, pasajero_nombre, cual_ruta, cual_espacio)
					SiNo
						Escribir "Pasaje no encontrado"
					FinSi
				SiNo
					Escribir "Vuelo no encontrado"
				FinSi
			'4':
				
				Vuelo(cual_ruta, ruta)
				
				si cual_ruta>=0 y cual_ruta<=3
					Repetir
						Escribir "Ordenar y mostrar lista pasajeros: "
						Escribir "------------------------------------"
						Escribir "a. Por número de asiento Ascendente"
						Escribir "------------------------------------"
						Escribir "b. Por número de asiento Descendente"
						Escribir "------------------------------------"
						Escribir "c. Salir"
						Escribir "------------------------------------"
						
						leer opc_2
						si (capacidad[cual_ruta,0]-capacidad[cual_ruta,1])<>0
							Limpiar Pantalla
							Sub_menu_1(opc_2, pasajero_nombre, cual_ruta, capacidad)
						SiNo
							Limpiar Pantalla
							Escribir "", ruta[cual_ruta], ":"
							Escribir "No hay pasajes comprados para este vuelo"
							Escribir ""
						FinSi
					Hasta Que opc_2=='c'
				SiNo
					Escribir "Vuelo no encontrado"
				FinSi
			'5':
				Repetir
					Escribir "Listado"
					Escribir "a. Cantidad de pasajes vendido por ruta aérea"
					Escribir "b. Porcentaje de ventas por ruta aérea "
					Escribir "c. Salir"
					leer opc_2
					Limpiar Pantalla
					para n=0 hasta 3 con paso 1
						cual_ruta=n
						si (capacidad[cual_ruta,0]-capacidad[cual_ruta,1])<>0
							Escribir "", ruta[cual_ruta], ": "
							
							Sub_menu_2(opc_2, pasajero_precio, cual_ruta , capacidad)
						SiNo
							Escribir "", ruta[cual_ruta], ": "
							Escribir "No hay pasajes comprados para este vuelo"
							Escribir ""
						FinSi
					FinPara
					
					
				Hasta Que opc_2=='c'

		Fin Segun
	Mientras que opc<>'SALIR'
FinAlgoritmo
SubProceso Lista(ruta Por Referencia)
	Definir n como entero
	Escribir "Rutas: "
	Escribir "----------------------------"
	Para n=0 Hasta 3 Con Paso 1
		Escribir ruta[n]
		Escribir "----------------------------"
	FinPara
	Escribir ""
FinSubProceso

SubProceso Sub_menu_1(opc_2 Por Referencia, pasajero_nombre Por Referencia, cual_ruta Por Referencia, capacidad Por Referencia)
	Definir n Como Entero
	Segun opc_2 Hacer
		'a':
			Escribir "Forma Ascendente: "
			Escribir ""
			Para n=0 hasta (capacidad[cual_ruta,0]-capacidad[cual_ruta,1])-1 Con Paso 1
				Escribir "------------------------------------"
				Escribir "Asiento ", n+1, ", Pasajero: ", pasajero_nombre[n, cual_ruta]
				Escribir "------------------------------------"
			FinPara
		'b':
			Escribir "Forma Descendente: "
			Escribir ""
			Para n=(capacidad[cual_ruta,0]-capacidad[cual_ruta,1])-1 hasta 0 Con Paso -1
				Escribir "------------------------------------"
				Escribir "Asiento ", n+1, ", Pasajero: ", pasajero_nombre[n, cual_ruta]
				Escribir "------------------------------------"
			FinPara
		'c':
			Limpiar Pantalla
		De Otro Modo:
			Escribir " "
			Escribir "Opcion  No Reconocida"
			Escribir " "
	Fin Segun
FinSubProceso

SubProceso Sub_menu_2(opc_2 Por Referencia, pasajero_precio Por Referencia, cual_ruta Por Referencia, capacidad Por Referencia)
	Definir total Como Real
	total=0
	Segun opc_2 Hacer
		'a':
			Escribir "Cantidad de Pasajeros en el vuelo: ",(capacidad[cual_ruta,0]-capacidad[cual_ruta,1])
			Escribir "------------------------------------"
		'b':
			Para n=0 hasta (capacidad[cual_ruta,0]-capacidad[cual_ruta,1])-1 Con Paso 1
				total=total+pasajero_precio[n,cual_ruta]
			FinPara
			Escribir "Ventas = $", total
		'c':
			Limpiar Pantalla
		De Otro Modo:
			Escribir " "
			Escribir "Opcion No Reconocida"
			Escribir " "
	Fin Segun
FinSubProceso

SubProceso Vuelo(cual_ruta Por Referencia, ruta Por Referencia)
	Definir n como entero
	Definir ruta_ingresada Como Caracter
	cual_ruta=0
	Lista(ruta)
	Escribir "Ingrese la ruta a viajar"
	Leer ruta_ingresada
	Limpiar Pantalla
	Para n=0 hasta 3 Con Paso 1
		si ruta[n]==ruta_ingresada
			cual_ruta=n
			Escribir " "
		FinSi
		
	FinPara
FinSubProceso
SubProceso Pasaje_2(ruta Por Referencia, pasajero_numeros Por Referencia, pasajero_nombre Por Referencia, cual_ruta Por Referencia, cual_espacio Por Referencia)
	Escribir "----------------------------"
	Escribir "Nombre y Apellido: ", pasajero_nombre[cual_espacio-1, cual_ruta]
	Escribir "----------------------------"
	Escribir "Ruta: ", ruta[cual_ruta]
	Escribir "----------------------------"
	Escribir "DNI: ", pasajero_numeros[0, cual_espacio-1, cual_ruta]
	Escribir "----------------------------"
FinSubProceso
SubProceso Precios(cual_espacio Por Referencia, pasajero_equipaje Por Referencia, pasajero_precio Por Referencia, cual_ruta Por Referencia)
	Segun cual_ruta
		0:
			Si cual_espacio<=20
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(150000+(150000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=150000
				FinSi
			FinSi
			si cual_espacio>20 y cual_espacio<=60
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(150000+((150000/100)*15)+((150000/100)*5))
				SiNo
					pasajero_precio[cual_espacio, cual_ruta]=(150000+((150000/100)*15))
				FinSi
			FinSi
			si cual_espacio>60
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(180000+(180000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=180000
				FinSi
			FinSi
		1:
			Si cual_espacio<=20
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(120000+(120000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=120000
				FinSi
			FinSi
			si cual_espacio>20 y cual_espacio<=60
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(120000+((120000/100)*15)+((120000/100)*5))
				SiNo
					pasajero_precio[cual_espacio, cual_ruta]=(120000+((120000/100)*15))
				FinSi
			FinSi
			si cual_espacio>60
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(150000+(150000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=150000
				FinSi
			FinSi
		2:
			Si cual_espacio<=10
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(70000+(70000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=70000
				FinSi
			FinSi
			si cual_espacio>10 y cual_espacio<=40
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(70000+((70000/100)*15)+((70000/100)*5))
				SiNo
					pasajero_precio[cual_espacio, cual_ruta]=(70000+((70000/100)*15))
				FinSi
			FinSi
			si cual_espacio>40
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(95000+(180000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=95000
				FinSi
			FinSi
		3:
			Si cual_espacio<=10
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(95000+(95000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=95000
				FinSi
			FinSi
			si cual_espacio>10 y cual_espacio<=40
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(95000+((95000/100)*15)+((95000/100)*5))
				SiNo
					pasajero_precio[cual_espacio, cual_ruta]=(95000+((95000/100)*15))
				FinSi
			FinSi
			si cual_espacio>40
				si pasajero_equipaje[cual_espacio, cual_ruta]==VERDADERO
					pasajero_precio[cual_espacio, cual_ruta]=(125000+(180000/100)*5)
				sino 
					pasajero_precio[cual_espacio, cual_ruta]=125000
				FinSi
			FinSi
	FinSegun
FinSubProceso
SubProceso Boleto(ruta Por Referencia, cual_ruta Por Referencia, cual_espacio Por Referencia, pasajero_nombre Por Referencia, pasajero_numeros Por Referencia, pasajero_equipaje Por Referencia, pasajero_precio Por Referencia)
	Escribir "BOLETO: "
	Escribir "----------------------------"
	Escribir "Ruta: ", ruta[cual_ruta]
	Escribir "----------------------------"
	Escribir "Nombre y Apellido: ", pasajero_nombre[cual_espacio, cual_ruta]
	Escribir "----------------------------"
	Escribir "DNI: ", pasajero_numeros[0, cual_espacio,cual_ruta]
	Escribir "----------------------------"
	Escribir "Telefono: ", pasajero_numeros[1, cual_espacio, cual_ruta]
	Escribir "----------------------------"
	Escribir "Equipaje en bodega: ", pasajero_equipaje[cual_espacio, cual_ruta]
	Escribir "----------------------------"
	Escribir "Número pasajero frecuente:", pasajero_numeros[2, cual_espacio, cual_ruta]
	Escribir "----------------------------"
	pasajero_numeros[3, cual_espacio, cual_ruta]=cual_espacio+1
	Escribir "Asiento: ", pasajero_numeros[3, cual_espacio, cual_ruta]
	Escribir "----------------------------"
	Precios(cual_espacio, pasajero_equipaje, pasajero_precio, cual_ruta)
	Escribir "Costo Pasaje: $", pasajero_precio[cual_espacio, cual_ruta]
	Escribir "----------------------------"
FinSubProceso
	