//wybaczcie jak raz pisze po polsku raz po angielsku, to sie zrefaktoruje xD

/*TODO:
poziom trudnosci - moze jakis mnoznik do wszystkiego w zaleznosci od trudnosci?
mechanizm logowania
refaktoryzacja zeby to bylo sensownie zrobione
*/
#include <iostream>

using namespace std;

class Postac {
private:
    string imie;

    double metale;          //TODO: wyjebac to z przedmiotami bo jest paskudne i zrobic to na osoblej klasie/tablicy/czymkolwiek innym
    double programowanie;
    double matematyka;
    double chemia;
    double fizyka;

    double szczescie;
    double zdrowie;

    int dzien;              //TODO: to tez wyjebac i zrobic inaczej(preferowalnie osobna klasa od mechaniki gry i osobna klasa od postaci jako postaci)
    int wolnyCzas;
    int dniDoSesji;

public:
    Postac(string nick) {
        imie = nick;

        metale = 0.0;
        programowanie = 0.0;
        matematyka = 0.0;
        chemia = 0.0;
        fizyka = 0.0; //i wlasnie dlatego te przedmioty sa do zrobienia inaczej, za duzo pisania recznie xD

        szczescie = 1.0;
        zdrowie = 1.0;

        dzien = 0;
        wolnyCzas = 24;
        dniDoSesji = 5;
    }

    string getImie() {
        return imie;
    }

    double getMetale() { //aw shit, here we go again
        return metale;
    }

    double getProgramowanie() {
        return programowanie;
    }

    double getMatematyka() {
        return matematyka;
    }

    double getChemia() {
        return chemia;
    }

    double getFizyka() {
        return fizyka;
    }

    double getSzczescie() {
        return szczescie;
    }

    double getZdrowie() {
        return zdrowie;
    }

    int getDzien() {
        return dzien;
    }

    int getWolnyCzas() {
        return wolnyCzas;
    }

    int getDniDoSesji() {
        return dniDoSesji;
    }

    void setMetale(double n) { //i jeszcze raz XD
        metale = n;
    }

    void setProgramowanie(double n) {
        programowanie = n;;
    }

    void setMatematyka(double n) {
        matematyka = n;
    }

    void setChemia(double n) {
        chemia = n;
    }

    void setFizyka(double n) {
        fizyka = n;
    }

    void setSzczescie(double n) {
        szczescie = n;
    }

    void setZdrowie(double n) {
        zdrowie = n;
    }

    void incDzien() {
        dzien++;
    }

    void decrWolnyCzas(int n) {
        wolnyCzas -= n;
    }

    void setWolnyCzas(int n) {
        wolnyCzas = n;
    }

    void decDniDoSesji() {
        dniDoSesji--;
    }

    void setDniDoSesji(int n) {
        dniDoSesji = n;
    }

    bool czyGameOver() {
        if(dniDoSesji == 0) {
            if(matematyka < 10.0 || fizyka < 10.0 || chemia < 10.0 || programowanie < 10.0 || metale < 10.0) { //XD!
                return true;
            }
        }

        return false;
    }

    void wyswietlMenu() { //TODO: przeniesc do klasy czy po prostu zestawu funkcji obslugujacych mechanike gry jak sie ja zrobi
        //tu jakies fikusne wypisywanie menu
        cout << "Witaj " << imie << "!\n1.Moje statystyki\n2.Idz sie uczyc\n3.Idz spac\n4.Idz zarabiac\n"; //brzydziej sie nie dalo, to tylko prowizorka
    }
};

int main()
{
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    int czynnosc;
    Postac gracz(imie);

    while(gracz.czyGameOver() == false) {
        gracz.wyswietlMenu();
        cin >> czynnosc;

        switch(czynnosc) {
        case 1: {
                //TODO: zaimplementowac wypisywanie statystyk
                break;
            }
        case 2: {
                //TODO: zaimplementowac uczenie sie
                break;
            }
        case 3: {
                //TODO: zaimplementowac spanie
                break;
            }
        case 4: {
                //TODO: zaimplementowac zarabianie
                break;
            }
        default: {
                cout << "Podaj prawidlowa opcje.";
                continue;
            }
        }
    }

    return 0;
}
