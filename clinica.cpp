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
        string usuario;
        string senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        Usuario user(usuario, senha, '0');
        user.setChave();
        if (!verifica<Usuario, vector<Usuario>>(user, arquivo)){
            cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
        }else{
            Usuario temp = getObjeto<Usuario, vector<Usuario>>(user, arquivo);
            if (temp.getSenha() == user.getSenha()){
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
        string usuario;
        string senha;
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
                    this->cadastro(true, arquivo);
                break;

                case 2:
                    imprimeUsuarios(arquivo);
                break;

                case 3:
                    if (altremove<Usuario>(arquivo, "USUARIO", "NOME", "ALTERAR")){
                        this->cadastro(true, arquivo);
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
        string chave, tipo;
        bool controle = false;
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
                    imprimeFuncionarios(arquivo, true);
                break;

                case 3:
                    cout << endl << "(1) ESPECIALISTA" << endl << "(2) OUTROS";
                    cout << endl  << "ESCOLHA: ";
                    do
                    {
                        cin >> opc;
                        switch (opc)
                        {
                            case 1:
                                chave = "CDOMD";
                                tipo = "ESPECIALISTA";
                                controle = true;
                            break;

                            case 2:
                                chave = "CPF";
                                tipo = "FUNCIONARIO";
                                controle = true;
                            break;
                            
                            default:
                                cout << "INVALIDO! TENTE NOVAMENTE!";
                        }
                    } while (!controle);
                    if (altremove<Funcionario>(arquivo, tipo, chave, "ALTERAR")){
                        this->registraFuncionario(arquivo);
                    }   
                break;

                case 4:
                    cout << endl << "(1) ESPECIALISTA" << endl << "(2) OUTROS";
                    cout << endl  << "ESCOLHA: ";
                    do
                    {
                        cin >> opc;
                        switch (opc)
                        {
                            case 1:
                                chave = "CDOMD";
                                tipo = "ESPECIALISTA";
                                controle = true;
                            break;

                            case 2:
                                chave = "CPF";
                                tipo = "FUNCIONARIO";
                                controle = true;
                            break;
                            
                            default:
                                cout << "INVALIDO! TENTE NOVAMENTE!";
                        }
                    } while (!controle);
                    if (!altremove<Funcionario>(arquivo, tipo, chave, "REMOVER")){
                        cout << endl << "ERRO! FUNCIONARIO NÃO EXISTE!" << endl;
                    }else{
                        cout << endl << "FUNCIONARIO REMOVIDO!" << endl;
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

    void Clinica::registraFuncionario(const string& arquivo){
        string nome;
        string cpf;
        string chave;
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
                {
                    cout << endl << "INSIRA O CDOMD DO ESPECIALISTA: ";
                    cin >> chave;
                    tipo = 'E';
                    funcionario.setChave(chave);
                    opc = 0;
                }
                break;

                case 2:
                    tipo = 'A';
                    opc = 0;
                    funcionario.setChave();
                break;

                case 3:
                    tipo = 'R';
                    opc = 0;
                    funcionario.setChave();
                break;
                
                default:
                    cout << endl << "INVALIDO! TENTE NOVAMENTE!";
                break;
            }
        }while(opc != 0);
        funcionario.setNome(nome);
        funcionario.setCPF(cpf);
        funcionario.setTipo(tipo);            
        if (verifica<Funcionario, vector<Funcionario>>(funcionario, arquivo)){
            cout << endl << "FUNCIONARIO JA CADASTRADO!" << endl;
        }else{
            if (tipo == 'E'){
                 Funcionario temp;
                 temp.setChave(cpf);
                if (verifica<Funcionario, vector<Funcionario>>(temp, arquivo)){
                    cout << endl << "FUNCIONARIO JA CADASTRADO!" << endl;
                }else{
                    registra<Funcionario>(funcionario, arquivo);
                    cout << endl << "FUNCIONARIO CADASTRADO COM SUCESSO!" << endl;
                }
            }else{
                registra<Funcionario>(funcionario, arquivo);
                cout << endl << "FUNCIONARIO CADASTRADO COM SUCESSO!" << endl;
            }
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
                    listaAgenda();
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

    void Clinica::listaAgenda(){
        string funcionario = "funcionarios.bin";
        string chave;
        imprimeFuncionarios(funcionario, false);
        cout << "INSIRA O CDOMD DE UM DOS ESPECIALISTAS: ";
        cin >> chave;
        Especialista especialista;
        especialista.setChave(chave);
        if (!verifica<Especialista, vector<Especialista>>(especialista, funcionario)){
            cout << endl << "ESPECIALISTA NÃO EXISTE!" << endl;
        }else{
            int ano = getAnoAtual();
            int mes, dia;
            cout << "INSIRA O MES DE " << ano << " QUE DESEJA ACESSAR" << endl;
            cout << "(1) Janeiro" << endl << "(2) Fevereiro" << endl << "(3) Março" << endl;
            cout << "(4) Abril" << endl << "(5) Maio" << endl << "(6) Junho" << endl;
            cout << "(7) Julho" << endl << "(8) Agosto" << endl << "(9) Setembro" << endl;
            cout << "(10) Outubro" << endl << "(11) Novembro" << endl << "(12) Dezembro";
            cout << "ESCOLHA: ";
            do {
                cin >> mes;
                if (mes < 1 || mes > 12) {
                    cout << endl << "MES INVALIDO TENTE NOVAMENTE";
                }
            }while(mes < 1 || mes > 12);
            Calendario calendario;
            calendario.imprimeMes(ano, mes);
            cout << endl << "ESCOLHA UM DIA: ";
            cin >> dia;
            if ( !comparaHora(dia, mes, ano) ){
                perror("ERRO! VOCÊ NÃO PODE AGENDAR UMA CONSULTA EM UM DIA QUE JÁ PASSOU!");
            }else{
                string arqAgenda = "agenda.bin";
                especialista = getObjeto<Especialista, vector<Especialista>>(especialista, funcionario);
                Agenda agenda(dia, mes, ano);
                agenda.setFuncionario(especialista.getChave());
                agenda.setChave();
                if (!verifica<Agenda, vector<Agenda>>(agenda, arqAgenda)){
                    agenda = getObjeto<Agenda, vector<Agenda>>(agenda, arqAgenda);
                }
                cout << endl << "AGENDA DE " << especialista.getNome() << " NA DATA " << dia << "/" << mes << "/" << ano << ":" << endl;
                agenda.imprimeAgenda();
            }
        } 
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