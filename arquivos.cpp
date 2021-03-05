#include "arquivos.hpp"

void limpa(const string& nome){
    remove(nome.c_str());
    ofstream recria (nome.c_str(), ios::app);
    recria.close();
}

void existe(const string& nome){
    if(!fs::exists(nome.c_str()))
    {
        perror("ERRO: ARQUIVO NAO EXISTE!");
        EXIT_FAILURE;
    }  
}

void imprimeUsuarios(const string& nome){
    existe(nome);
    cout << endl;
    printf("|%12s|%14s|", "NOME ", "TIPO DE CONTA ");
    cout << endl;
    ifstream in (nome.c_str());
    Usuario x;
    while(in >> x){
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
        printf("|%12s|%14s|", x.getUsuario().c_str(), tipo.c_str());
        cout << endl;
    }
    in.close();
}

void imprimeFuncionarios(const string& nome, const bool& admin){
    existe(nome);
    cout << endl;
    ifstream in (nome.c_str());
    Funcionario x;
    if (admin){
        printf("|%12s|%10s|%14s|", "NOME ", "CPF", "TIPO DE CONTA ");
        cout << endl;
        while(in >> x){
            string tipo;
            switch (x.getTipo())
            {
                case 'E':
                    tipo = "Administrador";
                break;

                case 'A':
                    tipo = "Assistente";
                break;

                case 'R':
                    tipo = "Geral";
                break;
            }
            printf("|%12s|%10s|%14s|", x.getNome().c_str(), x.getCPF().c_str(), tipo.c_str());
            cout << endl;
        }
    }else{

    }
    in.close();   
}