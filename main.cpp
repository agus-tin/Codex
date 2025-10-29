#include <iostream>
#include <vector>
#include <string>

#include "rlutil.h"

#include "Biblioteca.h"
#include "Libro.h"
#include "Prestamo.h"
#include "Admin.h"
#include "Socio.h"
#include "Genero.h"
#include "Rol.h"

using namespace std;

int main()
{
    // Inicialización
    Biblioteca biblioteca;

    // Menu inicial

    while (true)
    {
        int opcionMenuInicial = 0;

        cout << "Bienvenido al Sistema Integrado de Gestion Bibliotecaria \"Codex\"" << "\n\n";

        cout << "Seleccione una opcion de las siguientes: " << "\n\n";

        cout << "1. Iniciar sesion." << '\n';
        cout << "2. Salir." << "\n\n";

        if (!(cin >> opcionMenuInicial))
        {
            cin.clear(); // Limpia el estado de input stream.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Resetea el input stream.
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
            continue;
        }


        if (opcionMenuInicial == 1)
        {
            system("cls");
            break;
        }
        else if (opcionMenuInicial == 2)
        {
            exit(0);
        }
        else
        {
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    // Inicio de sesion

    /// NOTAS:
    /// -Un ADMIN tiene un "bool estado", hay que chequear si esta habilitado o no al iniciar sesion.

    while (true)
    {
        std::string usuario;
        std::string contrasenia;

        cout << "Ingrese sus datos:" << "\n\n";

        cout << "Usuario: ";
        cin >> usuario;

        cout << "Contrasenia: ";
        cin >> contrasenia;
        cout << '\n';

        Admin admin1("user1", "pass1", Rol::Bibliotecario);
        biblioteca.agregarAdmin(admin1);

        bool match = false;

        for (size_t i = 0; i < biblioteca.admins.size(); ++i)
        {
            if (biblioteca.admins[i].getUsuario() == usuario && biblioteca.admins[i].getEstado())
            {
                match = true;
                break;
            }
        }

        system("cls");

        if (!match)
        {
            system("cls");

            cout << "Usuario o contrasenia invalidos. Por favor intente de nuevo." << "\n\n";

            system("pause");
            system("cls");
        }
        else
        {
            break;
        }
    }

    return 0;
}
