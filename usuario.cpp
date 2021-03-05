#include "usuario.hpp"

        Usuario::Usuario(){}

        Usuario::Usuario(const char usuario[12], const char senha[12], const char& tipo):
        usuario((char*)usuario), senha((char*)senha), tipo(tipo){}

        Usuario::~Usuario(){}

        void Usuario::setUsuario(const char usuario[12]){
            this->usuario = (char*)usuario;
        }

        void Usuario::setSenha(const char senha[12]){
            this->senha = (char*)senha;
        }

        void Usuario::setTipo(const char tipo){
            this->tipo = tipo;
        }

        char* Usuario::getUsuario(){
            return this->usuario;
        }

        char* Usuario::getSenha(){
            return this->senha;
        }

        char Usuario::getTipo(){
            return this->tipo;
        }

        void Usuario::setChave(char* chave){
            this->chave.setChave( chave );
        }

        void Usuario::setChave(){
            //char* chave{ new char[strlen(usuario) + strlen(senha) + 1] };
            //chave = strcpy(chave, usuario);
            //chave = strcat(chave, senha);
            this->chave.setChave( usuario );
        }

        char* Usuario::getChave(){
            return this->chave.getChave();
        }

        ostream& operator <<(ostream& out, const Usuario& user){
            out << user.chave << "\n" << user.usuario << "\n" << user.senha << "\n" << user.tipo << endl;
            return out;
        }

        istream& operator >>(istream& in, Usuario& user){
            in >> user.chave;
            in >> user.usuario; 
            in >> user.senha; 
            in >> user.tipo;
            return in;
        }