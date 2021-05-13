#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if(KsiazkaAdresowa::czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (czyUzytkownikJestZalogowany())
    {
            adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy sie najpierw zalgoowac" << endl;
        system("pause");
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        return true;
    else
        return false;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
   if (czyUzytkownikJestZalogowany())
    {
            adresatMenedzer->wyswietlWszystkichAdresatow();
    }
    else
    {
        cout << "Aby wyswietlic adresatow, nalezy sie najpierw zalgoowac" << endl;
        system("pause");
    }
}



