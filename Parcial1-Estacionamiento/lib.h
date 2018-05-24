typedef struct
{
    int idPropietario;
    char nombre[40];
    char apellido[40];
    char direccion[40];
    int tarjeta;
    int estado;
    int idEstacionado;

}ePropietarios;

typedef struct
{
    char patente[20];
    int idMarca;
    char marcaNombre[20];
    int idPropietario;
    int estado;
    int idAuto;
    float precioXhora;
}eAuto;

void ordenarLista(eAuto[],int);

void MostrarAutosOrdenadoConPatente(eAuto[],int,ePropietarios[],int);

void mostrarDatosDeAudi(eAuto[],int,ePropietarios[],int);

void recaudacionTotalPorMarca(eAuto[],int);

void recaudacionTotal(eAuto[],int);

int devolverSiguienteIdAuto(eAuto[],int);

void mostrarDatosPorId(eAuto[],int,ePropietarios[],int,int);

int devolverHorasEstadia(void);

void autosHardcode(eAuto[],int);

void mostrarAutos(eAuto[],int);

void inicializarEstadoAutos(eAuto[],int);

int buscarLugarLibreAuto(eAuto[],int);

int darAltaAutoEstacionado(eAuto[],int ,ePropietarios[],int);

void darBajaPropietario(ePropietarios[],int);

void propietariosHardCode(ePropietarios[],int);

void mostrarPropietarios(ePropietarios[],int);

void modificarUsuario(ePropietarios[],int);

int darAltaPropietario(ePropietarios[],int);

int devolverSiguienteId(ePropietarios[],int);

int buscarLugarLibre(ePropietarios[],int);

void inicializarEstadoPropietarios(ePropietarios[],int);
