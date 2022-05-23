#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename STyp, int SRozmiar>
class Wektor
{
private:
  STyp ZmiennaWektor[SRozmiar];
 static int AktualnaIloscObiektow;
 static int CalkowitaIloscObiektow;
public:
  Wektor();
  ~Wektor();
  Wektor(Wektor<STyp, SRozmiar> &Wek); 
  Wektor(STyp l1, STyp l2, STyp l3);
  STyp operator[](int liczba) const { return ZmiennaWektor[liczba]; }
  STyp &operator[](int liczba) { return ZmiennaWektor[liczba]; }
  STyp operator*(const Wektor<STyp, SRozmiar> &Wek2);
  Wektor<STyp, SRozmiar> operator-(const Wektor<STyp, SRozmiar> &Wek2);
  Wektor<STyp, SRozmiar> operator+(const Wektor<STyp, SRozmiar> &Wek2);
  Wektor<STyp, SRozmiar> operator*(const double &liczba);
  Wektor<STyp, SRozmiar> operator/(const double &liczba);
  static int WyswietlAktualna() {return AktualnaIloscObiektow;}
  static int WyswietlCalkowita() {return CalkowitaIloscObiektow;}
};

template <typename STyp,int SRozmiar>
int Wektor<STyp,SRozmiar>::AktualnaIloscObiektow = 0; 

template <typename STyp,int SRozmiar>
int Wektor<STyp,SRozmiar>::CalkowitaIloscObiektow = 0;

template<typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar>::Wektor(Wektor<STyp,SRozmiar> &Wek)
{
    for(int i=0;i<SRozmiar;i++)
    {
    this->ZmiennaWektor[i]=Wek.ZmiennaWektor[i];
    }
    cout<<"Kopiuje"<<endl;
}


template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar>::Wektor()
{
     for(int i=0;i<SRozmiar;i++)
   {
      this->ZmiennaWektor[i]=0;
   }
  // cout << "Konstruktor bezparametryczny" << endl;
   ++AktualnaIloscObiektow;
   ++CalkowitaIloscObiektow;
}


template <typename STyp, int SRozmiar>
Wektor<STyp,SRozmiar>::~Wektor()
{
  //  cout << "DO WIDZENIA" << endl;
    --AktualnaIloscObiektow;
}


template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar>::Wektor(STyp l1, STyp l2, STyp l3)
{
    this->ZmiennaWektor[0] = l1;
    this->ZmiennaWektor[1] = l2;
    this->ZmiennaWektor[2] = l3;
    ++AktualnaIloscObiektow;
    ++CalkowitaIloscObiektow;
  //  cout << "Konstruktor parametryczny" << endl;
}

template <typename STyp,int SRozmiar>
STyp Wektor<STyp,SRozmiar>::operator*(const Wektor<STyp,SRozmiar> &Wek2)
{
    STyp wynik;
    for (int i = 0; i < SRozmiar; i++)
    {
        wynik += this->ZmiennaWektor[i] * Wek2[i];
    }
    return wynik;
}

template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar> Wektor<STyp,SRozmiar>::operator-(const Wektor<STyp,SRozmiar> &Wek2)
{
    Wektor<STyp,SRozmiar> Wynik;
    for (int i = 0; i < SRozmiar; i++)
    {
        Wynik[i] = this->ZmiennaWektor[i] - Wek2[i];
    }
    return Wynik;
}
template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar> Wektor<STyp,SRozmiar>::operator+(const Wektor<STyp,SRozmiar> &Wek2)
{
    Wektor<STyp,SRozmiar> wynik;
    for (int i = 0; i < SRozmiar; i++)
    {
        wynik[i] = this->ZmiennaWektor[i] + Wek2[i];
    }
    return wynik;
}
template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar> Wektor<STyp,SRozmiar>::operator*(const double &liczba)
{
    Wektor<STyp,SRozmiar> wynik;
    for (int i = 0; i < SRozmiar; i++)
    {
        wynik[i] = this->ZmiennaWektor[i] * liczba;
    }
    return wynik;
}
template <typename STyp,int SRozmiar>
Wektor<STyp,SRozmiar> Wektor<STyp,SRozmiar>::operator/(const double &liczba)
{
    Wektor<STyp,SRozmiar> wynik;
    for (int i = 0; i < SRozmiar; i++)
    {
        wynik[i] = this->ZmiennaWektor[i] / liczba;
    }
    return wynik;
}

template <typename STyp, int SRozmiar>
istream &operator>>(istream &Strm, Wektor<STyp, SRozmiar> &Wek)
{
    for (int i = 0; i < SRozmiar; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}


template <typename STyp, int SRozmiar>
ostream &operator<<(ostream &Strm, const Wektor<STyp, SRozmiar> &Wek)
{
    for (int i = 0; i < SRozmiar; i++)
    {
        Strm << "\t"<< setprecision(2) << Wek[i];
    }
    return Strm << endl;
}

#endif
