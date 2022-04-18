#include <iostream>
#include <vector>
#include <windows.h>

// Clase:
#include "nava/nava.h"
#include "tipNave/salupa.h"
#include "tipNave/submarin.h"
#include "tipNave/distrugator.h"
#include "tipNave/crucisator.h"
#include "tipNave/crucisator_aparare.h"
#include "common.h"

using namespace std;

vector<vector<int>> tabla;
vector<pair<int, Salupa>> salupe;
vector<pair<int, Submarin>> submarine;
vector<pair<int, Distrugator>> distrugatoare;
vector<pair<int, Crucisator>> crucisatoare;
vector<pair<int, Crucisator_aparare>> crucisatoare_aparare;

// Zona de declarare a variabilelor globale
int dim = 70;
int n = 1;

// Meniul de home:
int home ()
{
    system("cls");
    cout << "1. Start\n"
         << "2. Optiuni\n"
         << "3. Inchide aplicatia\n";
    cout << "Alege optiunea: ";
    int optiune;
    cin >> optiune;
    return optiune;
}

/*
 * Optiuni, de aici se pot schimba date precum:
 *      - marimea tablei (minim 50)
 */
void optiuni ()
{
    system("cls");
    cout << "1. Modifica dimensiunea tablei de joc\n"
         << "2. Modifica numarul de nave de pe tabla de joc\n"
         << "3. Inapoi la meniu\n";
    int optiune;
    cin >> optiune;
    switch (optiune)
    {
        default:
            break;
        case 1:
        {
            system("cls");
            cout << "Noua dimensiune a tablei: ";
            cin >> dim;
            while (dim < 50)
            {
                cout << "\nDimensiunea tablei nu poate fi mai mica de 50!!";
                cout << "\nNoua dimensiune a tablei: ";
                cin >> dim;
            }
            cout << "\nSucces";
            Sleep(2000);
            break;
        }
        case 2:
            system("cls");
            cout << "Noul nr de nave (este acelasi pentru abii jucatori): ";
            cin >> n;
            cout << "\nSucces";
            Sleep(2000);
            break;
    }
}

