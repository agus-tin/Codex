#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include "Fecha.h"
#include "Genero.h"

class ArchivoLibros;

class Libro
{
private:
    char _ISBN[14];
    char _titulo[50];
    char _autor[50];
    char _editorial[50];
    Fecha _fechaPublicacion;
    int _cantidadEjemplares;
    Genero _genero;
    bool _estado = true;

public:
    friend class ArchivoLibros;

    Libro();
    Libro(const char* ISBN, const char* titulo, const char* autor, const char* editorial, Fecha fechaPublicacion, int cantidadEjemplares, Genero genero);

    const char* getISBN() const { return _ISBN; }
    const char* getTitulo() const { return _titulo; }
    const char* getAutor() const { return _autor; }
    const char* getEditorial() const { return _editorial; }
    Fecha getFechaPubliacion() const { return _fechaPublicacion; }
    int getCantidadEjemplares() const { return _cantidadEjemplares; }
    Genero getGenero() const { return _genero; }
    bool getEstado() const { return _estado; }

    void setISBN(const char* ISBN);
    void setCantidadEjemplares(int cantidadEjemplares);
    void setEstado(bool estado) { _estado = estado; }

    friend std::ostream& operator<<(std::ostream& os, const Libro& libro);
    bool operator==(const Libro& libro) const { return std::strcmp(_ISBN, libro.getISBN()) == 0; }
};

bool validarISBN(const char* ISBN);

#endif // LIBRO_H_INCLUDED
