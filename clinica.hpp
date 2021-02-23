#ifndef clinica_hpp
#define clinica_hpp

//#ifdef _WIN32
//#include <winuser.h>
//#endif

//#ifdef linux
//#include <linux/input.h>
//#endif

#include <termios.h>
#include <stdio.h>
#include "arquivos.hpp"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>

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

        void setMascara(char*);
};

#endif