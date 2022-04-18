#ifndef NAVAL_WAR_DISTRUGATOR_H
#define NAVAL_WAR_DISTRUGATOR_H

#include "../nava/nava.h"
#include <iostream>

using namespace std;

class Distrugator : public Nava
{
    int forma[3][1];
public:
    Distrugator();
    ~Distrugator();

    // Supraincarcarea operatorului de citire
    friend istream& operator >> (istream&, Distrugator&);

    // Verificarea daca nava a fost lovita
    bool lovit(int, int);

    // Daca nava a fost lovita avaria este de 35
    void avariat(){avarie += 35; if(avarie > 100) avarie = 100;}

    void regenerare();
};


#endif //NAVAL_WAR_DISTRUGATOR_H
