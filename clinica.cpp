#include "clinica.hpp"

    Clinica::Clinica(){}

    Clinica::~Clinica(){}

    int main(void)
    {
        Clinica principal;
        principal.setFiles();
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
                    this->login("usuarios.bin");
                break;

                case 2:
                    this->cadastro(false, "usuarios.bin"); 
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

    void Clinica::login(const string& arquivo)
    {
        string usuario, senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        Usuario user(usuario, senha, '0');
        if (!verifica<Usuario, string, char>(user, arquivo, 'L')){
            cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
        }

        switch (user.getTipo()) {
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

    void Clinica::cadastro(bool admin, const string& arquivo)
    {
        string usuario, senha;
        char tipo;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        if (admin){
            int opc = -1;
            do {
                cout << endl << "(1) ADMINISTRADOR" << endl << "(2) ASSISTENTE ADMINISTRATIVO" << endl << "(3) USUARIO GERAL" << endl << "ESCOLHA: ";
                cin >> opc;
                switch (opc) {
                    case 1:
                        tipo = 'A';
                        opc = 0;
                    break;

                    case 2:
                        tipo = 'B';
                        opc = 0;
                    break;

                    case 3:
                        tipo = 'G';
                        opc = 0;
                    break;

                    default:
                        cout << "INVALIDO! TENTE NOVAMENTE!" << endl;
                }
            }while(opc != 0);
        }else{
            tipo = 'G';
        }
        Usuario user(usuario, senha, tipo);
        if (verifica<Usuario, string, char>(user, arquivo, 'C')){
           cout << endl << "USUARIO JA CADASTRADO!" << endl;
        }else{
            registra<Usuario, string>(user, arquivo);
            cout << endl << "USUARIO CADASTRADO COM SUCESSO!" << endl;
        }
    }

    void Clinica::menuAdministrador()
    {
        int opc = -1;
        cout << endl << "MENU DO ADMINISTRADOR";
        do {
            cout << endl << "(1) ADMINISTRAR USUARIOS" << endl << "(2) ADMNISTRAR FUNCIONARIOS"; 
            cout << endl << "(0) FINALIZAR EXECUÇÃO" << endl << "ESCOLHA: ";
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
        int opc = -1;
        string arquivo = "usuarios.bin";
        cout << endl <<"MENU ADMINISTRATIVO DE USUARIOS";
        do {
            
            cout << endl << "(1) CADASTRAR UM NOVO USUARIO" << endl << "(2) LISTAR USUARIOS";
            cout << endl << "(3) ALTERAR DADOS DE UM USUARIO" << endl << "(4) REMOVER UM USUARIO";
            cout << endl << "(0) SAIR DO MENU" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    cadastro(true, arquivo);
                break;

                case 2:
                    printFile<Usuario, string>(arquivo);
                    //https://stackoverflow.com/questions/6755250/format-output-in-a-table-c
                break;

                case 3:

                break;

                case 4:

                break;

                case 0:
                    cout << endl << "RETORNANDO AO MENU ADMINISTRATIVO." << endl;
                break;
            
                default:
                    cout << endl << "INVALIDO! TENTE NOVAMENTE!" << endl;
                break;
            }
        }while(opc != 0);
    }

    void Clinica::crudFuncionario()
    {
        int opc = -1;
        cout << endl <<"MENU ADMINISTRATIVO DE FUNCIONARIOS";
        do {
            cout << endl << "(1) CADASTRAR UM NOVO FUNCIONARIO" << endl << "(2) LISTAR FUNCIONARIOS";
            cout << endl << "(3) ALTERAR DADOS DE UM FUNCIONARIO" << endl << "(4) REMOVER UM FUNCIONARIO";
            cout << endl << "(0) SAIR DO MENU" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:

                break;

                case 2:

                break;

                case 3:

                break;

                case 4:

                break;

                case 0:
                    cout << endl << "RETORNANDO AO MENU ADMINISTRATIVO." << endl;
                break;
            
                default:
                    cout << endl << "INVALIDO! TENTE NOVAMENTE!" << endl;
                break;
            }
        }while(opc != 0);        
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

    void Clinica::setFiles(){
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

        if(!fs::exists("funcionarios.bin"))
        {
            fstream criar ("funcionarios.bin", ios::app | ios::binary);
            criar.close();
        }
    }