// Jocul propriu-zis:
void start ()
{
    /*
     * Citirea datelor:
     *      - Fiecare dintre cei doi jucatori isi poate alege 5 nave de lupta cu diferite abilitati
     *        pe care le pozitioneaza pe tabla si le atribuie un anumit numar de rachete
     * Fiecare dintre cele navele introduse de unul din cei doi jucatori va fi stocata intr-un vector de nave
     */
    system("cls");

    cout << "Jucatorul albastru: \n\n\n";

    // Citirea datelor pentru jucatorul albastru
    for (int i = 0; i < n; i++)
    {
        int tip;
        cout << "Tipul navei:\n"
             << "1. Salupa\n"
             << "2. Submarin\n"
             << "3. Distrugator\n"
             << "4. Crucisator\n"
             << "5. Crucisator cu sistem de aparare\n";
        cout << "Optiune: ";
        cin >> tip;
        cout << "\n\n";
        switch (tip)
        {
            default:
                break;
            case 1:
            {
                Salupa s;
                cin >> s;
                salupe.push_back(make_pair(1, s));
                break;
            }
            case 2:
            {
                Submarin su;
                cin >> su;
                submarine.push_back(make_pair(1, su));
                break;
            }
            case 3:
            {
                Distrugator d;
                cin >> d;
                distrugatoare.push_back(make_pair(1, d));
                break;
            }
            case 4:
            {
                Crucisator c;
                cin >> c;
                crucisatoare.push_back(make_pair(1, c));
                break;
            }
            case 5:
            {
                Crucisator_aparare ca;
                cin >> ca;
                crucisatoare_aparare.push_back(make_pair(1, ca));
                break;
            }
        }
        cout << "\n\n";
    }
    cout << "\n\n\n\n";

    // Citirea datelor pentru jucatorul rosu
    cout << "Jucatorul Rosu: \n\n\n";
    int nr_albastru, nr_rosu;
    nr_albastru = nr_rosu = n;
    for (int i = 0; i < n; i++)
    {
        int tip;
        cout << "Tipul navei:\n"
             << "1. Salupa\n"
             << "2. Submarin\n"
             << "3. Distrugator\n"
             << "4. Crucisator\n"
             << "5. Crucisator cu sistem de aparare\n";
        cin >> tip;
        cout << "\n\n";
        switch (tip)
        {
            default:
                break;
            case 1:
            {
                Salupa s;
                cin >> s;
                salupe.push_back(make_pair(2, s));
                break;
            }
            case 2:
            {
                Submarin su;
                cin >> su;
                submarine.push_back(make_pair(2, su));
                break;
            }
            case 3:
            {
                Distrugator d;
                cin >> d;
                distrugatoare.push_back(make_pair(2, d));
                break;
            }
            case 4:
            {
                Crucisator c;
                cin >> c;
                crucisatoare.push_back(make_pair(2, c));
                break;
            }
            case 5:
            {
                Crucisator_aparare ca;
                cin >> ca;
                crucisatoare_aparare.push_back(make_pair(2, ca));
                break;
            }
        }
        cout << "\n\n";
    }

    cout << "\n\n\n Citirea datelor este completa! Jocul va incepe in:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << 5 - i << '\n';
        Sleep(1000);
    }
    system("cls");
    int runda = 1;
    while (nr_albastru != 0 && nr_rosu != 0)
    {
        cout << "Runda " << runda << '\n';
        cout << "ALBASTRU mai are " << nr_albastru << " nave iar ROSU mai are " << nr_rosu << " nave\n";
        // Aici urmeaza sa jucam runda:

        // Exista problema ca daca salupa ataca crucisatorul si acesta isi activa dupa sistemul de aparare, el era inca lovit, asa ca il punem primul sa ia decizia
        for (int i = 0; i < crucisatoare_aparare.size(); i++)
        {
            if (crucisatoare_aparare[i].second.isActiva() && (crucisatoare_aparare[i].second.getAvarie() < 70 &&
                                                              crucisatoare_aparare[i].second.getCombustibil() > 0)&& crucisatoare_aparare[i].second.getRachete() > 0)
            {
                if (crucisatoare_aparare[i].first == 1)
                    cout << "Alegeti actiunea pentru crucisator cu sistem de aparare albastru: ";
                else
                    cout << "Alegeti actiunea pentru crucisator cu sistem de aparare rosu: ";
                int opt;
                cout << "1. Nimic    2. Atac    3. Regenerare    4. Armare sistem aparare\n\n";
                cin >> opt;
                if (opt == 2)
                    crucisatoare_aparare[i].second.atac();
                if (opt == 3)
                    distrugatoare[i].second.regenerare();
                if(opt == 4)
                    crucisatoare_aparare[i].second.armare();
                crucisatoare_aparare[i].second.intretinere(8);
            }
        }

        for (int i = 0; i < submarine.size(); i++)
        {
            if (submarine[i].second.isActiva() &&
                (submarine[i].second.getAvarie() < 70 && submarine[i].second.getCombustibil() > 0) && submarine[i].second.getRachete() > 0)
            {
                if (submarine[i].first == 1)
                    cout << "Alegeti actiunea pentru submarin albastru: ";
                else
                    cout << "Alegeti actiunea pentru submarin rosu: ";
                int opt;
                cout << "1. Nimic    2. Atac    3. Autodistrugere\n\n";
                cin >> opt;
                if (opt == 2)
                    submarine[i].second.atac();
                if (opt == 3)
                    submarine[i].second.autodistrugere();
                submarine[i].second.intretinere(2);
            }
        }
        for (int i = 0; i < salupe.size(); i++)
        {
            if (salupe[i].second.isActiva() &&
                (salupe[i].second.getAvarie() < 70 && salupe[i].second.getCombustibil() > 0)&& salupe[i].second.getRachete() > 0) // Cele care sunt active isi pot desfasura actiunile
            {
                if (salupe[i].first == 1)
                    cout << "Alegeti actiunea pentru salupa albastru: ";
                else
                    cout << "Alegeti actiunea pentru salupa rosu: ";
                int opt;
                cout << "1. Nimic    2. Atac\n\n";
                cin >> opt;
                if (opt == 2)
                    salupe[i].second.atac();
                salupe[i].second.intretinere(1);
            }
        }
        for (int i = 0; i < distrugatoare.size(); i++)
        {
            if (distrugatoare[i].second.isActiva() &&
                (distrugatoare[i].second.getAvarie() < 70 && distrugatoare[i].second.getCombustibil() > 0)&& distrugatoare[i].second.getRachete() > 0)
            {
                if (distrugatoare[i].first == 1)
                    cout << "Alegeti actiunea pentru distrugator albastru: ";
                else
                    cout << "Alegeti actiunea pentru distrugator rosu: ";
                int opt;
                cout << "1. Nimic    2. Atac   3.Regenerare\n\n";
                cin >> opt;
                if (opt == 2)
                    distrugatoare[i].second.atac();
                if (opt == 3)
                    distrugatoare[i].second.regenerare();
                distrugatoare[i].second.intretinere(3);
            }
        }
        for (int i = 0; i < crucisatoare.size(); i++)
        {
            if (crucisatoare[i].second.isActiva() &&
                (crucisatoare[i].second.getAvarie() < 70 && crucisatoare[i].second.getCombustibil() > 0)&& crucisatoare[i].second.getRachete() > 0)
            {
                if (crucisatoare[i].first == 1)
                    cout << "Alegeti actiunea pentru crucisator albastru: ";
                else
                    cout << "Alegeti actiunea pentru crucisator rosu: ";
                int opt;
                cout << "1. Nimic    2. Atac    3. Regenerare\n\n";
                cin >> opt;
                if (opt == 2)
                    crucisatoare[i].second.atac();
                if (opt == 3)
                    distrugatoare[i].second.regenerare();
                crucisatoare[i].second.intretinere(6);
            }
        }

        for (int i = 0; i < salupe.size(); i++)
        {
            if (salupe[i].second.isActiva() &&
                       (salupe[i].second.getAvarie() == 100 || salupe[i].second.getCombustibil() == 0 || salupe[i].second.getRachete() == 0)) // Verificam daca a fost distrusa
            {
                salupe[i].second.distrusa();
                if (salupe[i].first == 1) nr_albastru--; else nr_rosu--;
            }

        }
        for (int i = 0; i < submarine.size(); i++)
        {
            if (submarine[i].second.isActiva() &&
                       (submarine[i].second.getAvarie() == 100 || submarine[i].second.getCombustibil() == 0 || submarine[i].second.getRachete() == 0))
            {
                submarine[i].second.distrusa();
                if (submarine[i].first == 1) nr_albastru--; else nr_rosu--;
            }
        }
        for (int i = 0; i < distrugatoare.size(); i++)
        {
            if (distrugatoare[i].second.isActiva() &&
                       (distrugatoare[i].second.getAvarie() == 100 || distrugatoare[i].second.getCombustibil() == 0 || distrugatoare[i].second.getRachete() == 0))
            {
                distrugatoare[i].second.distrusa();
                if (distrugatoare[i].first == 1) nr_albastru--; else nr_rosu--;
            }
        }
        for (int i = 0; i < crucisatoare.size(); i++)
        {
            if (crucisatoare[i].second.isActiva() &&
                       (crucisatoare[i].second.getAvarie() == 100 || crucisatoare[i].second.getCombustibil() == 0 || crucisatoare[i].second.getRachete() == 0))
            {
                crucisatoare[i].second.distrusa();
                if (crucisatoare[i].first == 1) nr_albastru--; else nr_rosu--;
            }
        }
        for (int i = 0; i < crucisatoare_aparare.size(); i++)
        {
            if (crucisatoare_aparare[i].second.isActiva() && (crucisatoare_aparare[i].second.getAvarie() == 100 ||
                                                              crucisatoare_aparare[i].second.getCombustibil() == 0 || crucisatoare_aparare[i].second.getRachete() == 0))
            {
                crucisatoare_aparare[i].second.distrusa();
                if (crucisatoare_aparare[i].first == 1) nr_albastru--; else nr_rosu--;
            }
        }
        runda++;
        for (int i = 0; i < crucisatoare_aparare.size(); i++)
            crucisatoare_aparare[i].second.dezarmare();
    }
    system("cls");
    if (nr_albastru == 0)
        cout << "Jocul a fost castigat de jucatorul rosu!";
    else
        cout << "Jocul a fost castigat de jucatorul albastru!";
    Sleep(5000);
}


// Resetare tablei
void reset()
{
    tabla.clear();
    vector<int> v;
    for (int i = 0; i < dim; i++)
        v.push_back(0);
    for (int i = 0; i < dim; i++)
        tabla.push_back(v);
}

int main ()
{

    // Meniu

    // Afisarea optiunilor de inceput:
    int opt = home();
    while (opt != 3)
    {
        switch (opt)
        {
            default:
                cout << "Nu exista optiunea introdusa!";
                break;
            case 1:
            {
                reset();
                start();
                cout << " Jocul s-a terminat!";
                Sleep(5000);
                return 0;
            }
            case 2:
                optiuni();
                break;
            case 3:
                return 0;
        }
        opt = home();
    }
    return 0;
}