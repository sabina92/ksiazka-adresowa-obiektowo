#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include <vector>

using namespace std;

class PlikZAdresatami
{
    const string NAZWAPLIKUZADRESATAMI;
    int idOstatniegoAdresata;


    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzZPlikuIdOstatniegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWAPLIKUZADRESATAMI(nazwaPlikuZAdresatami){
    idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void wyswietlWszystkichAdresatow();

};

#endif
