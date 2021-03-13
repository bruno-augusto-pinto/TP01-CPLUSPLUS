#include "arquivos.hpp"

void limpa(const string& nome){
    remove(nome.c_str());
    ofstream recria (nome.c_str(), ios::app);
    recria.close();
}

void existe(const string& nome){
    if(!fs::exists(nome.c_str()))
    {
        perror("ERRO: ARQUIVO NAO existe!");
        EXIT_FAILURE;
    }  
}

void imprimeUsuarios(const string& nome){
    existe(nome);
    cout << endl;
    printf("|%12s|%14s|", "NOME ", "TIPO DE CONTA ");
    cout << endl;
    ifstream in (nome.c_str());
    Usuario it;
    while(in >> it){
        string tipo;
        switch (it.getTipo())
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
        printf("|%12s|%14s|", it.getUsuario().c_str(), tipo.c_str());
        cout << endl;
    }
    in.close();
}

void imprimeFuncionarios(const string& nome, const bool& admin){
    existe(nome);
    cout << endl;
    ifstream in (nome.c_str());
    Funcionario it;
    if (admin){
        printf("|%12s|%10s|%14s|%10s|", "NOME ", "CPF", "TIPO DE CONTA", "CMOMD");
        cout << endl;
        while(in >> it){
            string tipo;
            switch (it.getTipo())
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
            if(it.getTipo() == 'E'){
                printf("|%12s|%10s|%14s|%10s|", it.getNome().c_str(), it.getCPF().c_str(), tipo.c_str(), it.getChave().c_str());
            }else{
                printf("|%12s|%10s|%14s|%10s|", it.getNome().c_str(), it.getCPF().c_str(), tipo.c_str(), "-------");
            }
            cout << endl;
        }
    }else{
        printf("|%12s|%10s|", "NOME ", "CDOMD");
        cout << endl;
        while(in >> it){
            switch (it.getTipo())
            {
                case 'E':
                    printf("|%12s|%10s|", it.getNome().c_str(), it.getChave().c_str());
                    cout << endl;
                break;
            }
        }
    }
    in.close();   
}

void imprimeAgenda(const string& nome){
    existe(nome);
    cout << endl;
    ifstream in (nome.c_str());
    Agenda it;
    printf("|%6s|%12s|%10s|%14s|", "CODIGO", "HORARIO", "DISPONIBILIDADE", "PACIENTE");
    cout << endl;
    while(in >> it){
        string disponibilidade;
        for (int i = 0; i < 5; i++){
            if (it.getDisponibilidade(i)){
                disponibilidade = "DISPONIVEL";
                printf("|%6c|%12s|%10s|%14s|", i, it.getHorario(i).c_str(), disponibilidade.c_str(), "---------" );
            }else{
                disponibilidade = "INDISPONIVEL";
                printf("|%6c|%12s|%10s|%14s|", i, it.getHorario(i).c_str(), disponibilidade.c_str(), it.getPaciente(i).c_str());

            }
            cout << endl;
        }
    }
    in.close(); 
}

void historico(const string& arqAgenda, Usuario usuario){
    vector<Agenda> consultas;
    getFile<Agenda, vector<Agenda>>(arqAgenda, consultas);
    printf("|%12s|%12s|%10s|%14s|", "DENTISTA", "DATA", "HORARIO", "PACIENTE");
    for (Agenda it : consultas){
        for (int i = 0; i < 5; i++){
            if (it.getUsuario(i) == usuario.getUsuario()){
                printf("|%12s|%12s|%10s|%14s|", it.getFuncionario().c_str(), it.printData().c_str(), it.getHorario(i).c_str(), it.getPaciente(i).c_str());
                cout << endl;
            }
        }
    }
}