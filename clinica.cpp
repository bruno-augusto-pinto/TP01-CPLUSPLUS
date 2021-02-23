//COMANDO PARA COMPILAR NOSSO CODIGO (C++17 É REQUERIDO):
//// g++ -std=c++17 *.cpp -lstdc++fs -o PROGRAMA
///// COMO EXECUTAR: PROGRAMA NO CMD WINDOWS
/////// ./PROGRAMA NO LINUX, MAC E POWERSHELL

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

    void Clinica::menuPrincipal(){
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
                    cout << endl << "OPÇÃO INVALIDA, TENTE NOVAMENTE." << endl;
                break;
            }
        }
        while(opc != 0);
    }

    void Clinica::login(){
        string usuario, senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        cout << endl << "INSIRA A SENHA: ";
        setMascara( (char*) senha.c_str());
        switch (verificaUsuarios(usuario, senha))
        {
            case 'A':
                cout << endl << "Logou Admin" << endl; 
            break;

            case 'B':
                cout << endl << "Logou Assistente" << endl;
            break;

            case 'G':
                cout << endl << "Logou Geral" << endl;
            break;
            
            case 'E':
                EXIT_FAILURE;
            break;

            case 'O':
                cout << endl << "USUARIO OU SENHA INVALIDOS!" << endl;
            break;
        }
    }

    void Clinica::cadastro(){
        string usuario, senha;
        cout << endl << "INSIRA O USUARIO: ";
        cin >> usuario;
        setMascara( (char*) senha.c_str());
        if(cadastraUsuario(usuario, senha) == -1){
            EXIT_FAILURE;
        }else if (cadastraUsuario(usuario, senha) == 0) {
            cout << endl << "USUARIO JA CADASTRADO!";
        }else{
            cout << endl << "USUARIO CADASTRADO COM SUCESSO!";
        }
    }

    void Clinica::setMascara(char* senha){
        struct termios oflags, nflags;

        //disabling echo
        tcgetattr(fileno(stdin), &oflags);
        nflags = oflags;
        nflags.c_lflag &= ~ECHO;
        nflags.c_lflag |= ECHONL;

        if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
            perror("tcsetattr");
            EXIT_FAILURE;
        }

        cout << endl << "INSIRA A SENHA: ";
        cin >> senha;
        fgets(senha, sizeof(senha), stdin);
        //while(fgets(senha, sizeof(senha), stdin != GetAsynKeyState(VK_RETURN)){}
        senha[strlen(senha) - 1] = 0;
        
        //restore terminal
        if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
            perror("tcsetattr");
            EXIT_FAILURE;
        }
    }

    /*
        while((ch=getch())!=RETURN)
        {
            if(ch==BACKSPACE)
            {
                if(password.length()!=0)
                {
                    if(show_asterisk)
                        cout <<"\b \b";
                        password.resize(password.length()-1);
                }
            }
             else
            {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
            }
        }
    */