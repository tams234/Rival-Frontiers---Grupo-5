#include "unidades.h"
#include "Mapa.h"
#include <iostream>
using namespace std;

Unidad::Unidad(Coord c, Owner o, int vida, int ataque, int defensa, int rango, int movimiento, int puntosAccion, const string &nombre)
    : Entidad(c, o), vida(vida), ataque(ataque), defensa(defensa), rango(rango),
      movimiento(movimiento), puntosAccion(puntosAccion), nombre(nombre) {}

bool Unidad::mover(const Coord& c, Mapa& m) {
    if (puntosAccion <= 0) return false;
    setPosicion(c);
    puntosAccion--;
    return true;
}

int Unidad::atacar(Unidad* objetivo) {
    if (puntosAccion <= 0 || objetivo == nullptr) return 0;
    int dano = ataque - objetivo->get_Defensa();
    if (dano < 0) dano = 0;
    objetivo->restar_Vida(dano);
    puntosAccion--;
    return dano;
}

string Unidad::get_Nombre() const {
    return nombre;
}

Soldado::Soldado(Coord c, Owner o)
    :Unidad(c,o,100,20,10,1,3,2,"Soldado"){}

void Soldado::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    int dano = (ataque * 1.5) - objetivo->get_Defensa();
    if (dano < 0) dano = 0;
    objetivo->restar_Vida(dano);
}

Arquero::Arquero(Coord c, Owner o)
    : Unidad(c, o, 70, 25, 5, 3, 2, 2, "Arquero") {}

void Arquero::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    objetivo->restar_Vida(ataque);
}

Caballero::Caballero(Coord c, Owner o)
    : Unidad(c, o, 150, 30, 20, 1, 4, 2, "Caballero") {}

void Caballero::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    objetivo->restar_Vida((ataque + defensa) / 2);
}

Mago::Mago(Coord c, Owner o)
    : Unidad(c, o, 60, 40, 0, 5, 2, 1, "Mago") {}

void Mago::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    objetivo -> restar_Vida(ataque * 2);
    cout << "Mago: Bola de Fuego (Daño x2)." << endl;
}

Ingeniero::Ingeniero(Coord c, Owner o)
    : Unidad(c, o, 80, 5, 10, 1, 3, 1, "Ingeniero") {}

void Ingeniero::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    if (getOwner() == objetivo->getOwner()) {
        objetivo->restaurar_Vida(20);
        cout << "Ingeniero: Reparando unidad aliada (+20 HP)." << endl;
    }
}

Guardian::Guardian(Coord c)
    : Unidad(c, Owner::SYSTEM,200,40,30,1,2,2,"Guardian"){}

void Guardian::habilidad_especial(Unidad* objetivo) {
    if (objetivo == nullptr) return;
    objetivo->set_PuntosAccion(0);
    cout << "Guardian: Paralizando objetivo (pierde turno)." << endl;
}

