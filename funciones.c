#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**brief es el menu a mostrar.
 * param opcion -1 es para que el usuario ingrese los 5 opciones dadas.
 * return opcion.
 */

int menu(void)
{

    int opcion=-1;
    system("cls");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");

    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/**brief Inicializa un array de enteros con el valor recibido.
 * param personaArray es el array a ser inicializado.
 * param cant indica la longitud del array.
 * return -
 */
void inicializarArrayPersona(ePersonas personaArray[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        personaArray[i].estado= -1;
    }

}

/**
 * Obtiene el primer indice libre del array.
 * param lista el array se pasa como parametro.
 * return el primer indice disponible
 */
int obtenerEspacioLibre(ePersonas lista[],int cant)
{
    int i=0;
    int retorno=-1;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==-1)
        {
            retorno= i;
            break;
        }
    }
    return retorno;
}


/**brief Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista el array se pasa como parametro.
 * param dni el dni a ser buscado en el array.
 * return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
void mostrarOrdenado(ePersonas personaArray[],int cant)
{
    ePersonas aux;
    int i,j;
    for(i=0;i<cant-1;i++)
                 {
                     for(j=i+1;j<cant;j++)
                     {
                         if(strcmp(personaArray[i].nombre,personaArray[j].nombre)>0)
                            {
                                aux=personaArray[i];
                                personaArray[i]=personaArray[j];
                                personaArray[j]=aux;


                                aux=personaArray[i];
                                personaArray[i]=personaArray[j];
                                personaArray[j]=aux;

                                aux=personaArray[i];
                                personaArray[i]=personaArray[j];
                                personaArray[j]=aux;

                            }
                     }
                 }

                for(i=0; i<cant; i++)
                {
                    if(personaArray[i].estado==0)
                    {
                        printf("%s- %d- %d\n",personaArray[i].nombre,personaArray[i].edad,personaArray[i].dni);
                    }
                }
                system("pause");
}

/**brief Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista el array se pasa como parametro.
 * param dni el dni a ser buscado en el array.
 * return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(ePersonas lista[], int dni)
{
    int i;
    int cant=20,retorno=-1;

    for(i=0; i<cant; i++)
    {
        if(lista[i].dni==dni)
        {
            lista[i].estado=-1;
            retorno=i;
            break;
        }
    }
    return retorno;
}


 void mostrarGrafico(ePersonas personaArray[],int cant)
{
     int i, menores=0, adultos=0, adolescentes=0,mayor;
    for(i=0;i<cant;i++)
    {
        if(personaArray[i].estado==0)
        {
            if(personaArray[i].edad<=18)
            {
                menores++;
            }
            else if(personaArray[i].edad>18&&personaArray[i].edad<=35)
            {
                adolescentes++;
            }
            else if(personaArray[i].edad>35)
            {
                adultos++;
            }
        }
    }
    if(menores>adolescentes&&menores>adultos)
    {
        mayor=menores;
    }
    else if(adolescentes>menores&&adolescentes>adultos)
    {
        mayor=adolescentes;
    }
    else if(adultos>menores&&adultos>adolescentes)
    {
        mayor=adultos;
    }
    for(i=mayor;i>=0;i--)
    {
        if(i<menores)
        {
            printf(" *\t");
        }
        else
        {
            printf("  \t");
        }
        if(i<adolescentes)
        {
            printf("  *\t");
        }
        else
        {
            printf("   \t");
        }
        if(i<adultos)
        {
            printf("   *\n");
        }
        else
        {
            printf("    \n");
        }
    }
    printf("\n<18\t19-35\t>35\n");
    adultos=0;
    menores=0;
    adolescentes=0;
}






