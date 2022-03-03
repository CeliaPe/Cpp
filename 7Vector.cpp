#include <iostream>
#include <vector>
using namespace std;

void mostrarVector (vector<int> vector){
  int i;
  cout << "[";
  for (i = 0 ; i < vector.size()-1 ; i++){
    cout << vector[i] << ", "; //vector.at(i)
  }
  cout << vector[i] << "]";
}

vector<int> rellenarVector(){
  vector<int> vector;
  int numero,tama;

  cout << "Cuantos numeros quiere introducir? ";
  cin >> tama;
  for (int i = 0 ; i < tama ; i++){
    cout << "Introduce un numero " << endl;
    cin >> numero;
    vector.push_back(numero);
  }
  return vector;
}

int main(){
  vector<int> miVector1;                    // Sin inicializar
  vector<string> miVectorS;                 // Sin inicializar
  vector<int> miVector2(10,2);              // Inicializa un vector de tama 10 relleno de 2s.
  vector<int> miVector3{1,2,3,4,5};         // Inicializa un vector con los valores introducidos.
  /*vector<int>*/ miVector3 = {1,2,3,4,5};

  miVectorS = {"La casa verde"};
  cout << miVectorS[0] << endl;

  miVector2 = rellenarVector();
  mostrarVector(miVector2);


  return 0;
}
