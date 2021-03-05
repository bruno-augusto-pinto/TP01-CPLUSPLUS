#ifndef usuario_hpp
#define usuario_hpp

#include "chave.hpp"

using namespace std; 

class Usuario: public Chave{
    private:
        char* usuario = new char[12];
        char* senha = new char[12];
        char tipo;
        Chave chave;

    public:
        Usuario();

        Usuario(const char[12], const char[12], const char&);

        ~Usuario();

        void setUsuario(const char[12]);

        void setSenha(const char[12]);

        void setTipo(char);

        char* getUsuario();

        char* getSenha();

        char getTipo();

        void setChave(char*);

        void setChave();

        char* getChave();

        friend ostream& operator<<(ostream&, const Usuario&);

        friend istream& operator>>(istream&, Usuario&);

};

#endif