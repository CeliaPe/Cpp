#include <iostream>
using namespace std;

class Persona{
  private:
    string nombre;
    string dni;
  public:
    Persona(string nombre = "Celia", string dni = "12345678H"){
        this->nombre = nombre;
        this->dni = dni;
    }
    ~Persona(){
      cout << "¡Adios!" << endl;
    }

    void imprimir(){
      cout << "Me llamo " << this->nombre << " y mi DNI es " << this->dni << "." << endl;
    }

    void setNombre(string nombre){
      this->nombre = nombre;
    }
    void setDni(string dni){
      this->dni = dni;
    }
    string getNombre(){
      return this->nombre;
    }
    string getDni(){
      return this->dni;
    }
};

class Alumno : public Persona{
  private:
    string clase;
    int curso;
  public:
    Alumno (string clase = "DAW", int curso = 1){
      this->clase = clase;
      this->curso = curso;
    }
    void setClase(string clase){
      this->clase = clase;
    }
    void setCurso(int curso){
      this->curso = curso;
    }
    string getClase(){
      return this->clase;
    }
    int getCurso(){
      return this->curso;
    }

    void imprimir(){
      // No podemos llamar al imprimir del padre, porque estamos especializando
      // la función ahora: this->imprimir();
      cout << "Me llamo " << this->getNombre() << " y mi DNI es " << this->getDni() << "." << endl;
      cout << "Estoy en el grado de " << this->clase << " y estoy en " << this->curso << "º curso." << endl;
    }
};

int main(){
  //Persona miPersona;
  Alumno miAlumno;
  //miPersona.imprimir();
  miAlumno.imprimir();
  return 0;
}
