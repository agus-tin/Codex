#ifndef ARCHIVOLIBROS_H_INCLUDED
#define ARCHIVOLIBROS_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "Libro.h"
#include "Genero.h"

class ArchivoLibros
{
private:
    std::vector<Libro> libros;

public:
    ArchivoLibros(); // Al inicializar toda la data de "libros.dat" es cargada al vector dinámico "libros".
    ~ArchivoLibros(); // Al ser destruido el objeto se guarda toda la data a "libros.dat".

    void agregarLibro(Libro& libro);
    bool quitarLibro(const char* ISBN); // Es un char array [14].
    void listarLibros();

    void cargar();
    void guardar();

};

#endif // ARCHIVOLIBROS_H_INCLUDED
