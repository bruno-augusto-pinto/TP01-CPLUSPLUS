#ifndef usuario_hpp
#define usuario_hpp

#include "chave.hpp"

using namespace std; 

class Usuario: public Chave{
    private:
        string usuario;
        string senha;
        char tipo;
        Chave chave;

    public:
        Usuario();

        Usuario(const string&, const string&, const char&);

        ~Usuario();

        void setUsuario(const string&);

        void setSenha(const string&);

        void setTipo(const char&);

        string getUsuario();

        string getSenha();

        char getTipo();

        void setChave(const string&);

        void setChave();

        string getChave();

        friend ostream& operator<<(ostream&, const Usuario&);

        friend istream& operator>>(istream&, Usuario&);

};

#endif