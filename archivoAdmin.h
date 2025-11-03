#ifndef CLSARCHIVOADMIN_H_INCLUDED
#define CLSARCHIVOADMIN_H_INCLUDED

#include "Admin.h"

class ArchivoAdmin {
private:
    char _nombre[30];

public:
    ArchivoAdmin(const char* n = "admin.dat");

    void grabarRegistro(Admin obj);
    Admin leerRegistro(int pos);
    int contarRegistros();
    int buscarRegistroUsuario(const char* usuario);
    int ultimoRegistro();
    void listarArchivo();
    void modificarRegistro(Admin obj, int pos);
    bool copiaSeguridadRegistro();
    bool restaurarRegistro();
};

#endif // CLSARCHIVOADMIN_H_INCLUDED
