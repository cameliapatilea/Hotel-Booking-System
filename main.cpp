#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sistem_cazare.h"

using namespace std;

ifstream f("date.in");
ofstream g("date.out");


int main() {

    int rol;

    cout << "Pentru a efectua o cerere de cazare, introduceti 1." << '\n';
    cout << "Pentru a adauga un hotel, introduceti 2." << '\n';
    cout << "Pentru a administra hotelul, introduceti 3." << '\n';

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
            {
                ofstream out2("detalii_hotel.txt");
                adauga_hotel(out2);
                out2.close();
            }
            break;
        case 3:
        {
            int y;
            cout << "Pentru a vizualiza cererile, introduceti 1." << '\n';
            cout << "Pentru a anula o cerere, introduceti 2." << '\n';
            cout << "Pentru a opera o cerere si a o confirma, introduceti 3." << '\n';
            cout << "Pentru a vizualiza cererile de cazare confirmate, introduceti 4." << '\n';
            cin >> y;
            switch(y)
            {
                case 1:
                {
                    ifstream in("cereri_cazare.txt");
                    Grup G;
                    while((in >> G).good())
                    {
                        //in >> G;
                        cout << G ;
                        G = Grup();
                    }

                }
                    break;
                case 2:
                    anulare_cerere();
                    break;

                case 3:
                {
                    ofstream out3("cazari_confirmate.txt", ofstream::app);
                    verificare_cazare(out3);
                    out3.close();
                    break;
                }
                case 4:
                {
                  ifstream in1("cazari_confirmate.txt");
                  cout << "Cazarile confirmate sunt:" << '\n';

                  //de citit din fisier
                    break;
                }
                default:
                    cout << "Optiunea introdusa nu este valida" << '\n';
            }
        }

            break;
        default:
            cout << "Optiunea introdusa nu este valida" << '\n';
            break;

    }

}