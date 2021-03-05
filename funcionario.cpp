#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(const string& nome, const string& cpf, const char tipo):Pessoa(nome, cpf), tipo(tipo){}

Funcionario::~Funcionario(){}

void Funcionario::setNome(const string& nome){
  this->pessoa.setNome(nome);
}

void Funcionario::setCPF(const string& cpf){
  this->pessoa.setCPF(cpf);
}

string Funcionario::getNome(){
  return this->pessoa.getNome();
}

string Funcionario::getCPF(){
  return this->pessoa.getCPF();
}

void Funcionario::setTipo(const char& tipo){
  this->tipo = tipo;
}

char Funcionario::getTipo(){
  return this->tipo;
}

void Funcionario::setChave(const string& chave){
  this->pessoa.setChave( chave );
}

void Funcionario::setChave(){
  this->pessoa.setChave();
}

string Funcionario::getChave(){
  return this->pessoa.getChave();
}


ostream& operator <<(ostream& out, const Funcionario& funcionario){
  out << funcionario.pessoa << "\n" << funcionario.tipo << endl;
  return out;
}

istream& operator >>(istream& in, Funcionario& funcionario){
  in >> funcionario.pessoa;
  in >> funcionario.tipo;
  return in;
}