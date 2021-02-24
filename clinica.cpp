//COMANDO PARA COMPILAR O CODIGO (C++17 É REQUERIDO):
//// g++ -std=c++17 *.cpp -lstdc++fs -o PROGRAMA
///// COMO EXECUTAR EM CMD: PROGRAMA 
/////// BASH E POWERSHELL: ./PROGRAMA 

#include "clinica.hpp"

    Clinica::Clinica(){}

    Clinica::~Clinica(){}

    int main(void)
    {
        setAdmin();
        Clinica principal;
        cout << "BEM VINDO AO SISTEMA CLINICO-OTODONTARIO." << endl;
        principal.menuPrincipal();
        EXIT_SUCCESS;
    }

    void Clinica::menuPrincipal()
    {
        int opc = -1;
        do 
        {
            cout << endl << "MENU PRINCIPAL: " << endl << "(1) LOGIN" << endl << "(2) REGISTRO" << endl << "(0) FINALIZAR" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->login();
                break;

                case 2:
                    this->cadastro(); 
                break;

                case 0:
                    cout << endl << "FINALIZANDO A EXECUÇÃO.";
                break;
            
                default:
                    cout << endl << "OPÇÃO INVALIDA! TENTE NOVAMENTE." << endl;
                break;
            }
        }
        while(opc != 0);
    }

    void Clinica::login()
    {
        string usuario, senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        //senha = setMascara("INSIRA A SENHA: ");
        switch (verificaLogin(usuario, senha)) {
            case 'A':
                this->menuAdministrador();
            break;

            case 'B':
                this->menuAssistenteAdministrativo();
            break;

            case 'G':
                this->menuUsuarioGeral();
            break;
            
            case 'E':
                EXIT_FAILURE;
            break;

            case 'O':
                cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
            break;
        }
    }

    void Clinica::cadastro()
    {
        string usuario, senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        //senha = setMascara("INSIRA A SENHA: ");
        if(cadastraUsuario(usuario, senha) == -1){
            EXIT_FAILURE;
        }else if (cadastraUsuario(usuario, senha) == 0) {
            cout << endl << "USUARIO JA CADASTRADO!";
        }else{
            cout << endl << "USUARIO CADASTRADO COM SUCESSO!";
        }
    }

    void Clinica::menuAdministrador()
    {
        int opc = -1;
        cout << endl << "MENU DO ADMINISTRADOR" << endl;
        do {
            cout << "(1) ADMINISTRAR USUARIOS" << endl << "(2) ADMNISTRAR FUNCIONARIOS"<< endl; 
            cout << "(0) FINALIZAR EXECUÇÃO" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->crudUsuario();
                break;

                case 2:
                    this->crudFuncionario();
                break;

                case 0:
                    cout << endl << "FINALIZANDO EXECUÇÃO.";
                break;
            
                default:
                    cout << endl << "OPÇÃO INVALIDA! TENTE NOVAMENTE." << endl;
                break;
            }
        }while(opc != 0);
        EXIT_SUCCESS;
    }

    void Clinica::crudUsuario()
    {


    }

    void Clinica::crudFuncionario()
    {
        
    }

    void Clinica::menuAssistenteAdministrativo()
    {
        int opc = -1;
        cout << endl << "MENU DO ASSISTENTE ADMINISTRADOR" << endl;
        do {
            cout << "(1) " << endl << "(2) "<< endl; 
            cout << "(0) FINALIZAR EXECUÇÃO" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    
                break;

                case 2:
                    
                break;

                case 0:
                    cout << endl << "FINALIZANDO EXECUÇÃO.";
                break;
            
                default:
                    cout << endl << "OPÇÃO INVALIDA! TENTE NOVAMENTE." << endl;
                break;
            }
        }while(opc != 0);
        EXIT_SUCCESS;
    }

    void Clinica::menuUsuarioGeral()
    {
        int opc = -1;
        cout << endl << "MENU DO USUARIO GERAL" << endl;
        do {
            cout << "(1) ACESSAR AGENDA" << endl << "(2) OPÇÕES DA CONTA"<< endl; 
            cout << "(0) FINALIZAR EXECUÇÃO" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->menuAgenda();  
                break;

                case 2:
                    this->opcoesdaConta();
                break;

                case 0:
                    cout << endl << "FINALIZANDO EXECUÇÃO.";
                break;
            
                default:
                    cout << endl << "OPÇÃO INVALIDA! TENTE NOVAMENTE." << endl;
                break;
            }
        }while(opc != 0);
        EXIT_SUCCESS;
    }

    void Clinica::menuAgenda(){

    }

    void Clinica::opcoesdaConta(){

    }

