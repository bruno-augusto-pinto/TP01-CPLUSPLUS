#ifndef data_hpp
#define data_hpp

#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

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

        int getDia();

        int getMes();

        int getAno();

        string printData();

        friend ostream& operator <<(ostream&, const Data&);

        friend istream& operator >>(istream&, Data&);
};

#endif