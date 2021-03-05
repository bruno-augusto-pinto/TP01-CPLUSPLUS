#include "agenda.hpp"

Agenda::Agenda(){
  horario[0] = "08H-10H";
  horario[1] = "10H-12H";
  horario[2] = "13H-15H";
  horario[3] = "15H-17H";
  horario[4] = "17H-19H";
  for (unsigned i = 0; i < 5; i++){
    disponibilidade[i] = true;
    codigo[i] = i;
  }
}

Agenda::Agenda(const int& dia, const int& mes, const int& ano):data(dia, mes, ano)
{
  horario[0] = "08H-10H";
  horario[1] = "10H-12H";
  horario[2] = "13H-15H";
  horario[3] = "15H-17H";
  horario[4] = "17H-19H";
  for (unsigned i = 0; i < 5; i++){
    disponibilidade[i] = true;
    codigo[i] = i;
  }
}

Agenda::~Agenda(){}

void Agenda::setData(const Data& data){
  this->data = data;
}

void Agenda::setDisponibilidade(const bool& disponibilidade, const int& codigo){
  this->disponibilidade[codigo] = disponibilidade;
}

void Agenda::setPaciente(const string& paciente, const int& codigo){
  this->paciente[codigo] = paciente;
}

void Agenda::setFuncionario(const string& funcionario){
  this->funcionario = funcionario;
}

bool Agenda::getDisponibilidade(const int& codigo){
  return this->disponibilidade[codigo];
}

ostream& operator <<(ostream& out, const Agenda& agenda){
  out << agenda.data << "\n" << agenda.funcionario << "\n";
  for (int i = 0; i < 5; i++){
    out << agenda.codigo[i] << "\n" << agenda.horario[i] << "\n";
    out << agenda.disponibilidade[i] << agenda.paciente[i] << endl;
  }
  return out;
}

istream& operator>>(istream& in, Agenda& agenda){
  in >> agenda.data; 
  in >> agenda.funcionario;
  for (int i = 0; i < 5; i++){
    in >> agenda.codigo[i];
    in >> agenda.horario[i];
    in >> agenda.disponibilidade[i];
    in >> agenda.paciente[i];
  }
  return in;
}