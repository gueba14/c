#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	// Escribe un programa que solicite al usuario una cadena de caracteres y luego cuente el
	// número de vocales que contiene
    char palabra[50];
    char letra;
    int longitud, vocales, i;
    vocales=0;
    printf("ingrese la cadena\n");
    scanf("%s", &palabra);
    for (i=0;i<strlen(palabra);i++)
    {
        letra=palabra[i];
        if(letra=='a'||letra=='A'||letra=='o'||letra=='O'||letra=='i'||letra=='I'||letra=='u'||letra=='U'||letra=='e'||letra=='E')
        {
            vocales++;
        }
    }
    printf("la cantidad de vocales es: %d", vocales);
    return 0;
}


