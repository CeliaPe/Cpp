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

void imprimirArray(int array[20], int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << array[i] << endl;
  }
}

int main(){
  int numJuegos = 100;
  string juegos[numJuegos];

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

  cout << sizeof(juegos) << endl;












  return 0;
}
