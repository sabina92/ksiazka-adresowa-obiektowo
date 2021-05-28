#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        plikTekstowy << liniaZDanymiAdresata << endl;

        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImieAdresata() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwiskoAdresata() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonuAdresata() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmailAdresata() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdresAdresata() + '|';

    return liniaZDanymiAdresata;
}

string PlikZAdresatami::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    string liczba = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata);
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(liczba);

    return idAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    return adresaci;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    string bufor = "";
    idOstatniegoAdresata = 0;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
             bufor = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
         idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(bufor);
        return idOstatniegoAdresata;
        plikTekstowy.close();
    }
    else
    {
        idOstatniegoAdresata = 0;
    }
 return idOstatniegoAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImieAdresata(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwiskoAdresata(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonuAdresata(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmailAdresata(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdresAdresata(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

void PlikZAdresatami::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void PlikZAdresatami::usunAdresata(int idUsunietegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsunietegoAdresata != 0)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (idUsunietegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {}
            else
            {
                tymczasowyPlikTekstowy << wczytanaLinia<< endl;
            numerWczytanejLinii++;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
    idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
}

int PlikZAdresatami::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

int PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
{
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        return pobierzZPlikuIdOstatniegoAdresata();
    else
        return idOstatniegoAdresata;
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(idEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                    tymczasowyPlikTekstowy << liniaZDanymiAdresata << endl;
            }
            else
            {
                    tymczasowyPlikTekstowy << wczytanaLinia << endl;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}

