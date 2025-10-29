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

Libro::Libro()
        :
            _titulo{ "titulo" },
            _autor{},
            _editorial{ "editorial" },
            _fechaPublicacion{},
            _cantidadEjemplares{},
            _genero{}
{}

Libro::Libro(std::string ISBN,
             std::string titulo,
             Autor autor,
             std::string editorial,
             Fecha fechaPublicacion,
             int cantidadEjemplares,
             Genero genero,
             bool estado)
        :
            _titulo{ titulo },
            _autor{ autor },
            _editorial{ editorial },
            _fechaPublicacion{ fechaPublicacion },
            _cantidadEjemplares{ cantidadEjemplares },
            _genero{ genero },
            _estado{ estado }
{
    setISBN(ISBN);
}

void Libro::setISBN(std::string& ISBN)
{
    if (validadISBN(ISBN))
    {
        _ISBN = ISBN;
    }
    else
    {
        _ISBN = "ISBN no validado";
    }
}

bool Libro::guardar()
{

}

bool Libro::cargar(int pos)
{

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
    if (libro._estado) os << "Cantidad de ejemplares: " << libro._cantidadEjemplares << '\n';

    return os;
}
