#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct MateriaNota { //uso un struct de cada materia y la nota en esa materia del estudiantee
    string materia;
    float nota;
};

class Estudiante {
private:
    string nombre;
    int legajo;
    vector<MateriaNota> materias;

public:
    Estudiante(string nom = "", int leg = 0, vector<MateriaNota> mat = {}); //Por defecto se crea un estudiante "vacio"

    string getNombre();

    int getLegajo();

    float getPromedio();

    bool operator<(const Estudiante& otro) const; //cambio operador < para poder ordenar luego alfabeticamente en el sortnst; //cambio operador < para poder ordenar luego alfabeticamente en el sort

    friend ostream& operator<<(ostream& os, const Estudiante& est); //cambio operador << para poder imprimir directamente con cout y no tener que acceder a atributosstream& os, const Estudiante& est); //cambio operador << para poder imprimir directamente con cout y no tener que acceder a atributos
};

#endif