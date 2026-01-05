#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASAJEROS 120
#define MAX_RUTAS 4

// Estructura para almacenar la información de cada pasajero
struct Pasajero {
    char nombre[50];
    int dni;
    int telefono;
    int equipaje_bodega;
    int pasajero_frecuente;
    int numero_asiento;
    int ruta;
    float costo;
};

// Estructura para almacenar la información de cada ruta
struct Ruta {
    char nombre[30];
    int capacidad;
    int vendidos;
    float precio_base;
    int tramo1;
    int tramo2;
    float incremento1;
    float incremento2;
};

// Inicializo las rutas con capacidad, precios y los tramos de incremento (cada cuanto, el porcentaje)
struct Ruta rutas[MAX_RUTAS] = {
    {"Buenos Aires-Bariloche", 120, 0, 150000, 20, 60, 1.10, 1.20},
    {"Buenos Aires-Salta", 120, 0, 120000, 20, 60, 1.10, 1.25},
    {"Rosario-Buenos Aires", 80, 0, 70000, 10, 40, 1.15, 1.35},
    {"Mar Del Plata-Mendoza", 80, 0, 95000, 10, 40, 1.15, 1.32}
};

// Array de pasajeros y contador de pasajeros
struct Pasajero pasajeros[MAX_PASAJEROS];
int contador_pasajeros = 0;

// Prototipos de funciones
void menu();
void ventaPasaje();
void buscarPasajeAsiento();
void buscarPasajeroNombre();
void ordenarPasajeros();
void listarEstadisticas();
float calcularCosto(int ruta, int vendidos, int equipaje_bodega);
int validarDNI(int dni);
int validarTelefono(int telefono);

// El principal (MAIN)
int main() {
    printf("Empresa de Viajes Aereos... Bienvenidos!\n");
    printf("__________________________________________\n");
    menu();
    return 0;
}

void menu() {
    int opcion;
    do {
        printf("\n Men%c \n", 163);
        printf("1. Venta de pasaje\n");
        printf("2. Buscar pasaje por n%cmero de asiento\n", 163);
        printf("3. Buscar pasajero por nombre y apellido\n");
        printf("4. Ordenar y mostrar lista de pasajeros\n");
        printf("5. Listado de estad%csticas\n", 161);
        printf("6. Salir\n\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ventaPasaje();
                break;
            case 2:
                buscarPasajeAsiento();
                break;
            case 3:
                buscarPasajeroNombre();
                break;
            case 4:
                ordenarPasajeros();
                break;
            case 5:
                listarEstadisticas();
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.\n", 162, 160);
        }
    } while (opcion != 6);
}

void ventaPasaje() {
    if (contador_pasajeros >= MAX_PASAJEROS) {
        printf("No hay m%cs asientos disponibles.\n", 160);
        return;
    }

    struct Pasajero p;
    int rutaSeleccionada;

    printf("\n Venta de Pasaje \n");
    printf("_______________________\n");
    printf("Seleccione la ruta:\n");
    for (int i = 0; i < MAX_RUTAS; i++) {
        printf("%d. %s (Disponibles: %d)\n", i + 1, rutas[i].nombre, rutas[i].capacidad - rutas[i].vendidos);
    }
    do {
        printf("Ingrese el n%cmero de la ruta: ", 163);
        scanf("%d", &rutaSeleccionada);
        if (rutaSeleccionada < 1 || rutaSeleccionada > 4) {
            printf("Opci%cn no v%clida. Reintente.\n", 162, 160);
        }
    } while (rutaSeleccionada < 1 || rutaSeleccionada > 4);

    rutaSeleccionada--; // Ajuste al índice del arreglo

    if (rutas[rutaSeleccionada].vendidos >= rutas[rutaSeleccionada].capacidad) {
        printf("No hay asientos disponibles en esta ruta.\n");
        return;
    }

    printf("Ingrese Nombre y Apellido: ");
    scanf(" %[^\n]s", p.nombre);
    
    do {
        printf("Ingrese DNI: ");
        scanf("%d", &p.dni);
        if (!validarDNI(p.dni)) {
            printf("DNI no v%clido. Debe estar entre 1000000 y 99999999.\n", 160);
        }
    } while (!validarDNI(p.dni));
    
    do {
        printf("Ingrese Tel%cfono (sin caracter%cstica ni 15): ", 130, 161);
        scanf("%d", &p.telefono);
        if (!validarTelefono(p.telefono)) {
            printf("Tel%cfono no v%clido. Debe ser mayor a 999999 (sin caracter%cstica ni 15).\n", 130, 160, 161);
        }
    } while (!validarTelefono(p.telefono));
    
    printf("¿Lleva equipaje en bodega? (1=S%c, 0=No): ", 161);
    scanf("%d", &p.equipaje_bodega);
    printf("Ingrese el n%cmero de pasajero frecuente: \n\n", 163);
    scanf("%d", &p.pasajero_frecuente);

    // Asignar asiento y calcular costo
    p.numero_asiento = rutas[rutaSeleccionada].vendidos + 1;
    p.ruta = rutaSeleccionada;
    p.costo = calcularCosto(rutaSeleccionada, rutas[rutaSeleccionada].vendidos, p.equipaje_bodega);
    pasajeros[contador_pasajeros++] = p;
    rutas[rutaSeleccionada].vendidos++;

    printf("Pasaje vendido con %cxito. Datos del pasaje:\n", 130);
    printf("Nombre: %s\n", p.nombre);
    printf("DNI: %d\n", p.dni);
    printf("Tel%cfono: %d\n", 130, p.telefono);
    printf("Ruta: %s\n", rutas[p.ruta].nombre);
    printf("Asiento: %d\n", p.numero_asiento);
    printf("Costo: %.2f\n", p.costo);
    printf("N%cmero de pasajero frecuente: %d\n", 163, p.pasajero_frecuente);
    printf("_________________________________________\n");
}

