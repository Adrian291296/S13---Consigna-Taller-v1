#include <stdio.h>
#include "menu.h"
#include "vehiculo.h"
#include "venta.h"

void mostrarMenu()
{
    int opcion;

    do
    {
        printf("\n--- SGIC RUEDAS DE ORO ---\n");
        printf("1. Agregar vehiculo\n");
        printf("2. Listar vehiculos\n");
        printf("3. Venta de vehiculo\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarVehiculo();
            break;
        case 2:
            listarVehiculos();
            break;
        case 3:
            realizarVenta();
            break;
        case 0:
            printf("Sistema cerrado.\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}
