#ifndef EJ1_H
#define EJ1_H

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Tiempo {
private:
    int horas;
    int minutos;
    int segundos;
    string am_pm;

public:
    Tiempo(int h = 0, int m = 0, int s = 0, string ap = "a.m") {
        if (h > 12 || m >= 60 || s >= 60) {
            throw invalid_argument("ERROR: estas utilizando valores fuera de rango");
        }
        if (ap != "a.m" && ap != "p.m") { throw invalid_argument("ERROR: Valor de AM/PM inválido."); }
        horas = h;
        minutos = m;
        segundos = s;
        am_pm = ap;
    }

    int getHoras() { return horas; }
    int getMinutos() { return minutos; }
    int getSegundos() { return segundos; }
    string getAm_Pm() { return am_pm; }

    void setHoras(int h) { 
        if (h > 12) { throw invalid_argument("ERROR: Hora fuera de rango."); }
        horas = h; 
    }
    void setMinutos(int m) { 
        if (m >= 60) { throw invalid_argument("ERROR: Minutos fuera de rango."); }
        minutos = m; 
    }
    void setSegundos(int s) { 
        if (s >= 60) { throw invalid_argument("ERROR: Segundos fuera de rango."); }
        segundos = s; 
    }
    void setAm_Pm(string ap) { 
        if (ap != "a.m" && ap != "p.m") { throw invalid_argument("ERROR: Valor de AM/PM inválido."); }
        am_pm = ap; 
    }

    void imprimir24hs() {
        int horas24 = horas;
        if (horas24 == 12 && am_pm == "a.m") {
            horas24 = 0;
        } else if (am_pm == "p.m" && horas24 < 12) {
            horas24 += 12;
        }

        cout << setw(2) << setfill('0') << horas24 << "hh, " 
             << setw(2) << setfill('0') << minutos << "mm, " 
             << setw(2) << setfill('0') << segundos << "ss" << endl;
    }

    void imprimir12hs() {
        cout << setw(2) << setfill('0') << horas << "hh, " 
             << setw(2) << setfill('0') << minutos << "mm, " 
             << setw(2) << setfill('0') << segundos << "ss " 
             << am_pm << endl;
    }
};

#endif