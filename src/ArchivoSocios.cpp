#include "ArchivoSocios.h"

ArchivoSocios::ArchivoSocios()
{
    cargar();
}

ArchivoSocios::~ArchivoSocios()
{
    guardar();
}

void ArchivoSocios::agregarSocio(Socio& socio)
{
    socios.push_back(socio);
}

/*void ArchivoSocios::quitarSocio(int socioID)
{
    for (auto i = socios.begin(); i != socios.end(); ++i)
    {
        if (i->getSocioID() == socioID)
        {
            socios.erase(i);
            return;
        }
    }
}*/

bool ArchivoSocios::quitarSocio(int socioID)
{
    for (auto i = socios.begin(); i != socios.end(); ++i)
    {
        if (i->getSocioID() == socioID)
        {
            socios.erase(i);
            guardar();  // actualiza el archivo después de borrar
            return true;  
        }
    }

    // Si termina el for sin encontrar el ID
    return false;
}
void ArchivoSocios::listarSocios()
{
    if (socios.empty())
    {
        std::cout << "No hay socios registrados.\n";
        return;
    }

    std::cout << "---- LISTADO DE SOCIOS ----\n\n";
    for (const auto& socio : socios)
    {
        std::cout << socio << '\n';
    }
}

void ArchivoSocios::cargar()
{
    socios.clear();
    std::ifstream archivo("data/socios.dat", std::ios::binary);

    if (!archivo.is_open())
    {
        return;
    }

    int ID;
    archivo.read(reinterpret_cast<char*>(&ID), sizeof(int));
    Socio::setID(ID);

    Socio socio;
    while (archivo.read(reinterpret_cast<char*>(&socio), sizeof(Socio)))
    {
        socios.push_back(socio);
    }
    archivo.close();
}

void ArchivoSocios::guardar()
{
    _mkdir("data");

    std::ofstream archivo("data/socios.dat", std::ios::binary | std::ios::trunc);

    if (!archivo.is_open())
    {
        return;
    }

    int ID = Socio::getID();
    archivo.write(reinterpret_cast<const char*>(&ID), sizeof(int));

    for (auto& socio : socios)
    {
        archivo.write(reinterpret_cast<const char*>(&socio), sizeof(Socio));
    }
    archivo.close();
}
