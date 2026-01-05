#include <stdio.h>
#include <stdlib.h>
/* 7. Declarar un array de tipo decimal, que el usuario ingrese
 * la cantidad de notas a cargar, leer las notas por consola,
 * mostrar la suma de sus componentes y el promedio. */
int main()
{
    int cantidadNotas;
    float suma = 0, promedio = 0;
    printf("Ingrese la cantidad de notas.");
    scanf("%d", &cantidadNotas);
    float notas[cantidadNotas];
    for (int i = 0; i < cantidadNotas; i++)
    {
        printf("Ingrese nota nro. %d \n", i + 1);
        scanf("%f", &notas[i]);
        suma = suma + notas[i];
    }
    printf("La suma de los elementos del array es: %.2f\n", suma);
    promedio = suma / cantidadNotas;
    printf("El promedio es: %.2f\n", promedio);
    system("pause");
    return 0;
}