#ifndef chave_hpp
#define chave_hpp

#include <iostream>
#include <cstring>

using namespace std; 

class Chave{
    private:
        char* chave = new char;

    public:
        Chave();

        virtual ~Chave();

        void setChave(char*);

        char* getChave();

        friend ostream& operator<<(ostream&, const Chave&);

        friend istream& operator>>(istream&, Chave&);
};

#endif