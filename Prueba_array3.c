#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n;
    char num_hex[999999];
    for(n=0;n<=9;n=n+1)
    {
        num_hex[n]='.';
    }
    printf("ingrese su numero hexadecimal: ");
    scanf("%s", &num_hex);
    
    printf("todo: %s\n", num_hex);
    printf("\n");
    for(n=0;n<=9;n=n+1)
    {
        if(num_hex[n]!='.')
        {
            printf("%d: %c\n", n, num_hex[n]);
        }
    }

    return 0;
}