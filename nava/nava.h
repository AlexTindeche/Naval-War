#ifndef NAVAL_WAR_NAVA_H
#define NAVAL_WAR_NAVA_H

// Aditional
#include <string.h>
#include "../actiune/actiune.h"


class Nava
{
protected:
    char* tip{};
    int combustibil_initial;
    int rachete;
    class Pozitie{
    private:
        int x, y;
    public:
        void setX(int p){this->x = p;}
        void setY(int p){this->y = p;}
        int getX() const{return x;}
        int getY() const{return y;}
    }poz;
    int avarie;
    int activ; // Daca nava este distrusa sau nu
    Actiune a;
public:
    Nava(char * tip = " ", int combustibil_initial = 0);
    ~Nava();
    void setX(int x) {poz.setX(x);}
    void setY(int y) {poz.setY(y);}

    // Actiuni comune tuturor navelor:
    //      - Atac cu rachete
    virtual void atac();
    int getAvarie(){return avarie;}
    int distrusa(){activ = 0;}
    bool isActiva(){return activ;}
    int getCombustibil(){return combustibil_initial;}
    void intretinere(int x){combustibil_initial -= x; if(combustibil_initial < 0) combustibil_initial = 0;}
};


#endif //NAVAL_WAR_NAVA_H
