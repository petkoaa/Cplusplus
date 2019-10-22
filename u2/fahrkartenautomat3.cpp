#include <iostream>             //WORK IN PROGRESS// also eine realistische BVG Automat
using namespace std;

int main() {

  int a ,z ;
  double geld;

  cout << "Fahrkarteautomat BVG"<<endl;
  cout <<"Wählen Sie Ihre Fahrkarte aus"<<endl;
  cout << "1)Tageskarte 19 Euro"<<endl;
  cout << "2)Einzelfahrt 7.5 Euro"<<endl;
  cout << "3)Kurzstrecke 5 Euro"<<endl;

  cout << " 1, 2 oder 3 ?"<<endl;

  cin >> a;
  switch (a) {
    case '1':
    while (a==1) {
      geld = 19;
      break;
    }
    case '2':
    while (a==2) {
      geld = 7.5;
      break;
    }
    case '3':
    while (a==3) {
      geld = 5;
      break;
    }
    default:
    cout <<"Bitte die Fahrkarte waehlen"<<endl;
 }

  cout <<"Wie viele Tageskarte moechten Sie kaufen"<<endl;
  cin >> z;
  geld = geld * z;

  cout<< "Bezahlen Sie bitte."<<endl;
  cout<< z*7.5 <<endl;
  cout<< geld;

  for (int i = 0 ;i <= geld;) {
   cout<<"bitte Muenze werfen"<<endl;
   cin>> i;
   geld = geld - i ;
  }

 //Fahrkarteausgabe
 for (int i = 0; i<= z ; i++){
            cout<<"Bitte entnehmen Sie Fahrkarte\n";
 }
  cout<<"Bitte entnehmen Sie die Quittung."<<endl;


}
