#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	// Ingresar por consola 10 nombres de alumnos en un array y sus apellidos en otro,
	// concatenar de la forma "nombre apellido" para cada uno, y mostrar por consola.
    char nombre[10][50];
    char apellido[10][50];
    char nom_y_ap[10][100];
    for (int i=0;i<10;i++)
    {
        printf("Ingrese el nombre del la persona numero %d \n", i+1);
        scanf("%s", &nombre[i]);
        printf("Ingrese el apellido del la persona numero %d \n", i+1);
        scanf("%s", &apellido[i]);
        strcpy(nom_y_ap[i], nombre[i]);
        strcat(nom_y_ap[i], " ");
        strcat(nom_y_ap[i], apellido[i]);
    }
    for(int i=0;i<10;i++)
    {
        printf("%d Persona - Nombre y apellido: %s \n", i+1, nom_y_ap[i]);
    }
    return 0;
}
