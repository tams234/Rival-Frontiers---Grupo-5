#include "proyecto.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

Coord::Coord(int x, int y){
    this->x = x;
    this->y = y;
}
int Coord::getX() const {
    return x;
}

int Coord::getY() const {
    return y;
}

void Coord::setX(int x){
    this->x = x;
}

void Coord::setY(int y){
    this->y = y;
}

ostream& operator<<(ostream& os, const Coord& c) {
    os << "(" << c.x << "," << c.y << ")";
    return os;
}

Recursos::Recursos(int food, int metal, int energy){
    this->food = food;
    this->metal = metal;
    this->energy = energy;
}
void Recursos::addFood(int food){
    this->food += food;
}

void Recursos::addMetal(int metal){
    this->metal += metal;
}

void Recursos::addEnergy(int energy){
    this->energy += energy;
}
int Recursos::getFood() const {
    return food;
}

bool Recursos::operator>(const Recursos& other) const {
    int this_power = food + metal + energy;
    int other_power = other.food + other.metal + other.energy;
    return this_power > other_power;
}

ostream& operator<<(ostream& os, const Recursos& r){
    os << "[Food:" << r.food
       << " Metal:" << r.metal
       << " Energy:" << r.energy << "]";
    return os;
}

Entidad::Entidad(Coord c, Owner o) : posicion(c), owner(o) {}
Coord Entidad::getPosicion() const { return posicion; }

Evento::Evento(int t) : triggerTurn(t) {}
RecursosEvento::RecursosEvento(int t) : Evento(t) {}

void RecursosEvento::apply(Context& ctx) {
    ctx.playerResources.addFood(5);
    cout << "[Evento] Recursos modificados: Player Resources +5 de comida." << endl;
}

int Evento::getTurn() const {
    return triggerTurn;
}


void JugadorControl::update(Context& ctx){
    cout << "[JugadorControl] Turno del jugador (Turno: " << ctx.turn << ")" << endl;
}

string JugadorControl::name() const{
    return "JugadorControl";
}

void SystemController::update(Context& ctx){
    cout << "[SystemController] Ejecutando logica del sistema (Turno: " << ctx.turn << ")" << endl;
}

string SystemController::name() const{
    return "SystemController";
}

void NeutralController::update(Context& ctx){
    cout << "[NeutralController] Turno neutral (Turno: " << ctx.turn << ")" << endl;
}

string NeutralController::name() const{
    return "NeutralController";
}

Context::Context(){
    turn = 1;
    playerResources = Recursos(20,10,5);
    systemResources = Recursos(15,5,3);
}

Context::~Context(){

    for(Evento* e : events)
        delete e;

    for(controles* c : controllers)
        delete c;
}

void Context::addUnit(Unidad* u){
    units.push_back(u);
}

void Context::addEvent(Evento* e){
    events.push_back(e);
}

void Context::addController(controles* c){
    controllers.push_back(c);
}
