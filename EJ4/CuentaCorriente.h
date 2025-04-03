#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "Banco.h"
#include "CajadeAhorro.h"

class CuentaCorriente : public Banco {
    private:
        string tipoCuenta = "Cuenta Corriente";
        mutable int vecesMostrado = 0;

    public:
        CuentaCorriente(double fondos, string titular);

        void retirar (double cantidad) override;

        void mostrarInfo() override;
    
};

#endif