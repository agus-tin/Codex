#include "Pago.h"
#include <iostream>

void Pago::setFechaPago(Fecha& f)
{
    _fechapago = f;
}

void Pago::setImporte(float i)
{
    _importe = i;
}

void Pago::setEstado(bool e)
{
    _estado = e;
}

Fecha Pago::getFechaPago()
{
    return _fechapago;
}

float Pago::getImporte()
{
    return _importe;
}

bool Pago::getEstado()
{
    return _estado;
}

void Pago::cargar()
{
    cout << "CARGA DE PAGO" << std::endl;
    cout << "-----------------------------" << std::endl;

    cout << "Ingrese la fecha de pago: " << std::endl;
    _fechapago.carga();

    cout << "Ingrese el importe: ";
    cin >> _importe;

    cout << "¿El pago está activo? (1 = sí, 0 = no): ";
    cin >> _estado;

    cout << endl;
}

void Pago::guardar()
{
    cout << "GUARDANDO PAGO..." << endl;
    cout << "Fecha: ";
    _fechapago.mostrar();
    cout << "Importe: " << _importe << endl;
    cout << "Estado: " << _estado << endl;
    cout << "-----------------------------" << endl;
}
