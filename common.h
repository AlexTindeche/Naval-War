#ifndef NAVAL_WAR_COMMON_H
#define NAVAL_WAR_COMMON_H

#include <vector>
#include "nava/nava.h"
#include "tipNave/salupa.h"
#include "tipNave/submarin.h"
#include "tipNave/distrugator.h"
#include "tipNave/crucisator.h"
#include "tipNave/crucisator_aparare.h"

using namespace std;

extern vector <vector<int>> tabla;
extern vector <pair<int, Salupa>> salupe;
extern vector <pair<int, Submarin>> submarine;
extern vector <pair<int, Distrugator>> distrugatoare;
extern vector <pair<int, Crucisator>> crucisatoare;
extern vector <pair<int, Crucisator_aparare>> crucisatoare_aparare;
extern int dim;

#endif //NAVAL_WAR_COMMON_H
