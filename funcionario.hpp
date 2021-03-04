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

        Funcionario(const char*, const char*, const char);

        virtual ~Funcionario();

        void setNome(const char*);

        void setCPF(const char*);

        string getNome();

        char* getCPF();

        void setTipo(const char&);

        char getTipo();

        friend ostream& operator<<(ostream&, const Funcionario&);

        friend istream& operator>>(istream&, Funcionario&);
};

#endif