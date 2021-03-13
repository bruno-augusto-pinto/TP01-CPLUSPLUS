#ifndef folhadeponto_hpp
#define folhadeponto_hpp

//#include <algorithm> 
#include "chave.hpp"
#include "data.hpp" 

class FolhadePonto: public Chave{
    private:
        Chave chave;
        vector<string> observacao;
        vector<Data> data;
        int tamanho;
        
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