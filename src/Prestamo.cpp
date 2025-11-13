#include "Prestamo.h"

int Prestamo::prestamoID = 1;

Prestamo::Prestamo()
{
    _prestamoID = prestamoID++;
}

Prestamo::Prestamo(const char* ISBN, int socioID, Fecha fechaDevolucion)
    : _socioID{ socioID }, _fechaDevolucion{ fechaDevolucion }
{
    std::strncpy(_ISBN, ISBN, sizeof(_ISBN) - 1);
    _ISBN[sizeof(_ISBN) - 1] = '\0';

    _prestamoID = prestamoID++;
}

void Prestamo::setFechaDevolucion(Fecha fechaDevolucion)
{
    _fechaDevolucion = fechaDevolucion;
}

std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo)
{
    os << "  Prestamo ID: " << prestamo._prestamoID << '\n';
    os << "  Libro ISBN: " << prestamo._ISBN << '\n';
    os << "  Socio ID: " << prestamo._socioID << '\n';
    os << "  Fecha Devolucion: " << prestamo._fechaDevolucion << '\n';
    os << "  Estado: " << (prestamo._estado ? "Activo" : "Finalizado") << '\n';

    return os;
}

