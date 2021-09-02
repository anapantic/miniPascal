#include "izrazi.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

extern map<string, int> tablica;

int Promenljiva::vrednost() const {
    return tablica[_p];
}

void Promenljiva::nazubi() const {
    cout<<_p;
}

int Konstanta::vrednost() const {
    return _k;
}

void Konstanta::nazubi() const {
    cout<<_k;
}

BinOp::~BinOp() {
    delete _levi;
    delete _desni;
}

int Zbir::vrednost() const {
    return _levi->vrednost() + _desni->vrednost();
}

void Zbir::nazubi() const {
    _levi->nazubi();
    cout << " + ";
    _desni->nazubi();
}

int Razlika::vrednost() const {
    return _levi->vrednost() - _desni->vrednost();
}

void Razlika::nazubi() const {
    _levi->nazubi();
    cout << " - "; 
    _desni->nazubi();
}

int Proizvod::vrednost() const {
    return _levi->vrednost() * _desni->vrednost();
}

void Proizvod::nazubi() const {
    _levi->nazubi();
    cout<< " * ";
    _desni->nazubi();
}

int Kolicnik::vrednost() const {
    return _levi->vrednost() / _desni->vrednost();
}

void Kolicnik::nazubi() const {
    _levi->nazubi();
    cout << " / ";
    _desni->nazubi();
}

int Mod::vrednost() const {
    return _levi->vrednost() % _desni->vrednost();
}

void Mod::nazubi() const {
    _levi->nazubi(); 
    cout << " mod ";
    _desni->nazubi();
}

int Manje::vrednost() const {
    return _levi->vrednost() < _desni->vrednost();
}

void Manje::nazubi() const {
    _levi->nazubi();
    cout << " < ";
    _desni->nazubi();
}

int Vece::vrednost() const {
    return _levi->vrednost() > _desni->vrednost();
}

void Vece::nazubi() const {
    _levi->nazubi();
    cout << " > " ;
    _desni->nazubi();
}
