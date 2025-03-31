#ifndef REAL_H
#define REAL_H

#include "INumero.h"
#include <string>
#include <memory>

class Real: public INumero{
    private:
        double numero;

    public:
        Real(double n = 0){ numero = n;}

        string toString() const override {
            return to_string(numero); 
        }

        unique_ptr<INumero> suma (const INumero& otro) const override{
            const Real& r = static_cast<const Real&> (otro);
            return make_unique<Real>(numero + r.numero);
        }

        unique_ptr<INumero> resta (const INumero& otro) const override{
            const Real& r = static_cast<const Real&>(otro);
            return make_unique<Real>(numero - r.numero);
        }

        unique_ptr<INumero> producto (const INumero& otro) const override{
            const Real& r = static_cast<const Real&>(otro);
            return make_unique<Real>(numero * r.numero);
        }
        
};
#endif