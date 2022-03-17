#include <iostream>
using namespace std;

class Persona{
  private:
    string nombre;
    string dni;
  public:
    Persona(string nombre = "nombrePer", string dni = "dniPer"){
        this->nombre = nombre;
        this->dni = dni;
    }
    ~Persona(){
      cout << "Adios!" << endl;
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
/*
Cuando definimos atributos y métodos:
  Public    : Se puede acceder desde cualquier clase.
  Protected : Solo accesible desde la clase y sus descendientes.
  Private   : Solo accesible desde la clase donde se define.
*/
/*
Cuando definimos la herencia de una clase:
  Public:
      private   : No podemos acceder.
      protected : Protegido.
      public    : Publico.
  Protected:
      private   : No podemos acceder.
      protected : Protegido.
      public    : Protegido.
  Privada:
      private   : No podemos acceder.
      protected : Privado.
      public    : Privado.
*/
class Alumno : public Persona{
  private:
    string grado;
    int curso;
  public:
    Alumno (string nombre = "nombreAlum", string dni = "dniAlum",
            string grado = "gradoAlum", int curso = 1) : Persona (nombre,dni){
      this->grado = grado;
      this->curso = curso;
    }
    void setClase(string grado){
      this->grado = grado;
    }
    void setCurso(int curso){
      this->curso = curso;
    }
    string getClase(){
      return this->grado;
    }
    int getCurso(){
      return this->curso;
    }

    void imprimir(){
      // No podemos llamar al imprimir del padre, porque estamos especializando
      // la función ahora: this->imprimir();
      Persona::imprimir();
      // cout << "Me llamo " << this->getNombre() << " y mi DNI es " << this->getDni() << "." << endl;
      cout << "Estoy en el grado de " << this->grado << " y estoy en el curso "
           << this->curso << "." << endl;
    }
};

int main(){
  //Persona miPersona;
  Alumno alumnoDef;
  Alumno miAlumno("miNombre","miDni","miGrado",2);
  Alumno* ptrAlumno;
  //miPersona.imprimir();
  ptrAlumno = new Alumno("ptrNombre","ptrDni","ptrGrado",9);
  alumnoDef.imprimir();
  miAlumno.imprimir();
  ptrAlumno->imprimir();
  return 0;
}
