#include <iostream>
#include <vector>
using namespace std;

void imprimirVector(vector<int> v){
  for (int i = 0 ; i < v.size() ; i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

class Persona{
  private:
    string nombre;
    string dni;
    int edad;
    bool vip;
  public: //private:
    bool esMultiplo(int numeroMultiplo, int numero){
      return (numeroMultiplo%numero==0);
    }
    int sumaVector(vector<int> numVip){
      int suma = 0;
      for (int i = 0 ; i < numVip.size() ; i++){
        suma += numVip[i];
      }
      return suma;
    }
    vector<int> solicitarNumeros (int cuantos){
      vector<int> v;
      int numero;
      for (int i = 0 ; i < cuantos ; i++){
        cout << "Intoduce un numero: ";
        cin >> numero;
        v.push_back(numero);
      }
      return v;
    }
    void setVip(vector<int> numVip){
      this->vip = false;
      //Primera oportunidad: Condición de suma multiplo de 11.
      int suma = sumaVector(numVip);
      if (this->esMultiplo(suma,11)) this->vip = true;
      //Segunda oportunidad: Si alguno de los números es multiplo de 13.
      else{
        bool multiplo13 = false;
        for (int i = 0 ; i < numVip.size() && !multiplo13; i++){
          if (this->esMultiplo(numVip[i],13)) multiplo13 = true;
        }
        if (multiplo13){
          vector<int> v = solicitarNumeros(2);
          suma += sumaVector(v);
          if (this->esMultiplo(suma,11)) this->vip = true;
        }
      }
    }
  public:
    Persona( vector<int> numVip, string nombre, string dni, int edad = 18){
      this->nombre = nombre;
      this->dni = dni;
      this->edad = edad;
      setVip(numVip);
    }
    string getNombre(){
      return this->nombre;
    }
    string getDni(){
      return this->dni;
    }
    int getEdad(){
      return this->edad;
    }
    void setNombre(string nombre){
      this->nombre = nombre;
    }
    void setDni(string dni){
      this->dni = dni;
    }
    void setEdad(int edad){
      this->edad = edad;
    }
    bool esMayorEdad(){
      return this->edad>=18;
    }
    void imprimir(){
      cout << "Me llamo " << this->nombre << ", tengo " << this->edad << " años y mi DNI es " << this->dni << endl;
      if (this->esMayorEdad()) cout << "Es mayor de edad." << endl;
      cout << "Es vip = " << this->vip << endl;
    }
};

int main(){
  //Persona miPersona("Celia","12345678H",26);
  //Persona otraPersona("Isaac","87654321H");

  /*
  cout << "Comprobando que imprimir() funciona : " << endl;
  miPersona.imprimir();
  cout << "Comprobando que el constructor por defecto fuciona: " << endl;
  otraPersona.imprimir();
  cout << "Comprobando que los get funcionan: " << endl;
  cout << miPersona.getNombre() << " " << miPersona.getDni() << " " << miPersona.getEdad() << endl;
  cout << "Comprobando que los set funcionan: " << endl;
  miPersona.setNombre("Lucas");
  miPersona.setEdad(15);
  miPersona.setDni("23456781A");
  miPersona.imprimir();
  */

  vector<int> codigoVip = {0,10,1};
  imprimirVector(codigoVip);
  Persona miPersona(codigoVip,"Celia","12345678H",26);
  miPersona.imprimir();
  codigoVip = {2,10,2};
    imprimirVector(codigoVip);
  Persona miPersona2(codigoVip,"Celia","12345678H",26);
  miPersona2.imprimir();
  codigoVip = {2,10,13};
    imprimirVector(codigoVip);
  Persona miPersona3(codigoVip,"Celia","12345678H",26);
  miPersona3.imprimir();
  return 0;
}
