#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <vector>
#include <string>
#include "Libro.h"
#include "Prestamo.h"
#include "Admin.h"

class Biblioteca
{
public:
    std::vector<Libro> libros;
    std::vector<Prestamo> prestamos;
    std::vector<Admin> admins;

    void agregarLibro(Libro& libro)
    {
        libros.push_back(libro);
    }

    void quitarLibro(std::string& ISBN)
    {
        for (size_t i = 0; i < libros.size(); ++i)
        {
            if (libros[i].getISBN() == ISBN)
            {
                // _libros.begin() es un iterador que apunta al índice 0.
                // Sumamos i para moverlo a la posición del match.

                libros.erase(libros.begin() + i);
                break;
            }
        }
    }

    void agregarPrestamo(Prestamo& prestamo)
    {
        prestamos.push_back(prestamo);
    }

    void quitarPrestamo(Prestamo& prestamo) {

        for (size_t i = 0; i < prestamos.size(); ++i)
        {
            if (prestamos[i] == prestamo)
            {
                prestamos.erase(prestamos.begin() + i);
                break;
            }
        }
    }

    void agregarAdmin(Admin& admin)
    {
        admins.push_back(admin);
    }

    void quitarAdmin(Admin& admin)
    {
        for (size_t i = 0; i < admins.size(); ++i)
        {
            if (admins[i] == admin)
            {
                admins.erase(admins.begin() + i);
                break;
            }
        }
    }
};


#endif // BIBLIOTECA_H_INCLUDED
