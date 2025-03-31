#ifndef INUMERO_H
#define INUMERO_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class INumero{
    public:
        virtual string toString() const = 0;
        virtual unique_ptr<INumero> suma(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> resta(const INumero& otro) const = 0;
        virtual unique_ptr<INumero> producto(const INumero& otro) const = 0;
        virtual ~INumero() = default;  

};

#endif
