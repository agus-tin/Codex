#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "Persona.h"

class Admin : public Persona
{
  private:
    int _adminID;
    std::string _usuario;
    std::string _contrasenia;
    std::string _rol;
    
  public:
    int getadminID() const {return _adminID;}
    std::string getusuario() const {return _usuario;}
    std::string getcontrasenia() const {return _contrasenia;}
    std::string getrol() const {return _rol;}
    
    void setadminID(int adminID);
    void setusuario( std::string usuario);
    void setcontrasenia(std::string contrasenia);
    void setrol(std::string& rol);
    
    }
    
#endif // ADMIN_H
