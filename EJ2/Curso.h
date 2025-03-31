#ifndef CURSO_H
#define CURSO_H

#include "Estudiante.h"
#include <vector>
#include <memory>
#include <algorithm>

class Curso{
    private:
            vector< shared_ptr<Estudiante> > estudiantes;
    public:
            Curso(){};
            void desinscribir(int leg) {
                auto iterador = find_if(estudiantes.begin(), estudiantes.end(), 
                [leg](const shared_ptr<Estudiante>& est) {
                    return est->getLegajo() == leg;
                });
            
                if (iterador != estudiantes.end()) {
                    estudiantes.erase(iterador);

                } else { cout << "No se encontró al estudiante" << endl;}
            }

            const vector<shared_ptr<Estudiante>>& getEstudiantes() const {
                return estudiantes;
            }

            void inscribir(shared_ptr<Estudiante> estudiante) {
                if (estudiantes.size() < 20){estudiantes.push_back(estudiante);}
                else {cout <<"No hay cupos"<< endl;}
            }

            void buscar(int leg){
                auto iterador = find_if(estudiantes.begin(), estudiantes.end(), 
                [leg](const shared_ptr<Estudiante>& est) {
                    return est->getLegajo() == leg;
                    });
            
                if (iterador != estudiantes.end()) {
                    cout << "Estudiante inscripto" << endl;

                } else {cout << "Estudiante no inscripto" << endl;}
            }

            void completo (){
                if (estudiantes.size() == 20){ cout<< "Esta completo"<< endl;}
                else {cout <<"No esta completo"<<endl;}
            }

            void ordenar() { sort(estudiantes.begin(), estudiantes.end()); }

            Curso (const Curso& otroCurso){
                for (const auto& estudiante : otroCurso.estudiantes) {
                    estudiantes.push_back(make_shared<Estudiante>(*estudiante));
                }
            }
            //debo hacer una deep copy y no una shallow ya que Curso posee punteros con memoria alocada 
            //dinamicamente. La copia sera un nuevo objeto pero con toda su informacion alocada en otra posicion, 
            //entonces no habran problemas de memoria (no habran distintos punteros apuntando a una misma posicion de memoria).
            //Es decir que los cambios que se hagan en un Curso no afectaran al otro, que es lo que queremos. 
            //De esta manera, por ejemplo podriamos desinscribir a un alumno de un curso de ingles, pero no se va a ver afectado su curso de matematica.
        };

//c: Un Curso puede tener muchos Estudiantes, pero si el Curso se destruye, los Estudiantes no se 
//se destruyen. Los Estudiantes pueden existir por separado, hasta sin un Curso al que estén asociados, 
//porque pueden pertenecer a otros cursos o ser creados por otras por fuera del Curso.


#endif