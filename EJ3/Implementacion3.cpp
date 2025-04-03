#include "INumero.h"
#include "Complejo.h"
#include "Entero.h"
#include "Real.h"

Entero::Entero(int n){ numero = n;}

string Entero::toString() const {
    return to_string(numero); //Para poder imprimir
}

unique_ptr<INumero> Entero::suma (const INumero& otro) const{
    const Entero& e = static_cast<const Entero&> (otro); //convierto al dato que ingresa en la funcion en tipo entero (con static cast)
    return make_unique<Entero>(numero + e.numero); //devuelvo el unique_ptr de tipo Entero apuntando a la suma de los dos numeros
}

//HAGO LO MISMO CON TODOS LOS DEMAS CASOS 

unique_ptr<INumero> Entero::resta (const INumero& otro) const{
    const Entero& e = static_cast<const Entero&>(otro);
    return make_unique<Entero>(numero - e.numero);
}

unique_ptr<INumero> Entero::producto (const INumero& otro) const{
    const Entero& e = static_cast<const Entero&>(otro);
    return make_unique<Entero>(numero * e.numero);
}

Real::Real(double n){ numero = n;}

string Real::toString() const {
    return to_string(numero); 
}

unique_ptr<INumero> Real::suma (const INumero& otro) const{
    const Real& r = static_cast<const Real&> (otro);
    return make_unique<Real>(numero + r.numero);
}

unique_ptr<INumero> Real::resta (const INumero& otro) const{
    const Real& r = static_cast<const Real&>(otro);
    return make_unique<Real>(numero - r.numero);
}

unique_ptr<INumero> Real::producto (const INumero& otro) const{
    const Real& r = static_cast<const Real&>(otro);
    return make_unique<Real>(numero * r.numero);
}

Complejo::Complejo(double r, double i) {
    real = r;
    imaginario = i;
}

string Complejo::toString() const { //cambia con los otros tipos de numero porque en complejos tengo parte imaginaria y parte real
    stringstream ss;
    ss << real;
    if (imaginario >= 0) {
        ss << " + " << imaginario << "i";
    } else {
        ss << " - " << -imaginario << "i";
    }
    return ss.str();
}

unique_ptr<INumero> Complejo::suma(const INumero& otro) const {
    const Complejo& c = static_cast<const Complejo&>(otro);
    return make_unique<Complejo>(real + c.real, imaginario + c.imaginario); //se devuelve en dos partes, la operacion se hace por parte real e imaginaria
}

unique_ptr<INumero> Complejo::resta(const INumero& otro) const {
    const Complejo& c = static_cast<const Complejo&>(otro);
    return make_unique<Complejo>(real - c.real, imaginario - c.imaginario);
}

unique_ptr<INumero> Complejo::producto(const INumero& otro) const {
    const Complejo& c = static_cast<const Complejo&>(otro);
    double r = real * c.real - imaginario * c.imaginario;
    double i = real * c.imaginario + imaginario * c.real;
    return make_unique<Complejo>(r, i);
}
