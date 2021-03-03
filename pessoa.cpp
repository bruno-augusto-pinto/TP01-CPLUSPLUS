#include "pessoa.hpp"

Pessoa::Pessoa(){}

Pessoa::Pessoa(const char nome[12], const char cpf[10]):nome((char*)nome), CPF((char*)cpf){}

Pessoa::~Pessoa(){}

void Pessoa::setNome(const char nome[12]){
  this->nome = (char*)nome;
}

void Pessoa::setCPF(const char CPF[10]){
  this->CPF = (char*)CPF;
}

string Pessoa::getNome(){
  return this->nome;
}

char* Pessoa::getCPF(){
  return this->CPF;
}

ostream& operator <<(ostream& out, const Pessoa& pessoa){
  out << pessoa.nome << "\n" << pessoa.CPF << endl;
  return out;
}

istream& operator >>(istream& in, Pessoa& pessoa){
  in >> pessoa.nome; 
  in >> pessoa.CPF; 
  return in;
}