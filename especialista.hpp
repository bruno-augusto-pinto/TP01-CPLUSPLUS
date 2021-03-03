#ifndef especialista_hpp
#define especialista_hpp

#include "funcionario.hpp"
#include "agenda.hpp"

using namespace std; 

class Especialista: public Funcionario{
    private:
        Funcionario funcionario;
        

    public:
        Especialista();

        Especialista(Funcionario, const char);

        virtual ~Especialista();

        void setTipo(const char&);

        char getTipo();

        friend ostream& operator<<(ostream&, const Especialista&);

        friend istream& operator>>(istream&, Especialista&);
};

#endif