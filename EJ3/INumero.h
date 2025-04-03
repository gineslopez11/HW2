#ifndef INUMERO_H
#define INUMERO_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class INumero{
    public:
        // Uso smart pointers para el polimorfismo, evitando la gestión manual de memoria.  
        // Con esto puedo almacenar distintos tipos de números bajo la misma interfaz,  
        // que los datos se gestionen automáticamente y que no hayan fugas de memoria.
        // Sin punteros no se puede el Polimorfismo en este caso.
        virtual string toString() const = 0;
        virtual unique_ptr<INumero> suma(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> resta(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> producto(const INumero& otro) const = 0;
        virtual ~INumero() = default;  
        //Sin virtual, siempre se llamaría al de la base. En este caso se ejecuta el método que corresponde a la clase derivada

};

#endif
