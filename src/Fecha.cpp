#include "Fecha.h"
#include <iostream>
#include <ctime>

using namespace std;

Fecha::Fecha(int dia, int mes, int anio) {
    if(dia != 0){
        _dia=dia;
        _mes=mes;
        _anio=anio;
    }
    else{
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        _anio=tmPtr->tm_year+1900;
        _mes=tmPtr->tm_mon+1;
        _dia=tmPtr->tm_mday;
    }
}

void Fecha::setDia(int dia){
    _dia=dia;
}

void Fecha::setMes(int mes){
    _mes=mes;
}

void Fecha::setAnio(int anio){
    _anio=anio;
}

void Fecha::setFecha(int dia, int mes, int anio) {
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

std::ostream& operator<<(std::ostream& os, const Fecha& fecha)
{
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();

    return os;
}
