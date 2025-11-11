#include <iostream>
#include "Socio.h"

Socio::Socio()
{
    _socioID = socioID++;
}

int Socio::socioID = 1;

std::ostream& operator<<(std::ostream& os, const Socio& socio)
{
    os << "  Nombre del socio: " << socio.getNombre() << " " << socio.getApellido() << '\n';
    os << "  DNI: " << socio.getDNI() << '\n';
    os << "  Telefono: " << socio.getTelefono() << '\n';
    os << "  Correo: " << socio.getCorreo() << '\n';

    return os;
}
