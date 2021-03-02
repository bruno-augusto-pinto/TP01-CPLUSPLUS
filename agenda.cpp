#include "agenda.hpp"
//vector<list<vector>> 
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

Agenda::~Agenda(){}

void Agenda::setDisponibilidade(const bool& disponibilidade, const int& codigo){
  this->disponibilidade[codigo] = disponibilidade;
}

void Agenda::setUsuario(const Usuario& usuario, const int& codigo){
  this->usuario[codigo] = usuario;
}

//void Agenda::setPaciente(const Paciente&);

//void setPaciente(const String&);

bool Agenda::getDisponibilidade(const int& codigo){
  return this->disponibilidade[codigo];
}

//ostream& operator<<(ostream&, const Agenda&){}

//istream& operator>>(istream&, Agenda&){}