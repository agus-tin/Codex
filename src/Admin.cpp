#include "Admin.h"

std::string rolString(Rol rol)
{
    switch(rol)
    {
        case Rol::Auxiliar:       return "Auxiliar";
        case Rol::Bibliotecario:  return "Bibliotecario";
        case Rol::SysAdmin:       return "SysAdmin";
        default:                  return "Auxiliar";
    }
}

int Admin::adminID = 1;

Admin::Admin()
    : _usuario{ "usuario" }, _contrasenia{ "contrasenia" }, _rol{}
{}

Admin::Admin(std::string usuario, std::string contrasenia, Rol rol)
    : _usuario{ usuario }, _contrasenia{ contrasenia }, _rol{ rol }
{
    _adminID = adminID++;
}

void Admin::setUsuario(std::string usuario)
{
    _usuario = usuario;
}

void Admin::setContrasenia(std::string contrasenia)
{
    _contrasenia = contrasenia;
}

void Admin::setRol(Rol rol)
{
    _rol = rol;
}

std::ostream& operator<<(std::ostream& os, const Admin& admin)
{
    os << "AdminID: " << admin.getAdminID() << '\n';
    os << "Nombre: " << admin.getNombre() << " " << admin.getApellido() << '\n';
    Rol rol = admin.getRol();
    os << "Rol: " << rolString(rol);

    return os;
}
