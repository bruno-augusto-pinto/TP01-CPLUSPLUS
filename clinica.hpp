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

        void menuAssistenteAdministrativo(const Usuario& usuario);

        void menuUsuarioGeral(const Usuario& usuario);

        void menuAgenda(const Usuario& usuario);

        void opcoesdaConta();

        void setFiles();

        template <typename Objeto, typename Arquivo, typename TipoNome, typename TipoChave>
        int altremove(Arquivo arquivo, TipoNome tiponome, TipoChave tipochave, TipoNome operacao){
            string chave;
            cout << endl << "DIGITE O " << tipochave <<  " DO "  << tiponome << " QUE DESEJA " << operacao << ": ";
            cin >> chave;
            Objeto objeto;
            if (typeid(Objeto).name() == typeid(Usuario).name() ){
                objeto.setUsuario(chave);
                if (verifica<Usuario, string, char>(objeto, arquivo, 'C')){
                    remove<Usuario, string>(objeto, arquivo);
                    return 1;
                }
            }
            return 0;
        }
};
#endif