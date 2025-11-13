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

void menuLibros(Biblioteca& biblioteca);
void menuPrestamos(Biblioteca& biblioteca);
void menuAdmins(Biblioteca& biblioteca);
void menuSocios(Biblioteca& biblioteca);
int validarInput(int input);

int main()
{
    // Inicialización
    Biblioteca biblioteca;

    rlutil::saveDefaultColor();
    rlutil::hidecursor();

    // Esto es código de prueba.

    //Admin admin1(12345678, "Sys", "Admin", Fecha(1,1,2000), 1234567890, true, "agustinvalle23@gmail.com", "SYSADMIN", "12345", Rol::SysAdmin);
    //Libro libro1("9781138627000", "Real-Time Rendering", "Tomas Akenine-Moller, et al", "CRC Press", Fecha(6, 8, 2018), 1, Genero::Informatica);
    //Libro libro2("9780201835953", "Mythical Man-Month", "Frederick Brooks Jr.", "Addison-Wesley Professional", Fecha(2, 8, 1995), 2, Genero::Informatica);

    //biblioteca.admins.agregarAdmin(admin1);
    //biblioteca.libros.agregarLibro(libro1);
    //biblioteca.libros.agregarLibro(libro2);

    // Menu inicial

    while (true)
    {
        system("cls");

        int opcion = 0;

        std::cout << "Bienvenido al Sistema Integrado de Gestion Bibliotecaria ";
                rlutil::setColor(rlutil::LIGHTMAGENTA);
        std::cout << "\"Codex\"";
        rlutil::resetColor();
        std::cout << "." << "\n\n";

        std::cout << "Seleccione una opcion de las siguientes: " << "\n\n";

        std::cout << "1. Iniciar sesion." << '\n';
        std::cout << "2. Salir." << "\n\n";

        opcion = validarInput(opcion);

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

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    // Inicio de sesión

    /// NOTAS:
    /// -Comentar el ingreso a sesión lo deshabilita. Está bueno para testear.

    char usuario[30];
    char contrasenia[30];

    while (true)
    {
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
        std::cout << "Usuario o contrasenia invalidos. Por favor intente de nuevo." << "\n\n";
        system("pause");
        system("cls");
    }

    // Menu principal

    while (true)
    {
        system("cls");

        int opcion = 0;

        rlutil::setColor(rlutil::YELLOW);
        std::cout << "=======================\n";
        std::cout << "    MENU PRINCIPAL\n";
        std::cout << "=======================\n\n";
        rlutil::resetColor();

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Administrar libros." << '\n';
        std::cout << "2. Administrar prestamos." << '\n';
        std::cout << "3. Administrar usuarios." << '\n';
        std::cout << "4. Administrar socios." << '\n';
        std::cout << "5. Salir." << '\n';

        opcion = validarInput(opcion);

        if (opcion == 1)
        {
            menuLibros(biblioteca);
        }
        else if (opcion ==2)
        {
            menuPrestamos(biblioteca);
        }
        else if (opcion == 3)
        {
            if (biblioteca.admins.validarPrivilegios(usuario))
            {
                menuAdmins(biblioteca);
            }
            else
            {
                system("cls");

                std::cout << "No tienes los privilegios requeridos para acceder a este menu." << "\n\n";

                system("pause");
                system("cls");
            }

        }
        else if (opcion == 4)
        {
            menuSocios(biblioteca);
        }
        else if (opcion == 5)
        {
            return 0;
        }
        else
        {
            system("cls");

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }

    return 0;
}


void menuLibros(Biblioteca& biblioteca)
{
    while (true)
    {
        system("cls");

        int opcion = 0;

        rlutil::setColor(rlutil::LIGHTRED);
        std::cout << "--------LIBROS--------" << "\n\n";
        rlutil::resetColor();

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Agregar libro." << '\n';
        std::cout << "2. Quitar libro." << '\n';
        std::cout << "3. Listar libros." << '\n';
        std::cout << "4. Buscar libro por filtro." << '\n';
        std::cout << "5. Modificar cantidad de ejemplares." << '\n';
        std::cout << "6. Volver al menu principal." << "\n\n";

        opcion = validarInput(opcion);

        if (opcion == 1)
        {
            system("cls");

            char ISBN[14];
            char titulo[50];
            char autor[50];
            char editorial[50];
            Fecha fecha;
            int cantidadEjemplares = 0;
            Genero genero;

            // ISBN
            while (true)
            {
                std::cout << "ISBN (13 digitos): ";
                std::cin >> ISBN;

                if (validarISBN(ISBN))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Numero ISBN invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Titulo
            std::cout << "Titulo: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(titulo, 50);

            // Autor
            std::cout << "Autor: ";
            std::cin.getline(autor, 50);

            // Editorial
            std::cout << "Editorial: ";
            std::cin.getline(editorial, 50);

            // Fecha
            while (true)
            {
                int dia, mes, anio;

                std::cout << "Fecha de publicacion: " << '\n';

                std::cout << "   Dia: ";
                if (!(std::cin >> dia) || dia < 1 || dia > 31)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Dia invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Mes: ";
                if (!(std::cin >> mes) || mes < 1 || mes > 12)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Mes invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Anio: ";
                if (!(std::cin >> anio) || anio < 1500)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Anio invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                fecha.setFecha(dia, mes, anio);

                break;
            }

            // Cantidad de ejemplares
            while (true)
            {
                std::cout << "Cantidad de ejemplares: ";
                if (!(std::cin >> cantidadEjemplares))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Cantidad invalida, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
                else
                {
                    break;
                }
            }

            // Genero
            while (true)
            {
                std::cout << "Genero (elija una de las categorias): " << '\n';
                std::cout << "   1. Miscelaneo." << '\n';
                std::cout << "   2. No ficcion." << '\n';
                std::cout << "   3. Ciencia ficcion." << '\n';
                std::cout << "   4. Fantasia." << '\n';
                std::cout << "   5. Historia." << '\n';
                std::cout << "   6. Informatica." << '\n';
                std::cout << "   7. Matematica." << '\n';
                std::cout << "   8. Linguistica." << '\n';
                std::cout << "   9. Arte." << '\n';
                std::cout << "   10. Misterio." << '\n';
                std::cout << "   11. Biografia." << '\n';

                int opcionGenero;

                if (!(std::cin >> opcionGenero) || opcionGenero < 1 || opcionGenero > 11)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Genero invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
                else
                {
                    genero = static_cast<Genero>(opcionGenero - 1);
                    break;
                }
            }

            Libro libro(ISBN, titulo, autor, editorial, fecha, cantidadEjemplares, genero);
            biblioteca.libros.agregarLibro(libro);

        }

        else if (opcion == 2)
        {
            char ISBN[14];

            while (true)
            {
                system("cls");

                std::cout << "Escriba el numero ISBN del libro que quiera quitar: ";
                std::cin >> ISBN;

                if (validarISBN(ISBN))
                {
                    biblioteca.libros.quitarLibro(ISBN);

                    system("cls");
                    std::cout << "El libro, si es que estaba en la coleccion, ha sido removido." << "\n\n";
                    system("pause");
                    system("cls");

                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Numero ISBN invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

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
            int opcionFiltro;

            while (true)
            {
                system("cls");

                rlutil::setColor(rlutil::LIGHTRED);
                std::cout << "----BUSQUEDA POR FILTRO----" << "\n\n";
                rlutil::resetColor();

                std::cout << "Seleccione una opcion: " << "\n\n";

                std::cout << "1. Filtrar por ISBN." << '\n';
                std::cout << "2. Filtrar por genero." << '\n';
                std::cout << "3. Volver al menu de libros." << "\n\n";

                opcionFiltro = validarInput(opcionFiltro);

                if (opcionFiltro == 1)
                {
                    system("cls");

                    char ISBN[14];

                    while (true)
                    {
                        std::cout << "Ingrese el numero ISBN: ";
                        std::cin >> ISBN;

                        if (validarISBN(ISBN))
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            std::cout << "Numero ISBN invalido, pruebe de nuevo." << "\n\n";
                            system("pause");
                            system("cls");
                        }
                    }

                    system("cls");

                    Libro libro = biblioteca.libros.buscarPorISBN(ISBN);

                    rlutil::saveDefaultColor();

                    rlutil::setColor(rlutil::LIGHTRED);
                    std::cout << "-Libro con ISBN " << ISBN << "-\n\n";
                    rlutil::resetColor();

                    std::cout << libro << '\n';

                    system("pause");
                    system("cls");
                }
                else if (opcionFiltro == 2)
                {
                    Genero genero;

                    while (true)
                    {
                        system("cls");

                        std::cout << "Seleccione uno de los siguientes generos: " << '\n';

                        std::cout << "   1. Miscelaneo." << '\n';
                        std::cout << "   2. No ficcion." << '\n';
                        std::cout << "   3. Ciencia ficcion." << '\n';
                        std::cout << "   4. Fantasia." << '\n';
                        std::cout << "   5. Historia." << '\n';
                        std::cout << "   6. Informatica." << '\n';
                        std::cout << "   7. Matematica." << '\n';
                        std::cout << "   8. Linguistica." << '\n';
                        std::cout << "   9. Arte." << '\n';
                        std::cout << "   10. Misterio." << '\n';
                        std::cout << "   11. Biografia." << '\n';

                        int opcionGenero;

                        if (!(std::cin >> opcionGenero) || opcionGenero < 1 || opcionGenero > 11)
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            system("cls");
                            std::cout << "Genero invalido, pruebe de nuevo." << "\n\n";
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            genero = static_cast<Genero>(opcionGenero - 1);
                            break;
                        }
                    }

                    system("cls");

                    std::vector<Libro> libroPorGenero = biblioteca.libros.buscarPorGenero(genero);

                    rlutil::saveDefaultColor();

                    rlutil::setColor(rlutil::LIGHTRED);
                    std::cout << "--- Libros de " << genero << "---\n\n";
                    rlutil::resetColor();

                    if (libroPorGenero.empty())
                    {
                        system("cls");

                        std::cout << "No hay libros registrados de este genero." << "\n\n";

                    }

                    for (auto& libro : libroPorGenero)
                    {
                        std::cout << libro << '\n';
                    }

                    system("pause");
                    system("cls");
                }
                else if (opcionFiltro == 3)
                {
                    break;
                }
                else
                {
                    system("cls");

                    std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

                    system("pause");
                    system("cls");
                }
            }

        }
        else if (opcion == 5)
        {
            system("cls");

            char ISBN[14];

            while (true)
            {
                std::cout << "Ingrese el ISBN del libro: ";
                std::cin >> ISBN;

                if (validarISBN(ISBN))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Numero ISBN invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            int cantidadEjemplares;

            while (true)
            {
                std::cout << "Ingrese la nueva cantidad de ejemplares: ";

                cantidadEjemplares = validarInput(cantidadEjemplares);

                if (!(cantidadEjemplares < 0))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Cantidad de ejemplares no valida, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

                biblioteca.libros.modificarCantidadEjemplares(ISBN, cantidadEjemplares);

        }
        else if (opcion == 6)
        {
            break;
        }
        else
        {
            system("cls");

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }
}

void menuPrestamos(Biblioteca& biblioteca)
{
    while (true)
    {
        system("cls");

        int opcion = 0;

        rlutil::setColor(rlutil::LIGHTBLUE);
        std::cout << "-------PRESTAMOS-------" << "\n\n";
        rlutil::resetColor();

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Agregar prestamo." << '\n';
        std::cout << "2. Quitar prestamo." << '\n';
        std::cout << "3. Listar prestamos." << '\n';
        std::cout << "4. Cambiar fecha de devolucion." << '\n';
        std::cout << "5. Volver al menu principal." << "\n\n";

        opcion = validarInput(opcion);

        if (opcion == 1)
        {
            system("cls");

            char ISBN[14];
            int socioID;
            Fecha fechaDevolucion;

            // ISBN
            while (true)
            {
                std::cout << "ISBN del libro prestado (13 digitos): ";
                std::cin >> ISBN;

                if (validarISBN(ISBN))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Numero ISBN invalido, pruebe de nuevo.\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // socioID
            while (true)
            {
                std::cout << "Escriba el ID del socio que haya hecho el prestamo: ";

                socioID = validarInput(socioID);

                if (socioID > 0)
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "ID de socio invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Fecha de devolución
            while (true)
            {
                int dia, mes, anio;

                std::cout << "Fecha de devolucion:" << '\n';

                std::cout << "   Dia: ";
                if (!(std::cin >> dia) || dia < 1 || dia > 31)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Dia invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Mes: ";
                if (!(std::cin >> mes) || mes < 1 || mes > 12)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Mes invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Anio: ";
                if (!(std::cin >> anio) || anio < 1900 || anio > 2030)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Anio invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                fechaDevolucion.setFecha(dia, mes, anio);
                break;
            }

            Prestamo prestamo(ISBN, socioID, fechaDevolucion);

            biblioteca.prestamos.agregarPrestamo(prestamo);
        }
        else if (opcion == 2)
        {
            int prestamoID;

            while (true)
            {
                system("cls");

                std::cout << "Escriba el ID del prestamo que quiera quitar: ";

                prestamoID = validarInput(prestamoID);

                if (prestamoID > 0)
                {
                    biblioteca.prestamos.quitarPrestamo(prestamoID);

                    system("cls");
                    std::cout << "El prestamo, si es que estaba en el registro, ha sido removido." << "\n\n";
                    system("pause");
                    system("cls");

                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "ID de prestamo invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (opcion == 3)
        {
            system("cls");

            biblioteca.prestamos.listarPrestamos();

            system("pause");
            system("cls");
        }
        else if (opcion == 4)
        {
            int prestamoID;

            while (true)
            {
                system("cls");

                std::cout << "Ingrese el ID del prestamo: ";

                prestamoID = validarInput(prestamoID);

                if (prestamoID > 0)
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "ID de prestamo invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            Fecha fechaDevolucion;

            while (true)
            {

                int dia, mes, anio;

                std::cout << "Ingrese nueva fecha de devolucion:" << '\n';

                std::cout << "   Dia: ";
                if (!(std::cin >> dia) || dia < 1 || dia > 31)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");

                    std::cout << "Dia invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Mes: ";
                if (!(std::cin >> mes) || mes < 1 || mes > 12)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Mes invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Anio: ";
                if (!(std::cin >> anio) || anio < 1900 || anio > 2025)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");

                    std::cout << "Anio invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                fechaDevolucion.setFecha(dia, mes, anio);

                biblioteca.prestamos.cambiarFechaDevolucion(prestamoID, fechaDevolucion);

                break;
            }
        }
        else if (opcion == 5)
        {
            break;
        }
        else
        {
            system("cls");

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }
}

void menuAdmins(Biblioteca& biblioteca)
{
    while (true)
    {
        system("cls");

        int opcion = 0;

        rlutil::setColor(rlutil::GREEN);
        std::cout << "-------USUARIOS-------" << "\n\n";
        rlutil::resetColor();

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Agregar usuario." << '\n';
        std::cout << "2. Quitar usuario." << '\n';
        std::cout << "3. Listar usuario." << '\n';
        std::cout << "4. Volver al menu principal." << "\n\n";

        opcion = validarInput(opcion);

        if (opcion == 1)
        {
            system("cls");

            int DNI;
            char nombre[30];
            char apellido[30];
            Fecha fechaNacimiento;
            int telefono;
            bool estado = true;
            char correo[50];
            char usuario[30];
            char contrasenia[30];
            Rol rol; // 0 es Auxiliar, 1 es Bibliotecario y 2 es SysAdmin.


            // DNI
            while (true)
            {
                std::cout << "DNI (8 digitos): ";

                if (!(std::cin >> DNI))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "DNI invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                if (validarDNI(DNI))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "DNI invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Nombre
            while (true)
            {
                std::cout << "Nombre: ";
                std::cin.getline(nombre, 30);

                if (validarCadena(nombre, 30))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Nombre invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Apellido
            while (true)
            {
                std::cout << "Apellido: ";
                std::cin.getline(apellido, 30);

                if (validarCadena(apellido, 30))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Apellido invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Fecha de nacimiento
            while (true)
            {
                int dia, mes, anio;

                std::cout << "Fecha de nacimiento:" << '\n';

                std::cout << "   Dia: ";
                if (!(std::cin >> dia) || dia < 1 || dia > 31)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");

                    std::cout << "Dia invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Mes: ";
                if (!(std::cin >> mes) || mes < 1 || mes > 12)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Mes invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Anio: ";
                if (!(std::cin >> anio) || anio < 1900 || anio > 2025)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");

                    std::cout << "Anio invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                fechaNacimiento.setFecha(dia, mes, anio);
                break;
            }

            // Telefono
            while (true)
            {
                std::cout << "Telefono (10 digitos): ";

                if (!(std::cin >> telefono))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");

                    std::cout << "Telefono invalido, pruebe de nuevo." << '\n';
                    system("pause");
                    system("cls");
                    continue;
                }

                if (validarTelefono(telefono))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Telefono invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Correo
            while (true)
            {
                std::cout << "Correo electronico: ";
                std::cin.getline(correo, 50);

                if (validarCorreo(correo))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Correo invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Usuario
            while (true)
            {
                std::cout << "Nombre de usuario (mayor o igual a 6): ";
                std::cin.getline(usuario, 30);

                if (strlen(usuario) >= 6)
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Usuario invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Contraseña
            while (true)
            {
                std::cout << "Contrasenia: ";
                std::cin.getline(contrasenia, 30);

                if (strlen(contrasenia) >= 6)
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Contrasenia invalida, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Rol
            while (true)
            {
                std::cout << "Rol (elija una de las categorias): " << '\n';
                std::cout << "   1. Auxiliar." << '\n';
                std::cout << "   2. Bibliotecario." << '\n';
                std::cout << "   3. SysAdmin." << '\n';

                int opcionRol;

                if (!(std::cin >> opcionRol) || opcionRol < 1 || opcionRol > 3)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Rol invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
                else
                {
                    rol = static_cast<Rol>(opcionRol - 1);
                    break;
                }
            }

            Admin admin(DNI, nombre, apellido, fechaNacimiento, telefono, estado, correo, usuario, contrasenia, rol);

            biblioteca.admins.agregarAdmin(admin);
        }
        else if (opcion == 2)
        {
            int adminID;

            while (true)
            {
                system("cls");

                std::cout << "Escriba el ID del usuario que quiera quitar: ";

                adminID = validarInput(adminID);

                if (adminID > 0)
                {
                    biblioteca.admins.quitarAdmin(adminID);

                    system("cls");
                    std::cout << "El usuario, si es que estaba en el registro, ha sido removido." << "\n\n";
                    system("pause");
                    system("cls");

                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "ID de usuario invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (opcion == 3)
        {
            system("cls");

            biblioteca.admins.listarAdmins();

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

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }
}

void menuSocios(Biblioteca& biblioteca)
{
    while (true)
    {
        system("cls");

        int opcion = 0;

        rlutil::setColor(rlutil::CYAN);
        std::cout << "--------SOCIOS--------" << "\n\n";
        rlutil::resetColor();

        std::cout << "Seleccione una opcion: " << "\n\n";

        std::cout << "1. Agregar socio." << '\n';
        std::cout << "2. Quitar socio." << '\n';
        std::cout << "3. Listar socios." << '\n';
        std::cout << "4. Volver al menu principal." << "\n\n";

        opcion = validarInput(opcion);

        if (opcion == 1)
        {
            system("cls");

            int DNI;
            char nombre[30];
            char apellido[30];
            Fecha fechaNacimiento;
            int telefono;
            bool estado = true;
            char correo[50];

            // DNI
            while (true)
            {
                std::cout << "DNI (8 digitos): ";

                if (!(std::cin >> DNI))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "DNI invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                if (validarDNI(DNI))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "DNI invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Nombre
            while (true)
            {
                std::cout << "Nombre: ";
                std::cin.getline(nombre, 30);

                if (validarCadena(nombre, 30))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Nombre invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Apellido
            while (true)
            {
                std::cout << "Apellido: ";
                std::cin.getline(apellido, 30);

                if (validarCadena(apellido, 30))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Apellido invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            // Fecha de nacimiento
            while (true)
            {
                int dia, mes, anio;

                std::cout << "Fecha de nacimiento:" << '\n';

                std::cout << "   Dia: ";
                if (!(std::cin >> dia) || dia < 1 || dia > 31)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Dia invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Mes: ";
                if (!(std::cin >> mes) || mes < 1 || mes > 12)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Mes invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                std::cout << "   Anio: ";
                if (!(std::cin >> anio) || anio < 1900 || anio > 2025)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    system("cls");
                    std::cout << "Anio invalido." << "\n\n";
                    system("pause");
                    system("cls");
                    continue;
                }

                fechaNacimiento.setFecha(dia, mes, anio);
                break;
            }

            // Telefono
            while (true)
            {
                std::cout << "Telefono (10 digitos): ";

                if (!(std::cin >> telefono))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Telefono invalido, pruebe de nuevo." << '\n';
                    system("pause");
                    system("cls");
                    continue;
                }

                if (validarTelefono(telefono))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Telefono invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Correo
            while (true)
            {
                std::cout << "Correo electronico: ";
                std::cin.getline(correo, 50);

                if (validarCorreo(correo))
                {
                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "Correo invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }

            Socio socio(DNI, nombre, apellido, fechaNacimiento, telefono, estado, correo);

            biblioteca.socios.agregarSocio(socio);
        }
        else if (opcion == 2)
        {
            int socioID;

            while (true)
            {
                system("cls");

                std::cout << "Escriba el ID del socio que quiera quitar: ";

                socioID = validarInput(socioID);

                if (socioID > 0)
                {
                    biblioteca.socios.quitarSocio(socioID);

                    system("cls");
                    std::cout << "El socio, si es que estaba en el registro, ha sido removido." << "\n\n";
                    system("pause");
                    system("cls");

                    break;
                }
                else
                {
                    system("cls");
                    std::cout << "ID de socio invalido, pruebe de nuevo." << "\n\n";
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (opcion == 3)
        {
            system("cls");

            biblioteca.socios.listarSocios();

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

            std::cout << "Opcion invalida. Por favor ingrese solo el numero de su opcion." << "\n\n";

            system("pause");
            system("cls");
        }
    }
}

int validarInput(int input)
{
    if (!(std::cin >> input))
    {
        std::cin.clear(); // Limpia el estado de input stream.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Resetea el input stream.
    }

    return input;
}
