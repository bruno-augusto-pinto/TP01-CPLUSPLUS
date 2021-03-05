#ifndef chave_hpp
#define chave_hpp

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std; 

class Chave{
    private:
        string chave;

    public:
        Chave();

        virtual ~Chave();

        void setChave(const string&);

        string getChave();

        friend ostream& operator<<(ostream&, const Chave&);

        friend istream& operator>>(istream&, Chave&);
};

#endif