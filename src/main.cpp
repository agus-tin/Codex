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

int seleccionarOpcion(int& opcion);
void menuLibros(Biblioteca biblioteca);

int main()
{
    // Inicialización
    Biblioteca biblioteca;

    // Esto es código de prueba.
    // Lo usé para agregar libros y el usuario "user1" de forma manual, pero obviamente tenemos que empezar a hacerlo con la interfaz.

    //Admin admin1("user1", "pass1", Rol::SysAdmin);
    //Libro libro1("9781138627000", "Real-Time Rendering", "Tomas Akenine-Moller, et al", "CRC Press", Fecha(6, 8, 2018), 1, Genero::Informatica, true);
    //Libro libro2("9780201835953", "Mythical Man-Month", "Frederick Brooks Jr.", "Addison-Wesley Professional", Fecha(2, 8, 1995), 0, Genero::Informatica, false);

    //biblioteca.admins.agregarAdmin(admin1);
    //biblioteca.libros.agregarLibro(libro1);
    //biblioteca.libros.agregarLibro(libro2);

    // Menu inicial

    while (true)
    {
        system("cls");

        int opcion = 0;

        cout << "Bienvenido al Sistema Integrado de Gestion Bibliotecaria \"Codex\"" << "\n\n";

        cout << "Seleccione una opcion de las siguientes: " << "\n\n";

        cout << "1. Iniciar sesion." << '\n';
        cout << "2. Salir." << "\n\n";

        opcion = seleccionarOpcion(opcion);

        if (opcion == 1)
        {
            system("cls");
            break;
        }
        else if (opcion == 2)
        {
            return 0;
        }
        else
        {
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    // Inicio de sesión

    /// NOTAS:
    /// -Comentar el ingreso a sesión de esta manera lo deshabilita. Está bueno para testear.
    /// -Si el usuario no sabe sus datos queda atrapado en un loop infinito de validación. Posiblemente indeseado.

    /*while (true)
    {
        char usuario[30];
        char contrasenia[30];

        std::cout << "Ingrese sus datos: " << "\n\n";

        std::cout << "Usuario: ";
        std::cin >> usuario;
        std::cout << "Contrasenia: ";
        std::cin >> contrasenia;
        std::cout << '\n';

        if (biblioteca.admins.validarUsuario(usuario, contrasenia))
        {
            break;
        }

        system("cls");
        std::cout << "Usuario o contrasenia invalidos. Por favor intente de nuevo.\n\n";
        system("pause");
        system("cls");
    }*/

    //

    while (true)
    {
        system("cls");

        int opcion = 0;

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Administrar libros." << '\n';
        std::cout << "2. Salir." << '\n';

        opcion = seleccionarOpcion(opcion);

        if (opcion == 1)
        {
            menuLibros(biblioteca);
        }
        else if (opcion == 2)
        {
            return 0;
        }
        else
        {
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    return 0;
}

int seleccionarOpcion(int& opcion)
{
    if (!(cin >> opcion))
    {
        cin.clear(); // Limpia el estado de input stream.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Resetea el input stream.
    }

    return opcion;
}

void menuLibros(Biblioteca biblioteca)
{
    while (true)
    {
        system("cls");

        int opcion = 0;
        Libro libro;

        std::cout << "--------LIBROS--------" << "\n\n";

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Agregar libro." << '\n';
        std::cout << "2. Quitar libro." << '\n';
        std::cout << "3. Listar libros." << '\n';
        std::cout << "4. Volver al menu principal." << "\n\n";

        opcion = seleccionarOpcion(opcion);

        if (opcion == 1)
        {
            // Agregar libro.
        }
        else if (opcion == 2)
        {
            // Quitar libro.
        }
        else if (opcion == 3)
        {
            system("cls");

            biblioteca.libros.listarLibros();

            system("pause");
            system("cls");
        }
        else if (opcion == 4)
        {
            break;
        }
        else
        {
            system("cls");

            cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

}

/*void menuPrincipal()
{
    int opcion;

    do
    {
        system("cls");

        cout << "==============================\n";
        cout << "     SISTEMA DE BIBLIOTECA\n";
        cout << "==============================\n";
        cout << "1. Menu socios\n";
        cout << "2. Menu libros\n";
        cout << "3. Menu prestamos\n";
        cout << "4. Menu administradores\n";
        cout << "0. Salir\n";
        cout << "==============================\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            //case 1: menuSocios (); break;
            case 2: menuLibros(); break;
            //case 3: menuPrestamos(); break;
            //case 4: menuAdministradores(); break;
            case 0:
                return 0;
            default
                cout << "Opcion invalida. " << endl;
                break;
        }

        system("pause");

    } while (opcion!=0);

}*/

/*void menuSocios() {
    int opc;
    ArchivoSocios archSocios;
    Socio obj;
    do
    {
        system("pause");
        cout <<"-----MENU SOCIOS-----"<<endl;
        cout <<"1. Agregar socio"<<endl;
        cout <<"2. Listas socio"<<endl;
        cout <<"3. Buscar socio por numero de socio"<<endl;
        cout <<"4. Modificar socio"<<endl:
        cout <<"5. Borrar socio"<<endl;
        cout << "0. Volver al menu principal\n";
        cout << "-------------------"<<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: {
                obj.cargar();
                archSocios.grabarRegistro(obj);
                cout << "Socio agregado correctamente."<<endl;
                break;
            }

            case 2: {
                archSocios.listarArchivo();
                break;
            }

            case 3: {
                int nroSocio;
                cout << "Ingrese numero de socio a buscar: ";
                cin >> nroSocio;

                int pos = archSocios.buscarRegistroNroSocio(nroSocio);
                if (pos >= 0) {
                    obj = archSocios.leerRegistro(pos);
                    obj.mostrar();
                } else {
                    cout << "No se encontro ningun socio con ese numero."<<endl;
                }
                break;
            }

            case 4: {
                int nroSocio;
                cout << "Ingrese numero de socio a modificar: ";
                cin >> nroSocio;

                int pos = archSocios.buscarRegistroNroSocio(nroSocio);
                if (pos >= 0) {
                    obj = archSocios.leerRegistro(pos);
                    cout << "Socio actual:"<<endl;
                    obj.mostrar();

                    cout << "\nIngrese los nuevos datos: "<<endl;
                    obj.cargar();
                    archSocios.modificarRegistro(obj, pos);
                    cout << "Registro modificado correctamente."<<endl;
                } else {
                    cout << "Socio no encontrado."<<endl;
                }
                break;
            }

            case 5: { //
                int nroSocio;
                cout << "Ingrese numero de socio a eliminar: ";
                cin >> nroSocio;

                int pos = archSocios.buscarRegistroNroSocio(nroSocio);
                if (pos >= 0) {
                    obj = archSocios.leerRegistro(pos);
                    obj.setEstado(false);
                    archSocios.modificarRegistro(obj, pos);
                    cout << "Socio dado de baja correctamente."<<endl;
                } else {
                    cout << "Socio no encontrado."<<endl;
                }
                break;
            }
        }

        system("pause");
    } while(opc != 0);
}
*/
/* void menuLibros() {
    int opc;
    ArchivoLibros archLibros;
    Libro obj;

    do
    {
        system("cls");
        cout << "-----MENU LIBROS-----"<<endl;
        cout << "1. Agregar libro"<<endl;
        cout << "2. Listar libros"<<endl;
        cout << "3. Buscar libro por ISBN"<<endl;
        cout << "4. Modificar libro"<<endl;
        cout << "5. Eliminar libro "<<endl;
        cout << "0. Volver al menu principal"<<endl;
        cout << "---------------------"<<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: {
                obj.cargar();
                archLibros.grabarRegistro(obj);
                cout << "Libro agregado correctamente."<<endl;
                break;
            }

            case 2: {
                archLibros.listarArchivo();
                break;
            }

            case 3: {
                int isbn;
                cout << "Ingrese ISBN a buscar: ";
                cin >> isbn;

                int pos = archLibros.buscarRegistroIsbn(isbn);
                if (pos >= 0) {
                    obj = archLibros.leerRegistro(pos);
                    obj.mostrar();
                } else
                {
                    cout << "No se encontro ningun libro con ese ISBN."<<endl;
                }
                break;
            }

            case 4: {
                int isbn;
                cout << "Ingrese ISBN del libro a modificar: ";
                cin >> isbn;

                int pos = archLibros.buscarRegistroIsbn(isbn);
                if (pos >= 0)
                {
                    obj = archLibros.leerRegistro(pos);
                    cout << "Libro actual:\n";
                    obj.mostrar();

                    cout << "\nIngrese los nuevos datos:"<<endl;
                    obj.cargar();
                    archLibros.modificarRegistro(obj, pos);
                    cout << "Libro modificado correctamente."<<endl;
                }
                else
                {
                    cout << "Libro no encontrado."<<endl;
                }
                break;
            }

            case 5: {
                int isbn;
                cout << "Ingrese ISBN del libro a eliminar: ";
                cin >> isbn;

                int pos = archLibros.buscarRegistroIsbn(isbn);
                if (pos >= 0)
                {
                    obj = archLibros.leerRegistro(pos);
                    obj.setEstado(false);
                    archLibros.modificarRegistro(obj, pos);
                    cout << "Libro dado de baja correctamente."<<endl;
                } else {
                    cout << "Libro no encontrado."endl;
                }
                break;
            }
        }

        system("pause");

    } while(opc != 0);
}
*/
/*void menuPrestamos() {
    int opc;
    ArchivoPrestamos archPrestamos;
    Prestamo obj;

    do
    {
        system("cls");
        cout << "----- MENU PRESTAMOS -----"<<endl;
        cout << "1. Registrar prestamo"<<endl;
        cout << "2. Registrar devolucion"<<endl;
        cout << "3. Listar prestamos activos"<<endl;
        cout << "0. Volver al menu principal"<<endl;
        cout << "--------------------------"<<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: {
                obj.cargar();
                archPrestamos.grabarRegistro(obj);
                cout << "Prestamo registrado correctamente."<<endl;
                break;
            }

            case 2: {
                int idPrestamo;
                cout << "Ingrese ID del prestamo a devolver: ";
                cin >> idPrestamo;

                int pos = archPrestamos.buscarRegistroID(idPrestamo);
                if (pos >= 0) {
                    obj = archPrestamos.leerRegistro(pos);
                    if (obj.getDevuelto()) {
                        cout << "El prestamo ya fue devuelto."<<endl;
                    } else {
                        obj.setDevuelto(true);
                        archPrestamos.modificarRegistro(obj, pos);
                        cout << "Devolucion registrada correctamente."<<endl;
                    }
                } else {
                    cout << "Prestamo no encontrado."<<endl;
                }
                break;
            }

            case 3: {
                int cant = archPrestamos.contarRegistros();
                for (int i = 0; i < cant; i++) {
                    obj = archPrestamos.leerRegistro(i);
                    if (!obj.getDevuelto() && obj.getEstado()) {
                        obj.mostrar();
                        cout << "-----------------------------"<<endl;
                    }
                }
                break;
            }
        }

        system("pause");

    } while(opc != 0);
}*/
/*void menuAdministradores() {
    int opc;
    ArchivoAdmin archAdmin;
    Admin obj;

    do
    {
        system("cls");
        cout << "-----MENU ADMINISTRADORES-----"<<endl;
        cout << "1. Agregar administrador"<<endl;
        cout << "2. Listar administradores"<<endl;
        cout << "3. Buscar administrador por usuario"<<endl;
        cout << "4. Eliminar administrador "<<endl;
        cout << "0. Volver al menu principal"<<endl;
        cout << "------------------------------"<<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: {
                obj.cargar();
                archAdmin.grabarRegistro(obj);
                cout << "Administrador agregado correctamente."<<endl;
                break;
            }

            case 2: {
                archAdmin.listarArchivo();
                break;
            }

            case 3: {
                char usuario[30];
                cout << "Ingrese nombre de usuario: ";
                cin >> usuario;

                int pos = archAdmin.buscarRegistroUsuario(usuario);
                if (pos >= 0) {
                    obj = archAdmin.leerRegistro(pos);
                    obj.mostrar();
                } else {
                    cout << "Administrador no encontrado."<<endl;
                }
                break;
            }



            case 4: {
                char usuario[30];
                cout << "Ingrese nombre de usuario a eliminar: ";
                cin >> usuario;

                int pos = archAdmin.buscarRegistroUsuario(usuario);
                if (pos >= 0) {
                    obj = archAdmin.leerRegistro(pos);
                    obj.setEstado(false);
                    archAdmin.modificarRegistro(obj, pos);
                    cout << "Administrador dado de baja correctamente."<<endl;
                } else {
                    cout << "Administrador no encontrado."<<endl;
                }
                break;
            }
        }

        system("pause");

    } while(opc != 0);
}
*/
