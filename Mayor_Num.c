#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Num1, Num2, Num3;
    
    printf("ingrese los 3 numeros separados por espacios: \n");
    scanf("%f %f %f", &Num1, &Num2, &Num3);

    if((Num1>Num2) || (Num1==Num2))
    {
        if((Num2>Num3) || (Num1==Num3))
        {
            printf("El numero < %f > es el mayor",Num1);
        }else if((Num1>Num3) || (Num1==Num3)){
            printf("El numero < %f > es el mayor",Num1);
        }else{
            printf("El numero < %f > es el mayor",Num3);
        }
    }else{
        if((Num2>Num3) || (Num1==Num3))
        {
            printf("El numero < %f > es el mayor",Num2);
        }else{
            printf("El numero < %f > es el mayor",Num3);
        }
    }


    return 0;
}