#include <iostream>

using namespace std;

class Rekord
{
public:
    string nazwa_Rekord;
    double cenna_Brutto;
    double cenna_Netto;
    int nie_Wiem;
    Rekord();
    ~Rekord();
    void wpisz(string _nazwa_Rekord,double _cenna_Brutto,double _cenna_Netto,int _nie_Wiem);
    void wyswietl();
    Rekord(Rekord &a);

};

class Tabela
{
protected:
    Rekord *dane ;
    string nazwa_Tabela;
    int ilosc_Rekordow;
    int index;
public:
    setNazwa(string nazwa_Tabela);
    Tabela();
    ~Tabela();
    Tabela(Tabela &R);
    void wpisz_Rekord(Rekord _rekord );
    void wyswietl_Tabela();
    void wpisz(string _nazwa_Tabela,int _ilosc_Rekordow);
    void wpisz(Tabela &T);
    void edytuj_Rekord(int numer);
};

class Baza
{
    friend class Tabela;
private:
    Tabela *tabela;
    string nazwa_Baza;
    int ilosc_Tabela;
    int indexB;
public:
    Baza();
    ~Baza();
    void nazwaB(string b);
    void dopisz_Tabela(Tabela tab);
    void wyswietl_Baza();
    void usunTabela(int numer);
};
