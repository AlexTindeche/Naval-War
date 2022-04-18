#ifndef NAVAL_WAR_CRUCISATOR_H
#define NAVAL_WAR_CRUCISATOR_H

#include "../nava/nava.h"
#include <iostream>

using namespace std;

class Crucisator : public Nava
{
    int forma[3][2];
public:
    Crucisator();
    ~Crucisator();

    // Supraincarcarea operatorului de citire
    friend istream& operator >> (istream&, Crucisator&);

    // Verificarea daca nava a fost lovita
    bool lovit(int, int);

    // Daca nava a fost lovita avaria este de 20
    void avariat(){avarie += 20; if(avarie > 100) avarie = 100;}
};


#endif //NAVAL_WAR_CRUCISATOR_H
