// Referencias y punteros.

#include <iostream>
using namespace std;

int suma10 (int num){
  num += 10;
  return num;
}
int suma10 (int* ptrNum){
  *ptrNum += 10;
  return *ptrNum;
}

double* rellenarArrayNotas (int tama){
  double* array = new double[tama];
  string line;
  for (int i = 0 ; i < tama ; i++){
    cout << "Introduce una nota: ";
    getline(cin,line);
    array[i] = stoi(line);
  }
  return array;
}
double* subirNotaArray (double* array, int tama, int porcentaje){
// [...]
}
string* rellenarArray (int tama){
  string* array = new string [tama];
  for (int i = 0 ; i < tama ; i++){
    cout << "Introduce un color: ";
    getline(cin,array[i]);
  }
  return array;
}
void imprimirArray(string* array, int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << array[i] << endl;
  }
}
void imprimirArray(double* array, int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << array[i] << endl;
  }
}

int main() {
  //// Tercera parte
  string* colores = NULL;
  double* notas = NULL;
  string line;
  int numero;

  cout << "Numero de colores y notas: " ;
  getline(cin,line);
  numero = stoi(line);

  /*colores = new string[numero];
  colores = rellenarArray(numero);
  imprimirArray(colores, numero);*/

  //notas = new double[numero];
  notas = rellenarArrayNotas(numero);
  imprimirArray (notas, numero);




  delete [] colores;
  colores = NULL;

  //// Segunda parte
  /*
  int numero = 10;
  int resultado;

  cout << "Imprimir numero: " << numero << endl;
  resultado = suma10(numero);
  cout << "Imprimir numero depues de sumar10(int): " << numero << endl;
  cout << "Imprimir resultado depues de sumar10(int): " << resultado << endl;

  cout << "Imprimir numero: " << numero << endl;
  resultado = suma10(&numero);
  cout << "Imprimir numero depues de sumar10(*int): " << numero << endl;
  cout << "Imprimir resultado depues de sumar10(*int): " << resultado << endl;
  */

  //// Primera parte

  /*string juego = "Tetris";
  string &ocio = juego;
  int num = 5;
  //string juegos[5];
  string* ptrJuego = &juego;
  int* ptrNum = &num;*/


  /*cout << juego << endl; // Imprime Tetris.
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
  */

  /*cout << "Imprimo el juego: " << juego << endl;
  cout << "Imprimo el &juego: " << &juego << endl;
  //cout << "Imprimo el *juego: " << *juego << endl;
  cout << "Imprimo el ocio: " << ocio << endl;
  cout << "Imprimo el &ocio: " << &ocio << endl << endl;
  cout << "Imprimo el ptrJuego: " << ptrJuego << endl;
  cout << "Imprimo el &ptrJuego: " << &ptrJuego << endl;
  cout << "Imprimo el *ptrJuego: " << *ptrJuego << endl << endl;
  cout << "Imprimo el num: " << num << endl;
  cout << "Imprimo el *ptrNum: " << *ptrNum << endl;
  cout << "Imprimo el &num: " << &num << endl;
  cout << "Imprimo el ptrNum: " << ptrNum << endl << endl;*/

  return 0;
}
