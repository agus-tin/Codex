#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Persona.h"

class Socio : public Persona
{
private:
    int _socioID;

    static int socioID;

public:
    Socio();
    Socio(int DNI, const char* nombre, const char* apellido, Fecha& fechaNacimiento, int telefono, bool estado, const char* correo);

    int getSocioID() const { return _socioID; }

    static int getID() { return socioID; }
    static void setID(int ID) { socioID = ID; }

    friend std::ostream& operator<<(std::ostream& os, const Socio& socio);
};

#endif // SOCIO_H_INCLUDED
