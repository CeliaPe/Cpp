#include <iostream>
using namespace std;

void solicitarContrasena(string clave){
  string palabra;
  int i;
  /* // Cuando el pulpo solo quiere comer.
   do{
     cout << " Quiero crustaceos..." ;
     cin >> palabra;
   } while (clave != palabra);
   */
   /* // Cuando el pulpo se cabrea en cuanto no come.
   cout << "Quiero comer crustaceos..." ;
   cin >> palabra;
   while(clave != palabra){
     cout << "Eres tonto? Yo lo que quiero es comer crustaceos..." ;
     cin >> palabra;
  }*/
  //Cuando el pulpo se va cabreando poco a poco.
  cout << "Quiero comer crustaceos..." ;
  cin >> palabra;
  for(i = 0 ; clave != palabra && i < 3 ; i++){
    cout << "No me puedes dar mejor crustaceos..." ;
    cin >> palabra;
  }
  for( ; clave != palabra && i < 10 ; i++){
    cout << "Es que eres tonto? Que lo que quiero son crustaceos!!!" ;
    cin >> palabra;
  }
  if (clave != palabra) cout << "*El pulpo se cabreo y se fue*";
}
int aBase8 (int numero){
  int decenas;
  int unidades;
  if (numero > 64){
    cout << "No estamos preparados para trabajar la recurrencia todavía...";
    numero = -1;
  }
  else{
    unidades = numero%8;
    decenas = numero/8;
    numero = decenas*10 + unidades;
  }
  return numero;
}
void imprimirLista (string lista[], int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << lista[i] << endl;
  }
}
void imprimirLista (char lista[], int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << lista[i] << endl;
  }
}
void pasarLista (string lista[], int tama, char listaFaltas[]){
  string respuesta;

  for (int i = 0 ; i < tama ; i++){
    cout << "Está " << lista[i] << " en clase?"<< endl;
    cin >> respuesta;
    if (respuesta == "si") listaFaltas[i] = 'V';
    else listaFaltas[i] = 'F';
  }
}

int main() {
  string contrasena = "crustaceo";
  int numero;
  int numeroBase8;
  int tamaLista = 5;
  string listaPulpos[] = {"A" , "B", "C", "D", "E"};
  char listaFaltas[tamaLista];

  cout << "Celia Pedregosa" << endl;
// Dar de comer al pulpo.
  solicitarContrasena(contrasena);
// Pasar número a base8.
  cout << "Introduce un numero: ";
  cin >> numero;
  numeroBase8 = aBase8(numero);
  cout << numeroBase8 << endl;
// Pasar lista.
imprimirLista(listaPulpos, tamaLista);
cout << endl;
pasarLista (listaPulpos, tamaLista, listaFaltas);
cout << endl;
imprimirLista(listaFaltas, tamaLista);


  return 0;
}
