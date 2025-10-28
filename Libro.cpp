#include "Libro.h"

bool validadISBN(std::string ISBN)
{
    if (ISBN.size() != 13)
    {
        return false;
    }

    int sum = 0;

    for (int i = 0; i < 12; i++)
    {
        if (!isdigit(ISBN[i]))
        {
            return false;
        }

        int digito = ISBN[i] - '0';

        sum += (i % 2 == 0) ? digito : digito * 3;
    }

    int check = (10 - (sum % 10)) % 10;

    return ISBN[12] - '0' == check;
}

Libro::Libro(std::string ISBN, std::string titulo, Autor autor, std::string editorial, int cantidadEjemplares, Genero genero, bool estado)
    : _titulo{ titulo }, _autor{ autor }, _editorial{ editorial }, _cantidadEjemplares{ cantidadEjemplares }, _genero{ genero }, _estado{ estado }
{
    setISBN(ISBN);
}

void Libro::setISBN(std::string ISBN)
{
    if (validadISBN(ISBN))
    {
        _ISBN = ISBN;
    }
}
