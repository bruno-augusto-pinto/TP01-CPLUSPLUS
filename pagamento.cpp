#include "pagamento.hpp"

Pagamento::Pagamento(){}

Pagamento::~Pagamento(){}

void Pagamento::setVencimento(const Data& vencimento){
  this->vencimento = vencimento;
}

Data Pagamento::getVencimento(){
  return this->vencimento;
}

void Pagamento::setPagamento(const Data& pagamento){
  this->pagamento = pagamento;
}

Data Pagamento::getPagamento(){
  return this->pagamento;
}

void Pagamento::setChave(){
  string chave = tipo+vencimento.printData()+pagamento.printData();
  this->chave.setChave(chave);

}

string Pagamento::getChave(){
  return this->chave.getChave();
}

void Pagamento::setDescricao(const string& descricao){
  this->descricao = descricao;
}

string Pagamento::getDescricao(){
  return this->descricao;
}

void Pagamento::setTipo(const int& tipo){
  switch (tipo){
    case 1:
      this->tipo = "Agua";
    break;

    case 2:
      this->tipo = "Luz";
    break;

    case 3:
      this->tipo = "Aluguel";
    break;

    case 4:
      this->tipo = "Telefone";
    break;

    case 5:
      this->tipo = "Produtos de limpeza";      
    break;

    case 6:
      this->tipo = "Manutenção de Equipamentos";      
    break;

    case 7:
      this->tipo = "Material de Escritorio";      
    break;

    case 8:
      this->tipo = "Material de Atendimento";      
    break;
  }
}

string Pagamento::getTipo(){
  return this->tipo;
}

void Pagamento::setUsuario(const string& usuario){
  this->usuario = usuario;
}

string Pagamento::getUsuario(){
  return this->usuario;
}

ostream& operator <<(ostream& out, const Pagamento& pgt){
  out << pgt.chave << "\n" << pgt.tipo << "\n";
  out << pgt.vencimento << "\n" << pgt.pagamento << "\n";
  out << pgt.usuario << "\n" << pgt.descricao << endl;
  return out;
}

istream& operator >>(istream& in, Pagamento& pgt){
  in >> pgt.chave;
  in >> pgt.tipo;
  in >> pgt.vencimento;
  in >> pgt.pagamento;
  in >> pgt.usuario;
  in.ignore();
  getline(in, pgt.descricao);
  return in;

}