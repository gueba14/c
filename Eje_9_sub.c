#include<stdlib.h>
#include<stdio.h>
//* Crear una función que reciba un caracter y un número, y escriba un “triángulo”
//*formado por ese caracter, que tenga como anchura inicial la que se ha indicado.
//*Por ejemplo, si la caracter es * y la anchura es 4, debería escribir: //*
void FormarFigura(int ancho, char caracter);
int main()
{
    int anchura;
    char caracter;
    printf("Digite la anchura de la figura: ");
    scanf("%d", &anchura);
    printf("Digite el caracter de la figura: ");
    caracter=getchar();
    printf("Aqui esta su figura: \n");
    FormarFigura(anchura, caracter);
    return 0;
}
void FormarFigura(int ancho, char caracter)
{
    for(int i=ancho; i>0; i--)
    {
        for(int j=i; j>0; j--)
        {
            printf("%c", caracter);
        }
        printf("\n");
    }
}