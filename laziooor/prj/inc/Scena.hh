#ifndef SCENA_HH
#define SCENA_HH
#include "Lazik.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"
#include <memory>

class Scena
{
    std::shared_ptr<Lazik> AktywnyLazik;
    std::list<std::shared_ptr<ObiektGeom>> ObiektSceny;
    PzG::LaczeDoGNUPlota Lacze;

public:
    Scena();
    void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota &rLacze);
    void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom &rOb);
    void Rysuj() { Lacze.Rysuj(); }
    void WyborLazika();
    void MenuWyboru();
    std::shared_ptr<Lazik> getAktywny() { return AktywnyLazik; }
    std::shared_ptr<Lazik> &setAktywny() { return AktywnyLazik; } 
    PzG::LaczeDoGNUPlota WezLacze() { return Lacze; }
    void ZmienKolory(unsigned int liczba);
};

#endif