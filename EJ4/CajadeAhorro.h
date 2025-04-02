#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include "Banco.h"

class CajadeAhorro : public Banco {
    private:
        string tipoCuenta = "Caja de Ahorro";
        mutable int vecesMostrado = 0;

    public:
        CajadeAhorro(double fondos, string titular) : Banco(fondos, titular) {}

        void retirar(double cantidad) override {
            if (balance >= cantidad){
                balance -= cantidad;
                cout <<"Se retiraron "<< cantidad << "de la Caja de Ahorro"<< endl;

            }else{cout << "Fondos insuficientes" << endl;}
        }

        void mostrarInfo() override {
            cout << tipoCuenta <<":"<< endl
                 << "Titular: " << titularCuenta << endl
                 << "Fondos: " << balance << endl;
                 vecesMostrado += 1;
            
            if (vecesMostrado > 2) {
                balance -= 20;
                cout << "Se descontaron 20 por exceder el limite de consultas"<< endl;
            } 
        }

        friend class CuentaCorriente;
};

#endif