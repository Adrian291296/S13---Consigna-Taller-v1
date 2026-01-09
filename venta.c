#include <stdio.h>
#include <string.h>
#include "venta.h"
#include "vehiculo.h"
#include "cliente.h"

/*
    Realiza el proceso completo de venta:
    - Registra cliente
    - Solicita preferencias
    - Busca vehículos disponibles
    - Permite seleccionar uno
    - Marca el vehículo como vendido
    - Guarda el cambio en archivo
*/

void realizarVenta()
{
    Cliente c = registrarCliente();

    char marca[30];
    char tipo[20];
    int usado;
    float presupuesto;
    int idVehiculo;

    printf("\n--- PREFERENCIAS DEL CLIENTE ---\n");

    printf("Marca preferida: ");
    scanf("%s", marca);

    printf("Tipo de vehiculo (auto/camioneta): ");
    scanf("%s", tipo);

    printf("Usado? (1 = si, 0 = no): ");
    scanf("%d", &usado);

    printf("Presupuesto maximo: ");
    scanf("%f", &presupuesto);

    printf("\n--- VEHICULOS DISPONIBLES SEGUN PREFERENCIAS ---\n");
    buscarVehiculosPreferencias(marca, tipo, usado, presupuesto);

    printf("\nIngrese el ID del vehiculo que desea comprar: ");
    scanf("%d", &idVehiculo);

    Vehiculo *v = obtenerVehiculoPorID(idVehiculo);

    if (v != NULL)
    {
        v->disponible = 0;  // Marca como vendido
        guardarVehiculos(); // Persistencia en archivo

        printf("\n--- VENTA REGISTRADA EXITOSAMENTE ---\n");
        printf("Cliente : %s\n", c.nombre);
        printf("Edad    : %d\n", c.edad);
        printf("Vehiculo: %s %s\n", v->marca, v->modelo);
        printf("Precio  : $%.2f\n", v->precio);
    }
    else
    {
        printf("\nERROR: Vehiculo no disponible o ID incorrecto.\n");
    }
}
