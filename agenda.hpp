#ifndef agenda_hpp
#define agenda_hpp

#include <iostream>
#include <stdlib.h>

#include "data.hpp"
#include "chave.hpp"

using namespace std; 

class Agenda: public Chave{
    private:
      Data data;
      string horario[5];
      int codigo[5];
      bool disponibilidade[5];
      string paciente[5];
      string usuario[5];
      string funcionario;
      Chave chave;

    public:
        Agenda();

        Agenda(const int&, const int&, const int&);

        ~Agenda();

        void setData(const Data&);

        Data getData();

        void setDisponibilidade(const bool&, const int&);

        void setPaciente(const string&, const int&);

        string getPaciente(const int&);

        void setFuncionario(const string&);

        bool getDisponibilidade(const int&);

        string getHorario(const int&);

        void setChave();

        string getChave();

        void setUsuario(const string&, const int&);

        string getUsuario(const int&);

        void imprimeAgenda();

        friend ostream& operator <<(ostream&, const Agenda&);

        friend istream& operator >>(istream&, Agenda&);
};

#endif