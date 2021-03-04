#ifndef arquivos_hpp
#define arquivos_hpp

#include <fstream>
#include <vector>
#include <experimental/filesystem> 
#include <iterator>
#include <string.h>

#include "usuario.hpp"
#include "especialista.hpp"

namespace fs = std::experimental::filesystem::v1;

void existe(string nome){
    if(!fs::exists(nome.c_str()))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        EXIT_FAILURE;
    }  
}

template <typename Objeto>
void setObjetos(string nome, vector<Objeto>& objetos){
    ifstream in (nome.c_str());
    Objeto temporario;
    while(!in.eof()){
        in >> temporario;
        objetos.push_back(temporario);
    }
    in.close();
}

template <typename Objeto>
void registra(const Objeto& objeto, string nome){
    existe(nome);
    ofstream out (nome.c_str(), ios::app);
    out << objeto;
    out.flush();
    out.close();
}

template <typename Objeto>
int verifica(Objeto& objeto, string nome, char tipo){
    existe(nome);
    vector<Objeto> objetos;
    if (typeid(objeto).name() == typeid(Usuario).name() ){
        setObjetos<Usuario>(nome, objetos);
        for (Usuario x : objetos){
            switch (tipo)
            {
               case 'L': 
                    if (x.getUsuario() == objeto.getUsuario() && x.getSenha() == objeto.getSenha()){
                        objeto = x;
                    return 1;
                    }
                break;

                case 'C':
                    if (x.getUsuario() == objeto.getUsuario()){
                        return 1;
                    }
                break;
            }  
        }
    }
    return 0;
}

template <typename Objeto>
int verifica(Objeto objeto, const string& nome){
    existe(nome);
    vector<Objeto> objetos;
    if (typeid(objeto).name() == typeid(Funcionario).name() ){
        setObjetos<Funcionario>(nome, objetos);
        for (Objeto x : objetos){
            if (strcmp(x.getCPF(), objeto.getCPF()) == 0){
                return 0;
            }
        }
    }
    return 1;
}

void limpa(string nome){
    remove(nome.c_str());
    ofstream recria (nome.c_str(), ios::app);
    recria.close();
}

template <typename Objeto>
int remove(Objeto& objeto, string nome){
    existe(nome);
    if (typeid(objeto).name() == typeid(Usuario).name() ){
        vector<Objeto> objetos;
        typename vector<Objeto>::iterator it;
        setObjetos<Usuario>(nome, objetos);
        for (it = objetos.begin(); it != objetos.end(); ++it){
            if (it->getUsuario() == objeto.getUsuario()){
                objetos.erase(it);
                objetos.pop_back();
                limpa(nome);
                for (Objeto x : objetos){
                    registra<Usuario>(x, nome);
                }
                return 1;
            }        
        }
    }
    return 0;
}


template <typename Objeto>
void printObject(string nome){
    existe(nome);
    if (typeid(Objeto).name() == typeid(Usuario).name() ){
        cout << endl;
        printf("|%5s|%14s|", "NOME ", "TIPO DE CONTA ");
        cout << endl;
    }
    ifstream in (nome.c_str());
    Objeto x;
    while(in >> x){
        if (typeid(Objeto).name() == typeid(Usuario).name() ){
            string tipo;
            switch (x.getTipo())
            {
                case 'A':
                    tipo = "Administrador";
                break;

                case 'B':
                    tipo = "Assistente";
                break;

                case 'G':
                    tipo = "Geral";
                break;
            }
            printf("|%5s|%14s|", x.getUsuario().c_str(), tipo.c_str());
            cout << endl;
        }
    }
    in.close();
}

#endif
