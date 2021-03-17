#ifndef data_hpp
#define data_hpp

#include <iostream>

using namespace std; 

class Data{

    //DEFINIÇÃO DOS ATRIBUTOS PRIVADOS
    private:
        int dia;
        int mes;
        int ano;

    //DEFINIÇÃO DOS MÉTODOS PÚBLICOS
    public:
        Data();

        Data(const int&, const int&, const int&);

        ~Data();

        void setDia(const int&);

        void setMes(const int&);

        void setAno(const int&);

        int getDia();

        int getMes();

        int getAno();

        string printData();

        friend ostream& operator <<(ostream&, const Data&);

        friend istream& operator >>(istream&, Data&);
};

#endif