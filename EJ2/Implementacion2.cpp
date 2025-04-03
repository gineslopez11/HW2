#include "Curso.h"
#include "Estudiante.h"

//Curso::Curso(){};
void Curso::desinscribir(int leg) {
    auto iterador = find_if(estudiantes.begin(), estudiantes.end(), 
    [leg](const shared_ptr<Estudiante>& est) { //uso find_if para mover el iterador a la posicion donde se encuentra mi legajo que busco, si no devuelve estudiantes.end()
        return est->getLegajo() == leg; //si el elemento donde esta parado sobre el que busco (en el tercer parametro de find if), la variable iterador apunta hacia esa posicion
    });

    if (iterador != estudiantes.end()) {
        estudiantes.erase(iterador); //si el iterador no es end, significa que lo encontro, entonces lo elimino de mi vector

    } else { cout << "No se encontró al estudiante" << endl;}
}

const vector<shared_ptr<Estudiante>>& Curso::getEstudiantes() const {
    return estudiantes;
}

void Curso::inscribir(shared_ptr<Estudiante> estudiante) {
    if (estudiantes.size() < 20){estudiantes.push_back(estudiante);} // si hay lugar en el curso, lo inscribo simplemente haciendo un push back al vector
    else {cout <<"No hay cupos"<< endl;}
}

void Curso::buscar(int leg){
    auto iterador = find_if(estudiantes.begin(), estudiantes.end(), 
    [leg](const shared_ptr<Estudiante>& est) { //Hago lo mismo que hice para desinscribir solon que simplemente imprimo si esta inscripto o no
        return est->getLegajo() == leg;
        });

    if (iterador != estudiantes.end()) {
        cout << "Estudiante inscripto" << endl;

    } else {cout << "Estudiante no inscripto" << endl;}
}

void Curso::completo (){
    if (estudiantes.size() == 20){ cout<< "Esta completo"<< endl;}
    else {cout <<"No esta completo"<<endl;}
}

void Curso::ordenar() { sort(estudiantes.begin(), estudiantes.end()); } //ordena alfabeticamente

Curso::Curso(const Curso& otroCurso) {
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


Estudiante::Estudiante(string nom, int leg, vector<MateriaNota> mat){ //Por defecto se crea un estudiante "vacio"
    nombre = nom;
    legajo = leg;
    materias = mat;
}

string Estudiante::getNombre(){ return nombre; }

int Estudiante::getLegajo(){ return legajo; }

float Estudiante::getPromedio(){
    float suma_notas = 0;
    for(const auto& materia : materias){
        suma_notas += materia.nota; //recorro el vector de materias y voy sumando todas las notas que tiene
    }
    return suma_notas/materias.size(); //divido la suma de sus notas por todas las notas que tiene
}

bool Estudiante::operator<(const Estudiante& otro) const { return nombre < otro.nombre;} //cambio operador < para poder ordenar luego alfabeticamente en el sort

ostream& operator<< (ostream& os, const Estudiante& est){
    os << "Nombre: " << est.nombre << ", Legajo: " << est.legajo; //cambio operador << para poder imprimir directamente con cout y no tener que acceder a atributos
    return os;
}




//c: Este caso es relacion de Agregacion. Un Curso puede tener muchos Estudiantes, pero si el Curso se destruye, los Estudiantes no se 
//se destruyen. Los Estudiantes pueden existir sin pertenecer a ese Curso en particular, trasladandoce a un curso diferente. 
//Lo mismo con el Curso, este no depende de esos estudiantes, sino que puede tener estudiantes distintos o estar vacio.
