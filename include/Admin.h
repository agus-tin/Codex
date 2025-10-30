#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>
#include "Persona.h"
#include "Rol.h"

class Admin : public Persona
{
private:
    int _adminID;
    std::string _usuario;
    std::string _contrasenia;
    Rol _rol;

    static int adminID;

public:
    Admin();
    Admin(std::string usuario, std::string contrasenia, Rol rol);

    int getAdminID() const { return _adminID; }
    std::string getUsuario() const { return _usuario; }
    std::string getContrasenia() const { return _contrasenia; }
    Rol getRol() const { return _rol; }

    void setUsuario( std::string usuario);
    void setContrasenia(std::string contrasenia);
    void setRol(Rol rol);

    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
    bool operator==(const Admin& admin) const { return _adminID == admin.getAdminID(); }
};

#endif // ADMIN_H
