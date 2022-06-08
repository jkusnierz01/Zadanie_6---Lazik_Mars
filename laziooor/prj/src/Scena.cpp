#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Scena.hh"

void Scena::Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota &rLacze)
{
    rLacze.ZmienTrybRys(PzG::TR_3D);
    rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
    rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
    rLacze.UstawZakresZ(-0, 90);
    rLacze.UstawRotacjeXZ(40, 60); // Tutaj ustawiany jest widok

    rLacze.Inicjalizuj(); // Tutaj startuje gnuplot.
}

void Scena::DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom &rOb)
{
    PzG::InfoPlikuDoRysowania *wInfoPliku;

    wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
    wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

Scena::Scena()
{

    Inicjalizuj_Lacze(this->Lacze);
    Inicjalizuj_PowierzchnieMarsa(this->Lacze);

    Wektor3D w1(1, 0, 0), w2(0, 1, 0), w3(0, 0, 1);
    Wektor3D Skala(20, 20, 10);
    Wektor3D Polozenie1(0, 0, 0);
    Wektor3D Polozenie2(60, 60, 0);
    Wektor3D Polozenie3(-20, 70, 0);
    Macierz3D MacRotacji;
    MacRotacji(0) = w1;
    MacRotacji(1) = w2;
    MacRotacji(2) = w3;

    // Lazik Ob1("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, Skala, Polozenie1, MacRotacji);
    // Lazik Ob2("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony, Skala, Polozenie2, MacRotacji);
    // Lazik Ob3("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony, Skala, Polozenie3, MacRotacji);

    ObiektSceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, Skala, Polozenie1, MacRotacji));
    ObiektSceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony, Skala, Polozenie2, MacRotacji));
    ObiektSceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony, Skala, Polozenie3, MacRotacji));

    std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = ObiektSceny.begin();
    DodajDoListyRysowania(Lacze, **Iter);
    (**Iter).Przelicz_i_Zapisz_Wierzcholki();
    this->AktywnyLazik = static_pointer_cast<Lazik>(*Iter);
    DodajDoListyRysowania(Lacze, **(++Iter));
    (**Iter).Przelicz_i_Zapisz_Wierzcholki();
    DodajDoListyRysowania(Lacze, **(++Iter));
    (**Iter).Przelicz_i_Zapisz_Wierzcholki();
}

void Scena::WyborLazika()
{
    unsigned int wybor;
    std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = ObiektSceny.begin();
    MenuWyboru();
    std::cout << "Twoj wybor: ";
    std::cin >> wybor;
    switch (wybor)
    {
    case (1):
        this->AktywnyLazik = static_pointer_cast<Lazik>(*Iter);
        ZmienKolory(wybor);
        break;
    case (2):
        ++Iter;
        this->AktywnyLazik = static_pointer_cast<Lazik>(*Iter);
        ZmienKolory(wybor);
        break;

    case (3):
        ++Iter;
        ++Iter;
        this->AktywnyLazik = static_pointer_cast<Lazik>(*Iter);
        ZmienKolory(wybor);
        break;
    default:
        std::cout << "Niepoprawnie wybrany lazik" << std::endl;
        break;
    }
    Rysuj();
}

void Scena::ZmienKolory(unsigned int liczba)
{
    std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = ObiektSceny.begin();
    switch (liczba)
    {
    case (1):
        (*Iter)->WpiszKolorId(Kolor_JasnoNiebieski);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        break;

    case (2):
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_JasnoNiebieski);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        break;

    case (3):
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_Czerwony);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        ++Iter;
        (*Iter)->WpiszKolorId(Kolor_JasnoNiebieski);
        Lacze.ZnajdzNazwePliku((*Iter)->WezNazwePliku_BrylaRysowana())->ZmienKolor((*Iter)->WezKolorID());
        break;

    default:
        break;
    }
}

void Scena::MenuWyboru()
{
    std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = ObiektSceny.begin();
    std::shared_ptr<Lazik> Wsk;
    Wsk = static_pointer_cast<Lazik>(*Iter);
    std::cout << "1.    Nazwa:  \t\t" << Wsk->WezNazweObiektu() << std::endl
              << "      Polozenie:" << Wsk->WezPolozenie()
              << "      Orientacja [st]:  " << Wsk->WezKat() << std::endl
              << std::endl;

    ++Iter;
    Wsk = static_pointer_cast<Lazik>(*Iter);

    std::cout << "2.    Nazwa:    \t" << Wsk->WezNazweObiektu() << std::endl
              << "      Polozenie:" << Wsk->WezPolozenie()
              << "      Orientacja [st]:  " << Wsk->WezKat() << std::endl
              << std::endl;

    ++Iter;
    Wsk = static_pointer_cast<Lazik>(*Iter);

    std::cout << "3.    Nazwa:    \t" << Wsk->WezNazweObiektu() << std::endl
              << "      Polozenie:" << Wsk->WezPolozenie()
              << "      Orientacja [st]:  " << Wsk->WezKat() << std::endl
              << std::endl;
}
