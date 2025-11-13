#ifndef ARCHIVOPRESATMOS_H_INCLUDED
#define ARCHIVOPRESATMOS_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "Prestamo.h"
#include "rlutil.h"

class ArchivoPrestamos
{
private:
    std::vector<Prestamo> prestamos;

public:
    ArchivoPrestamos();
    ~ArchivoPrestamos();

    void agregarPrestamo(Prestamo& prestamo);
    void quitarPrestamo(int prestamoID);
    void listarPrestamos();
    void cambiarFechaDevolucion(int prestamoID, Fecha fechaDevolucion);

    void cargar();
    void guardar();

};


#endif // ARCHIVOPRESATMOS_H_INCLUDED
