// v0.4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int stud, duom, sk, paz, skaitiklis = 0, sum = 0, egzaminas;
    vector<int>nd;
    double vid;
    char raide, x, y, z, w;
    string pavadinimas, eilute;
    studentas studentai[100];
    srand(time(NULL));

    cout << "Iveskite studentu skaiciu (1000, 10000, 100000, 1000000, 10000000): " << endl;
    cin >> stud;
    pavadinimas = "Studentai_" + to_string(stud) + ".txt";
    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;
    ofstream out_data(pavadinimas);
    ifstream file_;

    cout << "Iveskite, kiek namu darbu reikia sugeneruoti: " << endl;
    cin >> sk;
    out_data << "Vardas" << "\t" << setw(14) << "Pavarde" << "\t" << setw(8);
    for (int l = 0; l < sk; l++)
        out_data << "ND" << to_string(l + 1) << setw(8);
    out_data << "\t" << "Egzamino pazymys" << endl;
    for (int i = 0; i < stud; i++) {
        out_data << "Vardas" << left << setw(9) << to_string(i + 1) << "Pavarde" << left << setw(8) << to_string(i + 1);
        for (int j = 0; j < sk; j++)
        {
            paz = rand() % 10 + 1;
            skaitiklis += 1;
            sum += paz;
            nd.push_back(paz);
            sort(nd.begin(), nd.end());
            out_data << setw(9) << paz;
            vid = sum / skaitiklis;
        }
        egzaminas = rand() % 10 + 1;
        out_data << "\t" << egzaminas << endl;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << endl;
    cout << to_string(stud) + " studentu failo kurimas uztruko: " << diff1.count() << " s\n";

    file_.open(pavadinimas);
    if (!file_) {
        cout << "Failo atidaryti nepavyko. Bandykite dar karta." << endl;
        exit(1);
    }
    auto start2 = std::chrono::high_resolution_clock::now();
    auto st2 = start2;
    while (!file_.eof())
    {
        getline(file_, eilute);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << endl;
    cout << to_string(stud) + " studentu failo nuskaitymas uztruko: " << diff2.count() << " s\n";
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
