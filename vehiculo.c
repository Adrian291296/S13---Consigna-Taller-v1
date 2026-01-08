#include <stdio.h>
#include <string.h>
#include "vehiculo.h"

#define MAX_VEHICULOS 100

Vehiculo inventario[MAX_VEHICULOS];
int totalVehiculos = 0;

void agregarVehiculo()
{
    Vehiculo v;
    v.id = totalVehiculos + 1;

    printf("Marca: ");
    scanf("%s", v.marca);

    printf("Modelo: ");
    scanf("%s", v.modelo);

    printf("Tipo (auto/camioneta): ");
    scanf("%s", v.tipo);

    printf("Ano: ");
    scanf("%d", &v.ano);

    printf("Precio: ");
    scanf("%f", &v.precio);

    printf("Es usado? (1 = si, 0 = no): ");
    scanf("%d", &v.usado);

    v.disponible = 1;

    inventario[totalVehiculos++] = v;
    printf("Vehiculo agregado correctamente.\n");
}

void listarVehiculos()
{
    printf("\n--- VEHICULOS DISPONIBLES ---\n");
    for (int i = 0; i < totalVehiculos; i++)
    {
        if (inventario[i].disponible)
        {
            printf("ID:%d | %s %s | %s | $%.2f\n",
                   inventario[i].id,
                   inventario[i].marca,
                   inventario[i].modelo,
                   inventario[i].tipo,
                   inventario[i].precio);
        }
    }
}

void buscarVehiculosPreferencias(char marca[], char tipo[], int usado, float presupuesto)
{
    printf("\n--- RESULTADOS SEGUN PREFERENCIAS ---\n");
    for (int i = 0; i < totalVehiculos; i++)
    {
        if (inventario[i].disponible &&
            strcmp(inventario[i].marca, marca) == 0 &&
            strcmp(inventario[i].tipo, tipo) == 0 &&
            inventario[i].usado == usado &&
            inventario[i].precio <= presupuesto)
        {

            printf("ID:%d | %s %s | $%.2f\n",
                   inventario[i].id,
                   inventario[i].marca,
                   inventario[i].modelo,
                   inventario[i].precio);
        }
    }
}

Vehiculo *obtenerVehiculoPorID(int id)
{
    for (int i = 0; i < totalVehiculos; i++)
    {
        if (inventario[i].id == id && inventario[i].disponible)
        {
            return &inventario[i];
        }
    }
    return NULL;
}
