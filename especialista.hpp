#ifndef especialista_hpp
#define especialista_hpp

#include "funcionario.hpp"
#include "assistente.hpp"
#include "agenda.hpp"

using namespace std; 

class Especialista: public Funcionario{
    private:
        Funcionario funcionario;
        Agenda agenda;
        Chave CDOMD; //Código Deontológico da OMD
        
    public:
        Especialista();

        Especialista(const string&, const string&, const char);

        virtual ~Especialista();

        void setNome(const string&);

        void setCPF(const string&);

        string getNome();

        string getCPF();

        void setTipo(const char&);

        char getTipo();

        void setAgenda(const Agenda&);

        Agenda getAgenda();

        friend ostream& operator<<(ostream&, const Especialista&);

        friend istream& operator>>(istream&, Especialista&);
};

#endif