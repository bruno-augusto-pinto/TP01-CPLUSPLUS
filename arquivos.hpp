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

void existe(const string&);
void limpa(const string&);

void imprimeUsuarios(const string&);
void imprimeFuncionarios(const string&, const bool&);


template <typename Objeto, typename Container>
void setObjetos(const string& nome, Container& objetos){
    ifstream in (nome.c_str());
    Objeto temporario;
    while(in >> temporario){
        //cout << "temporario: " << temporario << endl;
        objetos.push_back(temporario);
        //cout << "Objetos.front():" << objetos.front() << endl;
        //cout << "Objetos.back():" << objetos.back() << endl;
    }
    in.close();
    //for (auto it : objetos) {
        //cout << "Objeto it em set apos while: "<< endl << it;
    //}
}

template <typename Objeto>
void registra(const Objeto& objeto, const string& nome){
    existe(nome);
    ofstream out (nome.c_str(), ios::app | ios::binary);
    out << objeto;
    out.flush();
    out.close();
}

template <typename Objeto>
Objeto getObjeto(Objeto objeto, const string& nome){
    existe(nome);
    vector<Objeto> objetos;
    setObjetos<Objeto, vector<Objeto>>(nome, objetos);
    for (Objeto x : objetos){
        if (strcmp(x.getChave(), objeto.getChave()) == 0){
            return x;
        }
    }
    return objeto;
}

template <typename Objeto, typename Container>
int verifica(Objeto objeto, const string& nome){
    existe(nome);
    Container objetos;
    setObjetos<Objeto, Container>(nome, objetos);
    for (auto it : objetos) {
        cout << "Objeto it: "<< endl << it;
        if (strcmp(it.getChave(), objeto.getChave()) == 0){
            return 1;
        }
    }
    return 0;
}

template <typename Objeto>
int remove(Objeto objeto, const string& nome){
    existe(nome);
        vector<Objeto> objetos;
        setObjetos<Objeto, vector<Objeto>>(nome, objetos);
        typename vector<Objeto>::iterator it;
        for (it = objetos.begin(); it != objetos.end(); ++it){
            if (it->getChave() == objeto.getChave()){
                objetos.erase(it);
                objetos.pop_back();
                limpa(nome);
                for (Objeto x : objetos){
                    registra<Objeto>(x, nome);
                }
                return 1;
            }        
        }
    return 0;
}

#endif
