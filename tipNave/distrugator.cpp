#include "distrugator.h"
#include "../common.h"

Distrugator::Distrugator () : Nava("Distrugator", 300){for(int i = 0; i < 3; i++) forma[i][0] = 1;}
Distrugator::~Distrugator() = default;

istream& operator >> (istream& in, Distrugator& s){
    cout << "Introduceti pozitia navei (punctul cel din stanga cel mai jos al navei va reprezenta pozitia ei)\n";
    int ok = 0, x, y;
    while(ok == 0){
        cout << "\nX ";
        in >> x;
        cout << "\nY ";
        in >> y;
        ok = 1;
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 3; j++)
                if(tabla[i][j] == 1)
                    ok = 0;
        if(x > dim - 3 || y > dim - 2 || y < 0 || x < 0)
            ok = 0;
    }
    if(ok == 1){
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 2; j++)
                tabla[i][j] = 1;
        s.setX(x);
        s.setY(y);
    }
    cout << "Nr. rachete: ";
    in >> s.rachete;
    return in;
}

// Verificam daca e lovit
bool Distrugator::lovit(int x, int y){
    int ok = 0;
    for(int i = poz.getX(); i <= poz.getX() + 0; i++)
        for(int j = poz.getY(); j <= poz.getY() + 2; j++)
        {
            if(i == x && j == y)
                ok = 1;
        }
    if(ok == 1)
        return true;
    else
        return false;
}

void Distrugator::regenerare()
{
    intretinere(5);     // Folosesc functia de intretinere chiar daca nu este in cadrul rundei, pentru ca este mai usor si nu trebuie sa scriu de 2 ori acelasi lucru =)
    avarie -= 14;
    if (avarie < 0) avarie = 0;
}