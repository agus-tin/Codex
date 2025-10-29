#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

#include <iostream>
#include <vector>
#include "Libro.h"
#include "Socio.h"
#include "Fecha.h"

class Prestamo
{
private:
    int _prestamoID;
    std::vector<Libro> _librosPrestados;
    Socio _socio;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;
    bool _estado = true;

    static int prestamoID;

public:
    Prestamo(Socio socio, Fecha fechaPrestamo, Fecha fechaDevolucion);

    Fecha getFechaPrestamo() const { return _fechaPrestamo; }
    Fecha getFechaDevolucion() const { return _fechaDevolucion; }

    void setFechaDevolucion(Fecha fechaDevolucion);
    void setEstado(bool estado);

    void agregarLibro(Libro libro);
    void quitarLibro(std::string ISBN);

    friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo);
};

#endif // PRESTAMO_H_INCLUDED
