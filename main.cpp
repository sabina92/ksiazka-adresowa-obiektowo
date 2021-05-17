#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;

int komain()
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
    PlikZAdresatami plikZAdresatami("Adresai.txt");
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.rejestracjaUzytkownika();
     ksiazkaAdresowa.logowanieUzytkownika();
     plikZAdresatami.czyPlikJestPusty();
     ksiazkaAdresowa.dodajAdresata();
   ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    system("pause");
}
