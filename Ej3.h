#ifndef EJ3_H
#define EJ3_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <sstream>

using namespace std;

class INumero{
    public:
        virtual string toString() const = 0;
        virtual unique_ptr<INumero> suma(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> resta(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> producto(const INumero& otro) const = 0;
        virtual ~INumero() = default;  

};

class Entero: public INumero{
    private:
        int numero;

    public:
        Entero(int n = 0){ numero = n;}

        string toString() const override {
            return to_string(numero); 
        }

        unique_ptr<INumero> suma (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&> (otro);
            return make_unique<Entero>(numero + e.numero);
        }

        unique_ptr<INumero> resta (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero - e.numero);
        }

        unique_ptr<INumero> producto (const INumero& otro) const override{
            const Entero& e = static_cast<const Entero&>(otro);
            return make_unique<Entero>(numero * e.numero);
        }
        
};

class Real: public INumero{
    private:
        double numero;

    public:
        Real(double n = 0){ numero = n;}

        string toString() const override {
            return to_string(numero); 
        }

        unique_ptr<INumero> suma (const INumero& otro) const override{
            const Real& r = static_cast<const Real&> (otro);
            return make_unique<Real>(numero + r.numero);
        }

        unique_ptr<INumero> resta (const INumero& otro) const override{
            const Real& r = static_cast<const Real&>(otro);
            return make_unique<Real>(numero - r.numero);
        }

        unique_ptr<INumero> producto (const INumero& otro) const override{
            const Real& r = static_cast<const Real&>(otro);
            return make_unique<Real>(numero * r.numero);
        }
        
};


class Complejo : public INumero {
    private:
        double real;
        double imaginario;
    
    public:
        Complejo(double r = 0, double i = 0) {
            real = r;
            imaginario = i;
        }

        string toString() const override {
            stringstream ss;
            ss << real;
            if (imaginario >= 0) {
                ss << " + " << imaginario << "i";
            } else {
                ss << " - " << -imaginario << "i";
            }
            return ss.str();
        }
    
        unique_ptr<INumero> suma(const INumero& otro) const override {
            const Complejo& c = static_cast<const Complejo&>(otro);
            return make_unique<Complejo>(real + c.real, imaginario + c.imaginario);
        }
    
        unique_ptr<INumero> resta(const INumero& otro) const override {
            const Complejo& c = static_cast<const Complejo&>(otro);
            return make_unique<Complejo>(real - c.real, imaginario - c.imaginario);
        }
    
        unique_ptr<INumero> producto(const INumero& otro) const override {
            const Complejo& c = static_cast<const Complejo&>(otro);
            double r = real * c.real - imaginario * c.imaginario;
            double i = real * c.imaginario + imaginario * c.real;
            return make_unique<Complejo>(r, i);
        }
};

#endif