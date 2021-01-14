/*TODO:
logowanie, jezyk
*/
#include <iostream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>

double DIF[3] = { 1.3, 1.0, 0.7 }; //mnozniki poziomu trudnosci

using namespace std;

class Postac {
private:
    string imie;

    double metale;
    double programowanie;
    double matematyka;
    double chemia;
    double fizyka;

    double szczescie;
    double zdrowie;
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
        if (zdrowie <= 0.0) {
            return true;
        }

        if (dniDoSesji == 0) {
            if (matematyka < 10.0 || fizyka < 10.0 || chemia < 10.0 || programowanie < 10.0 || metale < 10.0) {
                return true;
            }

            matematyka = 0.0;
            fizyka = 0.0;
            chemia = 0.0;
            programowanie = 0.0;
            metale = 0.0;

            dniDoSesji = 10;
        }

        return false;
    }

    void wyswietlMenu() {
        cout << "\n________________________________________________________________" << endl;
        cout << "                       S.T.U.D.E.N.T.                 " << endl;
        cout << "            Symulator Traumatycznego Uczelnianego      " << endl;
        cout << "         Dysponowania Ekstremalnie Nieustającym Tempem      " << endl;
        cout << "________________________________________________________________" << endl;
        cout << imie << "     Dzień " << dzien << "    Zdrowie " << zdrowie << "/100" << "    Szczęście " << szczescie << "/100" << endl;
        cout << "________________________________________________________________" << endl;
        cout << endl;
        cout << "                  Co masz dziś w planach " << imie << "?" << endl;
        cout << "                  Zostalo Ci dziś jeszcze (" << wolnyCzas << ") godzin" << endl << endl;
        cout << "                     [1] " << "Moje statystyki" << endl;
        cout << "                     [2] " << "Ucz się" << endl;
        cout << "                     [3] " << "Idź do pracy" << endl;
        cout << "                     [4] " << "Idć spać" << endl << endl;

        cout << "_________________________________________________________________" << endl;
    }

    void wyswietlStaty() {
        cout << "_________________________________________________________________" << endl;
        cout << "                       Witaj " << imie << "!" << endl;

        cout << "          Dziś dzień (" << dzien << ") Twojej walki o przetrwanie." << endl;
        cout << "                  Do sesji pozostało [" << dniDoSesji << "] dni." << endl;
        cout << "                Zobaczmy, jak sobie radzisz!" << endl << endl << endl;
        cout << "                  Oto Twoje statystyki:" << endl;
        cout << "                     Zdrowie " << zdrowie << "/100" << endl;
        cout << "                     Szczęście " << szczescie << "/100" << endl << endl;
        cout << "                     Pieniądze " << stanKonta << "$" << endl << endl;
        cout << "      Poziom opanowania umiejętności z przedmiotów:" << endl << endl;

        cout << "                        Metale " << metale << " z 10"; if (metale < 5.0 && dniDoSesji < 5) cout << "    Nie wygląda to najlepiej!";
        cout << endl;
        cout << "                    Matematyka " << matematyka << " z 10"; if (matematyka < 5.0 && dniDoSesji < 5) cout << "    Musisz chyba nad tym popracować!";
        cout << endl;
        cout << "                 Programowanie " << programowanie << " z 10"; if (programowanie < 5.0 && dniDoSesji < 5) cout << "    Hmmmm...";
        cout << endl;
        cout << "                        Fizyka " << fizyka << " z 10"; if (fizyka < 5.0 && dniDoSesji < 5) cout << "  Ty naprawde nie masz aż tyle czasu!" << endl;
        cout << endl;
        cout << "                        Chemia " << chemia << " z 10"; if (chemia < 5.0 && dniDoSesji < 5) cout << "    Weź się za robotę!";
        cout << endl << "_________________________________________________________________";
    }

    void dodajUmiejetnosc(int nr, double n) {
        if (debuff) {
            n /= 2;
        }

        if (buff) {
            n *= 2;
        }

        switch (nr) {
        case 1: {
            metale += n;
            system("cls");
            cout << "Twoje opanowanie Metali wzorosło o [" << n << "] punktów..." << endl << endl;
            system("pause");
            system("cls");
            break;
        }

        case 2: {
            matematyka += n;
            system("cls");
            cout << "Twoje opanowanie Matematyki wzorosło o [" << n << "] punktów..." << endl << endl;
            system("pause");
            system("cls");
            break;
        }

        case 3: {
            programowanie += n;
            system("cls");
            cout << "Twoje opanowanie Programowania wzorosło o [" << n << "] punktów..." << endl << endl;
            system("pause");
            system("cls");
            break;
        }

        case 4: {
            if (debuffFizyka) {
                n /= 2;
            }
            fizyka += n;
            system("cls");
            cout << "Twoje opanowanie Fizyki wzorosło o [" << n << "] punktów..." << endl << endl;
            system("pause");
            system("cls");
            break;
        }

        case 5: {
            chemia += n;
            system("cls");
            cout << "Twoje opanowanie Chemii wzorosło o [" << n << "] punktów..." << endl << endl;
            system("pause");
            system("cls");
            break;
        }
        }
    }

    void wydarzenie(int nr) {
        cout << "\n________________________________________________________________" << endl;
        cout << endl << "Wydarzyło się coś niespodziewanego!" << endl;
        switch (nr) {
        case 1: {
            cout << "Zepsuł Ci się dysk w laptopie, przez co utracono ostatnie laborki z programowania.\nTracisz jeden poziom umiejętności w tej dziedzinie. (Skill -1)";
            programowanie -= 1.0;

            if (programowanie < 0) {
                programowanie = 0.0;
            }

            break;
        }

        case 2: {
            cout << "Szampańska zabawa na miasteczku, dominacja we flankach, jednakże każde zwycięstwo wiązało się z kosztami… (-100$)";
            stanKonta -= 100;

            if (stanKonta < 100) {
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

            if (szczescie < 0) {
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

            if (szczescie > 100) {
                szczescie = 100;
            }
            break;
        }

        case 13: {
            cout << "Po drodze ze sklepu spotykasz bezdomnego. Dajesz mu 10 monet.";
            stanKonta -= 10;

            if (stanKonta < 0) {
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

            if (szczescie < 0) {
                szczescie = 0;
            }

            break;
        }

        case 17: {
            cout << "Upłynął czas zapłaty za mieszkanie za ten miesiąc. Tracisz dodatkowe 50 monet na odsetki i 10 punktów szczęścia.";
            stanKonta -= 50;
            szczescie -= 10;

            if (szczescie < 0) {
                szczescie = 0;
            }

            if (stanKonta < 0) {
                stanKonta = 0;
            }

            break;
        }

        case 18: {
            cout << "Dostajesz 5.0 na kolokwium z fizyki. Zdobywasz dwa punkty umiejętności z przedmiotu Fizyka i 10 punktów szczęścia.";
            fizyka += 1.0;
            szczescie += 10.0;

            if (szczescie > 100) {
                szczescie = 100;
            }

            break;
        }

        case 19: {
            cout << "Poszliście za namową kolegi na siłownię i zrobiłeś świetny trening. Otrzymujesz 10 punktów szczęścia i dodatkowe 10 punktów zdrowia.";
            zdrowie += 10;
            szczescie += 10;

            if (zdrowie > 100) {
                zdrowie = 100;
            }

            if (szczescie > 100) {
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

        case 23: {
            cout << "Nareszcie! Tydzień Juwenaliów! Z powodu ekscytacji nauka idzie Ci 2 razy szybciej. ";

            buff = true;

            break;
        }
        }
        cout << "\n________________________________________________________________" << endl;
        cout << endl << endl;
        system("Pause");
        system("cls");
    }

    void spij() {
        cout << "Ile godzin chcesz spać?: ";
        int czas;
        cin >> czas;

        if (czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(czas);
        sen += czas;
        system("cls");
    }

    void uczSie() {
        if (banProduktywnosc) {
            cout << "Dziś nie możesz się uczyć";
            return;
        }
        cout << "Ile godzin chcesz się uczyć? -> ";
        int czas;
        cin >> czas;

        if (czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        cout << "Czego chcesz sie uczyć?\n[1] - Metale \n[2] - Matematyka \n[3] - Programowanie \n[4] - Fizyka \n[5] - Chemia\n";
        cout << "Twój wybór -> ";
        int przedmiot;
        cin >> przedmiot;
        if (przedmiot < 1 && przedmiot > 5) {
            cout << "Nie ma takiej opcji :(";
            return;
        }

        if (banChemia && przedmiot == 5) {
            cout << "Dzis nie mozesz sie uczyc chemii.";
            return;
        }

        decrWolnyCzas(czas);

        double gain = 1.0 * DIF[trudnosc] * czas;
        if (szczescie < 40) {
            gain *= 0.8;
        }

        if (szczescie > 70) {
            gain *= 1.2;
        }

        if (buff == true) {
            gain *= 2.0;
        }

        if (debuff == true) {
            gain /= 2.0;
        }

        dodajUmiejetnosc(przedmiot, gain);
        system("cls");
    }

    void zarabiaj() {
        cout << "Ile godzin chcesz pracować? -> ";
        int czas;
        cin >> czas;

        if (czas > wolnyCzas) {
            cout << "Niestety nie masz w tym dniu tyle czasu.";
            return;
        }

        decrWolnyCzas(czas);

        stanKonta += 3 * czas;
        system("cls");
    }

    void kolejnyDzien() {
        if (buff == 1) {
            buff = 0;
        }

        if (debuff == 1) {
            debuff = 0;
        }

        if (debuffFizyka == 1) {
            debuffFizyka = 0;
        }

        if (banChemia == 1) {
            banChemia = 0;
        }

        if (banProduktywnosc == 1) {
            banProduktywnosc = 0;
        }

        wolnyCzas = 24;
        dniDoSesji--;
        dzien++;

        if (sen < 7) {
            zdrowie -= (7 - sen) * 2;
            szczescie -= (7 - sen) * 3;

            if (szczescie < 0) {
                szczescie = 0;
            }
        }

        if (sen >= 8) {
            zdrowie += 5;

            if (zdrowie > 100) {
                zdrowie = 100;
            }

            if (sen > 8) {
                szczescie += 5;

                if (szczescie > 100) {
                    szczescie = 100;
                }
            }
        }

        sen = 0;
        system("cls");
        cout << "ZAPISYWANIE OBECNEJ SYMULACJI ...\nProszę czekać...";
        Sleep(2500);
        cout << "\nTrwa: zapisywanie postępu";
        Sleep(1000);
        cout << ", ścielenie łóżka";
        Sleep(1000);
        cout << ", zbieranie chęci do życia...";
        Sleep(2000);
        system("cls");
        cout << "ROZPOCZYNANIE SYMULACJI KOLEJNEGO DNIA...\nProszę czekać...";
        Sleep(1800);
        system("cls");
    }
};

int main()
{
    srand(time(nullptr));
    //SetConsoleOutputCP(65001);
    setlocale(LC_CTYPE, "Polish");//to mi zamienia na polskie litery w VS

    cout << "Podaj swoje imię: ";
    string imie;
    cin >> imie;

    int trudnosc;
    system("cls");
    cout << "Witaj " << imie << '\n';
    do {
        cout << "Wybierz swój poziom trudności.\n[0] - Łatwy \n[1] - Normalny \n[2] - Trudny\nTwój wybór -> ";
        cin >> trudnosc;
    } while (!(trudnosc > -1 && trudnosc < 3));

    Postac gracz(imie, trudnosc);

    cout << "\nMasz do rozdysponowania 3 punkty umiejętności na start.";
    int punkt;
    for (int i = 1; i <= 3; i++) {
        do {
            cout << "\nW co chcesz zainwestować (" << i << ") punkt?\n[1] - Metale \n[2] - Matematyka \n[3] - Programowanie \n[4] - Fizyka \n[5] - Chemia\nTwój wybór -> ";
            cin >> punkt;
        } while (!(punkt > 0 && punkt < 6));

        gracz.dodajUmiejetnosc(punkt, 1.0);
    }

    system("cls");


    //logowanie i jezyki do zrobienia jutro bo to latwe 

    int czynnosc;

    while (gracz.czyGameOver() == false) {
        int w = gracz.getWolnyCzas();
        int event = (rand() % 40) + 1;
        if (event < 24) {
            gracz.wydarzenie(event);
        }

        while (w > 0) {

            gracz.wyswietlMenu();
            cout << "Twój wybór -> ";
            cin >> czynnosc;

            switch (czynnosc) {
            case 1: {
                system("cls");
                gracz.wyswietlStaty();
                cout << endl << endl;
                system("Pause");
                system("cls");
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
                cout << "BŁĘDNA WARTOŚĆ!\nPodaj prawidłową opcję.";
                system("Pause");
                system("cls");
                continue;
            }
            }
            w = gracz.getWolnyCzas();
        }
        gracz.kolejnyDzien();
    }

    cout << endl << "GAME OVER!\nPrzetrwałeś/-aś " << gracz.getDzien() << " dni. \nTo prawdopodobnie i tak lepiej niż my :)";

    return 0;
}