float calcularCosto(int ruta, int vendidos, int equipaje_bodega) {
    float costo = rutas[ruta].precio_base;
    if (vendidos >= rutas[ruta].tramo1) {
        costo *= rutas[ruta].incremento1;
    }
    if (vendidos >= rutas[ruta].tramo2) {
        costo *= rutas[ruta].incremento2;
    }
    if (equipaje_bodega) {
        costo *= 1.05; // Recargo del 5% por equipaje en bodega
    }
    return costo;
}

void buscarPasajeAsiento() {
    int rutaSeleccionada, numero_asiento;

    printf("\n B%csqueda de Pasaje por N%cmero de Asiento \n", 163, 163);
    printf("___________________________________________________\n");

    // Pedir primero la ruta
    printf("Seleccione la ruta para la b%csqueda:\n", 163);
    for (int i = 0; i < MAX_RUTAS; i++) {
        printf("%d. %s\n", i + 1, rutas[i].nombre);
    }
    do {
        printf("Ingrese el n%cmero de la ruta: ", 163);
        scanf("%d", &rutaSeleccionada);
        if (rutaSeleccionada < 1 || rutaSeleccionada > MAX_RUTAS) {
            printf("Opci%cn no v%clida. Reintente.\n", 161, 160);
        }
    } while (rutaSeleccionada < 1 || rutaSeleccionada > MAX_RUTAS);

    rutaSeleccionada--; // Ajustar al índice del arreglo

    printf("Ingrese el n%cmero de asiento del pasaje: ", 163);
    scanf("%d", &numero_asiento);

    for (int i = 0; i < contador_pasajeros; i++) {
        if (pasajeros[i].ruta == rutaSeleccionada && pasajeros[i].numero_asiento == numero_asiento) {
            printf("Pasajero encontrado:\n");
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("DNI: %d\n", pasajeros[i].dni);
            printf("Ruta: %s\n", rutas[pasajeros[i].ruta].nombre);
            return;
        }
    }
    printf("No se encontr%c ning%cn pasajero con ese n%cmero de asiento en la ruta seleccionada.\n", 162, 161, 163);
}

void buscarPasajeroNombre() {
    int rutaSeleccionada;
    char nombre[50];

    printf("\n B%csqueda de Pasajero por Nombre y Apellido \n", 163);
    printf("__________________________________________________________\n");

    // Pedir primero la ruta
    printf("Seleccione la ruta para la b%csqueda:\n", 163);
    for (int i = 0; i < MAX_RUTAS; i++) {
        printf("%d. %s\n", i + 1, rutas[i].nombre);
    }
    do {
        printf("Ingrese el n%cmero de la ruta: ", 163);
        scanf("%d", &rutaSeleccionada);
        if (rutaSeleccionada < 1 || rutaSeleccionada > MAX_RUTAS) {
            printf("Opci%cn no v%clida. Reintente.\n", 162, 160);
        }
    } while (rutaSeleccionada < 1 || rutaSeleccionada > MAX_RUTAS);

    rutaSeleccionada--; // Ajustar al índice del arreglo

    printf("Ingrese el nombre y apellido del pasajero: ");
    scanf(" %[^\n]s", nombre);

    for (int i = 0; i < contador_pasajeros; i++) {
        if (pasajeros[i].ruta == rutaSeleccionada && strcmp(pasajeros[i].nombre, nombre) == 0) {
            printf("Pasajero encontrado:\n");
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("DNI: %d\n", pasajeros[i].dni);
            printf("Ruta: %s\n", rutas[pasajeros[i].ruta].nombre);
            return;
        }
    }
    printf("No se encontr%c ning%cn pasajero con ese n%cmero de asiento en la ruta seleccionada.\n", 162, 161, 163);
}

void ordenarPasajeros() {
    struct Pasajero temp;
    for (int i = 0; i < contador_pasajeros - 1; i++) {
        for (int j = i + 1; j < contador_pasajeros; j++) {
            if (strcmp(pasajeros[i].nombre, pasajeros[j].nombre) > 0) {
                temp = pasajeros[i];
                pasajeros[i] = pasajeros[j];
                pasajeros[j] = temp;
            }
        }
    }

    printf("\n Lista de Pasajeros Ordenada \n");
    printf("_________________________________________\n");
    for (int i = 0; i < contador_pasajeros; i++) {
        printf("Nombre: %s, DNI: %d, Ruta: %s, Asiento: %d, Costo: %.2f\n",
               pasajeros[i].nombre, pasajeros[i].dni, rutas[pasajeros[i].ruta].nombre,
               pasajeros[i].numero_asiento, pasajeros[i].costo);
    }
}

void listarEstadisticas() {
    printf("\n Estad%csticas \n", 161);
    printf("_________________________________________\n");
    for (int i = 0; i < MAX_RUTAS; i++) {
        printf("Ruta: %s\n", rutas[i].nombre);
        printf("Pasajes vendidos: %d\n", rutas[i].vendidos);
        printf("Capacidad total: %d\n", rutas[i].capacidad);
        printf("Asientos disponibles: %d\n", rutas[i].capacidad - rutas[i].vendidos);
        printf("_________________________________________\n");
    }
}

int validarDNI(int dni) {
    return (dni >= 1000000 && dni <= 99999999);
}

int validarTelefono(int telefono) {
    return (telefono > 999999);
}
