#include <iostream>
using namespace std;

bool muchaDiferencia(int diferencia, int num1, int num2){
  return (num1-num2 > diferencia);
}

bool meSirve (int numMax, int numMin, int num){
  return (numMin <= num && num <= numMax);
}
bool meSirveV2 (int numMax, int numMin, int num){
  return (numMin > num || num > numMax);
}

void imprimeBool (bool b){
  if (b == 0){
     cout << "False";
   } else {
     cout << "True";
   }

}

int main() {
  string saludo = "Hola!";
  string repetir;
  string contrasena = "aaaa";
  bool esCorrecto = false;
  bool diferencia;
  int edad = 26, edadIntroducida;
  double suma;
  bool ok;
  int numM, numm, num;

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

  /*cout << "¿Cuantos anios tienes? ";
  cin >> edadIntroducida;

  if (edadIntroducida >= edad){
    cout << "Eres un viejo.";
  } else {
    cout << "Eres un bb.";
  }

  diferencia = muchaDiferencia(5,edadIntroducida,edad);
  if (diferencia){
    cout << "Hay mucha diferencia de edad.";
  }*/

  /*Deberes 19.1.2022:
  - Crear función de valor absoluto (quitar signos).
  - Arreglar la función muchaDiferencia() para que funcione con cualquier edad (mayor o menor que la tuya).
  */

  /* // While y Do While
  repetir = "";
  while (repetir != contrasena){
    cout << "Introduce la contraseña: ";
    cin >> repetir;
  }

  do{
    cout << "Introduce la contraseña: ";
    cin >> repetir;
  } while (repetir != contrasena);
  */

  /* // For
  suma = 0;
  for (int i = 0 ; i <= 500 ; i+= 2){
    suma += i;
  }
  cout << "La suma de los 100 primeros números es: " << suma << endl;
  suma = 0;
  for (int i = 1 ; i <= 500 ; i++){
    if (i%2 == 0){
      suma += i;
    }
  }
  cout << "La suma de los 100 primeros números es: " << suma << endl;

  int arr[] = {10,20,30,40};
  for  (int i : arr){
    cout << i << endl;
  }*/

  numM = 30;
  numm = 10;
  cout << "Introduce un número; ";
  cin >> num;
  ok = meSirveV2 (numM,numm,num);
  imprimeBool(ok);

  return 0;
}
