#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Nie udalo sie dodac nowego adresata do pliki" << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie= "", nazwisko= "", numerTelefonu = "", Email= "", Adres ="";

    adresat.ustawIdAdresata( (plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    adresat.ustawImieAdresata(plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNazwiskoAdresata(plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonuAdresata(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmailAdresata(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdresAdresata(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    plikZAdresatami.wyswietlWszystkichAdresatow();
}
