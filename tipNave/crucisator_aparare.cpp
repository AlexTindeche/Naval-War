#include "crucisator_aparare.h"

int l[3][4] = {{0,1,1,0},{1,1,1,1},{0,1,1,0}};

Crucisator_aparare::Crucisator_aparare () : Nava(l, "Crucisator cu sistem de autoaparare"){}
Crucisator_aparare::~Crucisator_aparare() = default;