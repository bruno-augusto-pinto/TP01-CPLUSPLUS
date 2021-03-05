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

        Funcionario(const string&, const string&, const char);

        virtual ~Funcionario();

        void setNome(const string&);

        void setCPF(const string&);

        void setTipo(const char&);

        void setChave(const string&);

        void setChave();
        
        string getNome();

        string getCPF();

        string getChave();
        
        char getTipo();

        friend ostream& operator<<(ostream&, const Funcionario&);

        friend istream& operator>>(istream&, Funcionario&);
};

#endif