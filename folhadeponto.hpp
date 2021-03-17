#ifndef folhadeponto_hpp
#define folhadeponto_hpp

#include "chave.hpp"
#include "data.hpp"
#include "vector" 

class FolhadePonto: public Chave{

    //DEFINIÇÃO DOS ATRIBUTOS PRIVADOS
    private:
        Chave chave;
        vector<string> observacao;
        vector<Data> data;
        int tamanho;

    //DEFINIÇÃO DOS MÉTODOS PÚBLICOS    
    public:
        FolhadePonto();

        ~FolhadePonto();

        void setTamanho();

        int getTamanho();

        void setChave(const string&);

        string getChave();

        void setObservacao(const string&);

        string getObservacao(const int&);

        void setData(const Data&);

        Data getData(const int&);

        bool checkData(Data);

        //string printData();

        void imprimePonto();

        friend ostream& operator<<(ostream&, const FolhadePonto&);

        friend istream& operator>>(istream&, FolhadePonto&);
};

#endif