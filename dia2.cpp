#include <iostream>
using namespace std;

bool muchaDiferencia(int diferencia, int num1, int num2){
  return (num1-num2 > diferencia);
}

int main() {
  string saludo = "Hola!";
  string repetir;
  string contrasena = "aaaa";
  bool esCorrecto = false;
  bool diferencia;
  int edad = 26;
  int edadIntroducida;

  /*cout << "Imprimir por pantalla" << endl;
  cout << "Imprimir por pantalla\n";
  cout << "Comprobación de salto de línea";

  cout << saludo << endl;
  cout << saludo << "\n";
  */

  /*while (true){
    cout << "Introduce una palabra: ";
    cin >> repetir;
    cout << repetir << endl;
  }
  */

  /*while (!esCorrecto){
    cout << "Introduce la contraseña: ";
    cin >> repetir;
    if (repetir == contrasena){
      esCorrecto = true;
    }
  }

  repetir = "";
  while (repetir != contrasena){
    cout << "Introduce la contraseña: ";
    cin >> repetir;
  }*/

  cout << "¿Cuantos anios tienes? ";
  cin >> edadIntroducida;

  if (edadIntroducida >= edad){
    cout << "Eres un viejo.";
  } else {
    cout << "Eres un bb.";
  }

  diferencia = muchaDiferencia(5,edadIntroducida,edad);
  if (diferencia){
    cout << "Hay mucha diferencia de edad.";
  }

  /*Deberes 19.1.2022: 
  - Crear función de valor absoluto (quitar signos).
  - Arreglar la función muchaDiferencia() para que funcione con cualquier edad (mayor o menor que la tuya).
  */

  return 0;
}
