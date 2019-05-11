#ifndef HOTEL_HEADER_H
#define HOTEL_HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class Incapere{
private:
    int id;
    static int idIncapereGenerator;
public:
    Incapere()
    {
        this->id = idIncapereGenerator;
        idIncapereGenerator++;
    }
    int get_id()
    {
        return id;
    }
};
int Incapere::idIncapereGenerator = 1;

class Camera: public Incapere{
private:
    static int capacitate;
    int nrCamera;
    bool ocupat;
public:
    Camera()
    {
        nrCamera = 0;
        ocupat = false;
    }
    ~Camera()
    {
       ocupat = false;
    }
    friend istream &operator >> (istream &input, Camera &c)
    {
        input >> c.nrCamera;
    }
    friend ostream &operator << (ostream &output, const Camera &c)
    {
      //  output << "Ati ales camera cu numarul " << c.nrCamera << '\n';
      output << c.nrCamera << '\n';
    }

};
int Camera::capacitate = 2;

class Apartament:  public Incapere{
private:
    static int capacitate;
    int nrApartament;
    bool ocupat;

public:
   Apartament()
   {
       nrApartament = 0;
       ocupat = false;
   }
   ~Apartament()
   {
       ocupat = false;
   }
   friend istream& operator >> (istream &input, Apartament &a)
   {
       input >> a.nrApartament;
   }
   friend ostream& operator << (ostream &output, const Apartament &a)
   {
       //output << "Ati ales apartamentul cu numarul " << a.nrApartament << '\n';
       output << a.nrApartament << '\n';
   }

};
int Apartament::capacitate = 4;

class SalaConferinte:public Incapere{
private:
    string nume;
    bool proiector;
    string tip;
    int capacitate;
    int nrMese;
    vector<int> mese;
public:
    friend istream& operator>>(istream &input, SalaConferinte &s)
    {
        input >> s.nume;
        input >> s.tip;
        input >> s.capacitate;
        if(s.tip == "individual")
        {
            input >> s.nrMese;
            int x;
            for(int i = 0; i < s.nrMese; i++)
            {
                input >> x;
                if(x < 4 || x > 8)
                    throw invalid_argument("Masa trebuie sa aiba intre 4 si 8 locuri");
                else s.mese.push_back(x);
            }
        }
        else if(s.tip != "scena")
            throw invalid_argument("Nu exista o astfel de sala de conferinte");

    }
    friend ostream& operator<<(ostream &output, const SalaConferinte &s)
    {

        /*output << "Numele salii de conferinte este: " << s.nume << '\n';
        output << "Tipul salii de conferinte este: " << s.tip << '\n';
        output << "Capacitatea salii este de " << s.capacitate << " de persoane" << '\n';*/
        output << s.nume << '\n';
        output << s.tip << '\n';
        output << s.capacitate << '\n';
        if(s.tip == "individual")
        {
            /*output << "Sala are " << s.nrMese << " mese" << '\n';
            output << "Mesele au, in ordine, urmatoarele capacitati:" << '\n';*/
            output << s.nrMese << '\n';
            for(int i = 0; i < s.nrMese; i++)
                output << s.mese[i] << " ";
        }

    }
    /*
     * Metode Get + Set
     */
    int get_NrMese()
    {
        return nrMese;
    }
    int get_capacitate()
    {
        return capacitate;
    }
    SalaConferinte()
    {
        proiector = false;
        capacitate = 0;
        nrMese = 0;
    }
    SalaConferinte(int capacitate, int nrMese)
    {
        this->nrMese = nrMese;
        this->capacitate = capacitate;
    }
    ~SalaConferinte()
    {
        proiector = false;

    }

};


class Hotel{
private:
    string nume;
    int nrIncaperi;
    vector<Incapere> incaperi;
    int dimRestaurant;
public:
    Hotel()
    {
        nrIncaperi = 0;
        dimRestaurant = 0;
    }
    Hotel(string nume, int nrIncaperi, vector<Incapere> incaperi, int dimRestautant)
    {
        this->dimRestaurant = dimRestautant;
        this->incaperi = incaperi;
        this->nrIncaperi = nrIncaperi;
        this->nume = nume;
    }
    ~Hotel()
    {
        nrIncaperi = 0;
        dimRestaurant = 0;

    }
    friend istream &operator>>(istream &input, Hotel &h)
    {
        input >> h.nume;
        input >> h.nrIncaperi;
        input >> h.dimRestaurant;
    }
    friend ostream &operator<<(ostream &output, const Hotel &h)
    {
        /*output << "Numele hotelului: "<< h.nume << '\n';
        output << "Nr de incaperi ale hotelului este de: " << h.nrIncaperi << '\n';
        output << "Restaurantul are capacitatea de " << h.dimRestaurant << " persoane" << '\n';*/
        output << h.nume << '\n';
        output << h.nrIncaperi << '\n';
        output << h.dimRestaurant << '\n';
    }

};


#endif