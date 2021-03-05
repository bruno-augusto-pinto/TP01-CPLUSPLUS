#include "pessoa.hpp"

Pessoa::Pessoa(){}

Pessoa::Pessoa(const string& nome, const string& cpf):nome(nome), CPF(cpf){}

Pessoa::~Pessoa(){}

void Pessoa::setNome(const string& nome){
  this->nome = nome;
}

void Pessoa::setCPF(const string& CPF){
  this->CPF = CPF;
}

string Pessoa::getNome(){
  return this->nome;
}

string Pessoa::getCPF(){
  return this->CPF;
}

void Pessoa::setChave(const string& chave){
  this->chave.setChave( chave );
}

void Pessoa::setChave(){
  this->chave.setChave(CPF);
}

string Pessoa::getChave(){
  return this->chave.getChave();
}

ostream& operator <<(ostream& out, const Pessoa& pessoa){
  out << pessoa.chave << "\n" <<  pessoa.nome << "\n" << pessoa.CPF;
  return out;
}

istream& operator >>(istream& in, Pessoa& pessoa){
  in >> pessoa.chave;
  in >> pessoa.nome; 
  in >> pessoa.CPF; 
  return in;
}