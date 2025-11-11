#include "Libro.h"
#include <cctype>

/// NOTAS:
/// -Código como "_usuario[sizeof(_usuario) - 1] = '\0';" asegura que _usuario siempre sea una cadena válida,
/// que las funciones como std::cout << _usuario o strcmp no lean fuera de los límites y
/// que no haya comportamiento indefinido por falta del terminador nulo.

bool validarISBN(const char* ISBN)
{
    int len = std::strlen(ISBN);
    if (len != 13)
    {
        return false;
    }

    // Un ISBN funciona como un checksum que tenemos que validar de la siguiente manera:

    int suma = 0;
    for (int i = 0; i < 12; i++)
    {
        if (!isdigit(ISBN[i]))
        {
            return false;
        }

        int digito = ISBN[i] - '0';
        suma += (i % 2 == 0) ? digito : digito * 3;
    }

    int check = (10 - (suma % 10)) % 10;
    return ISBN[12] - '0' == check;
}

Libro::Libro()
{
    std::strcpy(_ISBN, "0000000000000");
    std::strcpy(_titulo, "titulo");
    std::strcpy(_editorial, "editorial");
    _cantidadEjemplares = 0;
    _estado = true;
}

Libro::Libro(const char* ISBN, const char* titulo, const char* autor, const char* editorial, Fecha fechaPublicacion, int cantidadEjemplares, Genero genero, bool estado)
{
    setISBN(ISBN);
    std::strncpy(_titulo, titulo, sizeof(_titulo) - 1);
    _titulo[sizeof(_titulo) - 1] = '\0';

    std::strncpy(_autor, autor, sizeof(_autor) - 1);
    _autor[sizeof(_autor) - 1] = '\0';

    std::strncpy(_editorial, editorial, sizeof(_editorial) - 1);
    _editorial[sizeof(_editorial) - 1] = '\0';

    _fechaPublicacion = fechaPublicacion;
    _cantidadEjemplares = cantidadEjemplares;
    _genero = genero;
    _estado = estado;
}

void Libro::setISBN(const char* ISBN)
{
    if (validarISBN(ISBN))
    {
        std::strncpy(_ISBN, ISBN, sizeof(_ISBN) - 1);
        _ISBN[sizeof(_ISBN) - 1] = '\0';
    }
    else
    {
        std::strcpy(_ISBN, "ISBN no valido");
    }
}

bool Libro::guardar()
{
    // Implementación futura
    return false;
}

bool Libro::cargar(int pos)
{
    // Implementación futura
    return false;
}

std::ostream& operator<<(std::ostream& os, const Libro& libro)
{
    os << "ISBN: " << libro._ISBN << '\n';
    os << "Titulo: " << libro._titulo << '\n';
    os << "Autor: " << libro._autor << '\n';
    os << "Genero: " << libro._genero << '\n';
    os << "Editorial: " << libro._editorial << '\n';
    os << "Fecha de publicacion: " << libro._fechaPublicacion << '\n';
    os << "Estado: " << (libro._estado ? "Disponible" : "No disponible") << '\n';
    if (libro._estado)
        os << "Cantidad de ejemplares: " << libro._cantidadEjemplares << '\n';

    return os;
}
