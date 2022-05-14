#include <stdio.h>
#include <stdlib.h>
#include "Parcial1.h"
#include "LibreriaTrabajo.h"
#include "Validaciones.h"
#include <ctype.h>
#include <string.h>

#define LENMOTO 1000
#define LENTRABAJO 1000


int main()
{
    char confirm = 'n';
    char confirmacion;
    int idTrabajo = 1000;
    int idMoto = 1000;
    eMoto motos[LENMOTO];
    eTrabajo trabajos[LENTRABAJO];
    int cant;
    int idPedido;
    int arrayEncontrado;


    if((initMoto(motos, LENMOTO)) == 0 && (initTrabajo(trabajos, LENTRABAJO)) == 0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    cant = preguntarSiHayLugarMotos(motos, LENMOTO);
                    if(cant == 1)
                    {
                        addMoto(motos, LENMOTO, &idMoto);
                        idMoto ++;
                    }
                    else
                    {
                        printf("No hay lugar en la base.\n");
                        system("pause");
                    }
                    break;
                case 2:
                     //modificar
                    cant = preguntarSiHayMotoCargada(motos ,LENMOTO);
                    if(cant == 1)
                    {
                        listarMotos(motos, LENMOTO);
                        pedirId(&idPedido);
                        arrayEncontrado = findMotoById(motos, LENMOTO, idPedido);
                        if(arrayEncontrado == -1)
                        {
                            printf("El id no tiene ninguna moto asociada.\n");
                        }
                        else
                        {
                            modifyMoto(motos, LENMOTO, arrayEncontrado);
                        }
                    }
                    else
                    {
                        printf("No hay cargada ninguna moto en el sistema\n");
                    }

                    system("pause");
                    break;
                case 3: //dar de baja
                    do
                    {
                        cant = preguntarSiHayMotoCargada(motos ,LENMOTO);
                        if(cant == 1)
                        {
                            listarMotos(motos, LENMOTO);
                            pedirId(&idPedido);
                            arrayEncontrado = findMotoById(motos, LENMOTO, idPedido);
                            if(arrayEncontrado == -1)
                            {
                                printf("El id no tiene ninguna moto asociada.\n");
                            }
                            else
                            {
                                removeMoto(motos, LENMOTO, arrayEncontrado);
                            }
                        }
                        else
                        {
                            printf("No hay cargada ninguna moto en el sistema\n");
                        }
                        salirDelPrograma(&confirmacion);
                    }while(confirmacion == 'y');
                    system("pause");
                    break;
                case 4:
                    //informar
                    listarMotos(motos, LENMOTO);
                    break;
                case 5:

                    break;
                case 6:
                    //informar
                    break;
                case 7:
                    //informar
                    break;
                case 8:
                    listarMotos(motos, LENMOTO);
                    pedirId(&idPedido);
                    arrayEncontrado = findMotoById(motos, LENMOTO, idPedido);
                    if(arrayEncontrado == -1)
                    {
                        printf("El id no tiene ninguna moto asociada.\n");
                    }
                    else
                    {
                        addTrabajo(trabajos, motos, LENTRABAJO, LENMOTO, arrayEncontrado, idTrabajo);
                        idTrabajo ++;
                    }
                    break;
                case 9:
                    printf("Desea salir del programa? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
                    salirDelPrograma(&confirm);
                    break;
                default:
                    confirm = 'y';
            }
        }while(confirm != 'y');
    }

    printf("\nHasta luego!!\n\n");
    system("pause");

    return 0;
}

