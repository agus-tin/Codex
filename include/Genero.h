#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

#include <iostream>

enum class Genero
{
    Misc,
    NoFiccion,
    CienciaFiccion,
    Fantasia,
    Historia,
    Informatica,
    Matematica,
    Linguistica,
    Arte,
    Misterio,
    Biografia
};

inline std::ostream& operator<<(std::ostream& os, const Genero& genero)
{
    switch (genero)
    {
        case Genero::Misc: os << "Miscelaneo"; break;
        case Genero::NoFiccion: os << "No ficcion"; break;
        case Genero::CienciaFiccion: os << "Ciencia ficcion"; break;
        case Genero::Fantasia: os << "Fantasia"; break;
        case Genero::Historia: os << "Historia"; break;
        case Genero::Informatica: os << "Informatica"; break;
        case Genero::Matematica: os << "Matematica"; break;
        case Genero::Linguistica: os << "Linguistica"; break;
        case Genero::Arte: os << "Arte"; break;
        case Genero::Misterio: os << "Misterio"; break;
        case Genero::Biografia: os << "Biografia"; break;
    }
    return os;
}

#endif // GENERO_H_INCLUDED
