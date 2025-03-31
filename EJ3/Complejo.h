#ifndef COMPLEJO_H
#define COMPLEJO_H

#include "INumero.h"
#include <string>
#include <memory>
#include <sstream>


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