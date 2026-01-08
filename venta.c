#include <stdio.h>
#include "venta.h"

void realizarVenta()
{
    Cliente c = registrarCliente();

    char marca[30], tipo[20];
    float presupuesto;
    int usado, idVehiculo;

    printf("Marca preferida: ");
    scanf("%s", marca);

    printf("Tipo de vehiculo: ");
    scanf("%s", tipo);

    printf("¿Usado? (1=si, 0=no): ");
    scanf("%d", &usado);

    printf("Presupuesto maximo: ");
    scanf("%f", &presupuesto);

    buscarVehiculosPreferencias(marca, tipo, usado, presupuesto);

    printf("\nIngrese ID del vehiculo a comprar: ");
    scanf("%d", &idVehiculo);

    Vehiculo *v = obtenerVehiculoPorID(idVehiculo);

    if (v != NULL)
    {
        v->disponible = 0;
        printf("\nVENTA REGISTRADA\n");
        printf("Cliente: %s\n", c.nombre);
        printf("Vehiculo: %s %s\n", v->marca, v->modelo);
        printf("Precio: $%.2f\n", v->precio);
    }
    else
    {
        printf("Vehiculo no disponible.\n");
    }
}
