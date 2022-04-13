#include "nava.h"

// Construcotrul clasei Nava
Nava::Nava(int f[][3], char * tip, int combustibil_initial){
    // tip
    tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);

    // forma => atribuirea unei matrice citite ca parametru
    for(int i = 0; i < 3; i++)
        for(int j; j < 3; j++)
            forma[i][j] = f[i][j];

    // combustibil_initial
    this->combustibil_initial = combustibil_initial;
};

// Destructorul clasei Nava
Nava::~Nava(){
    delete[] tip;
}

