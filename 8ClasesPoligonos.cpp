#include <iostream>
using namespace std;

// Class Triángulo
class Triangulo{
  private:
    double ladoA;
    double ladoB;
    double ladoC;
    string color;
    // Comprobar que la suma de los lados pequeños es mayor que el lado mayor.
    bool comprobarLongitudLados(double a, double b, double c){
      double max = a;
      double perimetro = a+b+c;
      if (max<b) max = b;
      if (max<c) max = c;
      return (perimetro-max > max);
    }
  public:
    Triangulo(double ladoA = 2, double ladoB = 2, double ladoC = 2, string color = "azul"){
      if (comprobarLongitudLados(ladoA,ladoB,ladoC)){
        if (ladoA > 0) this->ladoA = ladoA;
        if (ladoB > 0) this->ladoB = ladoB;
        if (ladoC > 0) this->ladoC = ladoC;
      } else {
        this->ladoA = 2;
        this->ladoB = 2;
        this->ladoC = 2;
      }
      this->color = color;
    }
    void setLadoA(double lado){
      if (comprobarLongitudLados(lado,this->ladoB,this->ladoC)){
        if (lado > 0) this->ladoA = lado;
      }
    }
    void setLadoB(double lado){
      if (comprobarLongitudLados(this->ladoA,lado,this->ladoC)){
        if (lado > 0) this->ladoB = lado;
      }
    }
    void setLadoC(double lado){
      if (comprobarLongitudLados(this->ladoA,this->ladoB,lado)){
        if (lado > 0) this->ladoC = lado;
      }
    }
    void imprimir(){
      cout << "Los lados del triangulo miden: " << this->ladoA << " " << this->ladoB << " " << this->ladoC << "." << endl;
    }
};


int main(){
  Triangulo t(2,2,40);
  t.setLadoA(3);
  t.setLadoB(3);
  t.setLadoC(3);
  t.imprimir();
  return 0;
}
