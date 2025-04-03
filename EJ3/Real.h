#ifndef REAL_H
#define REAL_H

#include "INumero.h"

class Real: public INumero{
    private:
        double numero;

    public:
        Real(double n = 0);

        string toString() const override;

        unique_ptr<INumero> suma (const INumero& otro) const override;

        unique_ptr<INumero> resta (const INumero& otro) const override;

        unique_ptr<INumero> producto (const INumero& otro) const override;

};
#endif