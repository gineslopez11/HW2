#include "Banco.h"
#include "CajadeAhorro.h"
#include "CuentaCorriente.h"

int main (){
    int operacion,seguir = 1,operacionCA,operacionCC,monto;

    CajadeAhorro caja(500, "Juan");      
    CuentaCorriente cuenta(300, "Juan");



    while (seguir){

        cout<<"Ingrese el numero de la operacion que desea realizar: "<<endl
            <<"1. Acceder a Cuenta de Ahorro"<<endl
            <<"2. Acceder a Cuenta Corriente"<<endl;

        cin >> operacion;

        switch (operacion) {
            case 1:
                cout<<"Ingrese el numero de la operacion que desea realizar: "<<endl
                    <<"1. Hacer un deposito"<<endl
                    <<"2. Hacer un retiro"<<endl
                    <<"3. Mostrar información de la cuenta"<<endl;
                    cin >> operacionCA;
                
                switch (operacionCA){
                    case 1:
                        cout<<"Ingrese el monto a depositar: "<<endl;
                        cin >> monto;
                        caja.depositar(monto);

                        break;

                    case 2:
                        cout<<"Ingrese el monto a retirar: "<<endl;
                        cin >> monto;
                        caja.retirar(monto);

                        break;
                    
                    case 3:
                        caja.mostrarInfo();

                        break;
                }
                    break;

            case 2:
                cout<<"Ingrese el numero de la operacion que desea realizar: "<<endl
                    <<"1. Hacer un deposito"<<endl
                    <<"2. Hacer un retiro"<<endl
                    <<"3. Mostrar información de la cuenta"<<endl;
                    cin >> operacionCC;

                
                switch (operacionCC){
                    case 1:
                        cout<<"Ingrese el monto a depositar: "<<endl;
                        cin >> monto;
                        cuenta.depositar(monto);

                        break;

                    case 2:
                        cout<<"Ingrese el monto a retirar: "<<endl;
                        cin >> monto;
                        cuenta.retirar(monto);

                        break;
                    
                    case 3:
                        cuenta.mostrarInfo();

                        break;
                }
                    break;
        }

        cout<<"Desea continuar haciendo operaciones?"<<endl
            <<"1. Si"<<endl
            <<"0. No"<<endl;
        cin >> seguir;
    }

}