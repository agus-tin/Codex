#include <iostream>
#include "Socio.h"

Socio::Socio()
    : _cuota{}
{}

int Socio::socioID = 1;

Socio::Socio(float cuota)
    : _cuota{ cuota }
{
    _socioID = socioID++;
}

void Socio::setCuota(float cuota)
{
    _cuota = cuota;
}

void Socio::setImpago(bool impago)
{
    _impago = impago;
}

std::ostream& operator<<(std::ostream& os, const Socio& socio)
{
    os << "  Nombre del socio: " << socio.getNombre() << " " << socio.getApellido() << '\n';
    os << "  DNI: " << socio.getDNI() << '\n';
    os << "  Telefono: " << socio.getTelefono() << '\n';
    os << "  Correo: " << socio.getCorreo() << '\n';

    return os;
}
