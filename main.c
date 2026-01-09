#include "menu.h"
#include "vehiculo.h"

int main()
{
    cargarVehiculos(); // CARGA INVENTARIO AL INICIAR
    mostrarMenu();
    guardarVehiculos(); // GUARDA AL SALIR
    return 0;
}
