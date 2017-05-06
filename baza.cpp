#include <iostream>
#include "baza.h"
using namespace std;
/* --------------------------------------------------------
            Rekord
-----------------------------------------------------------*/
Rekord::Rekord()
{
    nazwa_Rekord="";
    cenna_Brutto=0;
    this->cenna_Netto=0;
    this->nie_Wiem=0;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Rekord::~Rekord()
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Rekord::wpisz(string _nazwa_Rekord,double _cenna_Brutto,double _cenna_Netto,int _nie_Wiem)
{
    this->nazwa_Rekord=_nazwa_Rekord;
    this->cenna_Brutto=_cenna_Brutto;
    this->cenna_Netto=_cenna_Netto;
    this->nie_Wiem=_nie_Wiem;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Rekord::wyswietl()
{
    cout<<nazwa_Rekord<<"\t"<<cenna_Brutto<<"\t"<<cenna_Netto<<"\t"<<nie_Wiem<<endl;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Rekord::Rekord(Rekord &a)
{
    this->nazwa_Rekord=a.nazwa_Rekord;
    this->cenna_Brutto=a.cenna_Brutto;
    this->cenna_Netto=a.cenna_Netto;
    this->nie_Wiem=a.nie_Wiem;
}

/* -------------------------------------------------------
            Tabela
 ---------------------------------------------------------*/
Tabela::Tabela()
{
    ilosc_Rekordow=10;
    dane = new Rekord [10];
    index=0;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Tabela::setNazwa(string nazwa_Tabela )
{
    this->nazwa_Tabela=nazwa_Tabela;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Tabela::~Tabela()
{
    delete [] dane;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Tabela::wpisz_Rekord(Rekord _rekord )
{
    if(ilosc_Rekordow-1>index)
    {
        dane[index].wpisz(_rekord.nazwa_Rekord,_rekord.cenna_Brutto,_rekord.cenna_Netto,_rekord.nie_Wiem);
    }
    else
    {
        Rekord * TMP=new Rekord[ilosc_Rekordow];

        for (int i=0; i<ilosc_Rekordow; i++)
        {
            TMP[i]=dane[i];
        }

        delete [] dane;
        dane= new Rekord[ilosc_Rekordow+20];
        for (int i=0; i<ilosc_Rekordow; i++)
        {
            dane[i]=TMP[i];
        }
        ilosc_Rekordow+=20;
        // delete [] TMP;
        dane[index].wpisz(_rekord.nazwa_Rekord,_rekord.cenna_Brutto,_rekord.cenna_Netto,_rekord.nie_Wiem);

    }
    index++;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Tabela::wpisz(string _nazwa_Tabela,int _ilosc_Rekordow)
{

    nazwa_Tabela=_nazwa_Tabela;
    ilosc_Rekordow=_ilosc_Rekordow;
    dane = new Rekord[_ilosc_Rekordow];
    index=0;
    for(int i=0 ; i<ilosc_Rekordow; i++)
    {
        dane[i].wyswietl();
    }

}

void Tabela::wpisz(Tabela &T)
{
    this->nazwa_Tabela=T.nazwa_Tabela;
    this->ilosc_Rekordow=T.ilosc_Rekordow;
    this->dane = new Rekord [this->ilosc_Rekordow];
    this->index=T.index;
    for(int i=0 ; i<this->index; i++)
    {
        this->dane [i]=T.dane[i];
    }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Tabela::wyswietl_Tabela()
{
    cout<<nazwa_Tabela<<"\t"<<endl;
    for (int i=0; i<index; i++)
    {
        cout<<i<<"\t";
        dane[i].wyswietl();
    }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Tabela::Tabela(Tabela &R)
{
    this->nazwa_Tabela=R.nazwa_Tabela;
    this->ilosc_Rekordow=R.ilosc_Rekordow;
    this->dane = new Rekord [this->ilosc_Rekordow];
    this->index=R.index;
    for(int i=0 ; i<this->index; i++)
    {
        this->dane [i]=R.dane[i];
    }
}

/* -----------------------------------------------------------
             Baza
 -------------------------------------------------------------*/
Baza::Baza()
{
    tabela= new Tabela[10];
    ilosc_Tabela=10;
    indexB=0;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Baza::nazwaB(string b)
{
    nazwa_Baza=b;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Baza::~Baza()
{
    delete [] tabela;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Baza::dopisz_Tabela(Tabela tab)
{

    tabela[indexB].wpisz(tab);
    indexB++;

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Baza::wyswietl_Baza()
{
    cout<<nazwa_Baza<<"\t"<<endl;
    for (int i=0; i<indexB; i++)
    {
        cout<<i<<"\t";
        tabela[i].wyswietl_Tabela();
    }
    cout<<"\n\n";
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Baza::usunTabela(int numer)
{


}
