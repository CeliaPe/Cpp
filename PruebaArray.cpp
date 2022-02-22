#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int* crearListaAleatoria(int tama){
  srand(time(NULL));
  int numero;
  int* ptrArray = new int[tama];
  for (int i = 0 ; i < tama ; i++){
    numero = rand()%10;
    ptrArray[i] = numero;
  }
  return ptrArray;
}
void imprimirLista(int* ptrLista, int tama){
  for (int i = 0 ; i < tama ; i++){
    cout << ptrLista[i] << " ";
  }
  cout << endl;
}
void imprimirListaAlReves(int* ptrLista, int tama){
  for (int i = tama-1 ; i >= 0 ; i--){
    cout << ptrLista[i] << " ";
  }
  cout << endl;
}
void cambiarPorDobleLista(int* ptrLista, int tama, int pos){
  if (pos<tama){
    //Pensando que las posiciones se cuentan a partir de 1 y no de 0.
    ptrLista[pos-1] *= 2;
  }
}
//Devuelve el nuevo tamaño
int eliminarPosicionLista(int* ptrLista, int tama, int pos){
  //Pensando que las posiciones se cuentan a partir de 1 y no de 0.
  for (int i = (pos-1) ; i < tama ; i++){
    ptrLista[i]=ptrLista[i+1];
  }
  return tama-1;
}
int* invertirLista(int* ptrLista, int tama){
  int* ptrNuevaLista = new int[tama];
  for (int i = 0, j = tama-1 ; i < tama ; i++, j--){
    ptrNuevaLista[i] = ptrLista[j];
  }
  return ptrNuevaLista;
}
int* copiarLista (int* ptrLista, int tama){
  int* ptrNuevaLista = new int[tama];
  for (int i = 0 ; i < tama ; i++){
    ptrNuevaLista[i] = ptrLista[i];
  }
  return ptrNuevaLista;
}
int posMinimoLista(int* ptrLista, int tama){
  int posicion = 0;
  int minimo = ptrLista[0];
  for (int i = 1 ; i < tama ; i++){
    if (ptrLista[i]<minimo){
      minimo = ptrLista[i];
      posicion = i;
    }
  }
  return posicion;
}
int* ordenarLista (int* ptrLista, int tama){
  int* ptrCopiaLista = copiarLista(ptrLista,tama);
  int* ptrOrdenadaLista = new int[tama];
  int nuevoTama = tama;
  int posicionMin;
  for (int i = 0 ; i < tama ; i++){
    posicionMin = posMinimoLista(ptrCopiaLista,nuevoTama);
    ptrOrdenadaLista[i] = ptrCopiaLista[posicionMin];
    //Es posicionMin+1 porque la funcion eliminarPosicionLista está pensada como si las posiciones fueran ordinales.
    nuevoTama = eliminarPosicionLista(ptrCopiaLista,nuevoTama,posicionMin+1);
  }
  return ptrOrdenadaLista;
}

int main(){

  int* ptrArray1;
  int* ptrArray2; // Array invertido.
  int* ptrArray3; // Array ordenado.
  int tama = 5;
  cout << "Celia Pedregosa" << endl;
  cout << "Generar lista aleatoria" << endl;
  ptrArray1 = crearListaAleatoria(tama);
  imprimirLista(ptrArray1,tama);
  cout << "Cambiar por doble." << endl;
  cambiarPorDobleLista(ptrArray1,tama,3);
  imprimirLista(ptrArray1,tama);
  cout << "Eliminar una posicion de la Lista." << endl;
  tama = eliminarPosicionLista(ptrArray1,tama,2);
  imprimirLista(ptrArray1,tama);
  cout << "Imprimir lista al revés." << endl;
  imprimirListaAlReves(ptrArray1,tama);
  cout << "Guardar lista al revés en nueva lista." << endl;
  cout << "Lista nueva: ";
  ptrArray2 = invertirLista(ptrArray1,tama);
  imprimirLista(ptrArray2,tama);
  cout << "Lista antigua: ";
  imprimirLista(ptrArray1,tama);
  cout << "Lista ordenada: ";
  ptrArray3 = ordenarLista(ptrArray1,tama);
  imprimirLista(ptrArray3,tama);
  return 0;
}
