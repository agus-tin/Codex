#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Persona.h"

class Socio : public Persona
{
private:
    int _socioID;
    float _cuota;
    bool _impago{ false };

    static int socioID;

public:
    Socio(); // constructor default.
    Socio(float cuota);

    int getSocioID() const { return _socioID; }
    float getCuota() const { return _cuota; }
    bool getImpago() const { return _impago; }

    void setCuota(float cuota);
    void setImpago(bool impago);

    friend std::ostream& operator<<(std::ostream& os, const Socio& socio);
};

#endif // SOCIO_H_INCLUDED
