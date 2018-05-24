#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAMP 20
#define TAMA 100


int main()
{

    ePropietarios listaDePropietarios[TAMP];
    eAuto listaDeAutos[TAMA];
    //INICIALIZO ESTADO EN 0
    inicializarEstadoAutos(listaDeAutos,TAMA);
    inicializarEstadoPropietarios(listaDePropietarios,TAMP);

    //HARCODEO
    propietariosHardCode(listaDePropietarios,TAMP);
    autosHardcode(listaDeAutos,TAMA);

    char seguir='s';
    int opcion;
    int id;

    do
    {




        printf("1-Alta de propietario \n");
        printf("2-Modificacion de propietario \n");
        printf("3-Baja de propietario \n");
        printf("4-Ingreso de automovil\n");
        printf("5-Mostrar autos \n");
        printf("6-Recaudacion total del estacionamiento \n");
        printf("7-Recaudacion total por marca.\n");
        printf("8-Mostrar propietarios \n");
        printf("9-Mostrar propietario por id \n");
        printf("10-Datos de propietarios marca AUDI .\n");
        printf("11-Lista de autos estacionados,ordenado por patente .\n");
        printf("12-Egreso de auto.\n");
        printf("13- SALIR.\n");


        scanf(" %d",&opcion);

        switch(opcion)
        {

            case 1:

                darAltaPropietario(listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;

            case 2:
                modificarPropietario(listaDePropietarios,TAMP);
                fflush(stdin);
                system("pause");
                system("cls");
            break;

            case 3:
                darBajaPropietario(listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;

            case 4:

                darAltaAutoEstacionado(listaDeAutos,TAMA,listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;

            case 5:
                mostrarAutos(listaDeAutos,TAMA);
                system("pause");
                system("cls");

            break;
            case 6:
                recaudacionTotal(listaDeAutos,TAMA);
                system("pause");
                system("cls");
            break;
            case 7:
               recaudacionTotalPorMarca(listaDeAutos,TAMA);
                system("pause");
                system("cls");
            break;
            case 8:
                mostrarPropietarios(listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;
            case 9:
                mostrarPropietarios(listaDePropietarios,TAMP);
                printf("Ingrese id:");
                scanf("%d",&id);
                mostrarDatosPorId(listaDeAutos,TAMA,listaDePropietarios,TAMP,id);
                system("pause");
                system("cls");
            break;
            case 10:
                mostrarDatosDeAudi(listaDeAutos,TAMA,listaDePropietarios,TAMP);
                system("pause");
            system("cls");
                break;
            case 11:
                MostrarAutosOrdenadoConPatente(listaDeAutos,TAMA,listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;
            case 12:
                egresoDeAuto(listaDeAutos,TAMA,listaDePropietarios,TAMP);
                system("pause");
                system("cls");
            break;
            case 13:
                seguir='n';
            break;
}

}while(seguir=='s');

return 0;
}
