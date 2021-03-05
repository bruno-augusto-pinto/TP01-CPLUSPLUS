#include "data.hpp"

Data::Data(){}

Data::Data(const int& dia, const int& mes, const int& ano):dia(dia), mes(mes), ano(ano){}

Data::~Data(){}

void Data::setDia(const int& dia){
  this->dia = dia;
}

void Data::setMes(const int& mes){
  this->mes = mes;
}

void Data::setAno(const int& ano){
  this->ano = ano;
}

ostream& operator <<(ostream& out, const Data& data){
  out << data.dia << "\n" << data.mes << "\n" << data.ano << endl;
  return out;
}

istream& operator >>(istream& in, Data& data){
  in >> data.dia;
  in >> data.mes;
  in >> data.ano;
  return in;
}