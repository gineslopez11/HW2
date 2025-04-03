#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include "Banco.h"

class CajadeAhorro : public Banco {
    private: 
        string tipoCuenta = "Caja de Ahorro";
        mutable int vecesMostrado = 0; //Lo uso para el mostrarInfo. Si el usuario lo pidio mas de dos veces, se le cobran 20 cada vez que lo pida

    public:
        CajadeAhorro(double fondos, string titular);

        void retirar(double cantidad) override;

        void mostrarInfo() override;

        friend class CuentaCorriente;
};

#endif