#include "submarin.h"
#include "../common.h"

Submarin::Submarin() : Nava("Submarin", 225){for(int i = 0; i < 2; i++) forma[i][0] = 1;}
Submarin::~Submarin() = default;

// Supraincarcarea operatorului de citire

istream& operator >> (istream& in, Submarin& s){
    cout << "Introduceti pozitia navei (punctul cel din stanga cel mai jos al navei va reprezenta pozitia ei)\n";
    int ok = 0, x, y;
    while(ok == 0){
        cout << "\nX ";
        in >> x;
        cout << "\nY ";
        in >> y;
        ok = 1;
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 1; j++)
                if(tabla[i][j] == 1)
                    ok = 0;
    }
    if(ok == 1){
        for(int i = x; i <= x + 0; i++)
            for(int j = y; j <= y + 1; j++)
                tabla[i][j] = 1;
        s.setX(x);
        s.setY(y);
    }
    cout << "Nr. rachete: ";
    in >> s.rachete;
    return in;
}

// Verificare daca este lovit
bool Submarin::lovit(int x, int y){
    int ok = 0;
    for(int i = poz.getX(); i <= poz.getX() + 0; i++)
        for(int j = poz.getY(); j <= poz.getY() + 1; j++)
        {
            if(i == x && j == y)
                ok = 1;
        }
    if(ok == 1)
        return true;
    else
        return false;
}

void Submarin::autodistrugere()
{
    avarie = 100;
    // Verificam daca pentru fiecare nava daca este in zona tinta

    for(int i = poz.getX() - 2; i <= poz.getX() + 2; i++)
        for(int j = poz.getY() - 2; j <= poz.getY() + 3; j++)
        {
            if(tabla[i][j] == 1)
            {
                for (int k = 0; k < salupe.size(); k++)
                {
                    if(salupe[k].second.lovit(i, j))
                    {
                        while(salupe[k].second.getAvarie() != 100)
                            salupe[k].second.avariat();
                    }
                }
                for (int k = 0; k < submarine.size(); k++)
                {
                    if(submarine[k].second.lovit(i, j))
                    {
                        while(submarine[k].second.getAvarie() != 100)
                            submarine[k].second.avariat();
                    }
                }
                for (int k = 0; k < distrugatoare.size(); k++)
                {
                    if(distrugatoare[k].second.lovit(i, j))
                    {
                        while(distrugatoare[k].second.getAvarie() != 100)
                            distrugatoare[k].second.avariat();
                    }
                }
                for (int k = 0; k < crucisatoare.size(); k++)
                {
                    if(crucisatoare[k].second.lovit(i, j))
                    {
                        while(crucisatoare[k].second.getAvarie() != 100)
                            crucisatoare[k].second.avariat();
                    }
                }
                for (int k = 0; k < crucisatoare_aparare.size(); k++)
                {
                    if(crucisatoare_aparare[k].second.lovit(i, j))
                    {
                        while(crucisatoare_aparare[k].second.getAvarie() != 100)
                            crucisatoare_aparare[k].second.avariat();
                    }
                }
            }
        }
}