#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"
#include <cstring>

class Persona
{
private:
    int _DNI;
    char _nombre[30];
    char _apellido[30];
    Fecha _fechaNacimiento;
    int _telefono;
    bool _estado;
    char _correo[50];

public:
    Persona();
    Persona(int DNI, const char* nombre, const char* apellido, Fecha& fechaNacimiento, int telefono, bool estado, const char* correo);

    int getDNI() const { return _DNI; }
    const char* getNombre() const { return _nombre; }
    const char* getApellido() const { return _apellido; }
    Fecha getFechaNacimiento() const { return _fechaNacimiento; }
    int getTelefono() const { return _telefono; }
    bool getEstado() const { return _estado; }
    const char* getCorreo() const { return _correo; }

    void setDni(int DNI);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setTelefono(int telefono);
    void setEstado(bool estado);
    void setCorreo(const char* correo);
};

bool validarDNI(int DNI);
bool validarTelefono(int telefono);
bool validarCadena(const char* cadena, size_t tamanio);
bool validarCorreo(const char* correo);

#endif

