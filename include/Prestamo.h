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
    char _ISBN[14];
    int _socioID;
    Fecha _fechaDevolucion;
    bool _estado = true;

    static int prestamoID;

public:
    Prestamo();
    Prestamo(const char* ISBN, int socioID, Fecha fechaDevolucion);

    int getPrestamoID() const { return _prestamoID; }
    Fecha getFechaDevolucion() const { return _fechaDevolucion; }

    void setFechaDevolucion(Fecha fechaDevolucion);
    void setEstado(bool estado) { _estado = estado; }

    static int getID() { return prestamoID; }
    static void setID(int ID) { prestamoID = ID; }

    friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo);
    bool operator==(const Prestamo& prestamo) const { return _prestamoID == prestamo.getPrestamoID(); }
};

#endif // PRESTAMO_H_INCLUDED
