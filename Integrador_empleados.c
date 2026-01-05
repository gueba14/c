#include <stdio.h>
#include <stdlib.h>

int main()
{
    int empleados[3][40], opcion, a, legajo, pos, sueldo;
    char nombres[][40]={"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
    do{
        printf("1-Cargar empleados\n2-Mostrar empleados\n3-Mostrar el sueldo de un empleado\n4-Modificar la categoria de un empleado\n5-Salir\n\n");
        scanf("%d",&opcion);
        system("pause");
        system("cls");
        switch(opcion)
        {
            case(1):
                for(a=0;a<40;a++)
                {
                    do{
                        printf("Ingrese el Legajo del empleado numero %d: ", a+1);
                        scanf("%d",&empleados[0][a]);
                    }while(empleados[0][a]<10000 || empleados[0][a]>99999);
                    printf("\n");
                    printf("Ingrese el Nombre del empleado numero %d: ", a+1);
                    scanf("%s",&nombres[a]);
                    printf("\n");
                    do{
                        printf("Ingrese el Horas trabajadas del empleado numero %d: ", a+1);
                        scanf("%d",&empleados[1][a]);
                    }while(empleados[1][a]<0);
                    printf("\n");
                    do{
                        printf("Ingrese la Categoria del empleado numero %d: ", a+1);
                        scanf("%d",&empleados[2][a]);
                    }while(empleados[2][a]!=1 && empleados[2][a]!=2 && empleados[2][a]!=3);
                    system("pause");
                    system("cls");
                }
                break;
            case(2):
                for(a=0;a<40;a++)
                {
                    printf("o Legajo. %d\n", empleados[0][a]);
                    printf("o Nombre. %s\n",nombres[a]);
                    printf("o Horas trabajadas. %d\n", empleados[1][a]);
                    switch(empleados[2][a])
                    {
                        case(1):
                            printf("o Categoria. %d - Planta\n", empleados[2][a]);
                            break;
                        case(2):
                            printf("o Categoria. %d - Administrativo\n", empleados[2][a]);
                            break;
                        case(3):
                            printf("o Categoria. %d - Vendedor\n", empleados[2][a]);
                            break;
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case(3):
                pos=-1;
                sueldo=0;
                printf("Ingrese el legajo del empleado a buscar: \n");
                scanf("%d", &legajo);
                for(a=0;a<40;a++)
                {
                    if(legajo==empleados[0][a])
                    {
                        pos=a;
                    }
                }
                if(pos!=-1)
                {
                    printf("o Legajo. %d\n", empleados[0][pos]);
                    printf("o Nombre. %s\n",nombres[pos]);
                    switch(empleados[2][pos])
                    {
                        case(1):
                            sueldo=empleados[1][pos]*2000;
                            break;
                        case(2):
                            sueldo=empleados[1][pos]*1500;
                            break;
                        case(3):
                            sueldo=empleados[1][pos]*1000;
                            break;
                    }
                    printf("o Sueldo del empleado. %d\n", sueldo);
                }
                else
                {
                    printf("Empleado no encontrado\n");
                }
                system("pause");
                system("cls");
                break;
            case(4):
                pos=-1;
                printf("Ingrese el legajo del empleado a Modificar: \n");
                scanf("%d", &legajo);
                for(a=0;a<40;a++)
                {
                    if(legajo==empleados[0][a])
                    {
                        pos=a;
                    }
                }
                if(pos!=-1)
                {
                    do{
                        printf("Ingrese la categoria nueva del empleado:\n");
                        scanf("%d",&empleados[2][pos]);
                    }while(empleados[2][pos]!=1 && empleados[2][pos]!=2 && empleados[2][pos]!=3);
                    printf("Dato modificado exitosamente\n");
                }
                else
                {
                    printf("Empleado no encontrado\n");
                }
                system("pause");
                system("cls");
                break;    
        }
    }while(opcion!=5);
    return 0;
}