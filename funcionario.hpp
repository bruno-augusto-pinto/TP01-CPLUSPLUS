#ifndef funcionario_hpp
#define funcionario_hpp

#include <iostream>
#include <stdlib.h>

using namespace std; 

class Funcionario{
    private:
        string nome;
        char* CPF = new char(10);

    public:
        Funcionario();

        Funcionario(const string&, const char[10]);

        virtual ~Funcionario();

        void setNome(const string&);

        void setCPF(const char*);

        string getNome();

        char* getCPF();

        friend ostream& operator<<(ostream&, const Funcionario&);

        friend istream& operator>>(istream&, Funcionario&);
};

#endif