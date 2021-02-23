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
        senha = setMascara("INSIRA A SENHA: ");
        switch (verificaUsuarios(usuario, senha)) {
            case 'A':
                cout << endl << "Logou Admin" << endl; 
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
        senha = setMascara("INSIRA A SENHA: ");
        if(cadastraUsuario(usuario, senha) == -1){
            EXIT_FAILURE;
        }else if (cadastraUsuario(usuario, senha) == 0) {
            cout << endl << "USUARIO JA CADASTRADO!";
        }else{
            cout << endl << "USUARIO CADASTRADO COM SUCESSO!";
        }
    }

    int Clinica::getch(){
        int ch;
        struct termios t_old, t_new;

        tcgetattr(STDIN_FILENO, &t_old);
        t_new = t_old;
        t_new.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
        return ch;
    }

    string Clinica::setMascara(const char *prompt)
    {
        const char BACKSPACE=127;
        const char RETURN=10;

        string senha;
        unsigned char ch=0;

        cout <<prompt<<endl;

        while((ch=getch())!=RETURN)
        {
            if(ch==BACKSPACE)
            {
            if(senha.length()!=0)
              {
                 cout <<"\b \b";
                 senha.resize(senha.length()-1);
              }
            }
            else
            {
                senha+=ch;
                cout <<'*';
            }
        }
        cout <<endl;
        return senha;
    }
