//https://www.cplusplus.com/reference/fstream/fstream/
//https://docs.microsoft.com/pt-br/cpp/standard-library/filesystem?view=msvc-160

#ifndef arquivos_hpp
#define arquivos_hpp

#include <fstream>
#include <vector>
#include <experimental/filesystem> 

#include "usuario.hpp"

using namespace std;
 
using namespace std::experimental::filesystem::v1;

namespace fs = std::experimental::filesystem::v1;

template <typename Objeto, typename Arquivo>
int verifica(Objeto& objeto, Arquivo nome){
    bool igual = false;
    if(!fs::exists(nome.c_str()))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        EXIT_FAILURE;
    }
    ifstream in (nome.c_str());
    vector<Objeto> objetos;
    Objeto temporario;
    while(!in.eof()){
        in >> temporario;
        objetos.push_back(temporario);
    }
    in.close();

    for (Objeto x : objetos){
        if (typeid(objeto).name() == typeid(Usuario).name() ){
            if (x.getUsuario() == objeto.getUsuario() && x.getSenha() == objeto.getSenha()){
                objeto = x;
                return 1;
            }else if (x.getUsuario() == objeto.getUsuario()){
                igual = true;
            }
        }
    }
    if (igual){
        return -1;
    }
    return 0;
}

template <typename Objeto, typename Arquivo>
void registra(const Objeto& objeto, Arquivo nome){
    ofstream out (nome.c_str(), ios::app);
    out << objeto;
    out.flush();
    out.close();
}

#endif
