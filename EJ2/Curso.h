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
                [leg](const shared_ptr<Estudiante>& est) { //uso find_if para mover el iterador a la posicion donde se encuentra mi legajo que busco, si no devuelve estudiantes.end()
                    return est->getLegajo() == leg; //si el elemento donde esta parado sobre el que busco (en el tercer parametro de find if), la variable iterador apunta hacia esa posicion
                });
            
                if (iterador != estudiantes.end()) {
                    estudiantes.erase(iterador); //si el iterador no es end, significa que lo encontro, entonces lo elimino de mi vector

                } else { cout << "No se encontró al estudiante" << endl;}
            }

            const vector<shared_ptr<Estudiante>>& getEstudiantes() const {
                return estudiantes;
            }

            void inscribir(shared_ptr<Estudiante> estudiante) {
                if (estudiantes.size() < 20){estudiantes.push_back(estudiante);} // si hay lugar en el curso, lo inscribo simplemente haciendo un push back al vector
                else {cout <<"No hay cupos"<< endl;}
            }

            void buscar(int leg){
                auto iterador = find_if(estudiantes.begin(), estudiantes.end(), 
                [leg](const shared_ptr<Estudiante>& est) { //Hago lo mismo que hice para desinscribir solon que simplemente imprimo si esta inscripto o no
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

            void ordenar() { sort(estudiantes.begin(), estudiantes.end()); } //ordena alfabeticamente

            Curso (const Curso& otroCurso){
                for (const auto& estudiante : otroCurso.estudiantes) {
                    estudiantes.push_back(make_shared<Estudiante>(*estudiante));
                }
            }
            Curso(const Curso& otroCurso) {
                estudiantes = otroCurso.estudiantes; 
            }
            // Se debe hacer una shallow copy en vez de una deep copy porque los cursos comparten estudiantes. 
            // Si se hiciera una deep copy, cada curso tendría una copia independiente de cada estudiante, 
            // lo que haría que lo cambios de un curso no se hagan en el otro. 
            // Por ejemplo, si un estudiante cambia su apellido, el cambio debería ser en todos los cursos que pertenece. 
            // Con una shallow copy, los cursos comparten punteros a los mismos objetos.  
            // Además, si un estudiante es eliminado de un curso, no debería desaparecer de los demás cursos,
            // Esto se maneja con shared_ptr, ya que al eliminar un estudiante de un curso, solo se borra su referencia, 
            // y el estudiante solo se elimina de memoria cuando ningún el estudiante no este en ningun curso más.
        };

//c: Este caso es relacion de Agregacion. Un Curso puede tener muchos Estudiantes, pero si el Curso se destruye, los Estudiantes no se 
//se destruyen. Los Estudiantes pueden existir sin pertenecer a ese Curso en particular, trasladandoce a un curso diferente. 
//Lo mismo con el Curso, este no depende de esos estudiantes, sino que puede tener estudiantes distintos o estar vacio.


#endif