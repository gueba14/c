#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Peso_Kg, Peso_final;
    char Opcion_usuario[1];
    printf("ingrese el peso en Kg: \n");
    scanf("%f", &Peso_Kg);
    //printf("%f\n", Peso_Kg);    
    printf("ingrese a que unidad quiere convertir (Gramo => G, Libra => L, Tonelada => T, Onza => O): \n");
    scanf("%c", &Opcion_usuario);
    //printf("%d\n", Opcion_usuario);
    
    switch(Opcion_usuario){
        case ('G'):
            Peso_final=Peso_Kg*1000;
            printf("%f g\n", Peso_final);
        break;
        case ('L'):
            Peso_final=Peso_Kg*2.20462;
            printf("%f Lib\n", Peso_final);
        break;
        case ('T'):
            Peso_final=Peso_Kg*0.001;
            printf("%f Ton\n", Peso_final);
        break;
        case ('O'):
            Peso_final=Peso_Kg*35.274;
            printf("%f Onz\n", Peso_final);
        break;
        default:
            printf("opcion incorrecta\n");
    }
    system("pause");
    return 0;

}