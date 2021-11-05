// v0.5 pataisytas3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <chrono>
#include <list>

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
using std::ofstream;
using std::getline;
using std::istringstream;
using std::to_string;
using std::list;
using std::advance;


struct studentas {
    string vardas, pavarde;
    float galutinis_pazymys;
};


int main()
{
    vector <int> nd;
    string pavadinimas1, pavadinimas2, pavadinimas3, eilute;
    int egzaminas, sk, paz, n, stud;
    double mediana;
    float skaitiklis = 0, sum = 0, vidurinis, vid;
    char raide;

    srand(time(NULL));
    studentas k;
    list<studentas>duomenys;
    list<studentas>vargsiukai;
    list<studentas>kietiakai;



    cout << "Iveskite studentu skaiciu (1000, 10000, 100000, 1000000, 10000000): " << endl;
    cin >> stud;
    pavadinimas1 = "Vargsiukai.txt";
    pavadinimas2 = "Kietiakai.txt";
    pavadinimas3 = "Studentai.txt";
    ifstream file_;
    ofstream out_data1(pavadinimas1);
    ofstream out_data2(pavadinimas2);
    ofstream out_data3(pavadinimas3);
    cout << "Iveskite, kiek namu darbu reikia sugeneruoti: " << endl;
    cin >> sk;
    cout << "Iveskite, ar galutini pazymi norite matyti isvesta pagal namu darbu pazymiu vidurki, ar pagal ju mediana. Jei vidurkis, rasykite v, jei mediana, rasykite m." << endl;
    cin >> raide;
    if (raide != 'v' && raide != 'V' && raide != 'm' && raide != 'M') {
        cout << "Simbolis netinkamas, turite ivesti v arba m simboli." << endl;
        exit(EXIT_SUCCESS);
    }
    else if (raide == 'v' || raide == 'V') {
        out_data1 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal vidurki" << endl;
        out_data2 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal vidurki" << endl;
        out_data3 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal vidurki" << endl;

        for (int i = 0; i < stud; i++) {
            for (int j = 0; j < sk; j++)
            {
                paz = rand() % 10 + 1;
                skaitiklis += 1;
                sum += paz;
                vid = sum / skaitiklis;
            }
            egzaminas = rand() % 10 + 1;
            k.galutinis_pazymys = vid * 0.4 + 0.6 * egzaminas;
            k.vardas = "Vardas" + to_string(i + 1);
            k.pavarde = "Pavarde" + to_string(i + 1);
            duomenys.insert(duomenys.begin(), k);

            out_data3 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
            out_data3 << left << setw(37) << setprecision(3) << k.galutinis_pazymys << endl;
        }

        auto start2 = std::chrono::high_resolution_clock::now();
        auto st2 = start2;

        file_.open(pavadinimas3);
        if (!file_) {
            cout << "Failo atidaryti nepavyko. Bandykite dar karta." << endl;
            exit(1);
        }
        getline(file_, eilute);

        auto start4 = std::chrono::high_resolution_clock::now();
        auto st4 = start4;

        while (!file_.eof())
        {
            getline(file_, eilute);
            istringstream ss(eilute);
            ss >> k.vardas >> k.pavarde >> k.galutinis_pazymys;

            if (k.galutinis_pazymys < 5) {
                vargsiukai.insert(vargsiukai.begin(), k);
                out_data1 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
                out_data1 << left << setw(37) << setprecision(3) << k.galutinis_pazymys << endl;
            }
            else if (k.galutinis_pazymys >= 5) {
                kietiakai.insert(kietiakai.begin(), k);
                out_data2 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
                out_data2 << left << setw(39) << setprecision(3) << k.galutinis_pazymys << endl;
            }
        }

        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        cout << endl;
        cout << to_string(stud) + " studentu failo nuskaitymas uztruko: " << diff2.count() << " s\n";

        auto end4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff4 = end4 - start4;
        cout << endl;
        cout << to_string(stud) + " studentu rusiavimas i kietiakus ir vargsiukus uztruko: " << diff4.count() << " s\n";
    }

    else if (raide == 'm' || raide == 'M') {
        out_data1 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal mediana" << endl;
        out_data2 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal mediana" << endl;
        out_data3 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal mediana" << endl;

        for (int i = 0; i < stud; i++) {
            for (int j = 0; j < sk; j++)
            {
                paz = rand() % 10 + 1;
                skaitiklis += 1;
                sum += paz;
                nd.push_back(paz);
                sort(nd.begin(), nd.end());
                vid = sum / skaitiklis;
            }
            egzaminas = rand() % 10 + 1;
            vidurinis = size(nd) / 2;
            mediana = size(nd) % 2 == 0 ? (nd[vidurinis - 1] + nd[vidurinis]) / 2.0 : nd[vidurinis];
            k.galutinis_pazymys = mediana * 0.4 + 0.6 * egzaminas;
            k.vardas = "Vardas" + to_string(i + 1);
            k.pavarde = "Pavarde" + to_string(i + 1);
            out_data3 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
            out_data3 << left << setw(37) << setprecision(3) << k.galutinis_pazymys << endl;
        }

        auto start2 = std::chrono::high_resolution_clock::now();
        auto st2 = start2;

        file_.open(pavadinimas3);
        if (!file_) {
            cout << "Failo atidaryti nepavyko. Bandykite dar karta." << endl;
            exit(1);
        }
        getline(file_, eilute);

        auto start4 = std::chrono::high_resolution_clock::now();
        auto st4 = start4;

        while (!file_.eof())
        {
            getline(file_, eilute);
            istringstream ss(eilute);
            ss >> k.vardas >> k.pavarde >> k.galutinis_pazymys;

            if (k.galutinis_pazymys < 5) {
                vargsiukai.insert(vargsiukai.begin(), k);
                out_data1 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
                out_data1 << left << setw(37) << setprecision(3) << k.galutinis_pazymys << endl;
            }
            else if (k.galutinis_pazymys >= 5) {
                kietiakai.insert(kietiakai.begin(), k);
                out_data2 << left << setw(15) << k.vardas << left << setw(15) << k.pavarde;
                out_data2 << left << setw(39) << setprecision(3) << k.galutinis_pazymys << endl;
            }
        }

        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        cout << endl;
        cout << to_string(stud) + " studentu failo nuskaitymas uztruko: " << diff2.count() << " s\n";

        auto end4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff4 = end4 - start4;
        cout << endl;
        cout << to_string(stud) + " studentu rusiavimas i kietiakus ir vargsiukus uztruko: " << diff4.count() << " s\n";
    }
}

