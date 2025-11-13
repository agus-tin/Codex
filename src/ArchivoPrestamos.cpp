#include "ArchivoPrestamos.h"

ArchivoPrestamos::ArchivoPrestamos()
{
    cargar();
}

ArchivoPrestamos::~ArchivoPrestamos()
{
    guardar();
}

void ArchivoPrestamos::agregarPrestamo(Prestamo& prestamo)
{
    prestamos.push_back(prestamo);
}

void ArchivoPrestamos::quitarPrestamo(int prestamoID)
{
    for (auto i = prestamos.begin(); i != prestamos.end(); ++i)
    {
        if (i->getPrestamoID() == prestamoID)
        {
            prestamos.erase(i);
            return;
        }
    }
}
void ArchivoPrestamos::listarPrestamos()
{
    rlutil::saveDefaultColor();

    rlutil::setColor(rlutil::LIGHTBLUE);
    std::cout << "---- LISTADO DE PRESTAMOS ----" << "\n\n";
    rlutil::resetColor();

    if (prestamos.empty())
    {
        std::cout << "No hay prestamos registrados." << "\n\n";
        return;
    }

    for (const auto& prestamo : prestamos)
    {
        std::cout << prestamo << '\n';
    }
}

void ArchivoPrestamos::cambiarFechaDevolucion(int prestamoID, Fecha fechaDevolucion)
{
    for (auto& prestamo : prestamos)
    {
        if (prestamo.getPrestamoID() == prestamoID)
        {
            prestamo.setFechaDevolucion(fechaDevolucion);
        }
    }
}

void ArchivoPrestamos::cargar()
{
    prestamos.clear();
    std::ifstream archivo("data/prestamos.dat", std::ios::binary);

    if (!archivo.is_open())
    {
        return;
    }

    int ID;
    archivo.read(reinterpret_cast<char*>(&ID), sizeof(int));
    Prestamo::setID(ID);

    Prestamo prestamo;
    while (archivo.read(reinterpret_cast<char*>(&prestamo), sizeof(Prestamo)))
    {
        prestamos.push_back(prestamo);
    }
    archivo.close();
}

void ArchivoPrestamos::guardar()
{
    _mkdir("data");

    std::ofstream archivo("data/prestamos.dat", std::ios::binary | std::ios::trunc);

    if (!archivo.is_open())
    {
        return;
    }

    int ID = Prestamo::getID();
    archivo.write(reinterpret_cast<const char*>(&ID), sizeof(int));

    for (auto& prestamo : prestamos)
    {
        archivo.write(reinterpret_cast<const char*>(&prestamo), sizeof(Prestamo));
    }
    archivo.close();
}
