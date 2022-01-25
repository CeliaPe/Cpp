#include <iostream>
using namespace std;

/* VOLVEMOS MAÑANA
void mostrarArray (string array[]){
  for(int i = 0 ; i < array.size() ; i++){
    cout << i << " = " << array[i] << endl;
  }
}*/

int main(){
  int numJuegos = 10;
  string juegos[numJuegos];

  for(int i = 0 ; i < numJuegos ; i++){
    string jue;
    cout << "Introduce el nombre de un juego: ";
    cin >> jue;
    juegos[i] = jue;
  }

  juegos[4] = "Tetris";

  for(int i = 0 ; i < numJuegos ; i++){
    cout << "Juegos" << i << " = " << juegos[i] << endl;
  }





  //mostrarArray(juegos);

  return 0;
}
