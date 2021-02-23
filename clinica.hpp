#ifndef clinica_hpp
#define clinica_hpp

#include <termios.h>
#include <stdio.h>
#include "arquivos.hpp"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

        int getch();

        string setMascara(const char*);
};
#endif