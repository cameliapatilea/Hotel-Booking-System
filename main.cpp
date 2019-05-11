#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sistem_cazare.h"

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

ofstream out2("detalii_hotel.txt");
ofstream out3("cazari_confirmate.txt");


int main() {

    int rol;

    cout << "Pentru a efectua o cerere de cazare, introduceti 1." << '\n';
    cout << "Pentru a administra hotelul, introduceti 2." << '\n';

    cin >> rol;
    switch(rol)
    {
        case 1:
            {
                ofstream out("cereri_cazare.txt", ofstream :: app);
                adauga_cerere(out);
                out.close();
            }
            break;
        case 2:
            break;
        default:
            cout << "Optiunea introdusa nu este valida" << '\n';
            break;

    }

}