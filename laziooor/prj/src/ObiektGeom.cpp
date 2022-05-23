#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"

using namespace std;

ObiektGeom::ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa,
                       const char *sNazwaObiektu,
                       int KolorID,
                       Wektor3D Skala,
                       Wektor3D Polozenie
                      // ,Macierz3D MacierzRotacji
                       ) : _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID), _Skala(Skala), _Polozenie(Polozenie)/*, _MacierzRotacji(MacierzRotacji) */
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}

void ObiektGeom::Przelicz_i_Zapisz_Wierzcholkii(std::istream &StrumienWej, std::ostream &StrumienWyj)
{
  double WspX, WspY, WspZ;
  int Indeks_Wiersza;

  StrumienWej >> WspX >> WspY >> WspZ;
  if (StrumienWej.fail())
  {
    cout << "Blad wczytania wspolrzednych" << endl;
    abort();
  }
  Indeks_Wiersza = 0;
  do
  {
    WspX = WspX * this->_Skala[0] + this->_Polozenie[0];
    WspY = WspY * this->_Skala[1] + this->_Polozenie[1];
    WspZ = WspZ * this->_Skala[2] + this->_Polozenie[2];
    StrumienWyj <<WspX<<" "<<WspY<<" "<<WspZ<< endl;
    Indeks_Wiersza++;

    if (Indeks_Wiersza == 4)
    {
      StrumienWyj << endl;
      Indeks_Wiersza = 0;
    }

    StrumienWej >> WspX >> WspY >> WspZ;

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

 /* 
  double  WspX, WspY, WspZ;
  int Indeks_Wiersza = 0;

  StrmWe >> WspX >> WspY >> WspZ;

  if (StrmWe.fail())return false;

  do {
    WspX = WspX*this->_Skala[0]+this->_Polozenie[0];
    WspY = WspY*this->_Skala[1]+this->_Polozenie[1];
    WspZ = WspZ*this->_Skala[2]+this->_Polozenie[2];
    StrmWy << WspX << " " << WspY << " " << WspZ << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> WspX >> WspY >> WspZ;

  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;


  
  return  !StrmWy.fail();

  */
}
