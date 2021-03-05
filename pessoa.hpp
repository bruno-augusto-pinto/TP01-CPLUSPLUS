#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <stdlib.h>
#include "chave.hpp"

using namespace std; 

class Pessoa: public Chave{
    private:
        char* nome = new char(12);
        char* CPF = new char(10);
        Chave chave;

    public:
        Pessoa();

        Pessoa(const char[12], const char[10]);

        virtual ~Pessoa();

        void setNome(const char*);

        void setCPF(const char*);

        string getNome();

        char* getCPF();

        void setChave(char*);

        void setChave();

        char* getChave();

        friend ostream& operator<<(ostream&, const Pessoa&);

        friend istream& operator>>(istream&, Pessoa&);
};

#endif