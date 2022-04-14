#ifndef NAVAL_WAR_NAVA_H
#define NAVAL_WAR_NAVA_H

// Aditional
#include <string.h>

class Nava
{
    char* tip{};
    int forma[3][4];    // Forma este o matrice in care 1 reprezinta casutele ocupate de nava, iar 0 casutele neocupate
    int combustibil_initial;
    int x, y;
public:
    Nava(int forma[][4], char * tip = "", int combustibil_initial = 0);
    ~Nava();
};


#endif //NAVAL_WAR_NAVA_H
