#include "Persona.h"

bool validarDni(int DNI)
{
    int digitos = std::to_string(std::abs(DNI)).size();

    if (digitos != 8)
    {
        return false;
    }

    return true;
}

bool validarTelefono(int telefono)
{
    int digitos = std::to_string(std::abs(telefono)).size();

    if (digitos != 10)
    {
        return false;
    }

    return true;
}

bool validarCadena(std::string& cadena, size_t tamanio)
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

bool validarCorreo(std::string& correo)
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

Persona::Persona()
    : _DNI{ 0 }, _nombre{ "" }, _apellido{ "" }, _fechaNacimiento{}, _telefono{ 0 }, _estado{ false }, _correo{ "" }
{}

Persona::Persona(int DNI, std::string& nombre, std::string& apellido, Fecha& fechaNacimiento, int telefono, bool estado, std::string& correo)
    : _fechaNacimiento{ fechaNacimiento }, _estado{ estado }
{
    setDni(DNI);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setCorreo(correo);
}

void Persona::setDni(int DNI)
{
    if (validarDni(DNI))
    {
        _DNI = DNI;
    }
}

void Persona::setNombre(std::string& nombre)
{
    if (validarCadena(nombre, 30))
    {
        _nombre = nombre;
    }
}

void Persona::setApellido(std::string& apellido)
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

void Persona::setTelefono(int telefono)
{
    if (validarTelefono(telefono))
    {
        _telefono = telefono;
    }
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}

void Persona::setCorreo(std::string& correo)
{
    if (validarCorreo(correo))
    {
        _correo = correo;
    }
}


