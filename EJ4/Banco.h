#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

struct info{
    int balance;
    string tipo;
    string nombre;
};

class Banco{
    protected:
        double balance;
        string titularCuenta;
        
    
    public:
        Banco (double bal = 0, string titular = ""){
            balance = bal;
            titularCuenta = titular; 
        }

        virtual double retirar(double cantidad) const = 0;
        virtual void mostrarInfo() const = 0;

        virtual void depositar(double cantidad){
            balance += cantidad;
        }



};

#endif