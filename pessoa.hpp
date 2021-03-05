#ifndef pessoa_hpp
#define pessoa_hpp

//#include <iostream>
//#include <stdlib.h>
#include "chave.hpp"

using namespace std; 

class Pessoa: public Chave{
    private:
        string nome;
        string CPF;
        Chave chave;

    public:
        Pessoa();

        Pessoa(const string&, const string&);

        virtual ~Pessoa();

        void setNome(const string&);

        void setCPF(const string&);

        string getNome();

        string getCPF();

        void setChave(const string&);

        void setChave();

        string getChave();

        friend ostream& operator<<(ostream&, const Pessoa&);

        friend istream& operator>>(istream&, Pessoa&);
};

#endif