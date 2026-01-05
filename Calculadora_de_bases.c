#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void decimal_binario(int numero);
void decimal_octal(int numero);
void decimal_hexadecimal(int numero);
int binario_decimal(int numero);
int octal_decimal(char numero[]);
int hexadecimal_decimal(char numero_hexa[]);
int main()
{
  int choice_1, choice_2, num, num_dec, n;
  char num_hex[99999];
  char num_oct[99999];
  
  printf("test\n");
  do {
        for(n=0;n<=99999;n++)
        {
            num_oct[n]='.';
            num_hex[n]='.';
        }
        do{
            printf("Menu de ingreso de numero\n");
            printf("Opciones:\n");
            printf("1-Binario\n");
            printf("2-Octal\n");
            printf("3-Decimal\n");
            printf("4-Hexadecimal\n");
            printf("Ingrese la opcion que le corresponde al numero que este por ingresar: ");
            scanf("%d", &choice_1);
            printf("\n");
        }while(choice_1>4 || choice_1<1);

        switch(choice_1)
        {
            case 1:
                printf("ingrese su numero Binario: ");
                scanf("%d", &num);
                printf("\n");
                num_dec=binario_decimal(num);
                break;
            case 2:
                printf("ingrese su numero Octal: ");
                scanf("%s", &num_oct);
                num_dec=octal_decimal(num_oct);
                getchar();
                printf("\n");

                break;
            case 4:
                printf("ingrese su numero hexadecimal: ");
                scanf("%s", &num_hex);
                num_dec=hexadecimal_decimal(num_hex);
                getchar();
                printf("\n");
                break;
            default:
                printf("ingrese su numero Decimal: ");
                scanf("%d", &num);
                printf("\n");
                num_dec=num;
                break;
        }
        
        
        do{
            printf("\nMenu de opciones\n");
            printf("1. Pasar a numero a Binario\n");
            printf("2. Pasar a numero a Octal\n");
            printf("3. Pasar a numero Decimal\n");
            printf("4. Pasar a numero a Hexadecimal\n");
            printf("5. Salir\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &choice_2);
        }while(choice_2>5 || choice_2<1);
        switch(choice_2) 
        {
            case 1:  
                printf("\n");
                decimal_binario(num_dec);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("\n");
                decimal_octal(num_dec);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\n");
                printf("Numero Decimal: %d\n", num_dec);
                system("pause");
                system("cls");
                break;
            case 4:
                printf("\n");
                decimal_hexadecimal(num_dec);
                system("pause");
                system("cls");
                break;
            case 5:
                printf("test5\n");
                printf("Saliendo del programa");
                break;
            default:
                printf("Error");
                break;
        }
    } while (choice_2 != 5);
   return 0;
}
void decimal_binario(int numero_dec)
{
    //Este programa lo que hace es va paso por paso guardando de la misma manera en que se nos eneño en el apunte
    //La variable binario es el resto de las diviciones de entre el numero ingresado y 2 mostrandolas una por una
    //en orden invertido al que se optienen siendo guardadas en el array binario mientras tanto
    int i=0, binario[99999];
    while(numero_dec != 0)
    {
        binario[i]=numero_dec%2;
        numero_dec=numero_dec/2;
        i++;
    }
    i--;
    printf("Numero Binario: ");
    while(i>=0)
    {
        printf("%i",binario[i]);
        i--;
    }
    printf("\n");
    return;
}
void decimal_octal(int numero_dec)
{
    //Este programa lo que hace es va paso por paso guardando de la misma manera en que se nos eneño en el apunte
    //La variable octal es el resto de las diviciones de entre el numero ingresado y 8 mostrandolas una por una en
    //orden invertido al que se optienen siendo guardadas en el array octal mientras tanto
    int i=0, octal[99999];
    while(numero_dec != 0)
    {
        octal[i]=numero_dec%8;
        numero_dec=numero_dec/8;
        i++;
    }
    i--;
    printf("Numero Octal: ");
    while(i>=0)
    {
        printf("%i",octal[i]);
        i--;
    }
    printf("\n");
    return;
}
void decimal_hexadecimal(int numero_dec)
{
    //Este programa lo que hace es va paso por paso guardando de la misma manera en que se nos eneño en el apunte
    //La variable hexadecimal es el resto de las diviciones de entre el numero ingresado y 16 mostrandolas una por
    //una en orden invertido al que se optienen siendo guardadas en el array hexadecimal mientras tanto, cuando
    //son mostradas el switch detecta si son los nuemeros 10, 11, 12, 13, 14 o 15 y muestra la letra que le
    //corresponde a cada uno
    int i=0, hexadecimal[99999];
    while(numero_dec != 0)
    {
        hexadecimal[i]=numero_dec%16;
        numero_dec=numero_dec/16;
        i++;
    }
    i--;
    printf("Numero Hexadecimal: ");
    while(i>=0)
    {
        switch(hexadecimal[i])
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%i",hexadecimal[i]);
                break;
        }
        i--;
    }
    printf("\n");
    return;
}
int binario_decimal(int numero_bin)
{
    int digito, i=0, num=1, res=0;
    while(numero_bin != 0)
    {
        digito=numero_bin%2;
        if(digito==1)
        {
            res=res+num;
        }
        numero_bin=numero_bin/10;
        i++;
        num=num+num;
    }
    return res;
}
int octal_decimal(char numero_oct[])
{
    int n, m=0, inicio=-1, res=0;
    for(n=99998;n>=0;n--)
    {
        if(numero_oct[n]!='.' && inicio==-1)
        {
            inicio=n;
        }
    }
    inicio--;
    for(n=inicio;n>=0;n--)
    {

        switch(numero_oct[n])
        {
            
            case '0':
                res=res+0;

                break;
            case '1':
                res=res+(1*pow(8,m));

                break;
            case '2':
                res=res+(2*pow(8,m));

                break;
            case '3':
                res=res+(3*pow(8,m));

                break;
            case '4':
                res=res+(4*pow(8,m));

                break;
            case '5':
                res=res+(5*pow(8,m));

                break;
            case '6':
                res=res+(6*pow(8,m));

                break;
            case '7':
                res=res+(7*pow(8,m));

                break;
        }
        m++;
    }
    return res;
}
int hexadecimal_decimal(char numero_hexa[])
{
    int n, m=0, inicio=-1, res=0;
    for(n=99998;n>=0;n--)
    {
        if(numero_hexa[n]!='.' && inicio==-1)
        {
            inicio=n;
        }
    }
    inicio--;
    for(n=inicio;n>=0;n--)
    {

        switch(numero_hexa[n])
        {
            
            case '0':
                res=res+0;

                break;
            case '1':
                res=res+(1*pow(16,m));

                break;
            case '2':
                res=res+(2*pow(16,m));

                break;
            case '3':
                res=res+(3*pow(16,m));

                break;
            case '4':
                res=res+(4*pow(16,m));

                break;
            case '5':
                res=res+(5*pow(16,m));

                break;
            case '6':
                res=res+(6*pow(16,m));

                break;
            case '7':
                res=res+(7*pow(16,m));

                break;
            case '8':
                res=res+(8*pow(16,m));

                break;
            case '9':
                res=res+(9*pow(16,m));

                break;
            case 'A':
                res=res+(10*pow(16,m));

                break;
            case 'B':
                res=res+(11*pow(16,m));

                break;
            case 'C':
                res=res+(12*pow(16,m));

                break;
            case 'D':
                res=res+(13*pow(16,m));

                break;
            case 'E':
                res=res+(14*pow(16,m));

                break;
            case 'F':
                res=res+(15*pow(16,m));

                break;
        }
        m++;
    }
    return res;
}

