#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion, alumnos, prom_nota, a, n;
    float prom;
    opcion=0;
    prom_nota=0;
    prom=0;
    printf("Ingrese la cantidad de alumnos por comision: ");
    scanf("%d",&alumnos);
    float notas[alumnos][3];
    for(a=0;a<3;a++){
        for(n=0;n<alumnos;n++){
            notas[n][a]=0;
        }
    }
    system("pause");
    system("cls");
    while(opcion!=7)
    {
        do{
            printf("1. Cargar notas alumnos por comision\n2. Promedio por Comision\n3. Promedio de la materia\n4. Cantidad de aplazos en la materia\n5. Cantidad de regularizados en la materia\n6. Cantidad de aprobados en la materia\n7. Salir\n\nOpcion: ");
            scanf("%d",&opcion);
            printf("\n\n");
        }while(opcion<0 && opcion>7);
        switch(opcion)
        {
            case(1):
                for(a=0;a<3;a++){
                    printf("Cargando la comision %d\n", a+1);
                    for(n=0;n<alumnos;n++){
                        printf("Ingrese la nota del alumno %d: ",n+1);
                        scanf("%f", &notas[n][a]);
                    }
                }
                system("pause");
                system("cls");
                break;
            
            case(2):
                for(a=0;a<3;a++){
                    for(n=0;n<alumnos;n++){
                        prom=prom+notas[n][a];
                    }
                    prom=prom/alumnos;
                    printf("El promedio de la comision %d es: %f\n", a+1, prom);
                    prom=0;
                }
                system("pause");
                system("cls");
                break;
            
            case(3):
                for(a=0;a<3;a++){
                    for(n=0;n<alumnos;n++){
                        prom=prom+notas[n][a];
                    }  
                }
                prom=prom/(alumnos*3); 
                printf("El promedio de la materia es: %f\n", prom);
                prom=0;
                system("pause");
                system("cls");
                break;
            
            case(4):
                for(a=0;a<3;a++){
                    for(n=0;n<alumnos;n++){
                        if(notas[n][a]>=0 && notas[n][a]<4)
                        {
                            prom_nota++;
                        }
                    }  
                }
                printf("La cantidad de alumnos aplazos es: %d\n", prom_nota);
                prom_nota=0;
                system("pause");
                system("cls");
                break;
            
            case(5):
                for(a=0;a<3;a++){
                    for(n=0;n<alumnos;n++){
                        if(notas[n][a]>=4 && notas[n][a]<6)
                        {
                            prom_nota++;
                        }
                    }  
                }
                printf("La cantidad de alumnos regularizados es: %d\n", prom_nota);
                prom_nota=0;
                system("pause");
                system("cls");
                break;
            
            case(6):
                for(a=0;a<3;a++){
                    for(n=0;n<alumnos;n++){
                        if(notas[n][a]>=6)
                        {
                            prom_nota++;
                        }
                    }  
                }
                printf("La cantidad de alumnos aprobados es: %d\n", prom_nota);
                prom_nota=0;
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}