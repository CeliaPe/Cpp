#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Class Triangulo
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
    Triangulo(double ladoA = 0 , double ladoB = 0 , double ladoC = 0, string color = "azul"){
      this->ladoA = 2;
      this->ladoB = 2;
      this->ladoC = 2;
      setLados (ladoA,ladoB,ladoC);
      this->color = color;
      //Otra forma de hacerlo
      //if (comprobarLongitudLados(ladoA,ladoB,ladoC)){
      //  if (ladoA > 0) this->ladoA = ladoA;
      //  if (ladoB > 0) this->ladoB = ladoB;
      //  if (ladoC > 0) this->ladoC = ladoC;
      //} else {
      //  this->ladoA = 2;
      //  this->ladoB = 2;
      // this->ladoC = 2;
      //}
      //this->color = color;
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
    void setColor(string color){
      this->color = color;
    }
    double getLadoA(){
      return this->ladoA;
    }
    double getLadoB(){
      return this->ladoB;
    }
    double getLadoC(){
      return this->ladoC;
    }
    string getColor(){
      return this->color;
    }
    void setLados(double ladoA , double ladoB , double ladoC){
      if (comprobarLongitudLados(ladoA,ladoB,ladoC)){
        if (ladoA > 0) this->ladoA = ladoA;
        if (ladoB > 0) this->ladoB = ladoB;
        if (ladoC > 0) this->ladoC = ladoC;
      }
    }
    double perimetro(){
      return this->ladoA + this->ladoB + this->ladoC;
    }
    double area(){
      double sPer = this->perimetro()/2;
      double area = sqrt(sPer*(sPer-this->ladoA)*(sPer-this->ladoB)*(sPer-this->ladoC));
      return area;
    }
    void imprimirLados(){
      cout << "Los lados del triangulo miden: " << this->ladoA << " " << this->ladoB << " " << this->ladoC << "." << endl;
    }
    void imprimirColor(){
      cout << "Su color es: " << this->color << "." << endl;
    }
    void imprimirPerimetro(){
      cout << "Su perimetro es: " << this->perimetro() << "m." << endl;
    }
    void imprimirArea(){
      cout << "Su area es: " << this->area() << "m^2." << endl;
    }

    void imprimir(){
      this->imprimirLados();
      this->imprimirPerimetro();
      this->imprimirArea();
      this->imprimirColor();
    }
};
// Class Poligono
class Poligono{
  private:
    vector <double> lados;
  public:
    Poligono(vector <double> lados = {10,10,10,10}){
      setLados(lados);
    }
    void setLados (vector <double> lados){
      this->lados = lados;
    }
    vector <double> getLados(){
      return this->lados;
    }
    void setPosLado(int pos, double lado){
      // Comprobar que pos < numero de lados.
      if (pos < this->numeroLados()) this->lados[pos] = lado;
    }
    double getPosLado(int pos){
      return this->lados[pos];
    }
    int numeroLados(){
      return this->lados.size();
    }
    double perimetro(){
      double suma = 0;
      for (double elemento : this->lados){
        suma += elemento;
      }
      return suma;
    }
    double ladoMaximo(){
      int pos = posicionNumMayor():
      return getPosLado(pos);
    }
    int posicionNumMayor(){
      double max = this->lados[0];
      int posicion = 0;
      for (int i = 1 ; i < this->lados.size() ; i++){
        if (lados[i] > max){
           max = this->lados[i];
           posicion = i;
        }
      }
      return posicion;
    }
    void imprimir(){
      for (double elemento : this->lados){
        cout << elemento << endl;
      }
      cout << endl;
    }
};

int main(){
  vector <double> ladosTriangulo = {10,15,20};
  Poligono triangulo;

  triangulo.imprimir();
  triangulo.setLados(ladosTriangulo);
  triangulo.imprimir();
  triangulo.setPosLado(0,15);
  triangulo.imprimir();
  cout << triangulo.numeroLados();

  /*Triangulo t;
  t.setLadoA(3);
  t.setLadoB(3);
  t.setLadoC(3);
  t.setLados(10,15,20);
  t.setColor("amarillo");
  t.imprimir();*/
  return 0;
}
