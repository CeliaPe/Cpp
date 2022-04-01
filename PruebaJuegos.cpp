/*Tenemos una clase padre llamada JUEGO, que tiene de atributos el nombre (que
no puede modificar ninguno de sus hijos) y el precio.
Construir la clase con sus respectivos constructores (y destructores), gets,
sets y método de impresión. Añadir el método de descuento() que aplica un des-
cuento de 10€ y devuelve el valor del juego tras este descuento sin modificar
el precio real.

Tenemos dos clases hijos VIDEOJUEGO y JUEGOdeMESA.
Construir las clases con sus respectivos constructores (y destructores), gets,
sets y método de impresión.
En la clase VIDEOJUEGO existe el atributo plataforma y el descuento se hace de
forma distinta: Se aplica un 20% al precio y si es mayor que el descuento por
defecto de 10€ se aplica, si no se deja el descuento de 10€.
En la clase JUEGOdeMESA existen los atributos máximo y mínimo de jugadores.
Tiene además un método que permite saber si puedes jugar a un juego o no al pa-
sarle el número de jugadores que quieren jugar.
*/

#include <iostream>
using namespace std;

class Juego{
  private:
    string nombre;
  protected:
    double precio;
    double descuento;

  private:
    // No hace falta ponerlo porque un set private no tiene sentido.
    void setNombre(string nombre){
      this->nombre = nombre;
    }

  public:
    Juego(string nombre = "nombreJue", double precio = 0.0){
        this->nombre = nombre;
        this->precio = precio;
        this->descuento = 10;
    }
    ~Juego(){
      cout << "Adios juego!" << endl;
    }

    void imprimir(){
      cout << "El juego " << this->nombre << " vale " << this->precio << " euros." << endl;
    }
    void imprimirConDescuento(){
      this->imprimir();
      cout << "El precio con descuento es de " << this->precioConDescuento() << " euros." << endl;
    }
    string getNombre(){
      return this->nombre;
    }
    void setPrecio(double precio){
      this->precio = precio;
    }
    double getPrecio(){
      return this->precio;
    }
    double getDescuento(){
      return this->descuento;
    }
    double precioConDescuento(){
      return this->precio-this->descuento;
    }
};

class Videojuego : public Juego{
  private:
    string plataforma;
    void resetDescuento(){
      this->descuento = 10;
    }

  public:
  Videojuego (string nombre = "nombreVJuego", double precio = 0,
            string plataforma = "PC" ) : Juego (nombre,precio){
    this->plataforma = "PC";
  }
  ~Videojuego(){
    cout << "Adios videojuego!";
  }

  void setPrecio(double precio){
    this->precio = precio;
    resetDescuento();
  }
  void setPlataforma(string plataforma){
    this->plataforma = plataforma;
  }
  string getPlataforma(){
    return this->plataforma;
  }

  void imprimir(){
    Juego::imprimir();
    cout << "La plataforma utilizada es " << this->plataforma << " ." << endl;
  }
  void imprimirConDescuento(){
    this->imprimir();
    cout << "El descuento es de " << this->precioConDescuento() << " euros." << endl;
  }
  double precioConDescuento(){
    double nuevoDescuento = this->precio*0.2;
    if (nuevoDescuento > this->descuento){
      this->descuento = nuevoDescuento;
    }
    return this->precio - this->descuento;
  }
};

int main(){
  Juego juegoDef;
  Juego miJuego("miJuego",50);

  Videojuego vJuegoDef;
  Videojuego miVJuego("miVJuego",90);

  cout << "Juego por defecto:" << endl;
  juegoDef.imprimir();
  cout << "Juego con parámetros:" << endl;
  miJuego.imprimirConDescuento();
  cout << "Modifico con set:" << endl;
  miJuego.setPrecio(70);
  miJuego.imprimirConDescuento();
  cout << "Imprimo con get:" << endl;
  cout << "El juego " << miJuego.getNombre() << " vale " << miJuego.getPrecio() << " euros." << endl;

  cout << "vJuego por defecto:" << endl;
  vJuegoDef.imprimir();
  cout << "vJuego con parametros:" << endl;
  miVJuego.imprimirConDescuento();
  cout << "Modifico el vJuego con set:" << endl;
  miVJuego.setPrecio(80);
  miVJuego.imprimirConDescuento();
  cout << "Imprimo con get:" << endl;
  cout << "El juego " << miVJuego.getNombre() << " vale " << miVJuego.getPrecio() << " euros." << endl;

  return 0;
}
