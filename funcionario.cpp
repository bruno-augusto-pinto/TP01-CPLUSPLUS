#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(const string& nome, const char cpf[10]):nome(nome), CPF((char*)cpf){}

Funcionario::~Funcionario(){}

void Funcionario::setNome(const string& nome){
  this->nome = nome;
}

void Funcionario::setCPF(const char CPF[10]){
  this->CPF = (char*)CPF;
}

string Funcionario::getNome(){
  return this->nome;
}

char* Funcionario::getCPF(){
  return this->CPF;
}

ostream& operator <<(ostream& out, const Funcionario& funcionario){
  out << funcionario.nome << "\n" << funcionario.CPF << endl;
  return out;
}

istream& operator >>(istream& in, Funcionario& funcionario){
  in >> funcionario.nome; 
  in >> funcionario.CPF; 
  return in;
}