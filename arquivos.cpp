#include "arquivos.hpp"

namespace fs = std::experimental::filesystem::v1;

void setAdmin()
{
    if(!fs::exists("usuarios.bin"))
    {
        Usuario admin("admin", "admin", 'A');
        fstream criar ("usuarios.bin", ios::app | ios::binary);
        criar.close();
        ofstream out("usuarios.bin");
        out << admin;
        out.flush();
        out.close();
    }
}

char verificaLogin(const string& usuario, const string& senha)
{
    if(!fs::exists("usuarios.bin"))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        return 'E';
    }
    else
    {
        ifstream in ("usuarios.bin");
        vector<Usuario> users;
        Usuario user;

        while(!in.eof()){
            in >> user;
            users.push_back(user);
        }

        in.close();

        for (auto x : users) {
            if (x.getUsuario() == usuario){
                if (x.getSenha() == senha) {
                    users.clear();
                    return x.getTipo();
                }
            }
        }
        users.clear();
        return 'O';
    }
}

int cadastraUsuario(const string& usuario, const string& senha, const char& tipo)
{
    if(!fs::exists("usuarios.bin"))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        EXIT_FAILURE;
    }
    else
    {
        ifstream in ("usuarios.bin");
        vector<Usuario> users;
        Usuario user;

        while(!in.eof()){
            in >> user;
            users.push_back(user);
        }
        
        in.close();

        for (auto x : users) {
            if (x.getUsuario() == usuario){
                users.clear();
                return 0;
            }
        }

        users.clear();
        ofstream out ("usuarios.bin", ios::app);
        user.setUsuario(usuario);
        user.setSenha(senha);
        user.setTipo(tipo);
        out << user;
        out.flush();
        out.close();
    }  
    return 1; 
}
