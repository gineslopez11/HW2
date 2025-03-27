#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Tiempo{
    public:
           int horas = 0;
           int minutos = 0;
           int segundos = 0;

           Tiempo (int h, int m, int s){
                if (h >= 60 || m >= 60 || s>=60){throw invalid_argument ("ERROR: estas utilizando valores fuera de rango");}
                h = horas;
                m = minutos;
                s = segundos;
           }
           ~Tiempo(){}

           
        
};

int main (){

    return 0;
}
