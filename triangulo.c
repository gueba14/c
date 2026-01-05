#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Lado1, Lado2, Lado3;
	printf("Ingrese uno de los lados del triangulo \n");
	scanf("%d", &Lado1);
	printf("Ingrese otro de los lados del triangulo \n");
	scanf("%d", &Lado2);
	printf("Ingrese otro de los lados del triangulo \n");
	scanf("%d", &Lado3);
	if((Lado1==Lado2)&&(Lado2==Lado3)){
		printf("Triangulo Equilátero\n");
	}else{
		if((Lado1==Lado2)||(Lado1==Lado3)||(Lado2==Lado3)){
			printf("Triangulo Isósceles\n");
        }else{
			printf("Triangulo Escaleno");
		}
	}

    system("pause");
    return 0;
}