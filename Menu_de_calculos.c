#include <stdio.h>
#include <stdlib.h>

float suma(float num1, float num2);
float resta(float num1, float num2);
float multiplicacion(float num1, float num2);
float divicion(float num1, float num2);

int main()
{
    int opcion;
    float numero1, numero2, resultado;
    opcion=0;
    while(opcion!=5)
    {
        do
        {   
            system("cls");
            printf("1. Informar su suma\n2. Informar su resta\n3. Informar su multiplicacion\n4. Informar su division\n5. Salir\nSeleccione una operacion: \n\n");
            scanf("%d", &opcion);
        }while(opcion<1 && opcion>5);
    
        switch(opcion)
        {
            case(1):
                system("cls");
                printf("ingrese el primer numero\n");
                scanf("%f", &numero1);
                printf("ingrese el segundo numero a sumar\n");
                scanf("%f", &numero2);
                resultado=suma(numero1, numero2);
                printf("La suma de %f y %f es %f\n\n", numero1, numero2, resultado);
                opcion=0;
                system("pause");
                break;
            case(2):
                system("cls");
                printf("ingrese el primer numero\n");
                scanf("%f", &numero1);
                printf("ingrese el segundo numero a restar\n");
                scanf("%f", &numero2);
                resultado=resta(numero1, numero2);
                printf("La resta de %f y %f es %f\n\n", numero1, numero2, resultado);
                opcion=0;
                system("pause");
                break;
            case(3):
                system("cls");
                printf("ingrese el primer numero\n");
                scanf("%f", &numero1);
                printf("ingrese el multiplicador\n");
                scanf("%f", &numero2);
                resultado=multiplicacion(numero1, numero2);
                printf("La multiplicación de %f y %f es %f\n\n", numero1, numero2, resultado);
                opcion=0;
                system("pause");
                break;
            case(4):
                system("cls");
                printf("ingrese el dividendo\n");
                scanf("%f", &numero1);
                printf("ingrese el divisor\n");
                scanf("%f", &numero2);
                resultado=divicion(numero1, numero2);
                printf("La división de %f y %f es %f\n\n", numero1, numero2, resultado);
                opcion=0;
                system("pause");
                break;
        }
    }
    return 0;
}
float suma(float num1, float num2)
{
    float res;
    res=num1+num2;
    return res;
}
float resta(float num1, float num2)
{
    float res;
    res=num1-num2;
    return res;
}
float multiplicacion(float num1, float num2)
{
    float res;
    res=num1*num2;
    return res;
}
float divicion(float num1, float num2)
{
    float res;
    res=num1/num2;
    return res;
}
