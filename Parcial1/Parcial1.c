#include <stdio.h>
#include <stdlib.h>
#include "Parcial1.h"
#include "LibreriaTrabajo.h"
#include "Validaciones.h"
#include <ctype.h>
#include <string.h>

int menu()
{
    int opcion;

    system("cls");
    printf("===========================================================\n");
    printf("******************** MENU DE MOTOS ********************\n");
    printf("===========================================================\n\n");
    printf("Opcion 1: Alta de moto\n");
    printf("Opcion 2: Modificacion de moto\n");
    printf("Opcion 3: Baja de moto\n");
    printf("Opcion 4: Listar motos\n");
    printf("Opcion 5: Listar tipos\n");
    printf("Opcion 6: Listar colores\n");
    printf("Opcion 7: Listar servicios\n");
    printf("Opcion 8: Alta Trabajo\n");
    printf("Opcion 9: Salir\n\n");
    printf("Ingrese una opcion: ");
    pedirNumeroConRangoMenu(&opcion, 1, 9);

    return opcion;
}

int initMoto(eMoto list[], int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}

int initTrabajo(eTrabajo list[], int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}

int preguntarSiHayLugarMotos(eMoto list[], int len)
{
   int vacio = 0;
   for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            vacio = 1;
            break;
        }
    }
    return vacio;
}

//AGREGAR MOTO
int addMoto(eMoto list[], int len, int* id)
{
    int todoOk = -1;
    int cant;
    char confirmacion = 'y';
    eTipo tipo[4];
    int numeroTipo;
    eColor color[5];
    int numeroColor;
    int cilindrado;
    int puntaje;

    system("cls");

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len && confirmacion == 'y'; i++)
        {
            if(list[i].isEmpty == 1)
            {
                //Pedir marca de la moto
                printf("\nIngrese la marca de la moto: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].marca, 20);
                while(cant != 1)
                {
                    printf("Marca");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].marca, 20);
                }

                //pedir tipo
                printf("\n");
                hardcodeoTipoMoto(tipo);
                mostrarTipoMoto(tipo);
                printf("Ingrese el numero que corresponda al tipo de moto: ");
                pedirNumeroConRango(&numeroTipo, 1, 4);
                numeroTipo -= 1;
                list[i].idTipo = tipo[numeroTipo].id;

                //pedir color
                printf("\n");
                hardcodeoColorMoto(color);
                mostrarColorMoto(color);
                printf("Ingrese el numero que corresponda al color de moto: ");
                pedirNumeroConRango(&numeroColor, 1, 5);
                numeroColor -= 1;
                list[i].idColor = color[numeroColor].id;

                //pedir cilindrado
                printf("\n");
                cilindrado = pedirCilindrado();
                list[i].cilindrada = cilindrado;

                //pedir puntaje
                printf("\n");
                puntaje = pedirPuntaje();
                list[i].puntaje = puntaje;

                //Poner id
                list[i].id = *id;

                //poner isEmpty
                list[i].isEmpty = 0;

                //mostrarPasajeroUnico(list, i);*/

                printf("\nDesea ingresar otra moto? Teclee 'y' para ingresar otro o cualquier otra tecla para salir: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);

                todoOk = 0;
            }
        }
    }

    system("pause");

    return todoOk;
}

void hardcodeoTipoMoto(eTipo tipo[])
{
    eTipo harcodeados[4]=
    {
        {1000, "Enduro"},
        {1001, "Chopera"},
        {1002, "Scooter"},
        {1003, "Vintage"}
    };

    for(int i = 0; i < 4; i++)
    {
        tipo[i].id = harcodeados[i].id;
        strcpy(tipo[i].descripcion, harcodeados[i].descripcion);
    }
}

void mostrarTipoMoto(eTipo tipo[])
{
    int numero;

    printf("=======================\n");
    printf("Numero||      Tipo     \n");
    printf("------||---------------\n");
    for(int i = 0; i < 4; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s\n", tipo[i].descripcion);
    }
    printf("========================\n");
    printf("\n");
}

void hardcodeoColorMoto(eColor color[])
{
    eColor harcodeados[5]=
    {
        {10000, "Gris"},
        {10001, "Negro"},
        {10002, "Azul"},
        {10003, "Blanco"},
        {10004, "Rojo"}
    };

    for(int i = 0; i < 5; i++)
    {
        color[i].id = harcodeados[i].id;
        strcpy(color[i].nombreColor, harcodeados[i].nombreColor);
    }
}

void mostrarColorMoto(eColor color[])
{
    int numero;

    printf("=======================\n");
    printf("Numero||      Color     \n");
    printf("------||---------------\n");
    for(int i = 0; i < 5; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s\n", color[i].nombreColor);
    }
    printf("========================\n");
    printf("\n");
}

