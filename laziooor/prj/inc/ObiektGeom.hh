#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH
#include <string>
#include "lacze_do_gnuplota.hh"
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
  ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID, Wektor3D Skala, Wektor3D Polozenie, Macierz3D MacierzRotacji);
  int WezKolorID() const {return _KolorID;}
  void WpiszKolorId(int kolor) {_KolorID=kolor;}
  const std::string &WezNazweObiektu() const {return _NazwaObiektu;}
  const std::string &WezNazwePliku_BrylaRysowana() const
  {
    return _NazwaPliku_BrylaRysowana;
  }
  
  Wektor3D WezSkale() const 
  {
    Wektor3D wynik(_Skala);
    return wynik;
  }
  
  
  Wektor3D WezPolozenie() const
  {
    Wektor3D wynik(_Polozenie);
    return wynik;
  }
  Wektor3D &WpiszPolozenie() {return _Polozenie;}

  
  Macierz3D WezMacierzRotacji() const
  {
    Macierz3D wynik(_MacierzRotacji);
    return wynik;
  }
  Macierz3D &WpiszMacierzRotacji() {return _MacierzRotacji;}
  
  
  void Przelicz_i_Zapisz_Wierzcholki();
  void Przelicz_i_Zapisz_Wierzcholkii(std::istream & StumienWej,std::ostream &StrumienWyj);
};







#endif
