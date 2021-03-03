#ifndef especialista_hpp
#define especialista_hpp

#include "funcionario.hpp"
//#include "agenda.hpp"
#include "assistente.hpp"

using namespace std; 

class Especialista: public Funcionario{
    private:
        Funcionario funcionario;
        //Agenda agenda;
        
    public:
        Especialista();

        explicit Especialista(const Funcionario&);

        virtual ~Especialista();

        //void setAgenda(const Agenda&);

        //Agenda getAgenda();

        friend ostream& operator<<(ostream&, const Especialista&);

        friend istream& operator>>(istream&, Especialista&);
};

#endif