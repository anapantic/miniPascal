#ifndef __IZRAZI_HPP__
#define __IZRAZI_HPP__ 1

#include <iostream>
#include <string>

using namespace std;

class Izraz {
public:
    virtual int vrednost() const = 0;
    virtual void nazubi() const = 0;
    virtual ~Izraz(){
        
    }
};

class Promenljiva : public Izraz {
public:
    Promenljiva(string p)
        :_p(p)
    {}
    
    virtual void nazubi() const;
    
    int vrednost() const;
    
private:
    string _p;
};

class Konstanta : public Izraz {
public:
    Konstanta(int k)
        :_k(k)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
    
private:
    int _k;
};

class BinOp : public Izraz {
public:
    BinOp(Izraz *levi, Izraz *desni)
        :_levi(levi), _desni(desni)
    {}
    
    //cim nema int vrednost() const predefinisan, ona je apstraktna
    
    ~BinOp();
    
private:
    BinOp(const BinOp&);
    BinOp& operator=(const BinOp&);
protected:
    Izraz *_levi;
    Izraz *_desni;
};

class Zbir : public BinOp {
public:
    Zbir(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
    
    
};

class Razlika : public BinOp {
public:
    Razlika(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
};

class Proizvod : public BinOp {
public:
    Proizvod(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
};

class Kolicnik : public BinOp {
public:
    Kolicnik(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}

    void nazubi() const;
    
    int vrednost() const;
};

class Mod : public BinOp {
public:
    Mod(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
};

class Manje : public BinOp {
public:
    Manje(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
};

class Vece : public BinOp {
public:
    Vece(Izraz *levi, Izraz *desni)
        :BinOp(levi, desni)
    {}
    
    void nazubi() const;
    
    int vrednost() const;
};

#endif