// Comprobante Par Refinado
#include <stdio.h>
#include <stdlib.h>
int esPar(int num);
int main()
{
    int numero, resultado;
    printf("Ingrese un numero \n");
    scanf("%d", &numero);
    
    resultado=esPar(numero);
    if(resultado==1)
    {
        printf("El resultado es par");
    }
    else
    {
        printf("El resultado es impar");
    }
    return 0;
}
int esPar(int num)
{
    float res;
    int salida=0;
    res=num%2;
    if(res==0)
    {
        salida=1;
    }
    return salida;
}