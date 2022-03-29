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
        Esto quiere decir que la clase que hereda deja las funciones tal y como
        las tenía la clase padre.
  Protected:
      private   : No podemos acceder.
      protected : Protegido.
      public    : Protegido.
        Esto quiere decir que la clase que hereda tranforma las funciones que
        la clase padre tiene públicas en privadas.
  Privada:
      private   : No podemos acceder.
      protected : Privado.
      public    : Privado.
        Esto quiere decir que la clase que hereda tranforma las funciones que
        la clase padre tiene como protegidas o públicas en privadas.
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

    void probandoHerencia(){
      cout << "Si estoy en una herencia public: " << endl;
      //cout << "Llamo a algo privado: " << this->dni << endl;
      cout << "Llamo a algo publico: " << this->getDni() << endl;
    }
};

class Profesor : private Persona{
  private:
    double sueldo;
  public:
    Profesor (string nombre = "nombreProf", string dni = "dniProf",
              double sueldo = 2000.00 ) : Persona (nombre,dni){
      this->sueldo = sueldo;
    }
    void setSueldo(double sueldo){
      this->sueldo = sueldo;
    }
    double getSueldo(){
      return this->sueldo;
    }

    void imprimir(){
      // No podemos llamar al imprimir del padre, porque estamos especializando
      // la función ahora: this->imprimir();
      Persona::imprimir();
      // cout << "Me llamo " << this->getNombre() << " y mi DNI es " <<
      // this->getDni() << "." << endl;
      cout << "Mi sueldo es de " << this->sueldo << "euros." << endl;
    }
    void probandoHerencia(){
      cout << "Si estoy en una herencia public: " << endl;
      //cout << "Llamo a algo privado: " << this->dni << endl;
      cout << "Llamo a algo publico: " << this->getDni() << endl;
    }
};

int main(){
  Alumno alumnoDef;
  Alumno miAlumno("miNombre","miDni","miGrado",2);
  Alumno* ptrAlumno;
  Profesor profDef;
  ptrAlumno = new Alumno("ptrNombre","ptrDni","ptrGrado",9);
  alumnoDef.imprimir();
  miAlumno.imprimir();
  ptrAlumno->imprimir();
  profDef.imprimir();
  cout << alumnoDef.getDni();
  // cout << profDef.getDni();  // Da error porque la herencia a tranformado una
                                // función que era pública a privada...*/
  return 0;
}
