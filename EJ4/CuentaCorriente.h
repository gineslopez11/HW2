#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "Banco.h"
#include "CajadeAhorro.h"

class CuentaCorriente : public Banco {
    private:
        string tipoCuenta = "Cuenta Corriente";
        mutable int vecesMostrado = 0;

    public:
        CuentaCorriente(double fondos, string titular) : Banco(fondos, titular) {}

        void retirar (double cantidad) override {
            if (balance >= cantidad){
                balance -= cantidad;
                cout <<"Se retiraron "<< cantidad << "de la Cuenta Corriente"<< endl;
            }
            else if (balance < cantidad){
                CajadeAhorro caja(balance,titularCuenta);
                caja.retirar(cantidad);
                cout <<"Se retiraron "<< cantidad << "de la Caja de Ahorro porque no hay fondos en la Cuenta Corriente"<< endl;
            }
            else{cout <<"No hay fondos, no se puede retirar"<< endl;}
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
    
};

#endif