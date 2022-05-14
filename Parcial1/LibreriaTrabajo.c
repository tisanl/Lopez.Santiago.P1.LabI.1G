#include <stdio.h>
#include <stdlib.h>
#include "Parcial1.h"
#include "LibreriaTrabajo.h"
#include "Validaciones.h"
#include <ctype.h>
#include <string.h>


int addTrabajo(eTrabajo trabajos[], eMoto motos[], int lenTrabajo, int lenMoto, int array, int id)
{
    int todoOk = -1;
    char confirmacion = 'y';
    eServicio servicio[4];
    int numeroServicio;

    system("cls");

    for(int i = 0; i < lenTrabajo && confirmacion == 'y'; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            trabajos[i].id = id;
            trabajos[i].idMoto = motos[array].id;


            //pedir servicio
            printf("\n");
            hardcodeoServicio(servicio);
            mostrarServicio(servicio);
            printf("Ingrese el numero que corresponda al servicio para la moto: ");
            pedirNumeroConRango(&numeroServicio, 1, 4);
            numeroServicio -= 1;
            trabajos[i].idServicio = servicio[numeroServicio].id;

            trabajos[i].isEmpty = 0;

            printf("\nDesea ingresar añadir otro trabajo? Teclee 'y' para ingresar otro o cualquier otra tecla para salir: ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            todoOk = 0;
        }
    }

    system("pause");

    return todoOk;
}

void hardcodeoServicio(eServicio servicio[])
{
    eServicio harcodeados[5]=
    {
        {20000, "Limpieza"},
        {20001, "Ajuste"},
        {20002, "Balanceo"},
        {20003, "Cadena"},
    };

    for(int i = 0; i < 5; i++)
    {
        servicio[i].id = harcodeados[i].id;
        strcpy(servicio[i].descripcion, harcodeados[i].descripcion);
    }
}

void mostrarServicio(eServicio servicio[])
{
    int numero;

    printf("=======================\n");
    printf("Numero||    Servicio   \n");
    printf("------||---------------\n");
    for(int i = 0; i < 4; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s\n", servicio[i].descripcion);
    }
    printf("========================\n");
    printf("\n");
}

