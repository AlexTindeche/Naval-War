#include "nava.h"
#include <iostream>
#include "../common.h"

// Construcotrul clasei Nava
Nava::Nava(char * tip, int combustibil_initial){
    // tip
    this->tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);

    // combustibil_initial
    this->combustibil_initial = combustibil_initial;

    rachete = 0;

    //coordonatele vor fi automat puse pe niste valori care nu pot exista
    Pozitie xy;
    xy.setX(-100);
    xy.setY(-100);
    avarie = 0;
    activ = 1;
};

// Destructorul clasei Nava
Nava::~Nava(){
    delete[] tip;
}


// Atac:

void Nava::atac(){
    int x, y;
    cout << "Introduceti coordinatele pe care vreti sa le atacati: ";
    try
    {
        cin >> x >> y;
        if(x > dim || y > dim || x < 0 || y < 0)
            throw 0;
    }
    catch(...)
    {
        while(x > dim || y > dim || x < 0 || y < 0)
        {
            cout << "Coordonatele nu exista, introduceti datele din nou: ";
            cin >> x >> y;
        }
    }

    rachete--;
    // Pentru a ingreuna jocul, se pot ataca si propriile nave, chiar da este din greseala jucatorului!
    // Asa ca vom trece prin toti vectori de nave pentru a determina daca se afla ceva la coordonatele respective
    for(int i = 0; i < salupe.size(); i++){
        if(salupe[i].second.lovit(x, y))
            salupe[i].second.avariat();

    }
    for(int i = 0; i < submarine.size(); i++){
        if(submarine[i].second.lovit(x, y))
            submarine[i].second.avariat();
    }
    for(int i = 0; i < distrugatoare.size(); i++){
        if(distrugatoare[i].second.lovit(x, y))
            distrugatoare[i].second.avariat();
    }
    for(int i = 0; i < crucisatoare.size(); i++){
        if(crucisatoare[i].second.lovit(x, y))
            crucisatoare[i].second.avariat();
    }
    for(int i = 0; i < crucisatoare_aparare.size(); i++){
        if(crucisatoare_aparare[i].second.lovit(x, y))
            crucisatoare_aparare[i].second.avariat();
    }
}