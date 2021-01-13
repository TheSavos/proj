/*TODO:
logowanie, jezyk
*/
#include <iostream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>

double DIF[3] = {1.3, 1.0, 0.7}; //mnozniki poziomu trudnosci

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
    int sen;

    int dzien;              
    int wolnyCzas;
    int dniDoSesji;
    int trudnosc;

    int stanKonta;
    bool buff;
    bool debuff; 
    bool debuffFizyka;
    bool banChemia;
    bool banProduktywnosc;

public:
    Postac(string nick, int tr) {
        imie = nick;

        metale = 0.0;
        programowanie = 0.0;
        matematyka = 0.0;
        chemia = 0.0;
        fizyka = 0.0; 

        szczescie = 50.0;
        zdrowie = 100.0; 
        sen = 8;

        dzien = 0;
        wolnyCzas = 24;
        dniDoSesji = 10;
        trudnosc = tr;

        stanKonta = 10;
        buff = false;
        debuff = false;
        debuffFizyka = false;
        banChemia = false;
        banProduktywnosc = false;
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
        if(zdrowie <= 0.0) {
            return true;
        }

        if(dniDoSesji == 0) {
            if(matematyka < 10.0 || fizyka < 10.0 || chemia < 10.0 || programowanie < 10.0 || metale < 10.0) { 
                return true;
            }

            dniDoSesji = 10;
        }

        return false;
    }

    void wyswietlMenu() { 
        cout<< "\n________________________________________________________________" <<endl;
        cout<<"                       S.T.U.D.E.N.T.                 "<<endl;
        cout<<"            Symulator Traumatycznego Uczelnianego      "<<endl;
        cout<<"         Dysponowania Ekstremalnie Nieustajacym Tempem      "<<endl;         
        cout<< "________________________________________________________________" <<endl;
        cout<<imie<<"     Dzien "<<dzien<<"    Zdrowie "<<zdrowie<<"/100"<<"    Szczescie "<<szczescie<<"/100"<<endl;
        //nie wiem czy tu cos jeszcze czy tyle wystaeczy stat
        cout<< "________________________________________________________________" <<endl;
        cout<<endl<<endl;
        cout<<"                  Co masz dzis w planach "<<imie<<"?"<<endl;
        cout<<"                  Zostalo ci dzis jeszcze " << wolnyCzas << " godzin"<<endl<<endl;
        cout<<"                     1 "<<"Moje statystyki"<<endl;
 
        cout<<"                     2 "<<"Ucz sie"<<endl;
        cout<<"                     3 "<<"Idz do pracy"<<endl;
        cout<<"                     4 "<<"Idz spac"<<endl<<endl<<endl;
 
        cout<< "_________________________________________________________________" <<endl; 
    }

    void wyswietlStaty() {
        cout<< "_________________________________________________________________" <<endl;
        cout<<"                       Witaj "<<imie<<"!"<<endl;
 
        cout<<"          Dzis dzien "<<dzien<<" Twojej walki o przetrwanie"<<endl;
        cout<<"                  Do sesji pozostalo "<<dniDoSesji<<" dni"<<endl;
        cout<<"                Zobaczmy, jak sobie radzisz!"<<endl<<endl<<endl;
        cout<<"                  Oto Twoje statystyki:"<<endl;
        cout<<"                     Zdrowie "<<zdrowie<<"/100"<<endl;
        cout<<"                     Szczescie "<<szczescie<<"/100"<<endl<<endl;
        cout<<"                     Pieniadze "<<stanKonta<<"$"<<endl<<endl;
 
        cout<<"      Poziom opanowania umiejetnosci z przedmiotow:"<<endl<<endl;
 
        cout<<"                       Matematyka "<<matematyka<<" z 10"; if(matematyka<5.0&&dniDoSesji <5) cout<<"    Musisz chyba nad tym popracowac!";
        cout<<endl;
        cout<<"          Metale "<<metale<<" z 10"; if(metale<5.0&&dniDoSesji <5) cout<<"    Nie wyglada to najlepiej!";
        cout<<endl;
        cout<<"                 Programowanie "<<programowanie<<" z 10"; if(programowanie<5.0&&dniDoSesji <5) cout<<"    Hmmmm...";
        cout<<endl;
        cout<<"                        Chemia "<<chemia<<" z 10"; if(chemia<5.0&&dniDoSesji <5) cout<<"    Wez sie za robote!";
        cout<<endl;
        cout<<"                        Fizyka "<<fizyka<<" z 10"; if(fizyka<5.0&&dniDoSesji <5) cout<<"  Ty naprawde nie masz az tyle czasu!"<<endl;
    }

    void dodajUmiejetnosc(int nr, double n) {
        if(debuff) {
            n /= 2;
        }

        if(buff) {
            n *= 2;
        }

        switch(nr) {
            case 1: {
                metale += n;
                break;
            }

            case 2: {
                matematyka += n;
                break;
            }

            case 3: {
                programowanie += n;
                break;
            }

            case 4: {
                if(debuffFizyka) {
                    n /= 2;
                }
                fizyka += n;
                break;
            }

            case 5: {
                chemia += n;
                break;
            }
        }
    }

    void wydarzenie(int nr) {
        switch(nr) {
            case 1: {
                cout << "Zepsuł Ci się dysk w laptopie, przez co utracono ostatnie laborki z programowania. Tracisz jeden poziom umiejętności w tej dziedzinie. (Skill -1)";
                programowanie -= 1.0;

                if(programowanie < 0) {
                    programowanie = 0.0;
                }

                break;
            }

            case 2: {
                cout << "Szampańska zabawa na miasteczku, dominacja we flankach, jednakże każde zwycięstwo wiązało się z kosztami… (-100$)";
                stanKonta -= 100;

                if(stanKonta < 100) {
                    stanKonta = 0;
                }

                break;
            }

            case 3: {
                cout << "Okazało się, że zakupy same się nie zrobią, a z powodu pandemii w sklepach są olbrzymie kolejki. Zrobienie zakupów zajmuje Ci kilka godzin. (-5h)";
                decrWolnyCzas(5);

                break;
            }

            case 4: {
                cout << "Okazało się, że rozerwał się Twój chałat i musisz go zszyć, przez co nie możesz się dziś uczyć chemii.";
                banChemia = true;

                break;
            }

            case 5: {
                cout << "Nie wiesz, gdzie masz swój kalkulator, przez co wszystkie obliczenia musisz liczyć na piechotę. (Nauka Fizyki zajmuje ci 2 razy dłużej )";
                debuffFizyka = true;

                break;
            }

            case 6: {
                cout << "Raz na jakiś czas wypadałoby posprzątać. Dziś spędzasz cały dzień na sprzątaniu,  nie możesz się uczyć ani zarabiać.";
                banProduktywnosc = true;

                break;
            }

            case 7: {
                cout << "Rodzice są dumni z twoich postępów i w ramach niespodzianki przelali ci dodatkowe kieszonkowe (+100$)";
                
                stanKonta += 100;

                break;
            }

            case 8: {
                cout << "Jadąc do domu z uczelni zepsuł się twój tramwaj. Musisz wracać pieszo. (-2h)";
                programowanie--;

                decrWolnyCzas(2);

                break;
            }

            case 9: {
                cout << "Idąc do sklepu, okazało się, że jest godzina seniora. Twoje szczęście spadło o 5 punktów.";
                szczescie -= 5;

                if(szczescie < 0) {
                    szczescie = 0.0;
                }
                break;
            }

            case 10: {
                cout << "W trakcie powrotu z miasteczka, twój portfel wypadł. Tracisz wszystkie pieniądze.";
                stanKonta = 0;

                break;
            }

            case 11: {
                cout << "Na laboratorium z chemii wylał Ci się kwas na rękę. Z powodu poparzeń tracisz 15 punktów zdrowia.";
                zdrowie -= 15; 
                //zakladam ze tutaj nie ma konca gry i to zycie mozna jeszcze odrobic w dniu w ktorym to sie stalo

                break;
            }

            case 12: {
                cout << "Wygrywasz w grze we flanki! Otrzymujesz dodatkowe 10 punktów szczęścia!";
                szczescie += 10;

                if(szczescie > 100) {
                    szczescie = 100;
                }
                break;
            }

            case 13: {
                cout << "Po drodze ze sklepu spotykasz bezdomnego. Dajesz mu 10 monet.";
                stanKonta -= 10;

                if(stanKonta < 0) {
                    stanKonta = 0;
                }
                break;
            }

            case 14: {
                cout << "Kolega z grupy wytłumaczył Ci zagadnienie z inżynierii metali, które sprawiało Ci problem. Zdobywasz punkt umiejętności z przedmiotu Metale.";
                metale += 1.0;

                break;
            }

            case 15: {
                cout << "Ćwiczenia z matematyki zostały odwołane. Dzięki temu masz czas, aby przerobić zaległe zadania. Zdobywasz punkt umiejętności z przedmiotu Matematyka.";
                matematyka += 1.0;

                break;
            }

            case 16: {
                cout << "dąc do pokoju z kawą, potknąłeś się o torbę z zakupami. Zalałeś dywan napojem i stłukłeś swój ulubiony kubek. Tracisz godzinę na sprzątanie i 10 punktów szczęścia.";
                wolnyCzas -= 1;
                szczescie -= 10;

                if(szczescie < 0) {
                    szczescie = 0;
                }

                break;
            }

            case 17: {
                cout << "Upłynął czas zapłaty za mieszkanie za ten miesiąc. Tracisz dodatkowe 50 monet na odsetki i 10 punktów szczęścia.";
                stanKonta -= 50;
                szczescie -= 10;

                if(szczescie < 0) {
                    szczescie = 0;
                }

                if(stanKonta < 0) {
                    stanKonta = 0;
                }

                break;
            }

            case 18: {
                cout << "Dostajesz 5.0 na kolokwium z fizyki. Zdobywasz dwa punkty umiejętności z przedmiotu Fizyka i 10 punktów szczęścia.";
                fizyka += 1.0;
                szczescie += 10.0;

                if(szczescie > 100) {
                    szczescie = 100;
                }

                break;
            }

            case 19: {
                cout << "Poszliście za namową kolegi na siłownię i zrobiłeś świetny trening. Otrzymujesz 10 punktów szczęścia i dodatkowe 10 punktów zdrowia.";
                zdrowie += 10;
                szczescie += 10;

                if(zdrowie > 100) {
                    zdrowie = 100;
                }

                if(szczescie > 100) {
                    szczescie = 100;
                }

                break;
            }

            case 20: {
                cout << "Rodzice odwiedzili Cię na weekendzie. Tracisz 10 godzin, ale zyskujesz 150 złotych, które tata dał Ci na pożegnanie.";
                wolnyCzas -= 10;
                stanKonta += 150;

                break;
            }

            case 21: {
                cout << "Znikąd rozpętała się niesamowita ulewa, więc odwołano wyjście na miasteczko. Dzięki temu, można było poświęcić cały wieczór na powtórzenie materiału z chemii organicznej. Zyskujesz 2 punkty umiejętności z przedmiotu Chemia.";
                chemia += 2.0;

                break;
            }

            case 22: {
                cout << "Za Tobą nieprzespana noc. Nauka idzie Ci dzisiaj 2 razy wolniej.";
                debuff = true;

                break;
            }

            case 23 : {
                cout << "Nareszcie! Tydzień Juwenaliów! Z powodu ekscytacji nauka idzie Ci 2 razy szybciej. ";
                
                buff = true;

                break;
            }
        }
    }

    void spij() {
        cout << "Jak dlugo chcesz spac?: ";
        int czas;
        cin >> czas;

        if(czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(czas);
        sen += czas;
    }

    void uczSie() {
        if(banProduktywnosc) {
            cout << "Dzis nie mozesz sie uczyc";
            return;
        }
        cout << "Jak dlugo chcesz sie uczyc?: ";
        int czas;
        cin >> czas;

        if(czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        cout << "Czego chcesz sie uczyc? 1 - metale 2 - matematyka 3 - programowanie 4 - fizyka 5 - chemia\n";
        int przedmiot;
        cin >> przedmiot;
        if(przedmiot < 1 && przedmiot > 5) {
            cout << "Nie ma takiej opcji :(";
            return; 
        }

        if(banChemia && przedmiot == 5) {
            cout << "Dzis nie mozesz sie uczyc chemii";
            return;
        }

        decrWolnyCzas(czas);

        double gain = 1.0 * DIF[trudnosc] * czas;
        if(szczescie < 40) {
            gain *= 0.8;
        }

        if(szczescie > 70) {
            gain *= 1.2;
        }

        if(buff == true) {
            gain *= 2.0;
        }

        if(debuff == true) {
            gain /= 2.0;
        }

        dodajUmiejetnosc(przedmiot, gain);
    }

    void zarabiaj() {
        cout << "Jak dlugo chcesz pracowac?: ";
        int czas;
        cin >> czas;

        if(czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(czas);

        stanKonta += 3 * czas;
    }

    void kolejnyDzien() {
        if(buff == 1) {
            buff = 0;
        }

        if(debuff == 1) {
            debuff = 0;
        }

        if(debuffFizyka == 1) {
            debuffFizyka = 0;
        }

        if(banChemia == 1) {
            banChemia = 0;
        }

        if(banProduktywnosc == 1) {
            banProduktywnosc = 0;
        }

        wolnyCzas = 24;
        dniDoSesji--;
        dzien++;

        if(sen < 7) {
            zdrowie -= (7 - sen) * 2;
            szczescie -= (7 - sen) * 3;

            if(szczescie < 0) {
                szczescie = 0;
            }
        }

        if(sen >= 8) {
            zdrowie += 5;

            if(zdrowie > 100) {
                zdrowie = 100;
            }

            if(sen > 8) {
                szczescie += 5;

                if(szczescie > 100) {
                    szczescie = 100;
                }
            }
        }

        sen = 0;
    }
};

int main()
{
    srand(time(nullptr));
    SetConsoleOutputCP( 65001 );

    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;

    int trudnosc;
    cout << "Witaj " << imie << '\n';
    do {
        cout << "Wybierz swoj poziom trudnosci. 0 - łatwy 1 - normalny 2 - trudny: ";
        cin >> trudnosc;
    } while(!(trudnosc > -1 && trudnosc < 3));

    Postac gracz(imie, trudnosc);

    cout << "Masz do rozdysponowania 3 punkty na start.";
    int punkt;
    for(int i = 1; i <= 3; i++) {
        do {
            cout << "W co chcesz zainwestowac " << i << ". punkt? 1 - metale 2 - matematyka 3 - programowanie 4 - fizyka 5 - chemia: ";
            cin >> punkt;
        } while(!(punkt > 0 && punkt < 6));

        gracz.dodajUmiejetnosc(punkt, 1.0);
    }
    

    //logowanie i jezyki do zrobienia jutro bo to latwe 

    int czynnosc;

    while(gracz.czyGameOver() == false) {
        int w = gracz.getWolnyCzas();
        int event = rand() % 41;
        if(event < 24) {
            gracz.wydarzenie(event);
        }

        while(w > 0) { 
            
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
                    gracz.zarabiaj();
                    break;
                }
                case 4: {
                    gracz.spij();
                    break;
                }
                default: {
                    cout << "Podaj prawidlowa opcje.";
                    continue;
                }
            }
            cout << "xd ";
            w = gracz.getWolnyCzas();
        }
        cout << "asd ";
        gracz.kolejnyDzien();
    }

    cout << "Przegrales :(\nPrzezyles " << gracz.getDzien() << " dni. To prawdopodobnie lepiej niz my :)";

    return 0;
}
