#ifndef agenda_hpp
#define agenda_hpp

#include <iostream>
#include <stdlib.h>

#include "usuario.hpp"

using namespace std; 

class Agenda{
    private:
      string horario[5];
      int codigo[5];
      bool disponibilidade[5];
      //Paciente paciente[5];
      //String paciente[5];
      Usuario usuario[5];
      //Funcionario funcionario;
      //Funcionario funcionario;

    public:

        Agenda();

        ~Agenda();

        void setDisponibilidade(const bool&, const int&);

        void setUsuario(const Usuario&, const int&);

        //void setPaciente(const Paciente&);

        //void setPaciente(const String&);

        bool getDisponibilidade(const int&);

        //friend ostream& operator<<(ostream&, const Agenda&);

        //friend istream& operator>>(istream&, Agenda&);
};

#endif