#include "Autor.h"

Autor::Autor(std::string nombre, std::string apellido)
    : _nombre{ nombre }, _apellido{ apellido }
{
    _autorID = autorID++;
}

int Autor::autorID = 1;
