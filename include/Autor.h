#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

#include <iostream>
#include <string>

class Autor
{
private:
    int _autorID;
    std::string _nombre;
    std::string _apellido;

    static int autorID;

public:
    Autor();
    Autor(std::string nombre, std::string apellido);

    int getAutorID() const { return _autorID; }
    std::string getNombre() const { return _nombre; }
    std::string getApellido() const { return _apellido; }

    friend std::ostream& operator<<(std::ostream& os, const Autor& autor);
};

#endif // AUTOR_H_INCLUDED
