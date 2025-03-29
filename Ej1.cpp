#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Tiempo{
    private:
           int horas;
           int minutos;
           int segundos;
           string am_pm;

    public:
           Tiempo (int h = 0, int m = 0, int s = 0, string ap = "a.m"){
                if (h > 12 || m >= 60 || s >= 60){throw invalid_argument ("ERROR: estas utilizando valores fuera de rango");}
                horas = h;
                minutos = m;
                segundos = s;
                am_pm = ap;
           }
           ~Tiempo(){}

           int getHoras(){ return horas; }
           int getMinutos(){ return minutos; }
           int getSegundos(){ return segundos; }
           string getAm_Pm() {return am_pm; }
           
           void setHoras(int h){ horas = h; }
           void setMinutos(int m){ minutos = m; }
           void setSegundos(int s){ segundos = s; }
           void setAm_Pm(string ap) {am_pm = ap; }

           void imprimir24hs (){
                int horas24 = horas;
                if (horas24 == 12 && am_pm == "a.m"){
                    horas24 = 0;
                }
                else if(am_pm == "p.m" && horas24 < 12){
                    horas24 += 12;
                }

                cout <<setw(2)<<setfill('0')<<horas24<<"hh, "<<setw(2)<<setfill('0')
                     <<setw(2)<<setfill('0')<<minutos<<"mm, "<<setw(2)<<setfill('0')
                     <<setw(2)<<setfill('0')<<segundos<<"ss"<<setw(2)<<setfill('0')<<endl;
           }
           
           void imprimir12hs(){
            cout <<setw(2)<<setfill('0')<<horas<<"hh, "<<setw(2)<<setfill('0')
                 <<setw(2)<<setfill('0')<<minutos<<"mm, "<<setw(2)<<setfill('0')
                 <<setw(2)<<setfill('0')<<segundos<<"ss "<<setw(2)<<setfill('0')
                 <<am_pm<<endl;
                 
           }
};

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
