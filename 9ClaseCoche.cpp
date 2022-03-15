#include <iostream>
using namespace std;

// CONCEPTO: Herencia por composición o agragación.

class Motor{
  private:
    bool estado;
  // Métodos
  private:  // No hace falta pero Celia tiene TOC de código.
    void setEstado(bool estado){
      this->estado = estado;
    }
  public:
    // Constructor
    Motor(){
      this->estado = false; // Apagado
    }
    // Destructor
    ~Motor(){
      cout << "Pasamos por el destructor de motor." << endl;
    }

    bool getEstado (){
      return this->estado;
    }
    void arrancar(){
      this->setEstado(true);
    }
    void apagar(){
      this->setEstado(false);
    }
    void imprimir(){
      if (this->estado){
        cout << "El motor esta encendido.";
      } else {
        cout << "El motor esta apagado.";
      }
      cout << endl;
    }
};
class Ventana{
  private:
    bool estado;
  // Métodos:
  private:
    void setEstado(bool estado){
      this->estado = estado;
    }
  public:
    Ventana(){
      this->estado = false; // Esta cerrada.
    }
    ~Ventana(){
      cout << "Pasamos por el destructor de ventana." << endl;
    }
    bool getEstado (){
      return this->estado;
    }
    void cerrarVentana(){
      this->setEstado(false);
    }
    void abrirVentana(){
      this->setEstado(true);
    }
    void imprimir(){
      if (this->estado){
        cout << "La ventana esta abierta.";
      } else {
        cout << "La ventana esta cerrada.";
      }
      cout << endl;
    }

};
class Puerta{
  private:
    bool estado;
    Ventana ventanilla;
  private:
    void setEstado(bool estado){
      this->estado = estado;
    }
  public:
    Puerta(){
      this->estado = false;
    }
    ~Puerta(){
      cout << "Pasamos por el destructor de puerta." << endl;
    }
    bool getEstado (){
      return this->estado;
    }
    Ventana & getVentanilla(){
      return this->ventanilla;
    }
    void cerrarPuerta(){
      this->setEstado(false);
    }
    void abrirPuerta(){
      this->setEstado(true);
    }
    void imprimir(){
      if (this->estado){
        cout << "La puerta esta abierta.";
      } else {
        cout << "La puerta esta cerrada.";
      }
      cout << endl;
      this->ventanilla.imprimir();
    }
};

class Coche{
  private:
    bool estado;
    Puerta puertaDer;
    Puerta puertaIzq;
    Motor motor;
  private:
    void setEstado(bool estado){
      this->estado = estado;
    }
  public:
    Coche(){
      this->estado = false; // Coche cerrado
    }
    bool getEstado (){
      return this->estado;
    }
    Puerta & getPuertaDer(){
      return this->puertaDer;
    }
    Puerta & getPuertaIzq(){
      return this->puertaIzq;
    }
    Motor & getMotor(){
      return this->motor;
    }
    void cerrarCoche(){
      this->setEstado(false);
    }
    void abrirCoche(){
      this->setEstado(true);
    }
    void imprimir(){
      if (this->estado){
        cout << "El coche esta abierto.";
      } else {
        cout << "El coche esta cerrado.";
      }
      cout << endl;
      this->puertaDer.imprimir();
      this->puertaIzq.imprimir();
      this->motor.imprimir();
    }
};

int main(){
  Motor miMotor;
  miMotor.imprimir();
  miMotor.arrancar();
  miMotor.imprimir();
  miMotor.apagar();
  miMotor.imprimir();
  delete & miMotor;
  cout << "---------------------------------" << endl;
  Ventana miVentana;
  miVentana.imprimir();
  miVentana.abrirVentana();
  miVentana.imprimir();
  miVentana.cerrarVentana();
  miVentana.imprimir();
  cout << "---------------------------------" << endl;
  Puerta miPuerta;
  miPuerta.imprimir();
  miPuerta.abrirPuerta();
  miPuerta.imprimir();
  miPuerta.cerrarPuerta();
  miPuerta.imprimir();
  cout << "---------------------------------" << endl;
  miPuerta.getVentanilla().imprimir();
  miPuerta.getVentanilla().abrirVentana();
  miPuerta.getVentanilla().imprimir();
  miPuerta.getVentanilla().cerrarVentana();
  miPuerta.getVentanilla().imprimir();
  cout << "---------------------------------" << endl;
  Coche miCoche;
  miCoche.abrirCoche();
  miCoche.getMotor().arrancar();
  miCoche.getPuertaDer().abrirPuerta();
  miCoche.getPuertaDer().getVentanilla().abrirVentana();
  miCoche.imprimir();
  return 0;
}
