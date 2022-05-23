#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH
#include <string>
#include "Macierz.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class ObiektGeom
{
  std::string   _NazwaPliku_BrylaWzorcowa;
  std::string   _NazwaPliku_BrylaRysowana;
  std::string   _NazwaObiektu;
  int           _KolorID;
  Wektor3D      _Skala;
  Wektor3D      _Polozenie;
  Macierz3D     _MacierzRotacji;
  

public:
  ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie/*, Macierz3D MacierzRotacji*/);

  int WezKolorID() const { return _KolorID; }

  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }

  const std::string &WezNazwePliku_BrylaRysowana() const
  {
    return _NazwaPliku_BrylaRysowana;
  }

  void Przelicz_i_Zapisz_Wierzcholki();
  void Przelicz_i_Zapisz_Wierzcholkii(std::istream & StumienWej,std::ostream &StrumienWyj);
};

class Lazik:public ObiektGeom
{
  double _KatOrientacji_st;
  double _Szybkosc;
  double _Odleglosc_Do_Przejechania;
};

#endif
