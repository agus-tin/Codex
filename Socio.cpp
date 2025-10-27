#include <iostream>
#include "Socio.h"

Socio::Socio(float cuota)
    : _cuota{ cuota }
{
    _socioID = siguienteID++;
}

int Socio::siguienteID = 1;

void Socio::setCuota(float cuota)
{
    _cuota = cuota;
}

void Socio::setImpago(bool impago)
{
    _impago = impago;
}

void Socio::cargar()
{


}

void Socio::mostrar()
{
    std::cout << "SocioID: " << _socioID << "  Cuota: " << _cuota << "  Impago: " << _impago << std::endl;

}
