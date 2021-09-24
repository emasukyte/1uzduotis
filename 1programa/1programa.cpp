// 1programa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;
using std::vector;
using std::sort;
using std::ifstream;
using std::getline;


struct studentas {
    string vardas, pavarde;
    int egzaminas;
    float galutinis_pazymys;
    double mediana;
    float skaitiklis = 0;
    vector <int> nd;
    float sum = 0;
    float vidurinis;
    float vid;
    int sk;
    int paz;
    int n;
};

void pild(studentas& kint);
void printas1(studentas& kin);
void printas2(studentas& ki);
void pazymiu_generatorius(studentas& k);
void mediana(studentas& l);
void pazymiu_ivedimas(studentas& kk);
void egzamino_generatorius(studentas& ll);
void egzamino_ivedimas(studentas& kkk);

int main()
{
    int stud, duom;
    char raide, x, y, z, w;
    string eilute;
    studentas studentai[100];

    cout << "Ar norite duomenis ivesti patys, ar nuskaityti juos is failo? Jeigu patys, spauskite p, jeigu is failo, spauskite f." << endl;
    cin >> z;
    if (z != 'p' && z != 'P' && z != 'f' && z != 'F') {
        cout << "Simbolis netinkamas, turite ivesti p arba f simboli." << endl;
        exit(EXIT_SUCCESS);
    }
    else if (z == 'p' || z == 'P') {
        cout << "Iveskite studentu skaiciu: " << endl;
        cin >> stud;
        if (stud < 1 && stud > 100) {
            cout << "Ivestas blogas studentu skaicius, iveskite is naujo" << endl;
            exit(EXIT_SUCCESS);
        }
        else {
            for (int i = 0; i < stud; i++) {
                cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
                pild(studentai[i]);
            }
            cout << "Ar zinote, kiek namu darbu pazymiu bus? Jei taip, irasykite t, jei ne - irasykite n." << endl;
            cin >> x;
            if (x != 't' && x != 'T' && x != 'n' && x != 'N') {
                cout << "Simbolis netinkamas, turite ivesti t arba n simboli." << endl;
                exit(EXIT_SUCCESS);
            }
            else if (x == 'n' || x == 'N') {
                cout << "Namu darbu pazymius turesite ivesti patys. " << endl;
                for (int i = 0; i < stud; i++) {
                    cout << "Iveskite " << i + 1 << " studento namu darbu pazymius (norint nutraukti ivedima, spauskite 0)" << endl;
                    pazymiu_ivedimas(studentai[i]);
                    mediana(studentai[i]);
                }
            }
            else if (x == 't' || x == 'T') {
                cout << "Ar namu darbu pazymius norite ivesti patys, ar leisite juos sugeneruoti kompiuteriui? Jei patys - spauskite 'p', jei kompiuteirs - spauskite 'k'." << endl;
                cin >> y;
                if (y != 'p' && y != 'P' && y != 'k' && y != 'K') {
                    cout << "Simbolis netinkamas, turite ivesti p arba k simboli." << endl;
                    exit(EXIT_SUCCESS);
                }
                else if (y == 'k' || y == 'K') {
                    for (int i = 0; i < stud; i++) {
                        pazymiu_generatorius(studentai[i]);
                        mediana(studentai[i]);
                    }
                }
                else if (y == 'p' || y == 'P') {
                    for (int i = 0; i < stud; i++) {
                        cout << "Iveskite " << i + 1 << "-o studento pazymius" << endl;
                        pazymiu_ivedimas(studentai[i]);
                        mediana(studentai[i]);
                    }
                }
            }
            cout << "Ar egzamino pazymi ivesite patys, ar ji sugeneruoti kompiuteriui? Jei patys, spauskite 'p', jei kompiuteris, spauskite 'k'." << endl;
            cin >> w;
            if (w != 'p' && w != 'P' && w != 'k' && w != 'K') {
                cout << "Simbolis netinkamas, turite ivesti p arba k simboli." << endl;
                exit(EXIT_SUCCESS);
            }
            else if (w == 'k' || w == 'K') {
                for (int i = 0; i < stud; i++) {
                    cout << i + 1 << "-ojo studento egzamino pazymys";
                    egzamino_generatorius(studentai[i]);
                }
            }
            else if (w == 'p' || w == 'P') {
                for (int i = 0; i < stud; i++) {
                    cout << i + 1 << "-ojo studento egzamino pazymys";
                    egzamino_ivedimas(studentai[i]);
                }
            }

            cout << "Iveskite, ar galutini pazymi norite matyti isvesta pagal namu darbu pazymiu vidurki, ar pagal ju mediana. Jei vidurkis, rasykite v, jei mediana, rasykite m." << endl;
            cin >> raide;
            if (raide != 'v' && raide != 'V' && raide != 'm' && raide != 'M') {
                cout << "Simbolis netinkamas, turite ivesti v arba m simboli." << endl;
                exit(EXIT_SUCCESS);
            }

            else if (raide == 'v' || raide == 'V') {
                cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(50) << "Galutinis rezultatas pagal vidurki" << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < stud; i++)
                    printas1(studentai[i]);
            }


            else if (raide == 'm' || raide == 'M') {
                cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(50) << "Galutinis rezultatas pagal mediana" << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < stud; i++)
                    printas2(studentai[i]);
            }
        }
    }
    else if (z == 'f' || z == 'F') {
        ifstream file_("kursiokai.txt");
        if (file_.is_open())
        {
            while (getline(file_, eilute))
            {
                cout << eilute << '\n';
            }
            file_.close();
        }
        else
            cout << "Failo atidaryti nepavyko. Bandykite dar karta." << endl;
    }

    cout << "Iveskite, ar galutini pazymi norite matyti isvesta pagal namu darbu pazymiu vidurki, ar pagal ju mediana. Jei vidurkis, rasykite v, jei mediana, rasykite m." << endl;
    cin >> raide;
    if (raide != 'v' && raide != 'V' && raide != 'm' && raide != 'M') {
        cout << "Simbolis netinkamas, turite ivesti v arba m simboli." << endl;
        exit(EXIT_SUCCESS);
    }

    else if (raide == 'v' || raide == 'V') {
        cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(50) << "Galutinis rezultatas pagal vidurki" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < stud; i++)
            printas1(studentai[i]);
    }


    else if (raide == 'm' || raide == 'M') {
        cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(50) << "Galutinis rezultatas pagal mediana" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < stud; i++)
            printas2(studentai[i]);
    }
}

