#ifndef ENTERO_H
#define ENTERO_H

#include "INumero.h"

class Entero: public INumero{
    private:
        int numero;

    public:
        Entero(int n = 0);

        string toString() const override;

        unique_ptr<INumero> suma (const INumero& otro) const override;
        
        unique_ptr<INumero> resta (const INumero& otro) const override;

        unique_ptr<INumero> producto (const INumero& otro) const override;
        
};
#endif