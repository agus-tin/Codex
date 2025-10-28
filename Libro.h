#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <string>
#include "Autor.h"
#include "Fecha.h"
#include "Genero.h"

class Libro
{
private:
    std::string _ISBN;
    std::string _titulo;
    Autor _autor;
    std::string _editorial;
    int _cantidadEjemplares;
    Genero _genero;
    bool _estado;

public:
    Libro(std::string ISBN, std::string titulo, Autor autor, std::string editorial, int cantidadEjemplares, Genero genero, bool estado);

    std::string getISBN() const { return _ISBN; }
    std::string getTitulo() const { return _titulo; }
    Autor getAutor() const { return _autor; }
    std::string getEditorial() const { return _editorial; }
    int getCantidadEjemplares() const { return _cantidadEjemplares; }
    Genero getGenero() const { return _genero; }
    bool getEstado() const { return _estado; }

    void setISBN(std::string ISBN);
    void setCantidadEjemplares(int cantidadEjemplares) { _cantidadEjemplares = cantidadEjemplares; }
    void setEstado(bool estado) { _estado = estado; }
};

#endif // LIBRO_H_INCLUDED
