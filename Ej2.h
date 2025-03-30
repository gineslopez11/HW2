#ifndef EJ2_H
#define EJ2_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
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
            Estudiante(string nom, int leg){
                nombre = nom;
                legajo = leg;
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


};


class Curso{
    private:
            vector<shared_ptr<Estudiante>> estudiantes;
    public:
        void desinscribir(string nombre) {
            auto iterador = find_if(estudiantes.begin(), estudiantes.end(), [nombre](const shared_ptr<Estudiante>& est) {
            return est->getNombre() == nombre;
            });

            if (iterador != estudiantes.end()){
                estudiantes.erase(iterador);
            }else{
                cout<<"No se encontro al estudiante"<<endl;
            }
        }
        void inscribir(string nombre) {
            //hago un push_back del puntero y ya esta
        }
};


#endif