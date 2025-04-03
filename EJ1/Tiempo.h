#ifndef TIEMPO_H
#define TIEMPO_H

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
    Tiempo(int h = 0, int m = 0, int s = 0, string ap = "a.m");

    int getHoras();
    int getMinutos();
    int getSegundos();
    string getAm_Pm();

    void setHoras(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setAm_Pm(string ap);

    void imprimir24hs();

    void imprimir12hs();
};

#endif