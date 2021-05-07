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
    void ustawIdAdresata(int noweId);
    void ustawImieAdresata(string noweImie);
    void ustawNazwiskoAdresata(string noweNazwisko);
    void ustawNumerTelefonuAdresata(string nowyNumerTelefonu);
    void ustawEmailAdresata(string nowyEmail);
    void ustawAdresAdresata(string nowyAdres);

    int pobierzIdAdresata();
    string pobierzImieAdresata();
    string pobierzNazwiskoAdresata();
    string pobierzNumerTelefonuAdresata();
    string pobierzEmailAdresata();
    string pobierzAdresAdresata();
};

#endif
