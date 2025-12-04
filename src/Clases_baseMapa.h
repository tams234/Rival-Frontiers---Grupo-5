//
// Created by Tamara Lanfranco on 27/11/25.
//

#ifndef PROYECTO_MODULOB_CELDA_H
#define PROYECTO_MODULOB_CELDA_H
#include "Terreno.h"
#include "Edificios.h"
#include "proyecto.h"
#include "unidades.h"

class Celda {
private:
    Terreno* terreno;
    Edificios* edificio;
    Unidad* unidad;
    Owner owner;

public:
    Celda() : terreno(nullptr), edificio(nullptr), unidad(nullptr) {}

    void setTerreno(Terreno* t) {
        terreno = t;
    }

    void setEdificio(Edificios* e) {
        edificio = e;
    }

    void setUnidad(Unidad* u) {
        unidad = u;
    }

    Terreno* getTerreno() const {
        return terreno;
    }

    Edificios* getEdificio() const {
        return edificio;
    }

    Unidad* getUnidad() const {
        return unidad;
    }

    bool estaLibre() const {
        return unidad == nullptr && edificio == nullptr;
    }
    void setOwner(Owner p) {
        owner = p;
    }
    Owner getOwner() const {
        return owner;
    }
};


#endif //PROYECTO_MODULOB_CELDA_H