#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double pi = 3.14159;


class figur {
protected:
    double volumen;
    double area;

public:
///-Destruktor---------------------------------------------------------
    virtual ~ figur (){
    cout<<"Figur zerstoert."<<endl;  //virtual
    }
///-Methoden-----------------------------------------------------------
    virtual double volume ()const{}//abstrakt

    virtual double surfaceArea()const{}//abstrakt
    //alle funktionen unter sind nicht abstrakt

    //friend double volumes(const vector<figur> vec);
};

//kugel////////////////////////////////////////////////////////////////////////////
class kugel : public figur {
private:
    double radius;
public:
    ///-Konstruktor-----------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: ein Kugel entsteht. Der Text 'Kugel entsteht' ist auf dem
    //  Bildschirm gezeigt
    kugel(double rad){
    this-> radius = rad;
    cout<<"Kugel entsteht."<<endl;
    }

    ///-Destruktor-----------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Kugel ist zerstoert. Der Text 'Kugel weg' ist auf dem
    //  Bildschirm gezeigt
    ~kugel (){
    cout<<"Kugel weg"<<endl;
    }

    ///-Methoden--------------------------------------------------
    // Vor.: keine
    // Erg.: Volumen des Kugels ist geliefert
    // Eff.: keine
    double volume (){
    this-> volumen = (4/3)*pi*pow(radius,3);
    return volumen;
    }

    // Vor.: keine
    // Erg.: Surface area des Kugels ist geliefert
    // Eff.: keins
    double surfaceArea(){
    this-> area = 4*pi*pow(radius,2);
    return area;
    }
};

//kreiskegel///////////////////////////////////////////////////////////////////
class kreiskegel: public figur {
private:
    double radius;
    double hoehe;
public:
    ///-Konstruktor -----------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Kreiskegel mit Radius rad und Hoehe hoch entsteht.
    // Der text "Kreiskugel hier" ist auf dem Bildschirm gezeigt.
    kreiskegel (double rad,double hoch){
        this-> radius = rad;
        this-> hoehe = hoch;
        cout<< "Kreiskugel, hier."<<endl;
    }
    ///-Destruktor--------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Kreiskegel zerstoert. Der Text "Kreiskegel weg"
    // auf dem Bildschirm gezeigt
    ~kreiskegel (){
    cout<<"Kreiskegel weg"<<endl;
    }
    ///-Methoden------------------------------------------------
    // Vor.: keine
    // Erg.: Volumen des Kegels ist geliefert
    // Eff.: keins
    volume(){
    this-> volumen = (1.0/3.0)*pi*pow(radius,2)*hoehe;
    return volumen;
    }

    // Vor.: keine
    // Erg.: surface area des Kegels ist geliefert
    // Eff.: keins
    surfaceArea(){
    this-> area = pi*radius*(radius+(sqrt(pow(radius,2)+pow(hoehe,2))));
    }
};

//pyramide//////////////////////////////////////////////////////////////////////
class pyramide : public figur{
private:
    double hoehe;
    double seite;
public:
    ///-Konstruktor-----------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Eine Pyramide mit Hoehe hoch und Seite seite ist erstellt und
    // der Text "Pyramide ist gebaut." ist auf dem Bildschirm gezeigt.
    pyramide (double hoch,double seite){
    this-> hoehe = hoch;
    this-> seite = seite;
    cout<< "Pyramide ist gebaut." <<endl;
    }
    ///-Destruktor-------------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Die Pyramide ist zerstoert. Der Text "Pyramide weg" ist
    // auf dem Bildschirm gezeigt.
    ~pyramide(){
    cout<<"Pyramide weg.\n";
    }
    ///-Methoden---------------------------------------------------
    // Vor.: keine
    // Erg.: volumen der Pyramide ist geliefert
    // Eff.: keins
    volume (){
    this-> volumen = ( 1.0/3.0)*(pow(seite,2))*hoehe;
    return volumen;
    }

    // Vor.: keine
    // Erg.: Surface Area der Pyramide ist geliefert
    // Eff.: keins
    surfaceArea(){
    double apothema = sqrt(pow(hoehe,2)+ pow((seite/2),2));
    this-> area = (2*seite*apothema)+ (seite*seite);
    return area;
    }
};

//prisma//////////////////////////////////////////////////////////////////////////
class prisma: public figur{
private:
    double basis;
    double hoehe;
    double surfaceAreaMinusBasisX2;
public:
    ///-Konstruktor-------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Eine prisma mit seite seite und hoehe hoch ist erstellt.
    // Der Text "Ein Object der Klasse Prisma entsteht." ist auf dem Bildschirm gezeigt.
    prisma (double basis, double hoch, double surfaceAreaMinusBasisX2){
    this-> basis = basis;
    this-> hoehe = hoch;
    this-> surfaceAreaMinusBasisX2 = surfaceAreaMinusBasisX2;
    cout<<"Ein Object der Klasse Prisma entsteht."<<endl;
    }
    ///-Destruktor---------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Das prisma ist zerstoert. Der Text "Prisma weg" ist
    // auf dem Bildschirm gezeigt
    ~prisma (){
        cout<<"Prisma weg.\n";
    }

    ///-Methoden-------------------------------------------------
    // Vor.: keine
    // Erg.: volumen des Prismas ist geliefert
    // Eff.: keins
    volume (){
    this-> volumen =(hoehe*basis )+surfaceAreaMinusBasisX2;
    return volumen;
    }

     // Vor.: keine
    // Erg.: Surface Area des Prismas ist geliefert
    // Eff.: keins
    surfaceArea(){
    this-> area = basis*2 + surfaceAreaMinusBasisX2 ;
    return area;
    }
};


double volumes(const vector<figur*> vec){
    int counter = vec.size(); cout<<counter;
    double sum = 0;
    while (counter > 0){
        figur* elem = vec.at(counter-1);
        //cout <<(*elem).volume()<<endl;
        sum = sum + (*elem).volume();
        cout<<"action"<<endl;
        counter--;
    }
    return sum ;
}



/////////////////////////////////////////////////////////////////main

int main () {
vector<figur*> vec ;

kugel ball (6);
figur* b = &ball;
vec.push_back(b);
cout<<"\n nan?  -> ";
cout<< (*(vec[0])).volume()<<endl; //hier habe ich versucht nur ball auszudrucken

cout<<"kugel.volume -> "<< ball.volume()<<endl;
cout<<"kugel.surface -> "<< ball.surfaceArea()<<endl<<endl;

kreiskegel dank (4,19);
cout<<"volume.kegel -> "<<dank.volume()<<endl;
cout<<"kegel.surface -> "<<dank.surfaceArea()<<endl<<endl;

pyramide cheops (3,6);
cout<<"pyramide.volume -> "<<cheops.volume()<<endl;
cout<<"pyramide.surface -> "<<cheops.surfaceArea()<<endl<<endl;

prisma floyd (45,7, 40);
cout<<"prisma.volume -> " << floyd.volume()<<endl;
cout<<"prisma.surface -> "<< floyd.surfaceArea()<<endl<<endl;


//Leider konnte ich nicht finden wie genau man objekte by reference
//passt. Ich kreiege bei volumes immer ein nan.

}
