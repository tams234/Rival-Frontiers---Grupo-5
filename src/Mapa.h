//
// Created by Tamara Lanfranco on 27/11/25.
//

#ifndef PROYECTO_MODULOB_MAPA_H
#define PROYECTO_MODULOB_MAPA_H
#include <vector>
#include <iostream>
#include "Clases_baseMapa.h"

using namespace std;

class Mapa {
private:
    int filas;
    int columnas;
    vector<vector<Celda>> matriz;

public:
    Mapa(int _filas = 12, int _columnas = 12);

    int get_Filas() const { return filas; }
    int get_Columnas() const { return columnas; }

    Celda& get_Celda(int x, int y);
    void setTerreno(int x, int y, Terreno* t);
    void setEdificio(int x, int y, Edificios* e);

    bool esCoordenadaValida(int x, int y) const;
    void imprimir() const;

    void operator+= (const pair<Coord, Owner>& p);
    int calcularDominio(Owner p) const;
    friend ostream& operator<<(ostream& os, const Mapa& m);
};


#endif //PROYECTO_MODULOB_MAPA_H