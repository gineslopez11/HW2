#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct MateriaNota{
    string materia;
    float nota;
};

class Estudiante {
    private:
            string nombre;
            int legajo;
            vector<MateriaNota> materias;
    
    public:
            Estudiante(string nom = "", int leg = 0, vector<MateriaNota> mat = {}){ //Por defecto se crea un estudiante "vacio"
                nombre = nom;
                legajo = leg;
                materias = mat;
            }

            string getNombre(){ return nombre; }

            int getLegajo(){ return legajo; }

            float getPromedio(){
                float suma_notas = 0;
                for(const auto& materia : materias){
                    suma_notas += materia.nota; //recorro el vector de materias y voy sumando todas las notas que tiene
                }
                return suma_notas/materias.size(); //divido la suma de sus notas por todas las notas que tiene
            }

            bool operator<(const Estudiante& otro) const { return nombre < otro.nombre;} //cambio operador < para poder ordenar luego alfabeticamente en el sort

            friend ostream& operator<< (ostream& os, const Estudiante& est){
                os << "Nombre: " << est.nombre << ", Legajo: " << est.legajo; //cambio operador << para poder imprimir directamente con cout y no tener que acceder a atributos
                return os;
            }

};

#endif