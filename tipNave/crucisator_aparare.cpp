#include "crucisator_aparare.h"
#include "../common.h"

Crucisator_aparare::Crucisator_aparare () : Nava("Crucisator cu sistem de autoaparare"){
    for(int i = 0; i < 3; i++)
        forma[i][1] = forma[i][2] = 1;
    forma[1][0] = forma[1][3] = 1;
    sistem_aparare = false;
    cout << "Combstibil initial: ";
    cin >> combustibil_initial;
}
Crucisator_aparare::~Crucisator_aparare() = default;

// Supraincarcarea operatorului de citire

istream& operator >> (istream& in, Crucisator_aparare& s){
    cout << "Introduceti pozitia navei (punctul cel din stanga cel mai sus al navei va reprezenta pozitia ei)\n";
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
        if(x > dim - 4 || y > dim - 4 || y < 0 || x < 1)
            ok = 0;
    }
    if(tabla[x + 1][y - 1] == 1 || tabla[x + 2][y + 1] == 1)
        ok = 0;
    if(ok == 1){
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 0; j++)
                tabla[i][j] = 1;
        tabla[x + 1][y - 1] = 1;
        tabla[x + 2][y + 1] = 1;
        s.setX(x);
        s.setY(y);
    }
    cout << "Nr. rachete: ";
    in >> s.rachete;
    return in;
}

bool Crucisator_aparare::lovit(int x, int y){
    if(sistem_aparare)
        return false;
    int ok = 0;
    for(int i = poz.getX(); i <= poz.getX() + 1; i++)
        for(int j = poz.getY(); j <= poz.getY() + 2; j++)
        {
            if(i == x && j == y)
                ok = 1;
        }
    if((poz.getX() + 1 == x && poz.getY() - 1 == y) || (poz.getX() + 2 == x && poz.getY() + 1 == y))
        ok = 1;
    if(ok == 1)
        return true;
    else
        return false;
}

void Crucisator_aparare::armare(){sistem_aparare = true;} // Armarea sistemului de aparare
void Crucisator_aparare::dezarmare(){sistem_aparare = false;} // Dezarmarea sistemului de aparare