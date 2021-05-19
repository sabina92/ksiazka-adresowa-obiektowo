#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include <vector>
#include <windows.h>

using namespace std;

class PlikZAdresatami
{
    const string NAZWAPLIKUZADRESATAMI;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
 int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWAPLIKUZADRESATAMI(nazwaPlikuZAdresatami){
    idOstatniegoAdresata = pobierzIdOstatniegoAdresata();
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();

};

#endif
