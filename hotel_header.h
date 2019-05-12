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
    Camera(int nrCamera, bool ocupat) {
        this->nrCamera = nrCamera;
        this->ocupat = ocupat;
    }
    ~Camera()
    {
       ocupat = false;
    }
    friend istream &operator >> (istream &input, Camera &c)
    {
        input >> c.nrCamera;
        return input;
    }
    friend ostream &operator << (ostream &output, const Camera &c)
    {
      //  output << "Ati ales camera cu numarul " << c.nrCamera << '\n';
      output << c.nrCamera << '\n';
      return output;
    }
    /*
     * Metode Get + Set
     */
    bool get_ocupat()
    {
        return ocupat;
    }
    int get_nrCamera()
    {
        return nrCamera;
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
   Apartament(int nrApartament, bool ocupat)
   {
       this->nrApartament = nrApartament;
       this->ocupat = ocupat;
   }
   ~Apartament()
   {
       ocupat = false;
   }
   friend istream& operator >> (istream &input, Apartament &a)
   {
       input >> a.nrApartament;
       return input;
   }
   friend ostream& operator << (ostream &output, const Apartament &a)
   {
       //output << "Ati ales apartamentul cu numarul " << a.nrApartament << '\n';
       output << a.nrApartament << '\n';
       return output;
   }
   /*
    * Metode Get  + Set
    */
   bool get_ocupat()
   {
       return ocupat;
   }
   int get_nrApartament()
   {
       return nrApartament;
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
    bool ocupat;
    int nrSala;
public:
    SalaConferinte()
    {
        proiector = false;
        ocupat = false;
        nrSala = 0;
        nrMese = 0;
        capacitate = 0;
    }
    SalaConferinte(bool ocupat, string nume)
    {
        this->ocupat = ocupat;
        this->nume = nume;
    }
    ~SalaConferinte()
    {
        proiector = false;
        ocupat = false;
        nrSala = 0;
        nrMese = 0;
        capacitate = 0;
    }
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
        return input;

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
        return output;

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
    bool get_ocupat()
    {
        return ocupat;
    }
    int get_nrSala()
    {
        return nrSala;
    }
};


class Hotel{
private:
    string nume;
    int nrIncaperi;
    vector<Incapere> incaperi;
    int capacitateRestaurant;
    int capacitateMaxima;
    int nrCamere;
    vector<Camera> camere;
    int nrApartamente;
    vector<Apartament> apartamente;
    int nrSaliConferinta;
    vector<SalaConferinte> saliConferinta;
public:
    Hotel()
    {
        nrIncaperi = 0;
        capacitateRestaurant = 0;
        capacitateMaxima = 0;
        nrCamere = 0;
        nrApartamente = 0;
        nrSaliConferinta = 0;
    }
    Hotel(string nume, int nrIncaperi, vector<Incapere> incaperi, int dimRestautant, int capacitateMaxima)
    {
        this->capacitateRestaurant = dimRestautant;
        this->incaperi = incaperi;
        this->nrIncaperi = nrIncaperi;
        this->nume = nume;
        this->capacitateMaxima = capacitateMaxima;
    }
    ~Hotel()
    {
        nrIncaperi = 0;
        capacitateRestaurant = 0;
        capacitateMaxima = 0;
        nrCamere = 0;
        nrApartamente = 0;
        nrSaliConferinta = 0;

    }
    friend istream &operator>>(istream &input, Hotel &h)
    {
        int x;

        input >> h.nume;
        input >> h.nrIncaperi;
        input >> h.nrCamere;
        for (int i = 0; i < h.nrCamere; i++)
        {
            input>>x;
            h.camere.push_back(Camera(x, false));
        }
        input >> h.nrApartamente;
        for (int i = 0; i < h.nrApartamente; i++)
        {
            input>>x;
            h.apartamente.push_back(Apartament(x, false));
        }
        input >> h.nrSaliConferinta;
        input >> h.capacitateRestaurant;
        return input;
    }
    friend ostream &operator<<(ostream &output, const Hotel &h)
    {
        /*output << "Numele hotelului: "<< h.nume << '\n';
        output << "Nr de incaperi ale hotelului este de: " << h.nrIncaperi << '\n';
        output << "Capacitatea maxima a hotelului este de: " << h.capacitateMaxima << '\n';
        output << "Restaurantul are capacitatea de " << h.capacitateRestaurant << " persoane" << '\n';*/
        output << h.nume << '\n';
        output << h.nrIncaperi << '\n';
        output << h.nrCamere << '\n';
        output << h.nrApartamente << '\n';
        output << h.nrSaliConferinta << '\n';
        output << h.capacitateMaxima << '\n';
        output << h.capacitateRestaurant << '\n';
        return output;
    }

    /*
     * Metode Get + Set
     */
    string get_nume()
    {
        return nume;
    }
    int get_nrIncaperi()
    {
        return nrIncaperi;
    }
    int get_capacitateMaxima()
    {
        return capacitateMaxima;
    }
    int get_dimRestaurant()
    {
        return capacitateRestaurant;
    }
    int get_nrCamere()
    {
        return nrCamere;
    }
    vector<Camera> get_camere()
    {
        return camere;
    }
    int get_nrApartamente()
    {
        return nrApartamente;
    }
    vector<Apartament> getApartamente()
    {
        return apartamente;
    }
    int get_nrSaliConferinta()
    {
        return nrSaliConferinta;
    }
    vector<SalaConferinte> getSaliConferinta()
    {
        return saliConferinta;
    }

};


#endif