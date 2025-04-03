#ifndef ENTERO_H
#define ENTERO_H

#include "INumero.h"
#include <string>
#include <memory>


class Entero: public INumero{
    private:
        int numero;

    public:
        Entero(int n = 0){ numero = n;}

        string toString() const override {
            return to_string(numero); //Para poder imprimir
        }

        unique_ptr<INumero> suma (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&> (otro); //convierto al dato que ingresa en la funcion en tipo entero (con static cast)
            return make_unique<Entero>(numero + e.numero); //devuelvo el unique_ptr de tipo Entero apuntando a la suma de los dos numeros
        }
        
        //HAGO LO MISMO CON TODOS LOS DEMAS CASOS Y EN LAS OTRAS CLASES TAMBIEN

        unique_ptr<INumero> resta (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero - e.numero);
        }

        unique_ptr<INumero> producto (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero * e.numero);
        }
        
};
#endif