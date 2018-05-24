#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lib.h"
#include "time.h"
#define   ALPHA_ROMEO 1
#define   FERRARI 2
#define  AUDI 3
#define  OTRO 4



void ordenarLista(eAuto autoArray[],int tama)
{
    int i;
    int j;
    int n;
    char aux[50];
    for(i=0;i<tama-1;i++)
    {
        for(j=i+1;j<tama;j++)
            {
                if(autoArray[i].estado==1 && autoArray[j].estado==1)
                {
                    n=strcmp(autoArray[i].patente,autoArray[j].patente);
                        if(n>0)
                 {
                        strcpy(aux,autoArray[i].patente);
                        strcpy(autoArray[i].patente,autoArray[j].patente);
                        strcpy(autoArray[j].patente,aux);

                 }
                }


            }


        }

    }


void MostrarAutosOrdenadoConPatente(eAuto autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    int i;
    int j;
    printf("Patente |     Marca    |  Propietario \n");
    for(i=0;i<tama;i++)
    {
        if(autoArray[i].estado==1)
        {
            for(j=0;j<tamp;j++)
            {

                if(proArray[j].idPropietario==autoArray[i].idPropietario && proArray[j].estado==1)
                {
                    //ordeno patente
                    ordenarLista(autoArray,tama);
                    printf("%s       %-10s     %-10s   %10s \n",autoArray[i].patente,autoArray[i].marcaNombre,proArray[j].nombre,proArray[j].apellido);

                }
            }


        }


    }

}


void mostrarDatosDeAudi(eAuto autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    int i;
    int j;
    printf("|   Nombre    |    Apellido    |   patente   |   Marca   |   id auto \n");
    for (i = 0; i < tama; i++)
    {

        if (autoArray[i].idMarca==AUDI && autoArray[i].estado==1)
        {

            for (j = 0; j < tamp; j++)
            {
                if(proArray[j].estado==1 && proArray[j].idPropietario==autoArray[i].idPropietario)

                printf("%s            %-10s         %-10s     %-10s     %-10d\n", proArray[j].nombre, proArray[j].apellido,autoArray[j].patente,autoArray[i].marcaNombre,autoArray[i].idAuto);


            }



        }

    }
}



void recaudacionTotalPorMarca(eAuto autoArray[],int tama)
{
    int i;
    int horas=0;
    int opcion;
    float recaudacion=0;
    float recaudacionTotal=0;
    int horasTotales=0;
    printf("Ingrese marca: \n");
    printf("1.Alfa romeo \n2.Ferrari\n3.Audi\n4.Otro\n");
    printf("Opcion:");
    scanf("%d",&opcion);

    switch(opcion)
            {
                case ALPHA_ROMEO:

                for(i=0;i<tama;i++)
                {
                    horas=devolverHorasEstadia();
                    if(autoArray[i].estado==1 && autoArray[i].idMarca==ALPHA_ROMEO)
                    {
                        recaudacion=autoArray[i].precioXhora*horas;
                        horasTotales=horas+horasTotales;
                        recaudacionTotal=recaudacionTotal+recaudacion;
                    }

                }
                printf("Horas: %d   Recaudacion: %0.2f\n",horasTotales,recaudacionTotal);

                break;
                case FERRARI:
                for(i=0;i<tama;i++)
                    {
                    horas=devolverHorasEstadia();
                        if(autoArray[i].estado==1 && autoArray[i].idMarca==FERRARI)
                        {
                        recaudacion=autoArray[i].precioXhora*horas;
                        horasTotales=horas+horasTotales;
                        recaudacionTotal=recaudacionTotal+recaudacion;
                        }

                    }
                printf("Horas: %d   Recaudacion: %0.2f\n",horasTotales,recaudacionTotal);

                break;
                case AUDI:
                for(i=0;i<tama;i++)
                    {
                    horas=devolverHorasEstadia();
                        if(autoArray[i].estado==1 && autoArray[i].idMarca==AUDI)
                        {
                        recaudacion=autoArray[i].precioXhora*horas;
                        horasTotales=horas+horasTotales;
                        recaudacionTotal=recaudacionTotal+recaudacion;
                        }

                    }
                printf("Horas: %d   Recaudacion: %0.2f\n",horasTotales,recaudacionTotal);

                break;
                case OTRO:
                for(i=0;i<tama;i++)
                    {
                    horas=devolverHorasEstadia();
                        if(autoArray[i].estado==1 && autoArray[i].idMarca==OTRO)
                        {
                        recaudacion=autoArray[i].precioXhora*horas;
                        horasTotales=horas+horasTotales;
                        recaudacionTotal=recaudacionTotal+recaudacion;
                        }

                    }
                printf("Horas: %d   Recaudacion: %0.2f\n",horasTotales,recaudacionTotal);

                break;

    printf("Horas: %d  Recaudacion Total: %.2f\n",horas,recaudacionTotal);

}
}


