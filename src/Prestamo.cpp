#include "Prestamo.h"
#include <algorithm> // for std::remove_if

int Prestamo::prestamoID = 1;

Prestamo::Prestamo(Socio socio, Fecha fechaPrestamo, Fecha fechaDevolucion)
    : _socio(socio), _fechaPrestamo(fechaPrestamo), _fechaDevolucion(fechaDevolucion)
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

void Prestamo::agregarLibro(Libro libro)
{
    _librosPrestados.push_back(libro);
}

void Prestamo::quitarLibro(std::string ISBN)
{
    for (size_t i = 0; i < _librosPrestados.size(); ++i)
    {
        if (_librosPrestados[i].getISBN() == ISBN)
        {
            // _librosPrestados.begin() es un iterador que apunta al índice 0.
            // Sumamos i para moverlo a la posición del match.

            _librosPrestados.erase(_librosPrestados.begin() + i);

            return;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo)
{
    os << "Prestamo ID: " << prestamo._prestamoID << '\n';
    os << "Socio: " << prestamo._socio << '\n';
    os << "Fecha Prestamo: " << prestamo._fechaPrestamo << '\n';
    os << "Fecha Devolucion: " << prestamo._fechaDevolucion << '\n';
    os << "Estado: " << (prestamo._estado ? "Activo" : "Finalizado") << '\n';
    os << "Libros Prestados:" << '\n';

    for (const auto& libro : prestamo._librosPrestados)
    {
        os << libro << '\n';
    }

    return os;
}

