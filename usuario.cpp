#include "usuario.hpp"

        Usuario::Usuario(){}

        Usuario::Usuario(const string& usuario, const string& senha, const char& tipo):usuario(usuario), senha(senha), tipo(tipo){}

        Usuario::~Usuario(){}

        void Usuario::setUsuario(const string& usuario){
            this->usuario = usuario;
        }

        void Usuario::setSenha(const string& senha){
            this->senha = senha;
        }

        void Usuario::setTipo(const char& tipo){
            this->tipo = tipo;
        }

        string Usuario::getUsuario(){
            return this->usuario;
        }

        string Usuario::getSenha(){
            return this->senha;
        }

        char Usuario::getTipo(){
            return this->tipo;
        }

        void Usuario::setChave(const string& chave){
            this->chave.setChave( chave );
        }

        void Usuario::setChave(){
            this->chave.setChave( usuario );
        }

        string Usuario::getChave(){
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