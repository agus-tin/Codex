#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include "ArchivoLibros.h"
#include "ArchivoPrestamos.h"
#include "ArchivoAdmins.h"
#include "ArchivoSocios.h"

class Biblioteca
{
public:
    ArchivoLibros libros;
    ArchivoPrestamos prestamos;
    ArchivoAdmins admins;
    ArchivoSocios socios;
};


#endif // BIBLIOTECA_H_INCLUDED
