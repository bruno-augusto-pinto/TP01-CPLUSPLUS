#include "chave.hpp"

Chave::Chave(){}

Chave::~Chave(){}

void Chave::setChave(const string& chave){
  this->chave = chave;
}

string Chave::getChave(){
  return this->chave;
}

ostream& operator<<(ostream& out, const Chave& chave){
  out << chave.chave;
  return out;
}

istream& operator>>(istream& in, Chave& chave){
  in >> chave.chave;
  return in;
}