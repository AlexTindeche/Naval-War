#ifndef NAVAL_WAR_SUBMARIN_H
#define NAVAL_WAR_SUBMARIN_H

#include "../nava/nava.h"

#include <iostream>

using namespace std;

class Submarin : public Nava
{
    int forma[2][1];
public:
    Submarin();
    ~Submarin();

    // Supraincarcarea operatorului de citire
    friend istream& operator >> (istream&, Submarin&);

    // Verificarea daca nava a fost lovita
    bool lovit(int, int);

    // Daca nava a fost lovita avaria este de 50
    void avariat(){avarie += 50;}

    // Autodistrugere
    void autodistrugere();
};


#endif //NAVAL_WAR_SUBMARIN_H
