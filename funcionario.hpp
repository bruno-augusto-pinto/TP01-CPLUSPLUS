#ifndef funcionario_hpp
#define funcionario_hpp

#include "pessoa.hpp"

using namespace std; 

class Funcionario: public Pessoa{
    private:
        Pessoa pessoa;
        char tipo;

    public:
        Funcionario();

        explicit Funcionario(const Pessoa& pessoa, const char);

        virtual ~Funcionario();

        void setTipo(const char&);

        char getTipo();

        friend ostream& operator<<(ostream&, const Funcionario&);

        friend istream& operator>>(istream&, Funcionario&);
};

#endif