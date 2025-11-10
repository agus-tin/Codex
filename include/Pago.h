#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED

#include "Fecha.h"
#include "Socio.h"

class Pago
{
private:
    Fecha _fechapago;
    Socio _socio;
    float _importe;
    bool _estado;

public:
    
    void setFechaPago(Fecha& f);
    void setImporte(float i);
    void setEstado(bool e);
    Fecha getFechaPago();
    float getImporte();
    bool getEstado();
    void guardar();
    void cargar();
};

#endif // PAGO_H_INCLUDED
