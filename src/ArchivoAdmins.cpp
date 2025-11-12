#include "ArchivoAdmins.h"

bool ArchivoAdmins::validarPrivilegios(const char* usuario)
{
    for (auto& admin : admins)
    {
        if (std::strcmp(admin.getUsuario(), usuario) == 0 && admin.getRol() == Rol::SysAdmin)
        {
            return true;
        }
    }
}

ArchivoAdmins::ArchivoAdmins()
{
    cargar();
}

ArchivoAdmins::~ArchivoAdmins()
{
    guardar();
}

bool ArchivoAdmins::validarUsuario(const char* usuario, const char* contrasenia)
{
    for (auto& admin : admins)
    {
        if (std::strcmp(admin.getUsuario(), usuario) == 0 && // strcmp() compara C-strings y retorna 0 si son iguales
            std::strcmp(admin.getContrasenia(), contrasenia) == 0 &&
            admin.getEstado())
        {
            return true;
        }
    }
    return false;
}

void ArchivoAdmins::agregarAdmin(Admin& admin)
{
    admins.push_back(admin);
}

void ArchivoAdmins::quitarAdmin(int adminID)
{
    for (auto i = admins.begin(); i != admins.end(); ++i)
    {
        if (i->getAdminID() == adminID)
        {
            admins.erase(i);
            return;
        }
    }
}

void ArchivoAdmins::listarAdmins()
{
    std::cout << "--- LISTADO DE USUARIOS ---" << "\n\n";

    if (admins.empty())
    {
        std::cout << "No hay usuarios registrados." << "\n\n";
        return;
    }

    for (auto& admin : admins)
    {
        std::cout << admin << '\n';
    }
}

// cargar() es una función que usamos en el constructor en las clases archivo dentro
// de Biblioteca (que a su vez se crea al principio del programa, vean línea 20 de main).
// Su propósito es cargar los datos en los archivos ".dat" a los vectores dinámicos.
// De esta forma al inicializar el programa, se crean los registros y tenemos cargados los datos.

void ArchivoAdmins::cargar()
{
    // clear() es una precaución, limpia al vector dinámico.
    admins.clear();
    // Esto abre el stream para lectura en binario para el archivo "admins.dat".
    std::ifstream archivo("data/admins.dat", std::ios::binary);

    // Otra precaución, si el archivo no puede abrirse, para la función.
    if (!archivo.is_open())
    {
        return;
    }

    int ID;
    archivo.read(reinterpret_cast<char*>(&ID), sizeof(int));
    Admin::setID(ID);

    Admin admin;

    // Es el loop que carga data al vector mientras pueda leer data válida en el archivo.
    // Toma a la dirección de memoria del objeto "admin" mediante "&" y reinterpreta la dirección como un puntero
    // a una secuencia de bytes. Funciones como "archivo.read" o "archivo.write" tienen que trabajar con bytes.
    // sizeof(Admin) simplemente especifica el tamaño de un objeto Admin.
    while (archivo.read(reinterpret_cast<char*>(&admin), sizeof(Admin)))
    {
        admins.push_back(admin);
    }

    archivo.close();
}

// guardar() es una función que usamos al destruir las clases archivo. Cuando el programa se termina
// mediante el "return 0" en main, los destructores son llamados y la data es guardada en los archivos ".dat".

void ArchivoAdmins::guardar()
{
    // Esto crea una carpeta "data" si no existe o la abre si existe.
    _mkdir("data");

    // Esto abre el stream para escritura en binario para el archivo "admins.dat".
    // std::ios::trunc es clave acá porque si ya existe el archivo, lo borra, y si no existe lo crea.
    std::ofstream archivo("data/admins.dat", std::ios::binary | std::ios::trunc);

    if (!archivo.is_open())
    {
        return;
    }

    int ID = Admin::getID();
    archivo.write(reinterpret_cast<const char*>(&ID), sizeof(int));

    // Es el loop que pasa por todos los elementos cargados en el vector dinámico y los escribe en bytes.
    for (auto& admin : admins)
    {
        archivo.write(reinterpret_cast<const char*>(&admin), sizeof(Admin));
    }

    archivo.close();
}