int pedirCilindrado()
{
    int cilindrado;
    int cant;

    printf("Ingrese el cilindrado de la moto (50, 125, 500, 600 o 750): ");
    fflush(stdin);
    cant = scanf("%d", &cilindrado);
    while(cant == 0 || (cilindrado != 50 && cilindrado != 125 && cilindrado != 500 &&
                        cilindrado != 600 && cilindrado != 750))
    {
        printf("Numero invalido. Los cilindrados son 50, 125, 500, 600 o 750: ");
        fflush(stdin);
        cant = scanf("%d", &cilindrado);
    }

    return cilindrado;
}

int pedirPuntaje()
{
    int puntaje;
    int cant;

    printf("Ingrese el puntaje de la moto (del 1 al 10): ");
    pedirNumeroConRango(&puntaje, 1, 10);

    return puntaje;
}

//MODIFICACION MOTO
void pedirId(int* id)
{
    printf("Ingrese el Id de la moto que busca: ");
    pedirNumeroMenorToInfinito(id, 1000);
}

int findMotoById(eMoto list[], int len, int id)
{
    int array = -1;

    for(int i = 0;i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            array = i;
            printf("La moto ha sido encontrada.\n");
            break;
        }
    }

    return array;
}

void modifyMoto(eMoto list[], int len, int i)
{
    int cant;
    eColor color[5];
    int numeroColor;
    int puntaje;
    char confirm = 'n';

    //mostrarPasajeroUnico(list, i);
    do
    {
        system("cls");
        switch(subMenuModify())
        {
            case 1:
                //pedir color
                printf("\n");
                hardcodeoColorMoto(color);
                mostrarColorMoto(color);
                printf("Ingrese el numero que corresponda al color de moto: ");
                pedirNumeroConRango(&numeroColor, 1, 5);
                numeroColor -= 1;
                list[i].idColor = color[numeroColor].id;
                break;
            case 2:
                //pedir puntaje
                printf("\n");
                puntaje = pedirPuntaje();
                list[i].idTipo = puntaje;
                break;
        }
        printf("Ingrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu: ");
        salirDelPrograma(&confirm);
    }while(confirm == 'y');
}

int subMenuModify()
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE MODIFICACION ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Modificar el color\n");
    printf("Opcion 2: Modificar el puntaje\n");
    printf("Opcion 3: Salir\n\n");
    printf("Ingrese una opcion: ");
    pedirNumeroConRangoMenu(&opcion, 1, 3);

    return opcion;
}

int preguntarSiHayMotoCargada(eMoto list[], int len)
{
   int ocupado = 0;
   for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            ocupado = 1;
            break;
        }
    }
    return ocupado;
}

//BAJA MOTO
void removeMoto(eMoto list[], int len, int i)
{
    char confirmacionBaja;
    char confirm;

    do
    {
        printf("\nDesea dar de baja la moto? Escriba 'Y' para confirmar la baja: ");
        fflush(stdin);
        scanf("%c", &confirmacionBaja);
        confirmacionBaja = tolower(confirmacionBaja);
        if(confirmacionBaja == 'y')
        {
            list[i].isEmpty = 1;
            printf("La moto se ha dado de baja con exito.\n");
        }
        else
        {
            printf("La moto no se ha dado de baja.\n");
        }
        printf("Ingrese 'Y' si quiere registrar otra baja o cualquier otra tecla para volver al menu: ");
        salirDelPrograma(&confirm);

    }while(confirm == 'y');
}

//MOSTRAR
void listarMotos(eMoto list[], int len)
{
    eTipo tipo[4];
    eColor color[5];
    char stringTipo[20];
    char stringColor[20];

    hardcodeoTipoMoto(tipo);
    hardcodeoColorMoto(color);
    system("cls");
    printf("=============================================================================\n");
    printf("     Marca     ||  id  ||     Tipo     ||    Color   || Cilindrado || Puntaje\n");
    printf("---------------||------||--------------||------------||------------||--------\n");
    for(int i = 0; i < len && list[i].isEmpty == 0; i++)
    {
        printf("%15s||", list[i].marca);
        printf("%6d||", list[i].id);
        listarTipoMoto(list, i, tipo, stringTipo);
        printf("%14s||", stringTipo);
        listarColorMoto(list, i, color, stringColor);
        printf("%12s||", stringColor);
        printf("%12d||", list[i].cilindrada);
        printf("%8d\n", list[i].puntaje);
    }
    printf("=============================================================================\n");
    printf("\n");
}

void listarTipoMoto(eMoto list[], int j, eTipo tipo[], char stringTipo[20])
{
    for(int i = 0; i < 4; i++)
    {
        if(list[j].idTipo == tipo[i].id)
        {
            strcpy(stringTipo, tipo[i].descripcion);
        }
    }
}

void listarColorMoto(eMoto list[], int j, eColor color[], char stringColor[20])
{
    for(int i = 0; i < 5; i++)
    {
        if(list[j].idColor == color[i].id)
        {
            strcpy(stringColor, color[i].nombreColor);
        }
    }
}


