#include <iostream>
#include "baza.h"

using namespace std;

int main()
{
    Rekord a,b,c;
    a.wpisz("Brumbrum",12.5,10.2,20);
    b.wpisz("Hakunamatata",12.5,10.2,20);
    c.wpisz("AAAA",200.5,2.15,900);
    //a.wyswietl();
    //Rekord b (a);
    //b.wyswietl();
    Tabela B;

    B.setNazwa("ludzie");
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(b);
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(b);
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(b);
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(b);
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(c);
    B.wpisz_Rekord(b);
    B.wpisz_Rekord(a);
    B.wpisz_Rekord(c);
    Tabela G,F;
    G.wpisz(B);
    G.wyswietl_Tabela();
    G.setNazwa("Kopiowana");
    //
    cout<<"\n\n";
    B.wpisz_Rekord(b);
    B.wyswietl_Tabela();

    F.wpisz("cos",11);
    Baza baz;
    baz.nazwaB("BazaProba");
    baz.dopisz_Tabela(B);
    baz.wyswietl_Baza();
    baz.dopisz_Tabela(G);
    cout<<"\n\n";
    baz.wyswietl_Baza();
    //cout << "Hello world!" << endl;
    return 0;
}
