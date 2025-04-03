#include "Banco.h"
#include "CajadeAhorro.h"
#include "CuentaCorriente.h"

CajadeAhorro::CajadeAhorro(double fondos, string titular) : Banco(fondos, titular) {}

void CajadeAhorro::retirar(double cantidad) {
    if (balance >= cantidad){ //Si tiene dinero disponible
        balance -= cantidad;//Descuento del balance de la caja de ahorro
        cout <<"Se retiraron "<< cantidad << "de la Caja de Ahorro"<< endl; 

    }else{cout << "Fondos insuficientes" << endl;}
}

void CajadeAhorro::mostrarInfo() {
    cout << tipoCuenta <<":"<< endl
         << "Titular: " << titularCuenta << endl
         << "Fondos: " << balance << endl;
         vecesMostrado += 1;
    
    if (vecesMostrado > 2) {
        balance -= 20;
        cout << "Se descontaron 20 por exceder el limite de consultas"<< endl;
    } 
}

CuentaCorriente::CuentaCorriente(double fondos, string titular) : Banco(fondos, titular) {}

void CuentaCorriente::retirar (double cantidad) {
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

void CuentaCorriente::mostrarInfo() {
    cout << tipoCuenta <<":"<< endl
         << "Titular: " << titularCuenta << endl
         << "Fondos: " << balance << endl;
         vecesMostrado += 1;
    
    if (vecesMostrado > 2) {
        balance -= 20;
        cout << "Se descontaron 20 por exceder el limite de consultas"<< endl;
    } 
}
