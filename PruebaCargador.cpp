#include <iostream>
using namespace std;

/*
- Escribe tu nombre [0.5]
- Crear un objeto cargador [2p] formado por un cable [2p] (longitud, tipo de
entrada y tipo de salida, si permite transmisión de datos o solo carga) y el
adaptador de potencia [2p] (potencia de entrada, de salida y número de puertos
(max 3)). Prueba que funciona.
- Gestionar el número de puertos disponibles del cargador: ¿Puedo añadir otro
cable? [2p]
- Gestiona la utilidad de los cables: ¿Alguno de los cables conectados me permi-
te transmitir datos a mi dispositivo si este tiene una entrada de tipo micro
usb? [1,5p]
*/

class Cable{
  private:
    double longitud;
    string tipoEntrada, tipoSalida;
    bool datos;
  public:

    Cable (double longitud = 2 , string tipoEntrada = "E" ,
           string tipoSalida = "S" , bool datos = false){
      this->longitud = longitud;
      this->tipoEntrada = tipoEntrada;
      this->tipoSalida = tipoSalida;
      this->datos = datos;
    }
    ~Cable (){
      cout << "... destruye un cable ..." << endl;
    }
    double getLongitud(){
      return this->longitud;
    }
    string getTipoEntrada(){
      return this->tipoEntrada;
    }
    string getTipoSalida(){
      return this->tipoSalida;
    }
    bool getDatos(){
      return this->datos;
    }
    void setLongitud(double longitud){
      this->longitud = longitud;
    }
    void setTipoEntrada(string tipoEntrada){
      this->tipoEntrada = tipoEntrada;
    }
    void setTipoSalida(string tipoSalida){
      this->tipoSalida = tipoSalida;
    }
    void setDatos(bool datos){
      this->datos = datos;
    }

    void imprimir(){
      cout << "El cable mide " << this->longitud << ", su tipo de entrada es "
           << this->tipoEntrada << ", su tipo de salida es " << this->tipoSalida;
      if (datos) cout << " y permite la transmisión de datos." << endl;
    }
};

class Adaptador{
  private:
    double potenciaEntrada, potenciaSalida;
    int numPuertos;
  public:

    Adaptador (double potenciaEntrada = 220 , double potenciaSalida = 2 ,
           int numPuertos = 1){
      this->potenciaEntrada = potenciaEntrada;
      this->potenciaSalida = potenciaSalida;
      this->numPuertos = numPuertos;
    }
    ~Adaptador (){
      cout << "... destruye un adaptador ..." << endl;
    }
    double getPotenciaEntrada(){
      return this->potenciaEntrada;
    }
    double getPotenciaSalida(){
      return this->potenciaSalida;
    }
    int getNumPuertos(){
      return this->numPuertos;
    }
    void setPotenciaEntrada(double potenciaEntrada){
      this->potenciaEntrada = potenciaEntrada;
    }
    void setPotenciaSalida(double potenciaSalida){
      this->potenciaSalida = potenciaSalida;
    }
    void setNumPuertos(int numPuertos){
      this->numPuertos = numPuertos;
    }

    void imprimir(){
      cout << "El adaptador tiene una potencia de entrada de "
           << this->potenciaEntrada << ", su potencia de salida es " <<
           this->potenciaSalida << " y el número de puertos es " <<
           this->numPuertos << "." << endl;
    }
};

int main(){
  cout << "Celia Pedregosa" << endl;
}
