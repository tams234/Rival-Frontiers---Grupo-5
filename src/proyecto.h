//
// Created by Ricardo on 30/11/2025.
//

#ifndef PROYECTO_FINAL_PROYECTO_H
#define PROYECTO_FINAL_PROYECTO_H

#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Unidad;

enum class Owner {PLAYER, SYSTEM, NEUTRAL};

class Coord {
private:
    int x, y;
public:
    Coord(int x=0, int y=0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    friend ostream& operator << (ostream&, const Coord& );
};

class Recursos {
private:
    int food, metal, energy;
public:
    Recursos(int food=0, int metal=0, int energy=0);
    void addFood(int food);
    void addMetal(int metal);
    void addEnergy(int energy);
    bool operator>(const Recursos& other) const;
    int getFood() const;
    friend ostream& operator << (ostream&, const Recursos& );
};

class Logger {
private:
    ofstream file;
public:
    Logger();
    ~Logger();
    void log(const string&);
};

class Entidad {
private:
    Coord posicion;
    Owner owner;
public:
    Entidad(Coord c, Owner o);
    virtual ~Entidad() {}
    Coord getPosicion() const;
    Owner getOwner() const { return owner; }
    void setPosicion(const Coord& c) { posicion = c; }
};

class Evento {
protected:
    int triggerTurn;
public:
    Evento(int t);
    virtual ~Evento() {}
    int getTurn() const;
    virtual void apply(class Context&) = 0;
};

class RecursosEvento : public Evento {
private:
    int comida;
public:
    RecursosEvento(int t);
    void apply(class Context&) override;
};

class controles {
public:
    virtual void update(class Context&) =0;
    virtual string name() const = 0;
    virtual ~controles(){}
};

class JugadorControl : public controles {
public:
    void update(class Context &) override;
    string name() const override;
};

class SystemController : public controles{
public:
    void update(class Context&) override;
    string name() const override;
};

class NeutralController : public controles{
public:
    void update(class Context&) override;
    string name() const override;
};

class Context{
public:
    vector<Unidad*> units;
    vector<Evento*> events;
    vector<controles*> controllers;

    Recursos playerResources;
    Recursos systemResources;
    int turn;

public:
    Context();
    ~Context();
    void addUnit(Unidad* u);
    void addEvent(Evento* e);
    void addController(controles* c);
};



#endif //PROYECTO_FINAL_PROYECTO_H