/*TODO:
poziom trudnosci, logowanie, jezyk
*/
#include <iostream>

using namespace std;

class Postac {
private:
    string imie;

    double metale;          
    double programowanie;
    double matematyka;
    double chemia;
    double fizyka;

    double szczescie; //to jest do ugadania jak to zrobic takze nic z tym nie ruszalem na razie
    double zdrowie; //to jest do ugadania jak to zrobic takze nic z tym nie ruszalem na razie

    int dzien;              
    int wolnyCzas;
    int dniDoSesji;

    int stanKonta;
    bool buff;
    bool debuff;

public:
    Postac(string nick) {
        imie = nick;

        metale = 0.0;
        programowanie = 0.0;
        matematyka = 0.0;
        chemia = 0.0;
        fizyka = 0.0; 

        szczescie = 1.0;
        zdrowie = 100.0; 

        dzien = 0;
        wolnyCzas = 24;
        dniDoSesji = 10;

        stanKonta = 10;
        buff = false;
        debuff = false;
    }

    void decrWolnyCzas(int n) {
        wolnyCzas -= n;
    }

    int getDzien() {
        return dzien;
    }

    int getWolnyCzas() {
        return wolnyCzas;
    }

    bool czyGameOver() {
        if(dniDoSesji == 0) {
            if(matematyka < 10.0 || fizyka < 10.0 || chemia < 10.0 || programowanie < 10.0 || metale < 10.0) { 
                return true;
            }
        }

        dniDoSesji = 10;

        return false;
    }

    void wyswietlMenu() { 
        cout << "Masz jeszcze " << wolnyCzas << " godzin. \n1.Moje statystyki\n2.Idz sie uczyc\n3.Idz spac\n4.Idz zarabiac\n"; 
    }

    void wyswietlStaty() {
        cout << "Metale: " << metale << "\nMatematyka: " << matematyka << "\nProgramowanie: " << programowanie << "\nFizyka: " << fizyka << "\nChemia: " << chemia;
    }

    void wydarzenie(int nr) {
        switch(nr) {
            case 1: {

                break;
            }
        }
    }

    void spij() {
        cout << "Jak dlugo chcesz spac?: ";
        int temp;
        cin >> temp;

        if(temp > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(temp);
    }

    void uczSie() {
        cout << "Jak dlugo chcesz sie uczyc?: ";
        int temp;
        cin >> temp;

        if(temp > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        cout << "Czego chcesz sie uczyc? 1 - metale 2 - matematyka 3 - programowanie 4 - fizyka 5 - chemia";
        int temp2;
        cin >> temp2;
        if(temp2 < 1 && temp2 > 5) {
            cout << "Nie ma takiej opcji :(";
            return; 
        }

        decrWolnyCzas(temp);

        if(buff == true) {
            temp *= 2;
        }

        switch(temp2) {
            case 1: {
                metale += 0.1 * temp;
                break;
            }

            case 2: {
                matematyka += 0.1 * temp;
                break;
            }

            case 3: {
                programowanie += 0.1 * temp;
                break;
            }

            case 4: {
                fizyka += 0.1 * temp;
                break;
            }

            case 5: {
                chemia += 0.1 * temp;
                break;
            }
        }

    }

    void zarabiaj() {
        cout << "Jak dlugo chcesz pracowac?: ";
        int temp;
        cin >> temp;

        if(temp > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(temp);

        stanKonta += 3 * temp;
    }

    void kolejnyDzien() {
        if(buff == 1) {
            buff = 0;
        }

        dniDoSesji--;
        dzien++;
    }
};

int main()
{
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    cout << "Witaj " << imie << '\n';

    //logowanie i jezyki do zrobienia jutro bo to latwe 

    int czynnosc;
    Postac gracz(imie);

    while(gracz.czyGameOver() == false) {
        while(gracz.getWolnyCzas() > 0) {
            gracz.wyswietlMenu();
            cin >> czynnosc;

            switch(czynnosc) {
                case 1: {
                    gracz.wyswietlStaty();
                    break;
                }
                case 2: {
                    gracz.uczSie();
                    break;
                }
                case 3: {
                    gracz.spij();
                    break;
                }
                case 4: {
                    gracz.zarabiaj();
                    break;
                }
                default: {
                    cout << "Podaj prawidlowa opcje.";
                    continue;
                }
            }
        }

        gracz.kolejnyDzien();
    }

    cout << "Przegrales :(\nPrzezyles " << gracz.getDzien() << " dni. To prawdopodobnie lepiej niz my :)";

    return 0;
}
