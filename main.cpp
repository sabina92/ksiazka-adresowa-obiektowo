#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;

int ssmain()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
   // ksiazkaAdresowa.wylogowanieUzytkownika();
   ksiazkaAdresowa.dodajAdresata();
   ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}

int main()
{
    PlikZUzytkownikami plikZUzytkownikami("uzytkownicy.txt");
    PlikZAdresatami plikZAdresatami("Adresaci.txt");
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.rejestracjaUzytkownika();
     ksiazkaAdresowa.logowanieUzytkownika();
     plikZAdresatami.czyPlikJestPusty();
     ksiazkaAdresowa.dodajAdresata();
     ksiazkaAdresowa.dodajAdresata();
   ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    system("pause");
}

int cmain()
{
    PlikZAdresatami plikZAdresatami("Adresaci.txt");
    int id = 0;
    id = plikZAdresatami.pobierzIdOstatniegoAdresata();
    cout << id << "id" << endl;

    return 0;
}
