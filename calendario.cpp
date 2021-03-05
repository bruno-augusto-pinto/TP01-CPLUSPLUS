//https://www.cplusplus.com/reference/ctime/tm/

#include "calendario.hpp"

Calendario::Calendario(){}

Calendario::~Calendario(){}

int Calendario::numerodoDia(int dia, int mes, int ano){
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  ano -= mes < 3;
  return (ano+ano/4 - ano/100 + ano/400 + t[mes-1]+dia) % 7;
}

string Calendario::getNomeMes(int mes){
  return this->mes[mes];
}

int Calendario::numerodeDias(int mes, int ano){
  if (mes == 2 && ano % 400 == 0 ){
    return this->totaldeDias[1];
  }else if (mes == 2) {
    return this->totaldeDias[0];
  }
  if (mes == (1 | 3 | 5 | 7 | 8 | 10 | 12) ){
    return this->totaldeDias[3];
  }
  return this->totaldeDias[2];
}

void Calendario::imprimeCalendario(int ano){
  printf ("         Calendario - %d\n\n", ano); 
  //int dias;

  //INDEX DO DIA DE 0 A 6
  int atual = numerodoDia(1, 1, ano);

  //i interage através de todos os meses
  //j interage através dos dias do mes(i)
  for (int i = 0; i < 12; i++){
    int dias = numerodeDias(i+1, ano);

    //IMPRIME O MES
    printf("\n --------------%s---------------\n", getNomeMes(i).c_str()); 

    //IMPRIME COLUNAS
    printf("  Dom  Seg  Ter  Qua  Qui  Sex  Sab\n");

    int k;
    for (k = 0; k < atual; k++)
      printf("     ");

    for (int j = 0; j <= dias; j++)
    {
      printf("%5d", j);
      if (++k > 6){
        k = 0;
        printf("\n");
      }
    }
    
    if (k)
      printf("\n");

    atual = k;
  }
}

void Calendario::imprimeMes(int ano, int mes){
   printf ("\n         Calendario - %d\n", ano); 
  //int dias;

  //INDEX DO DIA DE 0 A 6
  int atual = numerodoDia(1, 1, ano-1);

  //i interage através de todos os meses
  //j interage através dos dias do mes(i)
  for (int i = 0; i < 12; i++)
  {
    int dias = numerodeDias(i+1, ano-1);
    if (i == mes-1)
    {  
      //IMPRIME O MES
      printf("--------------%s---------------\n", getNomeMes(i).c_str()); 
      //IMPRIME COLUNAS
      printf("  Dom  Seg  Ter  Qua  Qui  Sex  Sab\n");
    }
      int k;
      for (k = 0; k < atual; k++)
        if (i == mes-1)
        {  
          printf("     ");
        }

      for (int j = 0; j <= dias; j++)
      {
        if (i == mes-1)
        {  
          printf("%5d", j);
        }
        if (++k > 6){
          k = 0;
          if (i == mes-1)
          {  
            printf("\n");
          }
        }
      }
      if (k)
        if (i == mes-1)
        {  
          printf("\n");
        }

      atual = k;
  }
}

int comparaHora(int dia, int mes, int ano){
  time_t hoje;
  struct tm * hojeinfo;
  time (&hoje);
  hojeinfo = localtime (&hoje);
  if ( (1900 + hojeinfo->tm_year) > ano || hojeinfo->tm_mon > mes || hojeinfo->tm_mday > dia){
    return 0;
  }
  return 1;
}

int getAnoAtual(){
  time_t hoje;
  struct tm * hojeinfo;
  time (&hoje);
  hojeinfo = localtime (&hoje);
  return (1900 + hojeinfo->tm_year);
}