#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <iostream>

using namespace std;

class Banco{
    protected: //uso protected porque solo la caja de ahorro y la cuenta c. pueden acceder
        double balance; 
        string titularCuenta;

    
    public: //lo puede usar el usuario
        Banco (double bal = 0, string titular = ""){
            balance = bal;
            titularCuenta = titular; 
        }

        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;

        virtual void depositar(double cantidad){
            balance += cantidad; //Depositar es igual para las dos cuentas
        }



};

#endif