#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define cant_Personas 20

typedef struct
 {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;



int menu(void);


int main()
{

    /** Array donde se guarda la informacion */
    ePersonas personaArray[cant_Personas];

    int nombre,edad,dni,estado,opcion=0;
    int lugarLibre, resultadoDeBusqueda;

    /**Indica con un -1 que la posicion se encuentra vacia*/
    inicializarArrayPersona(personaArray,cant_Personas);

    do
    {
        opcion=menu();


        switch(opcion)
        {
            case 1:

                lugarLibre=obtenerEspacioLibre(personaArray,cant_Personas);
                if(lugarLibre==-1)
                {
                    printf("\nNO QUEDAN LUGARES LIBRES\n");
                    system("pause");
                }
                else
                {
                    printf("\nINGRESE EL NOMBRE:\n");
                    fflush(stdin);
                    scanf("%s",&personaArray[lugarLibre].nombre);
                    personaArray[lugarLibre].estado=0;


                    printf("\nINGRESE LA EDAD:\n");
                    scanf("%d",&personaArray[lugarLibre].edad);

                    printf("\nINGRESE EL DNI:\n");
                    scanf("%d",&personaArray[lugarLibre].dni);

                }

                    break;

            case 2:

                        printf("\nINGRESE EL DNI A BORRAR:\n");
                        scanf("%d",&dni);

                        resultadoDeBusqueda=buscarPorDni(personaArray,dni);
                        if(resultadoDeBusqueda == -1)
                        {
                            printf("\nEL DNI NO SE ENCUENTRA\n");
                            break;
                        }
                        printf("\nINGRESE EL NUEVO DNI:\n");

            case 3:

                    mostrarOrdenado(personaArray,cant_Personas);
                    system("pause");
                    break;

            case 4:
                    mostrarGrafico(personaArray,cant_Personas);
                    system("pause");
                    break;

            case 5:
                    printf("\nSaliendo del programa\n");

                    break;

            default:
                    printf("\nOPCION INCORRECTA\n");
                    system("pause");
                    break;
        }
    }while(opcion!='s');

    return 0;
}

