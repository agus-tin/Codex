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

        if (!(cin >> opcionMenuInicial)) // Para rechazar cosas que no son ints.
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

            cout << "Opcion invalida. Por favor ingrese un numero de los ofrecidos." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    // Inicio de sesion

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
        bool adminEstado = false;

        for (size_t i = 0; i < biblioteca.admins.size(); ++i)
        {
            if (biblioteca.admins[i].getUsuario() == usuario)
            {
                match = true;
                adminEstado = biblioteca.admins[i].getEstado();
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
        else if (match && !adminEstado)
        {
            system("cls");

            cout << "Usuario inhabilitado." << "\n\n";

            system("pause");
            system("cls");
        }
        else if (match && adminEstado)
        {
            break;
        }

    }

    // Menu principal

    while (true)
    {
        int opcionMenuPrincipal;

        cout << "Menu principal" << "\n\n";

        cout << "Seleccione una opcion de las siguientes:" << "\n\n";

        cout << "1. Libros." << '\n';
        cout << "2. Prestamos" << '\n';
        cout << "3. ." << '\n';
        cout << "4. Cuota." << "\n\n";

        if (!(cin >> opcionMenuPrincipal)) // Para rechazar cosas que no son ints.
        {
            cin.clear(); // Limpia el estado de input stream.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Resetea el input stream.
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
            continue;
        }

        switch (opcionMenuPrincipal)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            default:
                system("cls");

                cout << "Opcion invalida. Por favor ingrese un numero de los ofrecidos." << "\n\n";

                system("pause");
                system("cls");
                break;
        }

    }

    return 0;
}
