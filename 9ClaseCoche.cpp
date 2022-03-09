#include <iostream>
using namespace std;

class Motor{
  private:
    bool estado;
  // Métodos
  private:  // No hace falta pero Celia tiene TOC de código.
    void setEstado(bool estado){
      this->estado = estado;
    }
  public:
    Motor(){
      this->estado = false; // Apagado
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
      this->estado = false; // Estan cerradas.
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
};

int main(){
  Motor miMotor;
  miMotor.imprimir();
  miMotor.arrancar();
  miMotor.imprimir();
  miMotor.apagar();
  miMotor.imprimir();

  Ventana miVentana;
  miVentana.imprimir();
  miVentana.abrirVentana();
  miVentana.imprimir();
  miVentana.cerrarVentana();
  miVentana.imprimir();

  return 0;
}
