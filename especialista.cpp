#include "especialista.hpp"

Especialista::Especialista(){}

Especialista::Especialista(const Funcionario& funcionario):funcionario(funcionario){}

Especialista::~Especialista(){}

/*void Especialista::setAgenda(const Agenda& agenda){
  this->agenda = agenda;
}

Agenda Especialista::getAgenda(){
  return this->agenda;
}*/

ostream& operator <<(ostream& out, const Especialista& especialista){
  out << especialista.funcionario << endl;
  return out;
}

istream& operator >>(istream& in, Especialista& especialista){
  in >> especialista.funcionario; 
  return in;
}