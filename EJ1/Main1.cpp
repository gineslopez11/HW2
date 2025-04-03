#include <iostream>
#include "Tiempo.h"

using namespace std;
int main (){
    int h,m,s;
    string ap;

    bool entrada_valida = false;
    while (!entrada_valida){ //hago while hasta que se ingrese una entrada valida

        try{//hago try para ver que se ingresen correctamente los parametros de tiempo, si no se ingresan bien hago catch del error en Tiempo.h
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

            //Cambio cada parametro
            tap.setHoras(2);
            cout<<"se han cambiado las horas a 2: ";
            tap.imprimir24hs();
            tap.setMinutos(47);
            cout<<"se han cambiado los minutos a 47: ";
            tap.imprimir24hs();
            tap.setSegundos(3);
            cout<<"se han cambiado los segundos a 3: ";
            tap.imprimir24hs();
            tap.setAm_Pm("p.m");
            cout<<"se ha cambiado el dia a p.m: ";
            tap.imprimir24hs();

            entrada_valida = true;
            
        }catch(const invalid_argument& e){ //Si hay algun error lo advierto y se repite el while
            cout << e.what() << endl;
        }

    }

    return 0;
}
