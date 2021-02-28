#ifndef usuario_hpp
#define usuario_hpp

#include <iostream>
#include <stdlib.h>

using namespace std; 

class Usuario{
    private:
        string usuario;
        string senha;
        char tipo;

    public:
        Usuario();

        Usuario(const string&, const string&, const char&);

        ~Usuario();

        void setUsuario(string);

        void setSenha(string);

        void setTipo(char);

        string getUsuario();

        string getSenha();

        char getTipo();

        friend ostream& operator<<(ostream&, const Usuario&);

        friend istream& operator>>(istream&, Usuario&);

};

#endif