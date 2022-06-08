#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Lazik.hh"
#define PI 3.14159265

using namespace std;

Lazik::Lazik(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, Macierz3D MacierzRotacji)
    : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, Skala, Polozenie, MacierzRotacji)
{
}

void Lazik::Jedz(const double OdlegloscDoPrzejechania, const double szybkosc, PzG::LaczeDoGNUPlota Lacze)
{
    Wektor3D PolozenieTmp, Wsporzedne, Wspol_koncowe;
    Wsporzedne = WezPolozenie();

    Wspol_koncowe[0]=sqrt(pow(OdlegloscDoPrzejechania, 2) - pow(sin((this->WezKat() * PI) / 180) * OdlegloscDoPrzejechania, 2)) 
    *(cos(this->WezKat() * PI / 180) / (abs(cos(this->WezKat() * PI / 180))));

    Wspol_koncowe[1]=sqrt(pow(OdlegloscDoPrzejechania, 2) - pow(cos((this->WezKat() * PI) / 180) * OdlegloscDoPrzejechania, 2)) 
    *(sin(this->WezKat() * PI / 180) / (abs(sin(this->WezKat() * PI / 180))));
    
    Wspol_koncowe[0] = Wspol_koncowe[0] + WezPolozenie()[0];
    Wspol_koncowe[1] = Wspol_koncowe[1] + WezPolozenie()[1];
    // cout << Wsporzedne << endl;
    // cout << Wspol_koncowe << endl;
    for (double i = 0; abs(i) < OdlegloscDoPrzejechania+1; i += szybkosc)
    {
        usleep(10000);
        this->Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
        if (Wsporzedne[0] != Wspol_koncowe[0])
        {
            Wsporzedne[0] = Wsporzedne[0] + cos((this->WezKat() * PI) / 180) * szybkosc;
        }
        if (Wsporzedne[1] != Wspol_koncowe[1])
        {
            Wsporzedne[1] = Wsporzedne[1] + sin((this->WezKat() * PI) / 180) * szybkosc;
        }
        WpiszPolozenie() = Wsporzedne;
    }
    //  cout << Wsporzedne << endl;
}

void Lazik::Obroc(const double KatObrotu, PzG::LaczeDoGNUPlota Lacze)
{
    double Kat;

    for (int KatAktualny = 0; abs(KatAktualny) < abs(KatObrotu+1);)
    {
        Kat = KatAktualny * PI / 180;
        usleep(20000);
        Wektor3D WekX(cos(Kat + this->WezKat() * PI / 180), -sin(Kat + this->WezKat() * PI / 180), 0), WekY(sin(Kat + this->WezKat() * PI / 180), cos(Kat + this->WezKat() * PI / 180), 0), WekZ(0, 0, 1);
        this->WpiszMacierzRotacji()(0) = (WekX);
        this->WpiszMacierzRotacji()(1) = (WekY);
        this->WpiszMacierzRotacji()(2) = (WekZ);
        this->Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
        if(KatObrotu<0)
        {
            --KatAktualny;
        }
        else if(KatObrotu>0)
        {
            ++KatAktualny;
        }
    }

    this->WpiszKat() = this->WezKat() + KatObrotu;
}
