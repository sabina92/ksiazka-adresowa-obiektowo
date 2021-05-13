#include "Adresat.h"

    void Adresat::ustawIdAdresata(int noweId)
    {
        if (noweId >= 0)
        id = noweId;
    }

    void Adresat::ustawIdUzytkownika(int noweIdUzytkownika)
    {
        if (noweIdUzytkownika >= 0)
        id = noweIdUzytkownika;
    }

    void Adresat::ustawImieAdresata(string noweImie)
    {
        imie = noweImie;
    }

    void Adresat::ustawNazwiskoAdresata(string noweNazwisko)
    {
        nazwisko = noweNazwisko;
    }

     void Adresat::ustawNumerTelefonuAdresata(string nowyNumerTelefonu)
    {
        numerTelefonu = nowyNumerTelefonu;
    }
     void Adresat::ustawEmailAdresata(string nowyEmail)
    {
        email = nowyEmail;
    }
    void Adresat::ustawAdresAdresata(string nowyAdres)
    {
        adres = nowyAdres;
    }

    int Adresat::pobierzIdAdresata()
    {
        return id;
    }

      int Adresat::pobierzIdUzytkownika()
    {
        return idUzytkownika;
    }

    string Adresat::pobierzImieAdresata()
    {
        return imie;
    }
    string Adresat::pobierzNazwiskoAdresata()
    {
        return nazwisko;
    }
     string Adresat::pobierzNumerTelefonuAdresata()
    {
        return numerTelefonu;
    }
     string Adresat::pobierzEmailAdresata()
    {
        return email;
    }
     string Adresat::pobierzAdresAdresata()
    {
        return adres;
    }
