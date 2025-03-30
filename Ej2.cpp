#include <iostream>
#include "Ej2.h"

using namespace std;
int main (){
    Curso curso, cursoCopia;
    string nombre;
    int legajo, operacion;
    vector<MateriaNota> mats = { {"Matematica", 10.0}, {"Fisica", 7.5} }; 
    shared_ptr<Estudiante> nuevoEst;
    int seguir = 1;

    for (int i = 1; i <= 19; ++i) {
        vector<MateriaNota> materias = {
            {"Matematica", static_cast<float>((i * (13 + i)) % 10)}, 
            {"Fisica", static_cast<float>((i * (17 + i)) % 10)}  
        }; 
        shared_ptr<Estudiante> estudiante = make_shared<Estudiante>("Estudiante" + to_string(i), 1000 + i,materias);
        curso.inscribir(estudiante);
    }

    while (seguir){
        cout<<"Ingrese el numero de la operacion que desea realizar: "<<endl
            <<"1. Inscribir a un alumno"<<endl
            <<"2. Desinscribir a un alumno"<<endl
            <<"3. Verificar si un alumno esta inscripto"<<endl
            <<"4. Verificar si el curso esta completo"<<endl
            <<"5. Imprimir la lista en orden alfabetico"<<endl
            <<"6. Hacer copia del curso"<<endl;
        cin >> operacion;

        switch (operacion) {
            case 1:
                cout<<"Ingrese nombre del alumno: "<<endl;
                cin >> nombre;
                cout<< "Ingrese numero de legajo"<<endl;
                cin >> legajo;

                nuevoEst = make_shared<Estudiante>(nombre, legajo, mats);
                curso.inscribir(nuevoEst);

                break;

            case 2:
                cout << "Ingrese numero de legajo" << endl;
                cin >> legajo;
                curso.desinscribir(legajo);

                break;

            case 3:
                cout << "Ingrese numero de legajo" << endl;
                cin >> legajo;
                curso.buscar(legajo);

                break;

            case 4:
                curso.completo();
                break;

            case 5:
                curso.ordenar();
                for (const auto& alumno : curso.getEstudiantes()){
                    cout<<*alumno<<endl;
                }
                break;

            case 6:
                cursoCopia = curso;
                break;

            default:
                cout << "Opción no válida, por favor ingrese un número entre 1 y 6." << endl;
                break;
        }
        cout<<"Desea continuar haciendo operaciones?"<<endl
            <<"1. Si"<<endl
            <<"0. No"<<endl;
        cin >> seguir;
    }

    return 0;
}
