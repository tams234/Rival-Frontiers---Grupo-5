//
// Created by Tamara Lanfranco on 27/11/25.
//

#include "Mapa.h"
using namespace std;

Mapa::Mapa(int _filas, int _columnas) {
    filas = _filas;
    columnas = _columnas;
    matriz = vector<vector<Celda>>(filas, vector<Celda>(columnas));
}

Celda& Mapa::get_Celda(int x, int y) {
    return matriz[x][y];
}

bool Mapa::esCoordenadaValida(int x, int y) const {
    return x >= 0 && x < filas && y >= 0 && y < columnas;
}

void Mapa::setTerreno(int x, int y, Terreno* t) {
    if (esCoordenadaValida(x, y)) {
        matriz[x][y].setTerreno(t);
    }
}

void Mapa::setEdificio(int x, int y, Edificios* e) {
    if (esCoordenadaValida(x, y)) {
        matriz[x][y].setEdificio(e);
    }
}

void Mapa::imprimir() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            Terreno* t = matriz[i][j].getTerreno();

            if (t != nullptr) {
                cout << "[" << t->getCodigo() << "]";
            } else {
                cout << "[  ]";
            }
        }
        cout << "\n";
    }
}

void Mapa::operator+=(const pair<Coord, Owner>& p) {
    Coord c = p.first;
    if (esCoordenadaValida(c.getX(), c.getY())) {
        matriz[c.getX()][c.getY()].setOwner(p.second);
    }
}

int Mapa::calcularDominio(Owner p) const {
    int total = filas * columnas;
    int contador = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j].getOwner() == p) contador++;
        }
    }
    if (total == 0) return 0;
    return (contador * 100) / total;
}

ostream& operator<<(ostream& os, const Mapa& m) {
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            const Celda& c = m.matriz[i][j];
            string ownerCode = "..";
            switch (c.getOwner()) {
                case Owner::NEUTRAL: ownerCode = "N"; break;
                case Owner::PLAYER: ownerCode = "P"; break;
                case Owner::SYSTEM: ownerCode = "S"; break;
            }

            string code = "";
            if (c.getUnidad() != nullptr) {
                code = c.getUnidad()->get_Nombre().substr(0, 1);
            } else if (c.getEdificio() != nullptr) {
                code = c.getEdificio()->getCodigo().substr(0, 1);
            } else if (c.getTerreno() != nullptr) {
                code = c.getTerreno()->getCodigo().substr(0, 1);
            } else {
                code = " ";
            }

            os << "[" << ownerCode << code << "]";
        }
        os << "\n";
    }
    return os;
}
