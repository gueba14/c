#include <stdio.h>
#include <stdlib.h>
/*Leer 10 números por teclado, 5 para un array y 5 para otro array distinto. Mostrar los
10 números en pantalla mediante un solo array.*/
int main()
{
    int numeros1[5], numeros2[5], numeros3[10], i;
    for ( i = 0; i < 5 ; i++ )
    {
        printf("Ingrese el %dº numero", i);
        scanf("%d", &numeros1[i]);
    }
    for ( i = 0; i < 5 ; i++ )
    {
        printf("Ingrese el %dº numero", i+5);
        scanf("%d", &numeros2[i]);
    }
return 0;
}

