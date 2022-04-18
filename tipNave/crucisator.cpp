#include "crucisator.h"
#include "../common.h"

int l[3][4] = {{1,1,0,0},{1,1,0,0},{1,1,0,0}};

Crucisator::Crucisator() : Nava("Crucisator"){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            forma[i][j] = 1;
    cout << "Combstibil initial: ";
    cin >> combustibil_initial;
}
Crucisator::~Crucisator() = default;


// Supraincarcarea operatorului de citire

istream& operator >> (istream& in, Crucisator& s){
    cout << "Introduceti pozitia navei (punctul cel din stanga cel mai jos al navei va reprezenta pozitia ei)\n";
    int ok = 0, x, y;
    while(ok == 0){
        cout << "\nX ";
        in >> x;
        cout << "\nY ";
        in >> y;
        ok = 1;
        for(int i = x; i <= x + 1; i++)
            for(int j = y; j <= y + 2; j++)
                if(tabla[i][j] == 1)
                    ok = 0;
    }
    if(ok == 1){
        for(int i = x; i <= x + 1; i++)
            for(int j = y; j <= y + 2; j++)
                tabla[i][j] = 1;
        s.setX(x);
        s.setY(y);
    }
    cout << "Nr. rachete: ";
    in >> s.rachete;
    return in;
}


// Verificare daca este lovit
bool Crucisator::lovit(int x, int y){
    int ok = 0;
    for(int i = poz.getX(); i < poz.getX() + 1; i++)
        for(int j = poz.getY(); j < poz.getY() + 2; j++)
        {
            if(i == x && j == y)
                ok = 1;
        }
    if(ok == 1)
        return true;
    else
        return false;
}