#ifndef data_hpp
#define data_hpp

#include <iostream>

using namespace std; 

class Data{
    private:
        int dia;
        int mes;
        int ano;

    public:
        Data();

        Data(const int&, const int&, const int&);

        ~Data();

        void setDia(const int&);

        void setMes(const int&);

        void setAno(const int&);

        friend ostream& operator <<(ostream&, const Data&);

        friend istream& operator >>(istream&, Data&);
};

#endif