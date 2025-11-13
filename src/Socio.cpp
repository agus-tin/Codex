#include <iostream>
#include "Socio.h"

int Socio::socioID = 1;

Socio::Socio()
    : Persona()
{
    _socioID = socioID++;
}

Socio::Socio(int DNI,
             const char* nombre,
             const char* apellido,
             Fecha& fechaNacimiento,
             int telefono,
             bool estado,
             const char* correo)
    : Persona(DNI, nombre, apellido, fechaNacimiento, telefono, estado, correo)
{
    _socioID = socioID++;
}

std::ostream& operator<<(std::ostream& os, const Socio& socio)
{
    os << "  ID: " << socio.getSocioID() << '\n';
    os << "  Nombre: " << socio.getNombre() << " " << socio.getApellido() << '\n';
    os << "  DNI: " << socio.getDNI() << '\n';
    os << "  Telefono: " << socio.getTelefono() << '\n';
    os << "  Correo: " << socio.getCorreo() << '\n';

    return os;
}
