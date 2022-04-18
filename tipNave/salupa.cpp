#include "salupa.h"
#include "../common.h"

Salupa::Salupa() : Nava("Salupa", 55){forma = 1;}
Salupa::~Salupa() = default;


// Supraincarcarea operatorului de citire

istream& operator >> (istream& in, Salupa& s){
    cout << "Introduceti pozitia navei (punctul cel din stanga cel mai jos al navei va reprezenta pozitia ei)\n";
    int ok = 0, x, y;
    while(ok == 0){
        cout << "\nX ";
        in >> x;
        cout << "\nY ";
        in >> y;
        ok = 1;
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 0; j++)
                if(tabla[i][j] == 1)
                    ok = 0;
        if(x > dim - 2 || y > dim - 2 || y < 0 || x < 0)
            ok = 0;
    }
    if(ok == 1){
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 0; j++)
                tabla[i][j] = 1;
        s.setX(x);
        s.setY(y);
    }
    cout << "Nr. rachete: ";
    in >> s.rachete;
    return in;
}


// Verificare daca este lovit
bool Salupa::lovit(int x, int y){
    int ok = 0;
    for(int i = poz.getX(); i <= poz.getX() + 0; i++)
        for(int j = poz.getY(); j <= poz.getY() + 0; j++)
        {
            if(i == x && j == y)
                ok = 1;
        }
    if(ok == 1)
        return true;
    else
        return false;
}