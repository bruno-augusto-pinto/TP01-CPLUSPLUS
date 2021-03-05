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
            cout << endl << "MENU PRINCIPAL: " << endl << "(1) LOGIN" << endl << "(2) REGISTRO" << endl << "(3) EXPERIMENTAL CALENDARIO" << endl << "(0) FINALIZAR" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->login("usuarios.bin");
                break;

                case 2:
                    this->cadastro(false, "usuarios.bin"); 
                break;

                case 3:
                {
                    if ( !comparaHora(3, 2, 2021) ){
                        perror("ERRO! VOCÊ NÃO PODE AGENDAR CONSULTA DE UM DIA QUE JÁ PASSOU!");
                    }else{
                        cout << endl << "DATA VALIDA";
                    }
                    Calendario calendario;
                    calendario.imprimeCalendario(2020);
                }
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
        char* usuario = new char[12];
        char* senha = new char[12];
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        Usuario user(usuario, senha, '0');
        user.setChave();
        if (!verifica<Usuario, vector<Usuario>>(user, arquivo)){
            cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
        }else{
            Usuario temp = getObjeto<Usuario>(user, arquivo);
            if (strcmp(temp.getSenha(), user.getSenha()) == 0){
                user = temp;
                temp.~Usuario();
                switch (user.getTipo()) {
                    case 'A':
                        this->menuAdministrador(user);
                    break;

                    case 'B':
                        this->menuAssistenteAdministrativo(user);
                    break;

                    case 'G':
                        this->menuUsuarioGeral(user);
                    break;
                }
            }else{
                cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
            }
        }
    }

    void Clinica::cadastro(bool admin, const string& arquivo)
    {
        char* usuario = new char[12];
        char* senha = new char[12];
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
        user.setChave();
        if (verifica<Usuario, vector<Usuario>>(user, arquivo)){
            cout << endl << "USUARIO JA CADASTRADO!" << endl;
        }else{
            registra<Usuario>(user, arquivo);
            cout << endl << "USUARIO CADASTRADO COM SUCESSO!" << endl;
        }
    }

    void Clinica::menuAdministrador(const Usuario& usuario)
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
                    imprimeUsuarios(arquivo);
                break;

                case 3:
                    if (altremove<Usuario>(arquivo, "USUARIO", "NOME", "ALTERAR")){
                        cadastro(true, arquivo);
                    }
                break;

                case 4:
                    if (!altremove<Usuario>(arquivo, "USUARIO", "NOME", "REMOVER")){
                        cout << endl << "ERRO! USUARIO NÃO EXISTE!" << endl;
                    }else{
                        cout << endl << "USUARIO REMOVIDO!" << endl;
                    }
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
        string arquivo = "funcionarios.bin";
        int opc = -1;
        cout << endl <<"MENU ADMINISTRATIVO DE FUNCIONARIOS";
        do {
            cout << endl << "(1) REGISTRAR UM NOVO FUNCIONARIO" << endl << "(2) LISTAR FUNCIONARIOS";
            cout << endl << "(3) ALTERAR DADOS DE UM FUNCIONARIO" << endl << "(4) REMOVER UM FUNCIONARIO";
            cout << endl << "(0) SAIR DO MENU" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->registraFuncionario(arquivo);
                break;

                case 2:
                    //printObject<Funcionario>(arquivo);
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

    void Clinica::registraFuncionario(const string& arquivo){
        char* nome = new char(12);
        char* cpf = new char(10);
        int opc = -1;
        char tipo;
        cout << endl << "INSIRA O NOME: ";
        cin >> nome;
        cout << endl << "INSIRA O CPF: ";
        cin >> cpf;
        Funcionario funcionario;
        do {
            cout << endl << "(1) ESPECIALISTA";
            cout << endl << "(2) ASSISTENTE";
            cout << endl << "(3) RECEPCIONISTA";
            cout << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    //funcionario = new Especialista;
                    tipo = 'E';
                    opc = 0;
                break;

                case 2:
                    tipo = 'A';
                    opc = 0;
                break;

                case 3:
                    tipo = 'R';
                    opc = 0;
                break;
                
                default:
                    cout << endl << "INVALIDO! TENTE NOVAMENTE!";
                break;
            }
        }while(opc != 0);
        funcionario.setNome(nome);
        funcionario.setCPF(cpf);
        funcionario.setTipo(tipo);
        funcionario.setChave();
        if (verifica<Funcionario, vector<Funcionario>>(funcionario, arquivo)){
           cout << endl << "FUNCIONARIO JA CADASTRADO!" << endl;
        }else{
            registra<Funcionario>(funcionario, arquivo);
            cout << endl << "FUNCIONARIO CADASTRADO COM SUCESSO!" << endl;
        }
    }

    void Clinica::menuAssistenteAdministrativo(const Usuario& usuario)
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

    void Clinica::menuUsuarioGeral(const Usuario& usuario)
    {
        int opc = -1;
        cout << endl << "MENU DO USUARIO GERAL" << endl;
        do {
            cout << "(1) ACESSAR AGENDA DE CONSULTAS" << endl << "(2) OPÇÕES DA CONTA"<< endl; 
            cout << "(0) FINALIZAR EXECUÇÃO" << endl << "ESCOLHA: ";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    this->menuAgenda(usuario);  
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

    void Clinica::menuAgenda(const Usuario& usuario){
        cout << endl << "MENU DE AGENDA DE CONSULTAS.";
        cout << endl << "(1) AGENDAR UMA CONSULTA";
        cout << endl << "(2) LISTAR AGENDA DE CONSULTAS";
        cout << endl << "(3) DESMARCAR UMA CONSULTA";
        cout << endl << "(4) HISTORICO DE CONSULTAS";
        cout << endl << "ESCOLHA: ";
        int opc = -1;
        do {
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

                default:
                    cout << endl << "OPÇÃO INVALIDA! TENTE NOVAMENTE." << endl;
            }
        }while(opc != 0);
    }

    void Clinica::opcoesdaConta(){

    }

    void Clinica::setFiles(){
        if(!fs::exists("usuarios.bin"))
        {
            Usuario admin("admin", "admin", 'A');
            admin.setChave();
            fstream criar ("usuarios.bin", ios::app | ios::binary);
            criar.close();
            registra<Usuario>(admin, (string)"usuarios.bin");
        }

        if(!fs::exists("funcionarios.bin"))
        {
            fstream criar ("funcionarios.bin", ios::app | ios::binary);
            criar.close();
        }

        if(!fs::exists("agenda.bin"))
        {
            fstream criar ("agenda.bin", ios::app | ios::binary);
            criar.close();
        }
    }