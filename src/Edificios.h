//
// Created by Tamara Lanfranco on 27/11/25.
//

#ifndef PROYECTO_MODULOB_EDIFICIO_H
#define PROYECTO_MODULOB_EDIFICIO_H

#include <string>
#include "proyecto.h"
using namespace std;

class Edificios {
private:
    string codigo;

public:
    Edificios(const string& _codigo) : codigo(_codigo) {}
    virtual ~Edificios() {}
    string getCodigo() const {
        return codigo;
    }
    virtual void efecto_turno(Recursos& f) = 0;
    virtual void reaccion_evento(const Evento& e) = 0;
};

class Granja : public Edificios {
    public:
    Granja() : Edificios("Gr") {}
    void efecto_turno(Recursos& f) override {
        f.addFood (2);
    }
    void reaccion_evento(const Evento& e) override {}
};

class Torre : public Edificios {
public:
    Torre() : Edificios("To") {}
    void efecto_turno(Recursos& f) override {
        f.addEnergy(1);
    }
    void reaccion_evento(const Evento& e) override {}
};

class Cuartel : public Edificios {
public:
    Cuartel() : Edificios("Cu") {}
    void efecto_turno(Recursos& f) override {
        f.addMetal(1);
    }
    void reaccion_evento(const Evento& e) override {}
};

class Forja : public Edificios {
public:
    Forja() : Edificios("Fo") {}
    void efecto_turno(Recursos& f) override {
        f.addMetal(3);
        f.addEnergy(-1);
    }
    void reaccion_evento(const Evento& e) override {}
};


#endif //PROYECTO_MODULOB_EDIFICIO_H