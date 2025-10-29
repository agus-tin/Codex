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
    if(dia <= 31 && dia > 0) _dia=dia;
}

void Fecha::setMes(int mes){
    if(mes <= 12 && mes > 0) _mes=mes;
}

void Fecha::setAnio(int anio){
    if (anio > 1900) _anio=anio;
}

void Fecha::setFecha(int dia, int mes, int anio) {
    bool incorrecto = false;

    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int anioAct = tmPtr->tm_year + 1900;
    int mesAct = tmPtr->tm_mon + 1;
    int diaAct = tmPtr->tm_mday;

    if (anio < 1900 || anio > anioAct) {
        incorrecto = true;
    }
    else if (mes < 1 || mes > 12) {
        incorrecto = true;
    }
    else {
        int diasEnMes = 31;
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diasEnMes = 30;
        }
        else if (mes == 2) {
            bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
                if (esBisiesto) {
                    diasEnMes = 29;
                }  else {
                        diasEnMes = 28;
                    }
        }

        if (dia < 1 || dia > diasEnMes) {
            incorrecto = true;
        }
        else if (anio == anioAct) {
                if (mes > mesAct || (mes == mesAct && dia > diaAct)) {
                    incorrecto = true;
                }
            }
        }

    if (incorrecto) {
        cout << "La fecha es incorrecta. Intenta de nuevo." << '\n';

        int dia, mes, anio;

        cout<<"Ingrese el dia: ";
        cin>>dia;
        cout<<"Ingrese el mes: ";
        cin>>mes;
        cout<<"Ingrese el anio: ";
        cin>>anio;

        setFecha(dia, mes, anio);
    }
    else {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
}

std::ostream& operator<<(std::ostream& os, const Fecha& fecha)
{
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << '\n';

    return os;
}
