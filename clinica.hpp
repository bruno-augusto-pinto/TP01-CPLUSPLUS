#ifndef clinica_hpp
#define clinica_hpp

#include "arquivos.hpp"
#include "calendario.hpp"

using namespace std;

class Clinica {

    public:

        Clinica();

        ~Clinica();

        int main(void);

        void menuPrincipal();

        //https://cplusplus.com/articles/E6vU7k9E/
        void login(const string&);

        void cadastro(bool, const string&);

        void menuAdministrador(const Usuario& usuario);

        void crudUsuario();

        void crudFuncionario();

        void registraFuncionario(const string&);

        void menuAssistenteAdministrativo(const Usuario& usuario);

        void menuUsuarioGeral(const Usuario& usuario);

        void menuAgenda(const Usuario& usuario);

        void opcoesdaConta();

        void setFiles();

        template <typename Objeto>
        int altremove(string arquivo, string tiponome, string tipochave, string operacao){
            char* chave = new char;
            cout << endl << "DIGITE O " << tipochave <<  " DO "  << tiponome << " QUE DESEJA " << operacao << ": ";           
            cin >> chave;
            Objeto objeto;
            objeto.setChave((char*)chave);
            /*if (verifica<Objeto>(objeto, arquivo)){
                remove<Objeto>(objeto, arquivo);
                return 1;
            }*/
            return 0;
        }
};
#endif