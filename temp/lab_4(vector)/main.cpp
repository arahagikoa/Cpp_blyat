#include <iostream>
#include "vector.h"
/**
 * napisać program z klasą wektor która:
 * a) pozwala zainicjalizować wektor wielowymiarowy
 *  (wymiar jest parametrem konstruktora,  zmienne są alokowane w postaci dynamicznej tablicy
 *  (a nie wektora) i odpowiednio zwalniane w destruktorze (+2pkt)
 * c) posiada metodę print() drukujaca składowe wektora (+1pkt)
 * d) zmienne są prywatne, a ich zmiana pobranie wymaga set(indeks wartość) (+1pkt), metoda
 * te posiadaja odpowiednie zabezpieczenia zeby nie wywalilo programu przy probie
 * ustawienia zlej skladowej wektora
 * e) klasa zawiera zmienną statyczną gCount oraz metodę statyczną getVecNo która
 * zwraca liczbę wektorów w pamięci
 * uwaga : liczy się nie tylko to że program działa - liczy się też estetyka kodu:
 * - zmienne/metody powinny być prywatne/publiczne w zależności od potrzeb (tu: zmienne prywatne, reszta publiczna)
 * - metody które nic nie zmienają powinny być const-ami
*/

using namespace std;
int main(){
    Wektor z1(10);
    z1.print();//powinien drukować 10 zer
    cout<<"nw:\t"<<Wektor::getVecNo()<<endl;; // 1
    Wektor *z2 = new Wektor(5);
    cout<<"nw:\t"<<Wektor::getVecNo()<<endl; // 2
    z2->set(1,4);
    z2->set(5,1);//to nic zlego nie zrobi
    z2->print(); // drukuje 0,4,0,0,0
    delete z2;
    {
        Wektor u(9);
        cout<<"nw:\t"<<Wektor::getVecNo()<<endl;//2
    }
    cout<<"nw:\t"<<Wektor::getVecNo()<<endl;//1
    return 1;
}