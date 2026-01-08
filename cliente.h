#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_NOMBRE 40

typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    int edad;
} Cliente;

Cliente registrarCliente();

#endif
