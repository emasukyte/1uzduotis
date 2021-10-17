// v0.4.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

struct studentas {
};

int main()
{
    int stud, duom, sk, paz, skaitiklis = 0, sum = 0, egzaminas, vidurinis;
    vector<int>nd;
    double vid, mediana, galutinis_pazymys;
    char raide, x, y, z, w;
    string pavadinimas1, pavadinimas2;
    studentas studentai[100];
    srand(time(NULL));

    cout << "Iveskite studentu skaiciu (1000, 10000, 100000, 1000000, 10000000): " << endl;
    cin >> stud;
    pavadinimas1 = "Vargsiukai.txt";
    pavadinimas2 = "Kietiakai.txt";
    ofstream out_data1(pavadinimas1);
    ofstream out_data2(pavadinimas2);


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
        for (int i = 0; i < stud; i++) {
            for (int j = 0; j < sk; j++)
            {
                paz = rand() % 10 + 1;
                skaitiklis += 1;
                sum += paz;
                vid = sum / skaitiklis;
            }
            egzaminas = rand() % 10 + 1;
            galutinis_pazymys = vid * 0.4 + 0.6 * egzaminas;
            if (galutinis_pazymys < 5) {
                out_data1 << "Vardas" << left << setw(9) << to_string(i + 1) << "Pavarde" << left << setw(8) << to_string(i + 1);
                out_data1 << left << setw(30) << galutinis_pazymys << endl;
            }
            else if (galutinis_pazymys >= 5) {
                out_data2 << "Vardas" << left << setw(9) << to_string(i + 1) << "Pavarde" << left << setw(8) << to_string(i + 1);
                out_data2 << left << setw(30) << galutinis_pazymys << endl;
            }
        }
    }
    else if (raide == 'm' || raide == 'M') {
        out_data1 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal mediana" << endl;
        out_data2 << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(37) << "Galutinis pazymys pagal mediana" << endl;
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
            galutinis_pazymys = mediana * 0.4 + 0.6 * egzaminas;
            if (galutinis_pazymys < 5) {
                out_data1 << "Vardas" << left << setw(9) << to_string(i + 1) << "Pavarde" << left << setw(8) << to_string(i + 1);
                out_data1 << left << setw(30) << galutinis_pazymys << endl;
            }
            else if (galutinis_pazymys >= 5) {
                out_data2 << "Vardas" << left << setw(9) << to_string(i + 1) << "Pavarde" << left << setw(8) << to_string(i + 1);
                out_data2 << left << setw(30) << galutinis_pazymys << endl;
            }
        }
    }
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
