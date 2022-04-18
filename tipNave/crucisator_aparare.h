#ifndef NAVAL_WAR_CRUCISATOR_APARARE_H
#define NAVAL_WAR_CRUCISATOR_APARARE_H

#include "../nava/nava.h"
#include <iostream>

using namespace std;

class Crucisator_aparare : public Nava
{
    int forma[3][4];
    bool sistem_aparare;
public:
    Crucisator_aparare();
    ~Crucisator_aparare();

    // Supraincarcarea operatorului de citire
    friend istream& operator >> (istream&, Crucisator_aparare&);

    // Verificarea daca nava a fost lovita
    bool lovit(int, int);

    // Daca nava a fost lovita avaria este de 20
    void avariat(){avarie += 20; if(avarie > 100) avarie = 100;}

    // Armarea + dezarmarea sistemului de aparare
    void armare();
    void dezarmare();
};


#endif //NAVAL_WAR_CRUCISATOR_APARARE_H
