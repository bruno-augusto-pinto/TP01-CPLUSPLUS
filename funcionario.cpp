#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(const Pessoa& pessoa, const char tipo):pessoa(pessoa), tipo(tipo){}

Funcionario::~Funcionario(){}

void Funcionario::setTipo(const char& tipo){
  this->tipo = tipo;
}

char Funcionario::getTipo(){
  return this->tipo;
}

ostream& operator <<(ostream& out, const Funcionario& funcionario){
  out << funcionario.pessoa << funcionario.tipo << endl;
  return out;
}

istream& operator >>(istream& in, Funcionario& funcionario){
  in >> funcionario.pessoa;
  in >> funcionario.tipo;
  return in;
}