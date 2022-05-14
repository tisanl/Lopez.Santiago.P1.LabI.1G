#include <stdio.h>
#include <stdlib.h>
#include "Parcial1.h"
#include <ctype.h>
#include <string.h>

#define AUX 300

void salirDelPrograma(char* confirm)
{
    fflush(stdin);
    scanf("%c", confirm);
    *confirm = tolower(*confirm);
}

int pedirNumeroConRango(int* numero, int menor, int mayor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    while(cant == 0 || *numero < menor || *numero > mayor)
    {
        printf("Opcion invalida. Ingrese un numero del %d al %d: ", menor, mayor);
        fflush(stdin);
        cant = scanf("%d", numero);
        todoOk = 1;
    }

    return todoOk;
}

int pedirNumeroConRangoMenu(int* numero, int menor, int mayor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    for(int i = 0; cant == 0 || *numero < menor || *numero > mayor; i++)
    {
        printf("Opcion invalida. Ingrese un numero del %d al %d: ",menor , mayor);
        fflush(stdin);
        cant = scanf("%d", numero);
        if(i == 7)
        {
            printf("\nHa realizado muchos intentos. Intente denuevo mas tarde.\n"
                   "Hasta luego\n\n");
            *numero = mayor +1;
            todoOk = 1;
            system("pause");
            break;
        }
    }

    return todoOk;
}

int pedirYValidarString(char string[], int len)
{
    char auxCad[AUX];
    int alpha;
    int todoOk = 0; //retorna case 0 si es largo y hay caracteres invalidos

    fflush(stdin);
    gets(auxCad);
    alpha = validarTodoAlpha(auxCad);
    if(strlen(auxCad) < len && alpha == 1) //devuelve 1 si esta todo bien y guarda el cambio
    {
        todoOk = 1;
        strcpy(string, auxCad);
    }
    else if(strlen(auxCad) > len && alpha == 1) //retorna -1 si es muy larga
    {
        todoOk = -1;
    }
    else if(strlen(auxCad) < len && alpha == 0) //retorna -2 si hay cosas que no son numero
    {
        todoOk = -2;
    }

    return todoOk;
}

int validarTodoAlpha(char auxCad[])
{
    int todoOk = 1;
    int cant;
    for(int i = 0; i < AUX -1; i++)
    {
        cant = isalpha(auxCad[i]);
        if(auxCad[i] == '\0')
        {
            break;
        }
        else if(cant == 0 && auxCad[i] != 32)
        {
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

void whyInvalidString(int caso)
{
    switch(caso)
    {
        case -1:
            printf(" muy largo. Intente nuevamente: ");
            break;
        case -2:
            printf(" con caracteres no validos. Intente nuevamente: ");
            break;
        case 0:
            printf(" con caracteres no validos y muy largo. Intente nuevamente: ");
            break;
    }
}

int pedirNumeroMenorToInfinito(int* numero, int menor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    while(cant == 0 || *numero < menor)
    {
        printf("Opcion invalida. Ingrese un numero mayor a %d: ", menor);
        fflush(stdin);
        cant = scanf("%d", numero);
        todoOk = 1;
    }

    return todoOk;
}

