#ifndef clinica_hpp
#define clinica_hpp

#include <stdio.h>
#include <string.h>
#include "arquivos.hpp"

using namespace std;

class Clinica {

    public:

        Clinica();

        ~Clinica();

        int main(void);

        void menuPrincipal();

        //https://cplusplus.com/articles/E6vU7k9E/
        void login();

        void cadastro();

        //string setMascara(const char*);
};
#endif