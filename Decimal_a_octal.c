#include<stdlib.h>
#include<stdio.h>
int main()
{
    int  numero, digito, i=0, num=1, res=0;
    printf("::: ");
    scanf("%d", &numero);
    while(numero != 0)
    {
        digito=numero%8;
        if(digito==1)
        {
            res=res+num;
            //printf()
        }
        numero=numero/8;
        i++;
        num=num+num;
    }
    printf("%d", res);
    return 0;
}



int hexadecimal_decimal(char numero_hexa)
{
    return 0;
}







