#include "Admin.h"

const char* rolString(Rol rol)
{
    switch (rol)
    {
        case Rol::Auxiliar:       return "Auxiliar";
        case Rol::Bibliotecario:  return "Bibliotecario";
        case Rol::SysAdmin:       return "SysAdmin";
        default:                  return "Auxiliar";
    }
}

int Admin::adminID = 1;

Admin::Admin()
{
    std::strcpy(_usuario, "usuario");
    std::strcpy(_contrasenia, "contrasenia");
    _rol = Rol::Auxiliar;
    _adminID = adminID++;
}

Admin::Admin(const char* usuario, const char* contrasenia, Rol rol)
{
    std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
    _usuario[sizeof(_usuario) - 1] = '\0';
    std::strncpy(_contrasenia, contrasenia, sizeof(_contrasenia) - 1);
    _contrasenia[sizeof(_contrasenia) - 1] = '\0';
    _rol = rol;
    _adminID = adminID++;
}

void Admin::setUsuario(const char* usuario)
{
    std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
    _usuario[sizeof(_usuario) - 1] = '\0';
}

void Admin::setContrasenia(const char* contrasenia)
{
    std::strncpy(_contrasenia, contrasenia, sizeof(_contrasenia) - 1);
    _contrasenia[sizeof(_contrasenia) - 1] = '\0';
}

void Admin::setRol(Rol rol)
{
    _rol = rol;
}

std::ostream& operator<<(std::ostream& os, const Admin& admin)
{
    os << "AdminID: " << admin.getAdminID() << '\n';
    os << "Nombre: " << admin.getNombre() << " " << admin.getApellido() << '\n';
    os << "Usuario: " << admin.getUsuario() << '\n';
    os << "Rol: " << rolString(admin.getRol());
    return os;
}


