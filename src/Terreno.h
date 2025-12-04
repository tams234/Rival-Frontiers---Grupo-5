//
// Created by Tamara Lanfranco on 27/11/25.
//

#ifndef PROYECTO_MODULOB_TERRENO_H
#define PROYECTO_MODULOB_TERRENO_H
#include <string>
#include "unidades.h"
using namespace std;



// clase base para todos los tipos de terrenos
class Terreno {
private:
    string codigo;
public:
    Terreno(const string& _codigo) : codigo(_codigo) {}
    virtual ~Terreno() {}
    string getCodigo() const {
        return codigo;
    }
    virtual int costo_movimiento(const Unidad& u) const = 0;
    virtual int bono_defensa(const Unidad& u) const = 0;
};

//Terreno Agua
class Agua : public Terreno {
public:
    Agua() : Terreno("AG") {}
    int costo_movimiento(const Unidad& u) const override {
        return 9999;
    }

    int bono_defensa(const Unidad& u) const override {
        return 0;
    }
};


//Terreno Bosque
class Bosque : public Terreno {
public:
    Bosque() : Terreno("BO") {}
    int costo_movimiento(const Unidad& u) const override {
        return 2;
    }

    int bono_defensa(const Unidad& u) const override {
        return 1;
    }
};

//Terreno Llanura
class Llanura : public Terreno {
public:
    Llanura() : Terreno("LL") {}
    int costo_movimiento(const Unidad& u) const override {
        return 1;
    }

    int bono_defensa(const Unidad& u) const override {
        return 0;
    }
};

//Terreno Montaña
class Montaña : public Terreno {
public:
    Montaña() : Terreno("MO") {}
    int costo_movimiento(const Unidad& u) const override {
        return 3;
    }

    int bono_defensa(const Unidad& u) const override {
        return 2;
    }
};

//Terreno Pantano
class Pantano : public Terreno {
public:
    Pantano() : Terreno("PA") {}
    int costo_movimiento(const Unidad& u) const override {
        return 4;
    }

    int bono_defensa(const Unidad& u) const override {
        return -1;
    }
};

#endif //PROYECTO_MODULOB_TERRENO_H