void recaudacionTotal(eAuto autoArray[],int tama)
{
    int i;
    int horas=0;
    float recaudacion=0;
    float recaudacionTotal=0;
    int horasTotales=0;

    for(i=0;i<tama;i++)
    {
        if(autoArray[i].estado==1)
        {
            horas=devolverHorasEstadia();
            horasTotales=horas+horasTotales;
            recaudacion=autoArray[i].precioXhora*horas;
            recaudacionTotal=recaudacionTotal+recaudacion;
        }
    }

    printf("Horas: %d  Recaudacion Total: %.2f\n",horas,recaudacionTotal);

}

void mostrarDatosPorId(eAuto autoArray[],int tama,ePropietarios proArray[],int tamp,int id)
{

    int i;
    int j;

    for (i = 0; i < tamp; i++)
    {

        if (proArray[i].estado != 0 && proArray[i].idPropietario==id)
        {
            printf("|   Nombre    |    Apellido    |   patente   |   Marca   |   id  \n");
            for (j = 0; j < tama; j++)
            {
                if(proArray[i].idPropietario==autoArray[j].idPropietario && autoArray[j].estado!=0)

                printf("%s            %-10s           %-10s   %-10s        %-10d\n", proArray[i].nombre, proArray[i].apellido,autoArray[j].patente,autoArray[j].marcaNombre,autoArray[j].idAuto);


            }



        }

    }
}


/*Egreso del automóvil (No estacionados): calcular el valor de la estadía. Para ello se utilizará una función que
se encargará de determinar el tiempo de estadía del auto (Esta función ya se encuentra implementada). Al
mismo tiempo del egreso se debe emitir un ticket por pantalla informando: Nombre del propietario, patente
del auto, marca y valor de la estadía. Utilizar la siguiente tabla de valores:
*/

void egresoDeAuto(eAuto autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    int i;
    int j;
    int idPropietario;
    int idAuto;
    int horas;
    float precioFinal;
    mostrarPropietarios(proArray,tamp);
    printf("Ingrese id de propietario:");
    scanf("%d",&idPropietario);


    for(i=0;i<tamp;i++)
    {

        if(proArray[i].idPropietario==idPropietario && proArray[i].estado==1)
        {
            mostrarDatosPorId(autoArray,tama,proArray,tamp,idPropietario);
            printf("Ingrese id de auto:\n");
            scanf("%d",&idAuto);

            for(j=0;j<tama;j++)
            {
                if(autoArray[j].idAuto==idAuto && autoArray[j].estado==1)
                {
                    horas=devolverHorasEstadia();
                    precioFinal=horas*autoArray[j].precioXhora;
                    autoArray[j].estado=0;
                    printf("Nombre propietario: %s\n  Patente: %s\n  Marca: %s\n  Precio por hora: %f\n Horas estacionado: %d\n Precio Final: %0.2f\n",proArray[i].nombre,autoArray[j].patente,autoArray[j].marcaNombre,autoArray[j].precioXhora,horas,precioFinal);

                }/*else
                {
                    printf("No se encontro el auto.\n");break;
                }*/
            }





         }







}}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}



void mostrarAutos(eAuto autoArray[],int tama)
{
    int i;
    printf("id:      Auto :  \n");
    for(i=0;i<tama;i++)
    {
        if(autoArray[i].estado==1)
        {
            printf("%d     %10s \n",autoArray[i].idAuto,autoArray[i].marcaNombre);
        }


    }

}

