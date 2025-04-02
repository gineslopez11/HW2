#include "INumero.h"
#include "Entero.h"
#include "Real.h"
#include "Complejo.h"

int main() {
    
    unique_ptr<INumero> e1 = make_unique<Entero>(5);
    unique_ptr<INumero> r1 = make_unique<Real>(5.5);
    unique_ptr<INumero> c1 = make_unique<Complejo>(1, 3);

    cout << "El entero es: " << e1->toString() << endl
         << "El real es: " << r1->toString() << endl
         << "El complejo es: " << c1->toString() << endl;

    unique_ptr<INumero> SumaEnteros = e1->suma(*e1);
    unique_ptr<INumero> RestaEnteros = e1->resta(*e1);
    unique_ptr<INumero> ProdEnteros = e1->producto(*e1);

    unique_ptr<INumero> SumaReales = r1->suma(*r1);
    unique_ptr<INumero> RestaReales = r1->resta(*r1);
    unique_ptr<INumero> ProdReales = r1->producto(*r1);

    unique_ptr<INumero> SumaComplejos = c1->suma(*c1);
    unique_ptr<INumero> RestaComplejos = c1->resta(*c1);
    unique_ptr<INumero> ProdComplejos = c1->producto(*c1);

    cout << "Suma de enteros es: " << SumaEnteros->toString() << endl
         << "Resta de enteros es: " << RestaEnteros->toString() << endl
         << "Producto de enteros es: " << ProdEnteros->toString() << endl
         << "Suma de Reales es: " << SumaReales->toString() << endl
         << "Resta de Reales es: " << RestaReales->toString() << endl
         << "Producto de Reales es: " << ProdReales->toString() << endl
         << "Suma de Complejos es: " << SumaComplejos->toString() << endl
         << "Resta de Complejos es: " << RestaComplejos->toString() << endl
         << "Producto de Complejos es: " << ProdComplejos->toString() << endl;

    return 0;
}