#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int dia=0, int mes=0, int anio=0);

    void cargar();
    void cargarMesAnio();
    void mostrar();
    void mostrarMesAnio();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setFecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

};

#endif // CLSFECHA_H_INCLUDED

