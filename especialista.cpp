#include "especialista.hpp"

//Especialista::Especialista(){}

Especialista::Especialista(const string& nome, const string& cpf, const char tipo):Funcionario(nome, cpf, tipo){}

Especialista::~Especialista(){}

/*void Especialista::setNome(const string& nome){
  this->funcionario.setNome(nome);
}

void Especialista::setCPF(const string& cpf){
  this->funcionario.setCPF(cpf);
}

string Especialista::getNome(){
  return this->funcionario.getNome();
}

char* Especialista::getCPF(){
  return this->funcionario.getCPF();
}*/

void Especialista::setTipo(const char& tipo){
  this->funcionario.setTipo(tipo);
}

char Especialista::getTipo(){
  return this->funcionario.getTipo();
}

void Especialista::setAgenda(const Agenda& agenda){
  this->agenda = agenda;
}

Agenda Especialista::getAgenda(){
  return this->agenda;
}

ostream& operator <<(ostream& out, const Especialista& especialista){
  out << especialista.funcionario << endl;
  return out;
}

istream& operator >>(istream& in, Especialista& especialista){
  in >> especialista.funcionario; 
  return in;
}