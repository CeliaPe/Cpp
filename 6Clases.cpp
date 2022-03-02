 #include <iostream>
 using namespace std;

 class Rectangulo {
   private:
     double base;
     double altura;
   public:
     // Constructor
     Rectangulo(double base = 1, double altura = 1){
       //this->base = base;
       //this->altura = altura;
       setBase(base);
       setAltura(altura);
     }
     // Set
     void setBase(double base){
       (base > 0) ? this->base = base : this->base = 1;
     }
     void setAltura(double altura){
       (altura > 0) ? this->altura = altura : this->altura = 1;
     }
     // Get
     double getBase(){
       return this->base;
     }
     double getAltura(){
       return this->altura;
     }
     // Metodos
     double area(){
       return this->base * this->altura;
     }
     // Imprimir
     void imprimir(){
       cout << "La base es " << this->base << ", la altura es " << this->altura << " y el area es " << this->area() << endl;
     }
 };

 int main() {

   Rectangulo folio(-5,3);
   Rectangulo tablero;
   Rectangulo manta(4);
   double areaFolio;

   cout << "Folio: " << endl;
   folio.imprimir();
   folio.setBase(2);
   folio.setAltura(2);
   folio.imprimir();
   areaFolio = folio.area();
   cout << "El area del folio es: " << areaFolio << endl;

   cout << "Tablero: " << endl;
   tablero.imprimir();

   cout << "Manta: " << endl;
   manta.imprimir();

   return 0;
 }
