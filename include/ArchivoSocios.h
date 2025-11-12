#ifndef ARCHIVOSOCIOS_H_INCLUDED
#define ARCHIVOSOCIOS_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "Socio.h"

class ArchivoSocios
{
private:
    std::vector<Socio> socios;

public:
    ArchivoSocios();
    ~ArchivoSocios();

    void agregarSocio(Socio& socio);
    void quitarSocio(int socioID);
    void listarSocios();

    void cargar();
    void guardar();

};


#endif // ARCHIVOSOCIOS_H_INCLUDED
