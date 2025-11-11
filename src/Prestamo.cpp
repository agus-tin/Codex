#include "Prestamo.h"
#include <algorithm> // for std::remove_if

int Prestamo::prestamoID = 1;

Prestamo::Prestamo()
{
    _prestamoID = prestamoID++;
    _estado = true;
}

Prestamo::Prestamo(Libro libro, Socio socio, Fecha fechaPrestamo, Fecha fechaDevolucion)
    : _libroPrestado{ libro }, _socio{ socio }, _fechaPrestamo{ fechaPrestamo }, _fechaDevolucion{ fechaDevolucion }
{
    _prestamoID = prestamoID++;
}

void Prestamo::setFechaDevolucion(Fecha fechaDevolucion)
{
    _fechaDevolucion = fechaDevolucion;
}

void Prestamo::setEstado(bool estado)
{
    _estado = estado;
}

std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo)
{
    os << "Prestamo ID: " << prestamo._prestamoID << '\n';
    os << "Libro: " << prestamo._libroPrestado << '\n';
    os << "Socio: " << prestamo._socio << '\n';
    os << "Fecha Prestamo: " << prestamo._fechaPrestamo << '\n';
    os << "Fecha Devolucion: " << prestamo._fechaDevolucion << '\n';
    os << "Estado: " << (prestamo._estado ? "Activo" : "Finalizado") << '\n';

    return os;
}

