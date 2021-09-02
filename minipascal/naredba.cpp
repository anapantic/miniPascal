#include "naredba.hpp"
#include "izrazi.hpp"
#include <typeinfo>
#include <iostream>
#include <string>
#include <map>

using namespace std;

extern map<string, int> tablica;

void tabovi(unsigned t) {
    for(unsigned i = 0; i < t; i++)
        cout << "\t";
}

void IspisS::nazubi(unsigned t) const {
    tabovi(t);
    
    cout<< "ispisi(\"" << _s << "\")";
}

void IspisS::izvrsi() const {
    cout << _s << endl;
}

void IspisE::nazubi(unsigned t) const {
    tabovi(t);
    
    cout<< "ispisi(";
    _i->nazubi(); 
    cout << ")";
}

void IspisE::izvrsi() const {
    cout << _i->vrednost() << endl;
}

IspisE::~IspisE() {
    delete _i;
}

void Blok::izvrsi() const {
    for(unsigned i = 0; i < _v.size(); i++)
        _v[i]->izvrsi();
}

void Blok::nazubi(unsigned t) const {
    tabovi(t);
    cout<<"pocetak"<<endl;
    
    unsigned i;
    for(i = 0; i < _v.size() - 1; i++) {
        _v[i]->nazubi(t+1);
        cout<<";"<<endl;
    }
    
    _v[i]->nazubi(t+1);
    cout<<endl;
    
    tabovi(t);
    cout<<"kraj";
    
    if(t==0)
        cout<<".\n";
//     else
//         cout<<endl;
}

Blok::~Blok() {
    for(unsigned i = 0; i < _v.size(); i++)
        delete _v[i];
}

void Dodela::izvrsi() const {
    tablica[_p] = _i->vrednost();
}
    
Dodela::~Dodela() {
    delete _i;
}
void Dodela::nazubi(unsigned t) const {
    tabovi(t);
    cout<<_p << " := ";
    _i->nazubi();
}

void Unesi::izvrsi() const {
    int tmp;
    cin >> tmp;
    tablica[_p] = tmp;
}

void Unesi::nazubi(unsigned t) const {
    tabovi(t);
    cout<<"unesi(" << _p <<")";
}

void AkoJeOndaInace::izvrsi() const {
    if(_i->vrednost())
        _n1->izvrsi();
    else
        _n2->izvrsi();
}
    
AkoJeOndaInace::~AkoJeOndaInace() {
    delete _i;
    delete _n1;
    delete _n2;
}

void AkoJeOndaInace::nazubi(unsigned t) const {
    tabovi(t);
    cout<< "ako_je ";
    _i->nazubi();
    cout<< " onda:"<<endl;
    
    _n1->nazubi(t+1);
    cout<<endl;
    
    tabovi(t);
    cout<<"inace:"<<endl;
    _n2->nazubi(t+1);
    cout<<endl;
}

void AkoJeOnda::izvrsi() const {
    if(_i->vrednost())
        _n1->izvrsi();
}

void AkoJeOnda::nazubi(unsigned t) const {
    tabovi(t);
    cout<< "ako_je ";
    _i->nazubi();
    cout << " onda:"<<endl;
    _n1->nazubi(t+1);
    cout<<endl;
}
    
AkoJeOnda::~AkoJeOnda() {
    delete _i;
    delete _n1;
}

void DokJe::izvrsi() const {
    while(_i->vrednost())
        _n->izvrsi();
}
    
DokJe::~DokJe() {
    delete _i;
    delete _n;
}

void DokJe::nazubi(unsigned t) const {
    tabovi(t);
    cout<<"dok_je ";
    _i->nazubi();
    cout << " radi_sledece:"<<endl;
    _n->nazubi(t+1);
    //cout<<endl;
}