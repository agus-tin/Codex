#include "Persona.h"
#include <cctype> // Para funciones que trabajan con caracteres individuales.

bool validarDni(const std::string& DNI)
{
    if (DNI.size() != 8)
    {
        return false;
    }

    for (char c : DNI)
    {
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    return true;
}

bool validarCadena(const std::string& cadena, size_t tamanio)
{
    if (cadena.empty())
    {
        return false;
    }

    if (cadena.size() >= tamanio)
    {
        return false;
    }

    return true;
}

bool validarCorreo(const std::string& correo)
{
    size_t arroba = correo.find('@'); // Busca la primera aparición de '@'.
    size_t punto = correo.rfind('.'); // Busca la última aparición de '.'.

    if (arroba == std::string::npos) // npos ("no position") es como un null para size_t. Es el valor max de size_t.
    {
        return false;
    }

    if (punto == std::string::npos)
    {
        return false;
    }

    if (arroba >= punto)
    {
        return false;
    }

    if (correo.size() >= 50)
    {
        return false;
    }

    return true;
}

Persona::Persona(const std::string& DNI,
                 const std::string& nombre,
                 const std::string& apellido,
                 const Fecha& fechaNacimiento,
                 bool estado,
                 const std::string& correo)
{
    setDni(DNI);
    setNombre(nombre);
    setApellido(apellido);
    _fechaNacimiento = fechaNacimiento;
    _estado = estado;
    setCorreo(correo);
}

void Persona::setDni(const std::string& DNI)
{
    if (validarDni(DNI))
    {
        _DNI = DNI;
    }
}

void Persona::setNombre(const std::string& nombre)
{
    if (validarCadena(nombre, 30))
    {
        _nombre = nombre;
    }
}

void Persona::setApellido(const std::string& apellido)
{
    if (validarCadena(apellido, 30))
    {
        _apellido = apellido;
    }
}

void Persona::setFechaNacimiento(int dia, int mes, int anio)
{
    Fecha fecha;

    fecha.setFecha(dia, mes, anio);

    _fechaNacimiento = fecha;
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}

void Persona::setCorreo(const std::string& correo)
{
    if (validarCorreo(correo))
    {
        _correo = correo;
    }
}


