#ifndef VEHICULO_H
#define VEHICULO_H

#define MAX_MARCA 30
#define MAX_MODELO 30
#define MAX_TIPO 20

typedef struct
{
    int id;
    char marca[MAX_MARCA];
    char modelo[MAX_MODELO];
    char tipo[MAX_TIPO];
    int ano;
    float precio;
    int usado;
    int disponible;
} Vehiculo;

void agregarVehiculo();
void listarVehiculos();
void buscarVehiculosPreferencias(char marca[], char tipo[], int usado, float presupuesto);
Vehiculo *obtenerVehiculoPorID(int id);

// NUEVO
void cargarVehiculos();
void guardarVehiculos();

#endif
