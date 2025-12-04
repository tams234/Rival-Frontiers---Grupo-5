#ifndef PROYECTO_UNIDADES_H
#define PROYECTO_UNIDADES_H

#include <string>
#include "proyecto.h"
using namespace std;

class Mapa;

//Clase base
class Unidad: public Entidad {
protected:
    int vida;
    int ataque;
    int defensa;
    int rango;
    int movimiento;
    int puntosAccion;
    string nombre;
public:
    Unidad(Coord c, Owner o, int vida, int ataque, int defensa, int rango,
           int movimiento, int puntosAccion, const string& nombre);
    virtual ~Unidad() {}
    virtual bool mover(const Coord& c, Mapa& m);
    virtual int atacar(Unidad* objetivo);
    virtual void habilidad_especial(Unidad* objetivo) = 0;
    int get_Vida() const {
        return vida;
    };
    void set_Vida(int v) {
        vida = v;
    }
    int get_Defensa()const {
        return defensa;
    }
    void restar_Vida (int dano) {
        vida -= dano;
    }
    void restaurar_Vida(int cura) {
        vida += cura;
    }
    void set_PuntosAccion(int pa) {
        puntosAccion = pa;
    }
    string get_Nombre() const;
};

class Soldado : public Unidad {
public:
    Soldado(Coord c, Owner o);
    void habilidad_especial(Unidad* objetivo) override;
};

class Arquero : public Unidad {
public:
    Arquero(Coord c, Owner o);
    void habilidad_especial(Unidad* objetivo) override;
};

class Caballero : public Unidad {
public:
    Caballero(Coord c, Owner o);
    void habilidad_especial(Unidad* objetivo) override;
};

class Mago : public Unidad {
public:
    Mago(Coord c, Owner o);
    void habilidad_especial(Unidad* objetivo) override;
};

class Ingeniero : public Unidad {
public:
    Ingeniero(Coord c, Owner o);
    void habilidad_especial(Unidad* objetivo) override;
};

class Guardian : public Unidad {
    public:
    Guardian(Coord c);
    void habilidad_especial(Unidad* objetivo) override;
};

#endif
