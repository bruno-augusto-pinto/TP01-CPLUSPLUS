#include "folhadeponto.hpp"

FolhadePonto::FolhadePonto(){
  tamanho = 0;
}

FolhadePonto::~FolhadePonto(){}

void FolhadePonto::setTamanho(){
  this->tamanho++;
}

int FolhadePonto::getTamanho(){
  return this->tamanho;
}

void FolhadePonto::setChave(const string& funcionario){
  this->chave.setChave(funcionario);
}

string FolhadePonto::getChave(){
  return this->chave.getChave();
}

void FolhadePonto::setObservacao(const string& obs){
  this->observacao.push_back(obs);
}

string FolhadePonto::getObservacao(const int& codigo){
  return this->observacao[codigo];
}

void FolhadePonto::setData(const Data& data){
  this->data.push_back(data); 
}

Data FolhadePonto::getData(const int& codigo){
  return this->data[codigo];
}

bool FolhadePonto::checkData(Data data){
  for (Data dma : this->data){
    if (dma.printData().c_str() == data.printData().c_str()){
      return false;
    }
  }
  return true;
}

void FolhadePonto::imprimePonto(){
  cout << endl << "      FOLHA DE PONTO - " << this->chave << endl;
  printf("|%10s|%20s|", "DATA ", "OBSERVAÇÃO");
  for (int i = 0; i < this->getTamanho(); i++){
    cout << endl;
    printf("|%8s|%20s|", this->getData(i).printData().c_str(), this->getObservacao(i).c_str());
  }
  cout << endl << endl;
} 

ostream& operator <<(ostream& out, const FolhadePonto& folhadp){
  out << folhadp.chave << "\n" <<folhadp.tamanho;
  for (int i = 0; i < folhadp.tamanho; i++){
    out << "\n" << folhadp.data[i];
    out << "\n" << folhadp.observacao[i];
  }
  out << endl;
  return out;
}

istream& operator >>(istream& in, FolhadePonto& folhadp){
  in >> folhadp.chave;
  in >> folhadp.tamanho;
  for (int i = 0; i < folhadp.tamanho; i++){
    Data dTemp;
    in >> dTemp;
    folhadp.data.push_back(dTemp);
    string oTemp;
    in.ignore();
    getline(in, oTemp);
    folhadp.observacao.push_back(oTemp);
  }
  return in;
}