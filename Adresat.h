#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id=0, int idUzytkownika=0, string imie="", string nazwisko="", string numerTelefonu="", string email ="", string adres = "")
    {
        this-> id = id;
        this-> idUzytkownika = idUzytkownika;
        this-> imie = imie;
        this-> nazwisko= nazwisko;
        this-> numerTelefonu = numerTelefonu;
        this-> email = email;
        this-> adres = adres;
    };
    void ustawIdAdresata(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImieAdresata(string noweImie);
    void ustawNazwiskoAdresata(string noweNazwisko);
    void ustawNumerTelefonuAdresata(string nowyNumerTelefonu);
    void ustawEmailAdresata(string nowyEmail);
    void ustawAdresAdresata(string nowyAdres);

    int pobierzIdAdresata();
    int pobierzIdUzytkownika();
    string pobierzImieAdresata();
    string pobierzNazwiskoAdresata();
    string pobierzNumerTelefonuAdresata();
    string pobierzEmailAdresata();
    string pobierzAdresAdresata();
};

#endif
