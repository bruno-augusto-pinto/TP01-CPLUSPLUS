#include "usuarios.hpp"

        Usuario::Usuario(){}

        Usuario::Usuario(const string& usuario, const string& senha, const char& tipo):
        usuario(usuario), senha(senha), tipo(tipo){}

        Usuario::~Usuario(){}

        void Usuario::setUsuario(const string usuario){
            this->usuario = usuario;
        }

        void Usuario::setSenha(const string senha){
            this->senha = senha;
        }

        void Usuario::setTipo(const char tipo){
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

        ostream& operator <<(ostream& out, const Usuario& user){
            out << user.usuario << "\n" << user.senha << "\n" << user.tipo << endl;
            return out;
        }

        istream& operator >>(istream& in, Usuario& user){
            in >> user.usuario; 
            in >> user.senha; 
            in >> user.tipo;
            return in;
        }