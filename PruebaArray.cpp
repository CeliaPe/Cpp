#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <utility>
using namespace std;

int* crearListaAleatoria(int tama){
  srand(time(NULL));
  int numero;
  int* ptrArray = new int[tama];
  for (int i = 0 ; i < tama ; i++){
    numero = rand()%10+1;
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
bool estaEnLista(int* ptrLista, int tama, int elemento){
  bool esta = false;
  for (int i = 0 ; i < tama && !esta ; i++){
    if (ptrLista[i] == elemento) esta = true;
  }
  return esta;
}
/*
int* listaSinRepetidos (int* ptrLista, int tama){
  int* ptrSinRepetidosLista = new int[tama];
  int tamaSin = 0;
  bool esta;
  for (int i = 0 ; i < tama ; i++){ // Recorro la lista inicial.
    esta = true;
    for (int j = 0 ; j < tamaSin+1 && esta ; j++){ //Para cada elemento de la inicial compruebo si está en la nueva.
      // ¿Está el elmento ptrLista[i] en ptrSinRepetidosLista? -> Función!
      esta = estaEnLista(ptrSinRepetidosLista,tamaSin+1,ptrLista[i]);
    }
    if (!esta){	// Si no está lo añado.
        ptrSinRepetidosLista[tamaSin] = ptrLista[i];
        tamaSin++;
      }
  }
  return ptrSinRepetidosLista;
}
*/
pair<int*,int> listaSinRepetidos (int* ptrLista, int tama){
  int* ptrSinRepetidosLista = new int[tama];
  int tamaSin = 0;
  bool esta;
  for (int i = 0 ; i < tama ; i++){ // Recorro la lista inicial.
    esta = true;
    for (int j = 0 ; j < tamaSin+1 && esta ; j++){ //Para cada elemento de la inicial compruebo si está en la nueva.
      // ¿Está el elmento ptrLista[i] en ptrSinRepetidosLista? -> Función!
      esta = estaEnLista(ptrSinRepetidosLista,tamaSin+1,ptrLista[i]);
    }
    if (!esta){	// Si no está lo añado.
        ptrSinRepetidosLista[tamaSin] = ptrLista[i];
        tamaSin++;
      }
  }
  return {ptrSinRepetidosLista,tamaSin};
}
pair<int*,int> unirListas(int* ptrLista1, int tama1, int* ptrLista2, int tama2){
	int tamaUnion = tama1+tama2;
	int* ptrListaUnion = new int[tamaUnion];
	int i;
	for (i = 0 ; i < tama1 ; i++ ){
		ptrListaUnion[i] = ptrLista1[i];
	}
	for (int j = 0 ; j < tama2 ; i++, j++){
		ptrListaUnion[i] = ptrLista2[j];
	}
	return {ptrListaUnion,tamaUnion};
}
int mayorDeDos(int uno, int dos){
	int mayor = uno;
	if (dos > uno) mayor = dos;
	return mayor;
}
pair<int*,int> interseccionListas (int* ptrLista1, int tama1, int* ptrLista2, int tama2){
  int tamaMaxInter = mayorDeDos(tama1,tama2); // Una intersección de listas nunca puede ser dar una lista mayor que la mayor de las listas que la componen.
  int* ptrListaInterseccion= new int[tamaMaxInter];
  int tamaInt = 0;
  int* ptrLista1NoRep = new int[tama1];
  int tama1NoRep;
  bool esta;
  pair <int*,int> sinRepetir;
  // Antes de empezar elimino los repetidos de la primera lista:
  sinRepetir = listaSinRepetidos(ptrLista1,tama1);
  ptrLista1NoRep = sinRepetir.first;
  tama1NoRep = sinRepetir.second;
  for (int i = 0 ; i < tama1NoRep ; i++){ // Recorro la primera.
    esta = false;
    for (int j = 0 ; j < tama2 && !esta ; j++){ // Para cada elemento de la inicial compruebo si está en la segunda.
      esta = estaEnLista(ptrLista2,tama2,ptrLista1NoRep[i]);
    }
    if (esta){	// Si está es que aparece en las dos listas, lo añado.
        ptrListaInterseccion[tamaInt] = ptrLista1NoRep[i];
        tamaInt++;
      }
  }
  return {ptrListaInterseccion,tamaInt};
}


int main(){

  int* ptrArray1;
  int* ptrArray2; // Array invertido.
  int* ptrArray3; // Array ordenado.
  int tama = 5;
  pair <int*,int> sinRepetir;
  pair <int*,int> pairUnion;
  pair <int*,int> pairInterseccion;

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
  cout << "Lista sin repetidos: ";
  sinRepetir = listaSinRepetidos(ptrArray1,tama);
  imprimirLista(sinRepetir.first,sinRepetir.second);
  cout << "Unir listas: " << endl;
  ptrArray2 = crearListaAleatoria(tama);
  pairUnion = unirListas(ptrArray1, tama, ptrArray2,tama);
  cout << "Primera lista: ";
  imprimirLista(ptrArray1,tama);
  cout << "Segunda lista: ";
  imprimirLista(ptrArray2,tama);
  cout << "Lista unión: ";
  imprimirLista(pairUnion.first,pairUnion.second);
  cout << "Lista unión sin repetidos: "; //Se puede llamar a listaSinRepetidos dentro de la unión para que el resultado sea directamente sin repetidos.
  sinRepetir = listaSinRepetidos(pairUnion.first,pairUnion.second);
  imprimirLista(sinRepetir.first,sinRepetir.second);
  cout << "Lista intersección: ";
  pairInterseccion = interseccionListas(ptrArray1, tama, ptrArray2,tama);
  imprimirLista(pairInterseccion.first,pairInterseccion.second);
  return 0;
}
