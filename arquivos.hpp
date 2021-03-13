#ifndef arquivos_hpp
#define arquivos_hpp

#include <fstream>
#include <experimental/filesystem> 
#include <iterator>
#include <algorithm>

#include "usuario.hpp"
#include "especialista.hpp"
#include "agenda.hpp"
#include "folhadeponto.hpp"
#include "pagamento.hpp"

namespace fs = std::experimental::filesystem::v1;

void existe(const string&);
void limpa(const string&);

void imprimeUsuarios(const string&);
void imprimeFuncionarios(const string&, const bool&);
void imprimeAgenda(const string&);
void imprimePagamentos(const string&);

void historico(const string& arqAgenda, Usuario usuario);

template <typename Objeto, typename Container>
void getFile(const string& nome, Container& objetos){
    ifstream in (nome.c_str(), ios::binary);
    Objeto temporario;
    while (in >> temporario){
        objetos.push_back(temporario);
    }
    in.close();
}

template <typename Objeto>
void setFile(const Objeto& objeto, const string& nome){
    existe(nome);
    ofstream out (nome.c_str(), ios::app | ios::binary);
    out << objeto;
    out.flush();
    out.close();
}

template <typename Objeto, typename Container>
Objeto getObjeto(Objeto objeto, const string& nome){
    existe(nome);
    Container objetos;
    getFile<Objeto, Container>(nome, objetos);
    for (Objeto x : objetos){
        if (x.getChave() == objeto.getChave()){
            return x;
        }
    }
    return objeto;
}

template <typename Objeto, typename Container>
int verifica(Objeto objeto, const string& nome){
    existe(nome);
    Container objetos;
    getFile<Objeto, Container>(nome, objetos);
    for (Objeto it : objetos) {
        if (it.getChave() == objeto.getChave()){
            return 1;
        }
    }
    return 0;
}

template <typename Objeto, typename Container>
int remove(Objeto objeto, const string& nome){
    existe(nome);
        Container objetos;
        getFile<Objeto, Container>(nome, objetos);
        typename Container::iterator it;
        for (it = objetos.begin(); it != objetos.end(); ++it){
            if (it->getChave() == objeto.getChave()){
                objetos.erase(it);
                limpa(nome);
                for (Objeto x : objetos){
                    setFile<Objeto>(x, nome);
                }
                return 1;
            }        
        }
    return 0;
}

// template <typename Objeto, typename Container>
// void ordena(string nome){
//     Container objetos;
//     getFile<Objeto, Container>(nome, objetos);
//     limpa(nome);
//     vector<string> compara;
//     for (auto x : objetos){
//         compara.push_back(x.getChave());
//     }
//     std::sort(compara.begin(), compara.end());
//     typename vector<string>::iterator it;
//     for (it = compara.begin(); it != compara.end(); ++it){
//         for (auto x : objetos){
//             if (x.getChave() == *it){
//                 setFile<Objeto>(x, nome);
//             }
//         }
//     }
// }

#endif
