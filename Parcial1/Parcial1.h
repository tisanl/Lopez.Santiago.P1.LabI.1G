#ifndef PARCIAL1_H_INCLUDED
#define PARCIAL1_H_INCLUDED
typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;  //( 1 a 10)
    int isEmpty;
}eMoto;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id; //comienza en 1000
    char descripcion[20];
}eTipo;

typedef struct
{
    int id; //comienza en 10000
    char nombreColor[20];
}eColor;

typedef struct
{
    int id; //comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;

typedef struct
{
    int id; //(autoincremental)
    int idMoto; //(debe existir) Validar
    int idServicio;// (debe existir) Validar
    eFecha fecha; //( Validar día, mes y año)
    int isEmpty;
}eTrabajo;

#endif // PARCIAL1_H_INCLUDED
int menu();
int initMoto(eMoto[], int);

int initTrabajo(eTrabajo[], int);


int preguntarSiHayLugarMotos(eMoto[], int);

//AGREGAR MOTO
int addMoto(eMoto[], int, int*);

void hardcodeoTipoMoto(eTipo[]);

void mostrarTipoMoto(eTipo[]);

void hardcodeoColorMoto(eColor[]);

void mostrarColorMoto(eColor[]);

int pedirCilindrado();


int pedirPuntaje();

//MODIFICACION MOTO
void pedirId(int*);

int findMotoById(eMoto[], int, int);


void modifyMoto(eMoto[], int, int);

int subMenuModify();

int preguntarSiHayMotoCargada(eMoto[], int);


//BAJA MOTO
void removeMoto(eMoto[], int, int);

//MOSTRAR
void listarMotos(eMoto[], int);

void listarTipoMoto(eMoto[], int, eTipo[], char[]);


void listarColorMoto(eMoto[], int, eColor[], char[]);


