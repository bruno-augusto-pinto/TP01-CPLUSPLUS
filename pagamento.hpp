#ifndef pagamento_hpp
#define pagamento_hpp

#include "data.hpp"
#include "chave.hpp"

class Pagamento: public Chave{
    private:
      Data vencimento;
      Data pagamento;
      string descricao;
      Chave chave;
      string tipo;
      string usuario;

    public:

    Pagamento();

    ~Pagamento();

    void setVencimento(const Data&);

    Data getVencimento();

    void setPagamento(const Data&);

    Data getPagamento();

    void setChave();

    string getChave();

    void setDescricao(const string&);

    string getDescricao();

    void setTipo(const int&);

    string getTipo();

    void setUsuario(const string&);

    string getUsuario();

    friend ostream& operator <<(ostream&, const Pagamento&);

    friend istream& operator >>(istream&, Pagamento&);

};

#endif