#ifndef LAZIK_HH
#define LAZIK_HH
#include "ObiektGeom.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"


class Lazik:public ObiektGeom
{
  double _KatOrientacji_st;
  double _Szybkosc;
  double _Odleglosc_Do_Przejechania;
  public:
  Lazik(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, Macierz3D MacierzRotacji);
  void Jedz(const double OdlegloscDoPrzejechania, const double szybkosc, PzG::LaczeDoGNUPlota Lacze);
  void Obroc(const double KatObrotu, PzG::LaczeDoGNUPlota Lacze);
  double &WpiszKat() {return _KatOrientacji_st;}
  double WezKat() const {return _KatOrientacji_st;}
};


#endif 