void pild(studentas& kint) {
    cin >> kint.vardas >> kint.pavarde;
}


void pazymiu_generatorius(studentas& k) {
    cout << "Iveskite, kiek namu darbu pazymiu reikia sugeneruoti: " << endl;
    cin >> k.sk;
    cout << "Jusu pazymiai: ";
    for (int i = 0; i < k.sk; i++)
    {

        k.paz = rand() % 10 + 1;
        k.skaitiklis += 1;
        k.sum += k.paz;
        k.nd.push_back(k.paz);
        sort(k.nd.begin(), k.nd.end());
        cout << k.paz << " ";
    }
    cout << endl;
    k.vid = k.sum / k.skaitiklis;

}
void egzamino_generatorius(studentas& ll) {
    ll.egzaminas = rand() % 10 + 1;
    cout << " " << ll.egzaminas << endl;
}
void mediana(studentas& l) {
    l.vidurinis = size(l.nd) / 2;
    l.mediana = size(l.nd) % 2 == 0 ? (l.nd[l.vidurinis - 1] + l.nd[l.vidurinis]) / 2.0 : l.nd[l.vidurinis];
}

void printas1(studentas& kin) {
    kin.galutinis_pazymys = kin.vid * 0.4 + 0.6 * kin.egzaminas;
    cout << setw(15) << left << kin.vardas << " " << setw(15) << left << kin.pavarde << " " << "\t" << setw(3) << left << setprecision(3) << kin.galutinis_pazymys << endl;

}

void printas2(studentas& ki) {
    ki.galutinis_pazymys = ki.mediana * 0.4 + 0.6 * ki.egzaminas;
    cout << setw(15) << left << ki.vardas << " " << setw(15) << left << ki.pavarde << " " << "\t" << setw(3) << left << setprecision(3) << ki.galutinis_pazymys << endl;
}

void pazymiu_ivedimas(studentas& kk) {
    while (cin >> kk.paz) {

        if (kk.paz == 0) {
            break;
        }

        else if ((kk.paz < 1) || (kk.paz > 10))
        {
            cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
            exit(EXIT_SUCCESS);
        }

        else {
            kk.skaitiklis += 1;
            kk.sum += kk.paz;
            kk.nd.push_back(kk.paz);
            sort(kk.nd.begin(), kk.nd.end());
        }
    }
    kk.vid = kk.sum / kk.skaitiklis;

}

void egzamino_ivedimas(studentas& kkk) {
    cin >> kkk.egzaminas;
    if (kkk.egzaminas < 1 || kkk.egzaminas > 10) {
        cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
        exit(EXIT_SUCCESS);
    }
    else
        cout << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file








