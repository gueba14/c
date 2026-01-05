#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d",&numero);
    printf("\n");
    if((numero%2)==0){
        printf("El numero es par\n");
    }else{
        printf("El numero es impar\n");
    }
    system("pause");
    return 0;
}
