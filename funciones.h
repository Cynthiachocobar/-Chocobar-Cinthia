typedef struct
 {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersonas;


void inicializarArrayPersona(ePersonas personaArray[], int cant);
int obtenerEspacioLibre(ePersonas lista[],int cant);

void mostrarOrdenado(ePersonas personaArray[],int cant);
int buscarPorDni(ePersonas lista[], int dni);
void mostrarGrafico(ePersonas personaArray[],int cant);


