#include "ArchivoLibros.h"

ArchivoLibros::ArchivoLibros()
{
    cargar();
}

ArchivoLibros::~ArchivoLibros()
{
    guardar();
}

void ArchivoLibros::agregarLibro(Libro& libro)
{
    libros.push_back(libro);
}

bool ArchivoLibros::quitarLibro(const char* ISBN)
{
    for (auto i = libros.begin(); i != libros.end(); ++i)
    {
        if (std::strcmp(i->getISBN(), ISBN) == 0)
        {
            libros.erase(i);
            return true;
        }
    }
    return false;
}


void ArchivoLibros::listarLibros()
{
    rlutil::saveDefaultColor();

    rlutil::setColor(rlutil::LIGHTRED);
    std::cout << "---- LISTADO DE LIBROS ----\n\n";
    rlutil::resetColor();

    if (libros.empty())
    {
        std::cout << "No hay libros registrados." << "\n\n";
        return;
    }

    for (auto& libro : libros)
    {
        std::cout << libro << '\n';
    }
}

void ArchivoLibros::modificarCantidadEjemplares(const char* ISBN, int cantidadEjemplares)
{
    for (auto& libro : libros)
    {
        if (std::strcmp(libro.getISBN(), ISBN) == 0)
        {
            libro.setCantidadEjemplares(cantidadEjemplares);
        }
    }
}

Libro ArchivoLibros::buscarPorISBN(const char* ISBN)
{
    for (auto& libro : libros)
    {
        if (std::strcmp(libro.getISBN(), ISBN) == 0)
        {
            return libro;
        }
    }
}

bool ArchivoLibros::existeLibro(const char* ISBN)
{
    for (auto& libro : libros)
    {
        if (std::strcmp(libro.getISBN(), ISBN) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

std::vector<Libro> ArchivoLibros::buscarPorGenero(Genero genero)
{
    std::vector<Libro> resultados;

    for (auto& libro : libros)
    {
        if (libro.getGenero() == genero)
        {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

void ArchivoLibros::cargar()
{
    libros.clear();
    std::ifstream archivo("data/libros.dat", std::ios::binary);

    if (!archivo.is_open())
    {
        return;
    }

    Libro libro;

    while (archivo.read(reinterpret_cast<char*>(&libro), sizeof(Libro)))
    {
        libros.push_back(libro);
    }
}

void ArchivoLibros::guardar()
{
    _mkdir("data");

    std::ofstream archivo("data/libros.dat", std::ios::binary | std::ios::trunc);

    if (!archivo.is_open())
    {
        return;
    }

    for (auto& libro : libros)
    {
        archivo.write(reinterpret_cast<const char*>(&libro), sizeof(Libro));
    }
}
