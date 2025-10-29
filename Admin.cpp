#include <iostream>
#include "Admin.h"

void Admin::setadminID(int adminID)
{
    if (adminID > 0)
    {
        _adminID = adminID;
    }
}

void Admin::setusuario(std::string usuario)
{
    _usuario = usuario;
}

void Admin::setcontrasenia(std::string contrasenia)
{
    _contrasenia = contrasenia;
}

void Admin::setrol(std::string& rol)
{
    _rol = rol;
}

void Admin::cargar()
{
    // En esta etapa solo cargamos datos por consola
    cout << "Ingrese ID del administrador: ";
    cin >> _adminID;
    cin.ignore();

    cout << "Ingrese usuario: ";
    getline(cin, _usuario);

    cout << "Ingrese contrasenia: ";
    getline(cin, _contrasenia);

    cout << "Ingrese rol: ";
    getline(cin, _rol);
}

void Admin::mostrar()
{
    cout << "-----------------------------" << std::endl;
    cout << "ID Admin: " << _adminID << std::endl;
    cout << "Usuario: " << _usuario << std::endl;
    cout << "Rol: " << _rol << std::endl;
    cout << "-----------------------------" << std::endl;
}
