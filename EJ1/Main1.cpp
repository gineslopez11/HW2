#include <iostream>
#include "Tiempo.h"

using namespace std;
int main (){
    int h,m,s;
    string ap;

    bool entrada_valida = false;
    while (!entrada_valida){

        try{
            cout<<"Ingrese una hora: ";
            cin>>h;
            cout<<"Ingrese minutos: ";
            cin>>m;
            cout<<"Ingrese segundos: ";
            cin>>s;
            cout<<"Ingrese si es a.m o p.m: ";
            cin>>ap;

            Tiempo t1 (h);
            Tiempo t2 (h,m);
            Tiempo t3 (h,m,s);
            Tiempo tap (h,m,s,ap);

            t1.imprimir12hs();
            t2.imprimir12hs();
            t3.imprimir12hs();
            tap.imprimir12hs();
            tap.imprimir24hs();

            entrada_valida = true;
            
        }catch(const invalid_argument& e){
            cout << e.what() << endl;
        }

    }

    return 0;
}
