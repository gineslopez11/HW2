#ifndef COMPLEJO_H
#define COMPLEJO_H

#include "INumero.h"

class Complejo : public INumero {
    private:
        double real;
        double imaginario;
    
    public:
        Complejo(double r = 0, double i = 0);

        string toString() const override;
    
        unique_ptr<INumero> suma(const INumero& otro) const override;
    
        unique_ptr<INumero> resta(const INumero& otro) const override;
    
        unique_ptr<INumero> producto(const INumero& otro) const override;
};

#endif