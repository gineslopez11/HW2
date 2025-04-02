#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <iostream>

using namespace std;

class Banco{
    protected:
        double balance;
        string titularCuenta;

    
    public:
        Banco (double bal = 0, string titular = ""){
            balance = bal;
            titularCuenta = titular; 
        }

        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;

        virtual void depositar(double cantidad){
            balance += cantidad;
        }



};

#endif