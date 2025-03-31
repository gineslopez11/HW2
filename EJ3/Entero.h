#ifndef ENTERO_H
#define ENTERO_H

#include "INumero.h"
#include <string>
#include <memory>


class Entero: public INumero{
    private:
        int numero;

    public:
        Entero(int n = 0){ numero = n;}

        string toString() const override {
            return to_string(numero); 
        }

        unique_ptr<INumero> suma (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&> (otro);
            return make_unique<Entero>(numero + e.numero);
        }

        unique_ptr<INumero> resta (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero - e.numero);
        }

        unique_ptr<INumero> producto (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero * e.numero);
        }
        
};
#endif