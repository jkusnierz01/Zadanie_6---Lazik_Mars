#include <iostream>
#include <fstream>
#include <unistd.h>
#include "ObiektGeom.hh"
#define PI 3.14159265

using namespace std;

ObiektGeom::ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa,
                       const char *sNazwaObiektu,
                       int KolorID,
                       Wektor3D Skala,
                       Wektor3D Polozenie,
                       Macierz3D MacierzRotacji
                       )  : _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID), _Skala(Skala), _Polozenie(Polozenie), _MacierzRotacji(MacierzRotacji)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}


void ObiektGeom::Przelicz_i_Zapisz_Wierzcholkii(std::istream &StrumienWej, std::ostream &StrumienWyj)
{
  Wektor3D Wek_Wspolrzed;
  int Indeks_Wiersza;
  
  StrumienWej >> Wek_Wspolrzed[0] >> Wek_Wspolrzed[1] >> Wek_Wspolrzed[2];
  if (StrumienWej.fail())
  {
    cout << "Blad wczytania wspolrzednych" << endl;
    abort();
  }
  Indeks_Wiersza = 0;
  do
  {
    Wek_Wspolrzed=(this->_MacierzRotacji*(Wek_Wspolrzed^this->_Skala))+this->_Polozenie;

    StrumienWyj << Wek_Wspolrzed[0] << " " << Wek_Wspolrzed[1] << " " << Wek_Wspolrzed[2] << endl;
    Indeks_Wiersza++;

    if (Indeks_Wiersza == 4)
    {
      StrumienWyj << endl;
      Indeks_Wiersza = 0;
    }

    StrumienWej >> Wek_Wspolrzed[0] >> Wek_Wspolrzed[1] >> Wek_Wspolrzed[2];

  } while (!(StrumienWej.eof()));
}

void ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open()))
  {
    cerr << endl
         << "Nie mozna otworzyc jednego z plikow:" << endl
         << "    " << _NazwaPliku_BrylaWzorcowa << endl
         << "    " << _NazwaPliku_BrylaRysowana << endl
         << endl;
    abort();
  }
  Przelicz_i_Zapisz_Wierzcholkii(StrmWe, StrmWy);

}
