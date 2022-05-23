#ifndef MACIERZ_HH
#define MACIERZ_HH
#include "Wektor.hh"
#include "Wektor3D.hh"
#include <iostream>

using namespace std;


template <typename STyp, int SRozmiar>
class Macierz
{
private:
  Wektor<STyp, SRozmiar> TabWektor[SRozmiar];

public:
  Macierz();
  Macierz(Wektor<STyp, SRozmiar> w1, Wektor<STyp, SRozmiar> w2, Wektor<STyp, SRozmiar> w3);
  Wektor<STyp, SRozmiar> operator()(int liczba) const { return TabWektor[liczba]; }
  Wektor<STyp, SRozmiar> &operator()(int liczba) { return TabWektor[liczba]; }
  Wektor<STyp, SRozmiar> operator*(const Wektor<STyp, SRozmiar> &Wynik);
};


class Macierz3D:public Macierz<double,3>
{

};



template <typename STyp, int SRozmiar>
Macierz<STyp, SRozmiar>::Macierz()
{
  for (int i = 0; i < SRozmiar; i++)
  {
    this->TabWektor[i] = Wektor<STyp,SRozmiar>();
  }
}
template <typename STyp, int SRozmiar>
Macierz<STyp, SRozmiar>::Macierz(Wektor<STyp, SRozmiar> w1, Wektor<STyp, SRozmiar> w2, Wektor<STyp, SRozmiar> w3)
{
  this->TabWektor[0] = w1;
  this->TabWektor[1] = w2;
  this->TabWektor[2] = w3;
}

template <typename STyp, int SRozmiar>
Wektor<STyp, SRozmiar> Macierz<STyp, SRozmiar>::operator*(const Wektor<STyp, SRozmiar> &Wynik)
{
  Wektor <STyp,SRozmiar> wynik;
  for (int i = 0; i < SRozmiar; i++)
  {
    wynik[i] = this->TabWektor[i] * Wynik;
  }
  return wynik;
}

template <typename STyp, int SRozmiar>
istream &operator>>(istream &Strm, Macierz<STyp, SRozmiar> &Mac)
{
  for (int i = 0; i < SRozmiar; i++)
  {
    Strm >> Mac(i);
  }
  return Strm;
}

template <typename STyp, int SRozmiar>
ostream &operator<<(ostream &Strm, const Macierz<STyp, SRozmiar> &Mac)
{
  for (int i = 0; i < SRozmiar; i++)
  {
    Strm << Mac(i) << endl;
  }
  return Strm;
}


#endif
