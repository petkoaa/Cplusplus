
#include <iostream>

using namespace std;



///////////////////////////////////////////////////////////////////PERSON
class Person {
protected:
    string name;
    string adresse;
    friend class Tutor;
public:
    ///-Konstruktor---------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff. Ein Person ist geboren. Text ist auf dem Bildschirm
    // gezeigt.
    Person (string name,string adresse){
        this-> name = name;
        this-> adresse = adresse;
        cout<<"Ein Person mit dem Name "<<name<<",  ist geboren.\n";
    }

    ///-Destruktor----------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein person stirbt. text ist auf dem Bildschirm angezeigt.
    virtual ~Person(){
        cout<<name<<" stirbt.\n";
    }

    ///-Methoden-------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Person Atmet. Text ist auf dem Bildschirm gezeigt.
    virtual void atmen (){
        cout<<name<<" atmet.\n";
    }

    // Vor.: keine
    // Erg.: keins
    // Eff.: Persona kocht kaffee fur Person b.
    // Der text "Person a kocht kaffe fuer berson b"
    //ist auf dem Bildschirm gezeigt.
    virtual void kaffee_kochen_fuer(Person p){
        cout<<name<<" kocht Kaffee fuer " <<p.name<<endl;
    }

    friend class Studi; //dammit alle einander kaffee machen koennen
    friend class Angestellte_r;
    friend class Tutor;
    friend class Proff;
    friend class WiMi;
};

///////////////////////////////////////////////////////////////////////STUDI
class Studi : public Person {
private:
    int matrikelnummer;
    int studienjahr;
    friend class Angestellte_r;
public:
    ///-Konstruktor---------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Studi entsteht
    // Text ist auf dem Bildschirm gezeigt.
    Studi(string name, string adresse, int matrikelnummer, int studienjahr): Person(name,adresse){
        this-> matrikelnummer = matrikelnummer;
        this-> studienjahr = studienjahr;
        cout<<"Ein Studi mit Matrikerlnummer "<<matrikelnummer<<" ist da, "<<
        "und er/sie ist seiner/ihrer "<<studienjahr<<"-te Studienjahr.\n";
    }

    ///-Destruktor-----------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Studi stirbt.
    // Text ist auf dem Bildschirm gezeigt.
    ~Studi(){
    cout<<name<<" stirbt.\n";
    }

    ///-Methoden---------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Studis Studieren. Text ist auf dem Bildschirm gezeigt.
    studieren(string str){
    cout<<name<< " studiert "<<str<<endl;
    }


};

//////////////////////////////////////////////////////////////////ANGESTELLTE
class Angestellte_r : public Person {
protected:
    string vorgesetzte_r;  // ich habe probiert hier Person anstatt von string zu haben
    string fachbereich;    // aber ich glaube das programm war spaeter beim konstruktor
                           // vervirrt.
    float gehalt;
    friend class Studi;     //ein paar freunde
    friend class Person;
public:
    ///-Konstruktor-------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Angestellte_r entsteht
    // Text ist auf dem Bildschirm gezeigt.
    Angestellte_r (string name, string adresse, string vorgesetzte_r,
    string fachbereich, float gehalt): Person( name,adresse){
        this -> vorgesetzte_r = vorgesetzte_r;
        this -> fachbereich = fachbereich;
        this -> gehalt = gehalt;
        cout<<name<<" ist angestellt.\n";
    }
    ///-Destruktor--------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Angestellte_r ist entlassen.
    // Text ist auf dem Bildschirm gezeigt.
    virtual ~Angestellte_r(){
    cout<<name<<" ist gekuendigt.\n";
    }

    ///-Methoden------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Eine angestelte bewertet Studis. Text ist auf dem Bildschirm gezeigt.
    bewerte(Studi a, int note){
    cout<<name<<" hat "<<a.name<<" die Note "<<note<<" gegeben.\n";}
};

////////////////////////////////////////////////////////////////////////////Tutor
class Tutor: public Angestellte_r {
public:
     ///-Konstruktor-------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Tutor entsteht
    // Text ist auf dem Bildschirm gezeigt.
    Tutor(string name, string adresse, string vorgesetzte_r, string fachbereich,
    float gehalt):Angestellte_r (name, adresse, vorgesetzte_r, fachbereich, gehalt){
        cout<<name<<" ist jetzt Tutor\n";
    }
    ///-Destruktor--------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Tutor ist entlassen.
    // Text ist auf dem Bildschirm gezeigt.
    ~Tutor(){"Tutor ist nicht mehr \n"; }
    };

    ///-Methoden----------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein tutor unterichtet.
    tutorium_geben(){
        cout<<" Gibt Tutorium.\n";
    }


///////////////////////////////////////////////////////////////////////////Proff
class Proff: public Angestellte_r {
public:
     ///-Konstruktor-------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Proff entsteht
    // Text ist auf dem Bildschirm gezeigt.
    Proff(string name, string adresse, string vorgesetzte_r, string fachbereich,
    float gehalt):Angestellte_r (name, adresse, vorgesetzte_r, fachbereich, gehalt){
        cout<<name<<" ist Proff.\n";
    }
   ///-Destructor--------------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse Proff ist entlassen.
    // Text ist auf dem Bildschirm gezeigt.
    ~Proff(){"Proff ist nicht mehr \n";}

    };

    ///-Methoden------------------------------------------------
    //vor.: keine
    //erg.: keine
    //eff.: Ein Proff halt Vorlesung. Text ist auf dem Bildschirm gezeigt.
    vorlesung_halten(){
        cout<<"Halt eine Vorlesung."<<endl;
    }



///////////////////////////////////////////////////////////////////////////WiMi
class WiMi: public Angestellte_r {
public:
     ///-Konstruktor-------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse WiMi entsteht
    // Text ist auf dem Bildschirm gezeigt.
    WiMi(string name, string adresse, string vorgesetzte_r, string fachbereich,
    float gehalt):Angestellte_r (name, adresse, vorgesetzte_r, fachbereich, gehalt){
        cout<<name<<" ist jetzt WiMi\n";
    }
    ///-Destruktor--------------------------------------
    // Vor.: keine
    // Erg.: keins
    // Eff.: Ein Object der Klasse WiMi ist entlassen.
    // Text ist auf dem Bildschirm gezeigt.
    ~WiMi(){"WiMi ist nicht mehr \n"; }

    };





int main(){
    Person petko ("Petko", "Goerzallee 131");
    Person iva ("Iva","Svoboda 6");
    iva.atmen(); // person atmet
    petko.kaffee_kochen_fuer(iva); //person macht person kaffee
    petko.kaffee_kochen_fuer(iva);


    Studi ivan ("Ivan", "Goerzallee 131", 4111492, 4);
    Studi eli ("Eli", "Goerzallee 123",3444444, 4);
    ivan.kaffee_kochen_fuer(eli);   // studi macht studi kaffee
    ivan.kaffee_kochen_fuer(petko); //studi macht person kaffee
    petko.kaffee_kochen_fuer(ivan); //person macht studi kaffee
    petko.atmen();
    ivan.atmen();       //studis koennen atmen

    Angestellte_r emilio ("Emilio" ,"candyland", "Max", "Bioinformatik", 1000000 ); //
    emilio.kaffee_kochen_fuer(petko);

    Tutor boyan ("Boyan", "Goerzallee 131", "Hoffman", "Informatik", 666);
    boyan.kaffee_kochen_fuer(boyan);

    Proff maxx ("Max", "candyland", "Jesus", "Informatik", 9999999 );
    maxx.atmen();
    maxx.kaffee_kochen_fuer(ivan);
    boyan.bewerte(ivan, 2);
}




