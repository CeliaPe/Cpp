#include <iostream>
using namespace std;

int multiplicaX5 (int num){
  return num*5;
}

void meMultiplicoX5 (int &num){
  num = num*5;
  cout << "Num en la funcion vale: " << num << endl;
}

void subirNota (int notas[3] , int posicion , int nuevaNota){
  notas[posicion] = nuevaNota;
}

void imprimirArray(int array[], int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << array[i] << endl;
  }
}

void rellenarArray (int nume[], int tama){
  for (int i = 0 ; i < tama ; i++){
    nume[i] = i;
  }
}

void sumarDe4en4(int nume[], int tama, int sumaNum[]){
  for (int i = 0 ; i < tama ; i+=4){
    sumaNum[i/4] = i + i+1 + i+2 + i+3;
  }
}

int main(){
  int num = 10;
  string juegos[num];
  int numeros[num];

  int numero1 = 2;
  int numero2 = 0;
  int notas[] = {8,4,9};

  /*cout << "¿Cuántos juegos quieres introducir?";
  cin >> numJuegos;

  for(int i = 0 ; i < numJuegos ; i++){
    string jue;
    cout << "Introduce el nombre de un juego: ";
    cin >> jue;
    juegos[i] = jue;
  }

  juegos[4] = "Tetris";

  for(int i = 0 ; i < numJuegos ; i++){
    cout << "Juegos" << i << " = " << juegos[i] << endl;
  }*/

  /*
  numero2 = multiplicaX5(numero1);
  cout << "El numero1 es " << numero1 << endl;
  cout << "El numero2 es " << numero2 << endl;

  meMultiplicoX5(numero1);
  cout << "El numero1 es " << numero1 << endl << endl;

  cout << "Notas original" << endl;
  imprimirArray(notas,3);
  cout << "Subimos la nota" << endl;
  subirNota(notas,1,9);
  cout << "Nota tras subir la nota" << endl;
  imprimirArray(notas,3);
  */

  //cout << sizeof(numeros) << endl;

  // EJERCICIO

  int tama = 100;
  int nume[tama];
  int sumaNum[tama/4];
  cout <<  "Rellenamos el array con los 100 primeros números." << endl;
  rellenarArray (nume, tama);
  cout <<  "Sumamos de 4 en 4." << endl;
  sumarDe4en4(nume, tama, sumaNum);
  /*cout << "Otra forma de hacerlo [F]" << endl;
  int suma = 0;
  int contador = 0;
  for (int i = 0 ; i < tama ; i++){
    suma += i;
    contador ++;
    if (contador % 4 == 0){
      sumaNum[i/4] = suma;
      suma = 0;
    }
  }*/
  cout <<  "Imprimimos" << endl;
  imprimirArray(sumaNum,tama/4);











  return 0;
}
