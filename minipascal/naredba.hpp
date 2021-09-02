#ifndef __NAREDBA_HPP__
#define __NAREDBA_HPP__ 1

#include "izrazi.hpp"
#include <string>
#include <vector>

using namespace std;

class Naredba {
public:
    virtual void izvrsi() const = 0;
    virtual void nazubi(unsigned t) const = 0;
    virtual ~Naredba() {
        
    }
};

class IspisS : public Naredba {
public:
    IspisS(string s)
        :_s(s)
    {}
    
    void nazubi(unsigned t) const;
    
    void izvrsi() const;
    
private:
    string _s;
};

class IspisE : public Naredba {
public:
    IspisE(Izraz *i)
        :_i(i)
    {}
    
    void nazubi(unsigned t) const;
    
    void izvrsi() const;
    
    ~IspisE();
    
private:
    IspisE(const IspisE&);
    IspisE& operator=(const IspisE&);
    Izraz *_i;
};

class Blok : public Naredba {
public:
    Blok(vector<Naredba*> v)
        :_v(v)
    {}
    
    void nazubi(unsigned t) const;
    
    void izvrsi() const;
    
    ~Blok();
private:
    Blok(const Blok&);
    Blok& operator=(const Blok&);
    vector<Naredba*> _v;
};

class Dodela : public Naredba {
public:
    Dodela(string p, Izraz *i)
        :_p(p), _i(i)
    {}
    
    void izvrsi() const;
    
    void nazubi(unsigned t) const;
    
    ~Dodela();
    
private:
    Dodela(const Dodela&);
    Dodela& operator=(const Dodela&);
    string _p;
    Izraz *_i;
};

class AkoJeOndaInace : public Naredba {
public:
    AkoJeOndaInace(Izraz *i, Naredba *n1, Naredba *n2)
        :_i(i), _n1(n1), _n2(n2)
    {}
    
    void izvrsi() const;
    
    void nazubi(unsigned t) const;
    
    ~AkoJeOndaInace();
    
private:
    AkoJeOndaInace(const AkoJeOndaInace&);
    AkoJeOndaInace& operator=(const AkoJeOndaInace&);
    Izraz *_i;
    Naredba *_n1;
    Naredba *_n2;
};

class AkoJeOnda : public Naredba {
public:
    AkoJeOnda(Izraz *i, Naredba *n1)
        :_i(i), _n1(n1)
    {}
    
    void izvrsi() const;
    
    void nazubi(unsigned t) const;
    
    ~AkoJeOnda();
    
private:
    AkoJeOnda(const AkoJeOnda&);
    AkoJeOnda& operator=(const AkoJeOnda&);
    Izraz *_i;
    Naredba *_n1;
};

class Unesi : public Naredba {
public:
    Unesi(string p)
        :_p(p)
    {}
    
    void nazubi(unsigned t) const;
    
    void izvrsi() const;
    
private:
    string _p;
};

class DokJe : public Naredba {
public:
    DokJe(Izraz *i, Naredba *n)
        :_i(i), _n(n)
    {}
    
    void izvrsi() const;
    
    void nazubi(unsigned t) const;
    
    ~DokJe();

private:
    DokJe(const DokJe&);
    DokJe& operator=(const DokJe&);
    Izraz *_i;
    Naredba *_n;
};

#endif