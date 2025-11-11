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

void ArchivoLibros::quitarLibro(const char* ISBN)
{
    for (auto i = libros.begin(); i != libros.end(); ++i)
    {
        if (std::strcmp(i->getISBN(), ISBN) == 0)
        {
            libros.erase(i);
            break;
        }
    }
}

void ArchivoLibros::listarLibros()
{
    if (libros.empty())
    {
        std::cout << "No hay libros registrados.\n";
        return;
    }

    for (auto& libro : libros)
    {
        std::cout << libro << '\n';
    }
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

    archivo.close();
}

void ArchivoLibros::guardar()
{
    _mkdir("data");

    std::ofstream archivo("data/libros.dat", std::ios::binary | std::ios::trunc);

    if (!archivo.is_open())
    {
        return;
    }

    for (const auto& libro : libros)
    {
        archivo.write(reinterpret_cast<const char*>(&libro), sizeof(Libro));
    }

    archivo.close();
}
