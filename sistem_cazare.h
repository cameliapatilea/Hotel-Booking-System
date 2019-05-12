#pragma once
#include "hotel_header.h"
#include "grup_header.h"

void adauga_cerere(ostream &out)
{
    Grup G;
    cin >> G;
    out << G;
}
void adauga_hotel(ostream &out)
{
    Hotel H;
    cin >> H;
    out << H;

}
void anulare_cerere()
{
    int x, nr = 0;
    Grup G;
    vector<Grup> w;

    ifstream in("cereri_cazare.txt");

    cout << "Cererile de cazare sunt:" << '\n';

    while(in >> G)
    {
        nr++;
        w.push_back(G);
        cout << "Cererea cu numarul " << nr << " :" << '\n';
        cout << G << '\n';
        G = Grup();
    }

    in.close();

    cout << "Alegeti cererea pe care doriti sa o anulati:" << '\n';

    cin >> x;

    w.erase(w.begin() + (x - 1));
    nr--;

    ofstream out("cereri_cazare.txt");
    cout << "Cererile ramase sunt:" << '\n';

    for(int i = 0; i <  w.size(); i++)
    {
        out << w[i];
        cout << "Cererea cu numarul "<< i << ":" << '\n';
        cout << w[i];
    }

    out.close();
}
void verificare_cazare(ostream &out)
{
    ifstream in1("detalii_hotel.txt");
    ifstream in2("cereri_cazare.txt");

    Hotel H;
    Grup G;
    int nr = 0;
    vector<Grup> w;
    vector<Grup> cazari;
    //vector<Camera> C;
    //vector<Apartament> A;
    //vector<SalaConferinte> SC;
    int x;
    int cazariConfirmate = 0;


    in1 >> H;
    int tempCapacitateMax = H.get_capacitateMaxima();

    while(in2 >> G)
    {
        nr++;
        w.push_back(G);
        G = Grup();

    }

    int tempnrCamere = H.get_nrCamere();
    int tempApartamente = H.get_nrApartamente();
    int tempSaliConf = H.get_nrSaliConferinta();
    int tempIncaperi = H.get_nrIncaperi();

    cout << "Numele hotelului este: " << H.get_nume() <<'\n';
    cout << "Hotelul are capacitatea de "<< H.get_capacitateMaxima() << " persoane\n";
    cout << "Hotelul are " << H.get_nrIncaperi() << " incaperi: camere de 2 persoane, 4 persoane si sali de conferinta\n";
    cout << "Hotelul are " << H.get_nrCamere() << " camere de persoane\n";
    cout << "Hotelul are " << H.get_nrApartamente() << " apartamente de 4 persoane\n";
    cout << "Hotelul are " << H.get_nrSaliConferinta()  << " sali de cdonferinta\n";
    cout << "Restaurantul are capacitatea de " << H.get_dimRestaurant() <<  " persoane\n";
    cout << '\n';
    cout << "Cererile de cazare sunt:" << '\n';

    for(int i = 0; i < w.size(); i++)
    {
        cout << "Cererea cu numarul " << i << '\n';
        cout << w[i];
    }

    cout << "Selectati o cerere pentru a o putea confirma:\n";
    cin >> x;

    int ok = 0;
    for(int i = 0; i < w.size() && ok == 0; i++)
        if(i == x)
        {
            ok = 1;
            G = w[i];
        }

   for(int i = 1; i <= 365 - G.get_perioada(); i++)
   {
       int gasit = 1;
       for(int j = i; j <= i + G.get_perioada() && ok == 1; j++)
           for(int k = 0; k < cazari.size(); k++)
           {
               if(j >= cazari[k].get_sosire() && j<= cazari[k].get_sosire() + cazari[k].get_perioada())
               {
                   if()
               }
           }
   }

}