#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <stdlib.h>

using namespace std; 

class Pessoa{
    private:
        char* nome = new char(12);
        char* CPF = new char(10);

    public:
        Pessoa();

        Pessoa(const char[12], const char[10]);

        virtual ~Pessoa();

        void setNome(const char*);

        void setCPF(const char*);

        string getNome();

        char* getCPF();

        friend ostream& operator<<(ostream&, const Pessoa&);

        friend istream& operator>>(istream&, Pessoa&);
};

#endif