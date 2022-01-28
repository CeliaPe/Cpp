// Referencias y punteros.

#include <iostream>
using namespace std;

int main() {
  string juego = "Tetris";
  string &ocio = juego;
  string juegos[5];

  cout << juego << endl; // Imprime Tetris.
  cout << ocio << endl; // Imprime Tetris.
  cout << &ocio << endl; // Imprime la dirección.
  cout << &juego << endl; // Imprime la dirección.

  ocio = "pokemon";

  cout << ocio << endl;
  cout << juego << endl;

  cout << &juegos << endl;
  cout << &juegos[0] << endl;
  cout << &juegos[1] << endl;
  cout << &juegos[2] << endl;
  cout << &juegos[3] << endl;
  cout << &juegos[4] << endl;






  return 0;
}
