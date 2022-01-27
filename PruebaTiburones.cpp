#include <iostream>
#include <locale.h>
using namespace std;

int aniosADias (int anios){
  const int DIASENANIO = 365;
  return DIASENANIO*anios;
}

int aniosAMeses (int anios){
  const int MESESENANIO = 12;
  return MESESENANIO*anios;
}

int dientesCaidos(int anios){
  int meses;
  int total = 0;
  meses = aniosAMeses(anios);
  for(int  i = 0 ; i <= meses ; i += 5){
    total += i;
  }
  return total;
}

int dientesCaidosConTope(int anios , int maxAnios){
  int meses;
  int maxMeses;
  int total = 0;
  meses = aniosAMeses(anios);
  maxMeses = aniosAMeses(maxAnios);
  for(int  i = 0 ; i <= meses  && i < maxMeses; i += 5){
    total += i;
  }
  return total;
}

//aniosAMeses

int main(){

  setlocale(LC_ALL, "spanish");

  int aniosTiburon;
  int mesesTiburon;
  int diasTiburon;
  int totalDientes;
  int tope = 8;

  // Imprime tu nombre por pantalla.
  cout << "Celia" << endl;

  // Pregunta por pantalla cuántos años tienen el tiburón.
  cout << "Cuantos anios tiene el tiburon? ";
  cin >> aniosTiburon;
  cout << "El tiburon tiene " << aniosTiburon << " anios." << endl;

  // Partiendo de un número de años, calcula cuanto tiempo en días y cuánto
  // tiempo en meses ha pasado.
  diasTiburon = aniosADias(aniosTiburon);
  cout << "El tiburon tiene " << diasTiburon << " dias." << endl;
  mesesTiburon = aniosAMeses(aniosTiburon);
  cout << "El tiburon tiene " << mesesTiburon << " meses." << endl;

  // Cada 5 meses al tiurón se le caen tantos dientes como meses tenga, es
  // decir:
  // A los 5 meses se le caen 5 dientes.
  // A los 10 meses se le caen 10 dientes. En total se le han caido 15.
  // A los 15 meses se le caen 15 dientes. En total se le han caido 30.
  // Calcula cuántos dientes se le han caido al tiburón.
  totalDientes = dientesCaidos(aniosTiburon);
  cout << "Al tiburon se le han caido " << totalDientes << " dientes." << endl;

  // Si el tiburón tiene más de 8 años yano le quedan dientes que puedan caer.
  // Modifica la función anterior para que deje de sumar dientes caídos cuando
  // los meses lleguen a 8 años.
  totalDientes = dientesCaidosConTope(aniosTiburon , tope);
  cout << "Al tiburon se le han caido " << totalDientes << " dientes." << endl;

  totalDientes = dientesCaidosConTope(aniosTiburon , tope);
  cout << "Al tiburon se le han caido " << totalDientes << " dientes." << endl;

  return 0;
}
