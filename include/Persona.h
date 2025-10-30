#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "Fecha.h"

class Persona
{
private:
    int _DNI;
    std::string _nombre;
    std::string _apellido;
    Fecha _fechaNacimiento;
    int _telefono;
    bool _estado;
    std::string _correo;

public:
    Persona(); // constructor default.
    Persona(int DNI, std::string& nombre, std::string& apellido, Fecha& fechaNacimiento, int telefono, bool estado, std::string& correo);

    int getDNI() const { return _DNI; }
    std::string getNombre() const { return _nombre; }
    std::string getApellido() const { return _apellido; }
    Fecha getFechaNacimiento() const { return _fechaNacimiento; }
    int getTelefono() const { return _telefono; }
    bool getEstado() const { return _estado; }
    std::string getCorreo() const { return _correo; }

    void setDni(int DNI);
    void setNombre(std::string& nombre);
    void setApellido(std::string& apellido);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setTelefono(int telefono);
    void setEstado(bool estado);
    void setCorreo(std::string& correo);
};

#endif // PERSONA_H
