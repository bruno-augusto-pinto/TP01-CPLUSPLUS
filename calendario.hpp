#ifndef calendario_hpp
#define calendario_hpp

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std; 

class Calendario{
    private:
      const vector<string> mes {
        "Janeiro",
        "Fevereiro",
        "Março",
        "Abril",
        "Maio",
        "Junho",
        "Julho",
        "Agosto",
        "Setembro",
        "Outubro",
        "Novembro",
        "Dezembro",
      };

      const vector<int> totaldeDias{
        28,
        29,
        30,
        31,
      };
      
    public:
        Calendario();

        ~Calendario();

        int numerodoDia(int, int, int);

        string getNomeMes(int);

        int numerodeDias(int, int);

        void imprimeCalendario(int);

        friend ostream& operator<<(ostream&, const Calendario&);

        friend istream& operator>>(istream&, Calendario&);
};

#endif