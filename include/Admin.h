#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Rol.h"

class Admin : public Persona
{
private:
    int _adminID;
    char _usuario[30];
    char _contrasenia[30];
    Rol _rol;

    static int adminID;

public:
    Admin();
    Admin(const char* usuario, const char* contrasenia, Rol rol);

    int getAdminID() const { return _adminID; }
    const char* getUsuario() const { return _usuario; }
    const char* getContrasenia() const { return _contrasenia; }
    Rol getRol() const { return _rol; }

    void setUsuario(const char* usuario);
    void setContrasenia(const char* contrasenia);
    void setRol(Rol rol);

    static int getID() { return adminID; }
    static void setID(int ID) { adminID = ID; }

    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
    bool operator==(const Admin& admin) const { return _adminID == admin.getAdminID(); }
};

#endif // ADMIN_H_INCLUDED

