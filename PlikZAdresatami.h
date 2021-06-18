#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikTekstowy.h"
#include <vector>
#include <windows.h>

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;
    string nazwaTymczasowegoPlikuZAdresatami = "tymczasowy.txt";

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
 int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();


public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku){
        idOstatniegoAdresata = pobierzIdOstatniegoAdresata();
    };

    void dopisz(string tekst)
    {
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            if (czyPlikJestPusty())
                plikTekstowy << "To jest poczatek pliku" << endl;

            plikTekstowy << tekst << endl;
        }
        plikTekstowy.close();
    }
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void usunAdresata(int idUsuwanegoAdresata);
    int podajIdWybranegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
    void edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresata);

};

#endif
