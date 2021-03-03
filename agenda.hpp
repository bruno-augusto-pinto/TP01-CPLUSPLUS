#ifndef agenda_hpp
#define agenda_hpp

#include <iostream>
#include <stdlib.h>

#include "data.hpp"

using namespace std; 

class Agenda{
    private:
      Data data;
      string horario[5];
      int codigo[5];
      bool disponibilidade[5];
      string paciente[5];
      string funcionario;

    public:
        Agenda(const int&, const int&, const int&);

        ~Agenda();

        void setData(const Data&);

        void setDisponibilidade(const bool&, const int&);

        void setPaciente(const string&, const int&);

        void setFuncionario(const string&);

        bool getDisponibilidade(const int&);

        friend ostream& operator <<(ostream&, const Agenda&);

        friend istream& operator >>(istream&, Agenda&);
};

#endif