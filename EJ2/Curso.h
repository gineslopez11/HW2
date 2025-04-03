#ifndef CURSO_H
#define CURSO_H

#include "Estudiante.h"
#include <memory>
#include <algorithm>

using namespace std;

class Curso {
private:
    vector<shared_ptr<Estudiante>> estudiantes;

public:
    Curso() {}
    void desinscribir(int leg);

    const vector<shared_ptr<Estudiante>>& getEstudiantes() const;

    void inscribir(shared_ptr<Estudiante> estudiante);

    void buscar(int leg);

    void completo();

    void ordenar();

    Curso(const Curso& otroCurso);
};

#endif