#include <stdio.h>
#include "cliente.h"

int totalClientes = 0;

Cliente registrarCliente()
{
    Cliente c;
    c.id = ++totalClientes;

    printf("Nombre del cliente: ");
    scanf("%s", c.nombre);

    printf("Edad: ");
    scanf("%d", &c.edad);

    return c;
}
