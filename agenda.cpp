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

Data Agenda::getData(){
  return this->data;
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

string Agenda::getPaciente(const int& codigo){
  return this->paciente[codigo];
}

bool Agenda::getDisponibilidade(const int& codigo){
  return this->disponibilidade[codigo];
}

string Agenda::getHorario(const int& codigo){
  return this->horario[codigo];
}

void Agenda::setChave(){
  string chave = funcionario + ":" + std::to_string(data.getDia()) + "/" + std::to_string(data.getMes()) + "/" + std::to_string(data.getAno());
  this->chave.setChave(chave);
}

string Agenda::getChave(){
  return this->chave.getChave();
}

void Agenda::setUsuario(const string& usuario, const int& codigo){
  this->usuario[codigo] = usuario;
}

string Agenda::getUsuario(const int& codigo){
  return this->usuario[codigo];
}

void Agenda::imprimeAgenda(){
    printf("|%6s|%7s|%10s|", "CODIGO", "HORARIO", "DISPONIBILIDADE");
    cout << endl;
    string disponibilidade;
    for (int i = 0; i < 5; i++){
        if (this->getDisponibilidade(i)){
            disponibilidade = "DISPONIVEL";
        }else{
            disponibilidade = "INDISPONIVEL";
        }
        printf("|%6i|%7s|%10s|", i, this->getHorario(i).c_str(), disponibilidade.c_str());
        cout << endl;
    }
}

ostream& operator <<(ostream& out, const Agenda& agenda){
  out << agenda.chave << "\n" << agenda.data << "\n" << agenda.funcionario;
  for (int i = 0; i < 5; i++){
    out << "\n" << agenda.codigo[i] << "\n" << agenda.horario[i] << "\n";
    out << agenda.disponibilidade[i] << "\n" << agenda.paciente[i] << "\n";
    out << agenda.usuario[i];
  }
  out << endl;
  return out;
}

istream& operator>>(istream& in, Agenda& agenda){
  in >> agenda.chave;
  in >> agenda.data; 
  in >> agenda.funcionario;
  for (int i = 0; i < 5; i++){
    //if (!agenda.disponibilidade[i]) {
      in >> agenda.codigo[i];
      in >> agenda.horario[i];
      in >> agenda.disponibilidade[i];
      in >> agenda.paciente[i];
      in >> agenda.usuario[i];
    //}
  }
  return in;
}