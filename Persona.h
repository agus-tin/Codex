#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "Fecha.h"

class Persona
{
private:
    std::string _DNI;
    std::string _nombre;
    std::string _apellido;
    Fecha _fechaNacimiento;
    bool _estado;
    std::string _correo;

public:
    Persona(const std::string& DNI,
            const std::string& nombre,
            const std::string& apellido,
            const Fecha& fechaNacimiento,
            bool estado,
            const std::string& correo);

    std::string getDNI() const { return _DNI; }
    std::string getNombre() const { return _nombre; }
    std::string getApellido() const { return _apellido; }
    Fecha getFechaNacimiento() const { return _fechaNacimiento; }
    bool getEstado() const { return _estado; }
    std::string getCorreo() const { return _correo; }

    void setDni(const std::string& DNI);
    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setEstado(bool estado);
    void setCorreo(const std::string& correo);
};

#endif // PERSONA_H
