#ifndef ARCHIVOADMINS_H_INCLUDED
#define ARCHIVOADMINS_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "Admin.h"
#include "rlutil.h"

class ArchivoAdmins
{
private:
    std::vector<Admin> admins;

public:
    ArchivoAdmins();
    ~ArchivoAdmins();

    bool validarUsuario(const char* usuario, const char* contrasenia);
    bool validarPrivilegios(const char* usuario);

    void agregarAdmin(Admin& admin);
    void quitarAdmin(int adminID);
    void listarAdmins();

    void cargar();
    void guardar();

};



#endif // ARCHIVOADMINS_H_INCLUDED
