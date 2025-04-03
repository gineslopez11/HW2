#include "Tiempo.h"


Tiempo::Tiempo(int h, int m, int s, string ap) { //por defecto se inicializan en 0 por si no se ingresan valores en los parametros
    if (h > 12 || m >= 60 || s >= 60) {
        throw invalid_argument("ERROR: estas utilizando valores fuera de rango"); //hago throw aca y try/catch en el main por si se ingresan erroneamente los valores
    }
    if (ap != "a.m" && ap != "p.m") { throw invalid_argument("ERROR: Valor de AM/PM inválido."); }
    horas = h;
    minutos = m;
    segundos = s;
    am_pm = ap;
}

int Tiempo::getHoras() { return horas; }
int Tiempo::getMinutos() { return minutos; }
int Tiempo::getSegundos() { return segundos; }
string Tiempo::getAm_Pm() { return am_pm; }

void Tiempo::setHoras(int h) { 
    if (h > 12) { throw invalid_argument("ERROR: Hora fuera de rango."); } //Hago set para cambiar solo la hora
    horas = h; 
}
void Tiempo::setMinutos(int m) { 
    if (m >= 60) { throw invalid_argument("ERROR: Minutos fuera de rango."); }
    minutos = m; 
}
void Tiempo::setSegundos(int s) { 
    if (s >= 60) { throw invalid_argument("ERROR: Segundos fuera de rango."); }
    segundos = s; 
}
void Tiempo::setAm_Pm(string ap) { 
    if (ap != "a.m" && ap != "p.m") { throw invalid_argument("ERROR: Valor de AM/PM inválido."); }
    am_pm = ap; 
}

void Tiempo::imprimir24hs() {
    int horas24 = horas;
    if (horas24 == 12 && am_pm == "a.m") { //si son las 12 de la noche, equivale a las 00 hs en horario 24 hs
        horas24 = 0;
    } else if (am_pm == "p.m" && horas24 < 12) { //si es horario de la tarde solo le tengo que sumar 12 para el 24 hs
        horas24 += 12;
    }

    cout << setw(2) << setfill('0') << horas24 << "hh, " 
            << setw(2) << setfill('0') << minutos << "mm, " 
            << setw(2) << setfill('0') << segundos << "ss" << endl;
}

void Tiempo::imprimir12hs() {
    cout << setw(2) << setfill('0') << horas << "hh, " 
            << setw(2) << setfill('0') << minutos << "mm, " 
            << setw(2) << setfill('0') << segundos << "ss " 
            << am_pm << endl;
}
