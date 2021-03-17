#ifndef pessoa_hpp
#define pessoa_hpp

#include "chave.hpp"

using namespace std; 

class Pessoa: public Chave{

    //DEFINIÇÃO DOS ATRIBUTOS PRIVADOS
    private:
        string nome;
        string CPF;
        Chave chave;

    //DEFINIÇÃO DOS MÉTODOS PÚBLICOS
    public:
        Pessoa();

        Pessoa(const string&, const string&);

        virtual ~Pessoa();

        void setNome(const string&);

        void setCPF(const string&);

        string getNome();

        string getCPF();

        void setChave(const string&);

        void setChave();

        string getChave();

        friend ostream& operator<<(ostream&, const Pessoa&);

        friend istream& operator>>(istream&, Pessoa&);
};

#endif