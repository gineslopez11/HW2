#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include <string>
#include <memory>
#include <iostream>
#include "Banco.h"

using namespace std;

class CajadeAhorro : public Banco {
    private:
        string tipoCuenta = "Caja de Ahorro";
        int vecesMostrado = 0;

    public:
        CajadeAhorro(double fondos, string titular) : Banco(fondos, titular) {}

        double retirar(double cantidad) {
            if (balance >= cantidad){
                balance -= cantidad;
                return cantidad;

            }else{cout << "Fondos insuficientes" << endl;}
        }

        void mostrarInfo(){
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