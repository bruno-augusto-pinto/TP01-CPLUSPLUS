#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(const char* nome, const char* cpf, const char tipo):Pessoa(nome, cpf), tipo(tipo){}

Funcionario::~Funcionario(){}

void Funcionario::setNome(const char* nome){
  this->pessoa.setNome(nome);
}

void Funcionario::setCPF(const char* cpf){
  this->pessoa.setCPF(cpf);
}

string Funcionario::getNome(){
  return this->pessoa.getNome();
}

char* Funcionario::getCPF(){
  return this->pessoa.getCPF();
}

void Funcionario::setTipo(const char& tipo){
  this->tipo = tipo;
}

char Funcionario::getTipo(){
  return this->tipo;
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