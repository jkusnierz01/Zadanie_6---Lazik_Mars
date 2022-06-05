#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Scena.hh"

using namespace std;

/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
  rLacze.UstawZakresZ(-0, 90);
  rLacze.UstawRotacjeXZ(40, 60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj(); // Tutaj startuje gnuplot.
}

void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;

  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

int main()
{
  {
    Wektor3D w1(1,0,0),w2(0,1,0),w3(0,0,1);
    Wektor3D Skala(20, 20, 10);
    Wektor3D Polozenie1(0, 0, 0);
    Wektor3D Polozenie2(60, 60, 0);
    Wektor3D Polozenie3(-20, 70, 0);
    Macierz3D MacRotacji;
    MacRotacji(0)=w1;
    MacRotacji(1)=w2;
    MacRotacji(2)=w3;   
    double Odleglosc_DO_Przeje, szybkosc, KatObrotu;
    Scena Scena1;

    
    PzG::LaczeDoGNUPlota Lacze;

    Inicjalizuj_Lacze(Lacze);
    if (!Inicjalizuj_PowierzchnieMarsa(Lacze))
      return 1;

    
    
    

    //Lazik FSR("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, Skala, Polozenie1);
    //Lazik Perseverance("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony, Skala, Polozenie2);
    //Lazik Curiosity("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony, Skala, Polozenie3);
    Lazik Ob1("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, Skala, Polozenie1, MacRotacji);
    Lazik Ob2("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony, Skala, Polozenie2, MacRotacji);
    Lazik Ob3("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony, Skala, Polozenie3, MacRotacji);


    DodajDoListyRysowania(Lacze, Ob1);
    DodajDoListyRysowania(Lacze, Ob2);
    DodajDoListyRysowania(Lacze, Ob3);

    Ob1.Przelicz_i_Zapisz_Wierzcholki();
    Ob2.Przelicz_i_Zapisz_Wierzcholki();
    Ob3.Przelicz_i_Zapisz_Wierzcholki();

    Ob1.WpiszKat()=0;
    cout << endl
         << "Start programu gnuplot" << endl
         << endl;
    Lacze.Rysuj();
  
    cout << "Podaj kat obrotu: ";
    cin >> KatObrotu;

    Ob1.Obroc(KatObrotu,Lacze);



    cout<<endl << "Podaj odleglosc: ";
    cin >> Odleglosc_DO_Przeje;
    cout<<endl << "Podaj predkosc: ";
    cin >> szybkosc;
    Ob1.Jedz(Odleglosc_DO_Przeje,szybkosc, Lacze);

    cout << "Podaj kat obrotu: ";
    cin >> KatObrotu;
    Ob1.Obroc(KatObrotu,Lacze);




    cout<<endl << "Podaj odleglosc: ";
    cin >> Odleglosc_DO_Przeje;
    cout<<endl << "Podaj predkosc: ";
    cin >> szybkosc;


    Ob1.Jedz(Odleglosc_DO_Przeje, szybkosc, Lacze);

    //cin.ignore(100, '\n');
  /*

    Ob1.Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();

    cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
    cin.ignore(100, '\n');

    Ob1.Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();

    cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
    cin.ignore(100, '\n');
    */
   
  }
  cout << endl << endl << "Aktualna ilosc obiektow: " << Wektor3D::WyswietlAktualna() << endl;
  cout << "Calkowita ilosc obiektow: " << Wektor3D::WyswietlCalkowita() << endl;
}
