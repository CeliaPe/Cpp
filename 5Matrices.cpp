#include <iostream>
using namespace std;

int const TAMA = 10;

void rellenarMatrizCeros (int matriz [TAMA][TAMA], int nFil, int nCol){
  for (int i = 0 ; i < nFil ; i++){
    for (int j = 0 ; j < nCol ; j++){
      matriz [i][j] = 0;
    }
  }
}

int main(){
  int array[TAMA];
  int matriz[TAMA][TAMA];

  return 0;
}