int buscarLugarLibreAuto(eAuto autoArray[],int tama)

{
    int retorno=-1;
    int i;
    if(tama > 0 && autoArray != NULL)
    {
        retorno = -2;
        for(i=0;i<tama;i++)
        {
            if(autoArray[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int devolverSiguienteIdAuto(eAuto proAuto[],int tama)
{
    int retorno = 0;
    int i;
    if(tama > 0 && proAuto != NULL)
    {
        for(i=0; i<tama; i++)
        {
            if(proAuto[i].estado == 1)
            {
                    if(proAuto[i].idAuto>retorno)
                    {
                         retorno=proAuto[i].idAuto;
                    }

            }

        }
    }
     return retorno+1;
}

int darAltaAutoEstacionado(eAuto autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    int opcion;
    char nombre[50];
    int id;
    int i;
    int indice;
    char marcaNombre[][20]={"","Alfa romeo","Ferrari","audi","Otro"};

    indice =buscarLugarLibreAuto(autoArray,tama);
        if(indice >= 0)
        {

            id = devolverSiguienteIdAuto(autoArray,tama);

            autoArray[indice].idAuto=id;
            printf("Ingrese patente: ");
            fflush(stdin);
            gets(autoArray[indice].patente);
            printf("Ingrese marca: \n");
            printf("1.Alfa romeo \n2.Ferrari\n3.Audi\n4.Otro\n");
            printf("Opcion:");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case ALPHA_ROMEO:
                autoArray[indice].idMarca=ALPHA_ROMEO;
                strcpy(autoArray[indice].marcaNombre,marcaNombre[ALPHA_ROMEO]);
                autoArray[indice].precioXhora=150;

                break;
                case FERRARI:
                   autoArray[indice].idMarca=FERRARI;
                   strcpy(autoArray[indice].marcaNombre,marcaNombre[FERRARI]);
                   autoArray[indice].precioXhora=175;
                break;
                case AUDI:
                    autoArray[indice].idMarca=AUDI;
                    strcpy(autoArray[indice].marcaNombre,marcaNombre[AUDI]);
                    autoArray[indice].precioXhora=200;
                break;
                case OTRO:
                   autoArray[indice].idMarca=OTRO;
                   strcpy(autoArray[indice].marcaNombre,marcaNombre[OTRO]);
                    autoArray[indice].precioXhora=250;
                break;
            }
            int idProp;
            mostrarPropietarios(proArray,tamp);
            printf("Ingrese id de propietario:");

            scanf("%d",&idProp);

                for(i=0;i<tamp;i++)
                {
                    if(proArray[i].idPropietario==idProp && proArray[i].estado==1)
                    {
                        autoArray[indice].idPropietario=idProp;
                        autoArray[indice].estado=1;

                        printf("Guardado con exito\n");break;
                    }




                }


            //}
        }
    }



void darBajaPropietario(ePropietarios proArray[],int tamp)
{
    int id;
    int i;

    mostrarPropietarios(proArray,tamp);

    printf(" Ingrese su id: ");
    scanf(" %d",&id);

    for(i=0;i<tamp;i++)
    {
        if(proArray[i].idPropietario==id)
        {
            proArray[i].estado=0;
            printf("El propietario fue dado de baja \n");
            break;
        }
    }

    }





void mostrarPropietarios(ePropietarios proArray[],int tamp){
    int i;
    printf("Id :|  Nombre  |  Apellido  |  Direccion| \n");
    for (i = 0; i < tamp; i++) {
        if (proArray[i].estado != 0) {


            printf("%d  %-10s  %-10s  %-10s   \n", proArray[i].idPropietario, proArray[i].nombre,proArray[i].apellido,proArray[i].direccion);
            printf("\n");
        }
    }
}





void modificarPropietario(ePropietarios proArray[],int tamp)//
{

    int id;
    int i;
    char respuesta;
    int tarjeta;
    mostrarPropietarios(proArray,tamp);

    printf(" Ingrese su id: ");
    scanf(" %d",&id);
    if(id<devolverSiguienteId(proArray,tamp) && id>0)
    {

    for(i=0;i<tamp;i++)
    {


        if(proArray[i].estado==1 && proArray[i].idPropietario==id)
        {

            printf("Ingrese nueva tarjeta:");
            scanf(" %d",&tarjeta);
            printf("Esta seguro ?(s/n)");
            fflush(stdin);
            respuesta=getchar();

            if(respuesta=='s')
            {
                proArray[i].tarjeta=tarjeta;
                 printf("Se modifico con exito \n");break;
            }else
            {
                printf("Operacion cancelada \n");break;
            }
        }
    }
    }else
    {
        printf("No se encontro el usuario\n");
    }




    }


int darAltaPropietario(ePropietarios proArray[],int tamp)//
{

    char nombre[50];
    int id;
    int indice;
    int retorno=-1;
    if(tamp > 0 && proArray != NULL)
    {
        retorno = -2;
        indice =buscarLugarLibre(proArray,tamp);
        if(indice >= 0)
        {
            retorno = -3;
            id = devolverSiguienteId(proArray,tamp);

            retorno = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(proArray[indice].nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(proArray[indice].apellido);
            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(proArray[indice].direccion);
            printf("Ingrese numero de tarjeta de credito: ");
            scanf("%d",&proArray[indice].tarjeta);
            proArray[indice].idPropietario = id;
            proArray[indice].estado = 1;
            printf("Se dio de alta con exito\n");
        }
    }
    return retorno;
}


/** \brief Devuelve el id mas 1 del ultimo usuario cargado en el array
 *
 * \param proArray[] array a usar
 * \param tamp tamaño del array
 * \return int =0 si el array no esta cargado, -1 si no hay lugar,si encuentra devuelve el id.
 *
 */
int devolverSiguienteId(ePropietarios proArray[],int tamp)
{
    int retorno = 0;
    int i;
    if(tamp > 0 && proArray != NULL)
    {
        for(i=0; i<tamp; i++)
        {
            if(proArray[i].estado == 1)
            {
                    if(proArray[i].idPropietario>retorno)
                    {
                         retorno=proArray[i].idPropietario;
                    }

            }

        }
    }
     return retorno+1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param userArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int buscarLugarLibre(ePropietarios proArray[],int tamp)//

{
    int retorno=-1;
    int i;
    if(tamp > 0 && proArray != NULL)
    {
        retorno = -2;
        for(i=0;i<tamp;i++)
        {
            if(proArray[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief Inicializa el status en un array de propietarios
 * \param proArray Es el array en el cual buscar
 * \param tamp Indica la logitud del array
 * \param
 * \return -
 *
 */

void inicializarEstadoPropietarios(ePropietarios proArray[],int tamp)//
{
    int i;
    for(i=0;i<tamp;i++)
    {
       proArray[i].estado=0;

    }
}

void inicializarEstadoAutos(eAuto autoArray[],int tama)
{
    int i;
    for(i=0;i<tama;i++)
    {
       autoArray[i].estado=0;

    }
}

void autosHardcode(eAuto autoArray[],int tama)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    char marcaNombre[][20]={"","Alfa romeo","Ferrari","audi","Otro"};
    float precios[5]={0,150,175,200,250};
    int i;
    for( i=0;i<10;i++)
    {


        autoArray[i].idPropietario=propietario[i];
        strcpy(autoArray[i].patente,patente[i]);
        autoArray[i].idAuto=id[i];
        autoArray[i].estado=1;
        autoArray[i].idMarca=marca[i];
        autoArray[i].precioXhora=precios[marca[i]];
        strcpy(autoArray[i].marcaNombre,marcaNombre[marca[i]]);//asigno nombre a la id marca

    }

}


void propietariosHardCode(ePropietarios proArray[],int tamp)
{

	//int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
	char apellido[][20]= {"Gomez","Gutierrez","Jaim","Jhon"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int i;
    int indice;

    for(i=0;i<4;i++)
    {
            indice=buscarLugarLibre(proArray,tamp);
            proArray[indice].idPropietario=devolverSiguienteId(proArray,tamp);
            strcpy(proArray[indice].nombre,nombre[i]);
            strcpy(proArray[indice].apellido,apellido[i]);
            strcpy(proArray[indice].direccion,direccion[i]);
            proArray[indice].estado = 1;


    }

}
