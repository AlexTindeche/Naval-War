#ifndef NAVAL_WAR_SALUPA_H
#define NAVAL_WAR_SALUPA_H

#include <iostream>

using namespace std;

#include "../nava/nava.h"

class Salupa : public Nava
{
    int forma;
public:
    Salupa();
    ~Salupa();

    // Supraincarcarea operatorului de citire
    friend istream& operator >> (istream&, Salupa&);

    // Verificarea daca nava a fost lovita
    bool lovit(int, int);

    // Daca nava a fost lovita avaria este de 100
    void avariat(){avarie = 100;}
};


#endif //NAVAL_WAR_SALUPA_H
