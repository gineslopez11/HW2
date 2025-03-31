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
            Estudiante(string nom = "", int leg = 0, vector<MateriaNota> mat = {}){
                nombre = nom;
                legajo = leg;
                materias = mat;
            }

            string getNombre(){ return nombre; }

            int getLegajo(){ return legajo; }

            float getPromedio(){
                float suma_notas = 0;
                for(const auto& materia : materias){
                    suma_notas += materia.nota;
                }
                return suma_notas/materias.size();
            }

            bool operator<(const Estudiante& otro) const { return nombre < otro.nombre;}

            friend ostream& operator<< (ostream& os, const Estudiante& est){
                os << "Nombre: " << est.nombre << ", Legajo: " << est.legajo;
                return os;
            }

};

#endif