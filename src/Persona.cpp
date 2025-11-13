#include "Persona.h"
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>

bool validarDNI(int DNI)
{
    int digitos = 0;

    int temp = std::abs(DNI);
    while (temp > 0)
    {
        // Dividir por 10 sirve par contar dígitos porque cuenta las posiciones hasta llegar a 0.
        temp /= 10;
        digitos++;
    }
    return digitos == 8;
}

bool validarTelefono(int telefono)
{
    int digitos = 0;
    int temp = std::abs(telefono);
    while (temp > 0)
    {
        temp /= 10;
        digitos++;
    }
    return digitos == 10;
}

bool validarCadena(const char* cadena, size_t tamanio)
{
    if (cadena == nullptr || cadena[0] == '\0')
    {
        return false;
    }
    if (strlen(cadena) >= tamanio)
    {
        return false;
    }
    return true;
}

bool validarCorreo(const char* correo)
{
    if (correo == nullptr)
    {
        return false;
    }

    const char* arroba = strchr(correo, '@');
    const char* punto = strrchr(correo, '.');

    if (!arroba || !punto)
    {
        return false;
    }
    if (arroba >= punto)
    {
        return false;
    }
    if (strlen(correo) >= 50)
    {
        return false;
    }
    return true;
}

Persona::Persona()
    : _DNI{},
      _fechaNacimiento{},
      _telefono{},
      _estado{true}
{
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _correo[0] = '\0';
}

Persona::Persona(int DNI,
                 const char* nombre,
                 const char* apellido,
                 Fecha& fechaNacimiento,
                 int telefono,
                 bool estado,
                 const char* correo)
    : _fechaNacimiento{fechaNacimiento},
      _estado{estado}
{
    setDni(DNI);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setCorreo(correo);
}

void Persona::setDni(int DNI)
{
    if (validarDNI(DNI)) _DNI = DNI;
}

void Persona::setNombre(const char* nombre)
{
    if (validarCadena(nombre, sizeof(_nombre))) strncpy(_nombre, nombre, sizeof(_nombre) - 1), _nombre[sizeof(_nombre) - 1] = '\0';
}

void Persona::setApellido(const char* apellido)
{
    if (validarCadena(apellido, sizeof(_apellido))) strncpy(_apellido, apellido, sizeof(_apellido) - 1), _apellido[sizeof(_apellido) - 1] = '\0';
}

void Persona::setFechaNacimiento(int dia, int mes, int anio)
{
    Fecha fecha;
    fecha.setFecha(dia, mes, anio);
    _fechaNacimiento = fecha;
}

void Persona::setTelefono(int telefono)
{
    _telefono = telefono;
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}

void Persona::setCorreo(const char* correo)
{
    if (validarCorreo(correo)) strncpy(_correo, correo, sizeof(_correo) - 1), _correo[sizeof(_correo) - 1] = '\0';
}



