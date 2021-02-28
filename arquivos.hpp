//https://www.cplusplus.com/reference/fstream/fstream/
//https://docs.microsoft.com/pt-br/cpp/standard-library/filesystem?view=msvc-160

#ifndef arquivos_hpp
#define arquivos_hpp

#include <fstream>
#include <vector>
#include <experimental/filesystem> 
#include <iterator>

#include "usuario.hpp"

using namespace std;
 
using namespace std::experimental::filesystem::v1;

namespace fs = std::experimental::filesystem::v1;

template <typename Arquivo>
void existe(Arquivo nome){
    if(!fs::exists(nome.c_str()))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        EXIT_FAILURE;
    }  
}

template <typename Objeto, typename Arquivo>
void setObjeto(Arquivo nome, vector<Objeto>& objetos){
    ifstream in (nome.c_str());
    Objeto temporario;
    while(!in.eof()){
        in >> temporario;
        objetos.push_back(temporario);
    }
    in.close();
}

template <typename Objeto, typename Arquivo>
void registra(const Objeto& objeto, Arquivo nome){
    existe<string>(nome);
    ofstream out (nome.c_str(), ios::app);
    out << objeto;
    out.flush();
    out.close();
}

template <typename Objeto, typename Arquivo, typename Operacao>
int verifica(Objeto& objeto, Arquivo nome, Operacao tipo){
    existe<string>(nome);
    vector<Objeto> objetos;
    if (typeid(objeto).name() == typeid(Usuario).name() ){
        setObjeto<Usuario, string>(nome, objetos);
    }
    for (Objeto x : objetos){
        if (typeid(objeto).name() == typeid(Usuario).name() ){
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

template <typename Arquivo>
void limpa(Arquivo nome){
    remove(nome.c_str());
    ofstream recria (nome.c_str(), ios::app);
    recria.close();
}

template <typename Objeto, typename Arquivo>
int remove(Objeto& objeto, Arquivo nome){
    existe<string>(nome);
    vector<Objeto> objetos;
    typename vector<Objeto>::iterator it;
    if (typeid(objeto).name() == typeid(Usuario).name() ){
        setObjeto<Usuario, string>(nome, objetos);
    }
    for (it = objetos.begin(); it != objetos.end(); ++it){
        if (typeid(objeto).name() == typeid(Usuario).name() ){
            if (it->getUsuario() == objeto.getUsuario()){
                objetos.erase(it);
                objetos.pop_back();
                limpa<string>(nome);
                for (Objeto x : objetos){
                    registra<Usuario, string>(x, nome);
                }
                return 1;
            }        
        }
    }
    return 0;
}


template <typename Objeto, typename Arquivo>
void printObject(Arquivo nome){
    existe<string>(nome);
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
