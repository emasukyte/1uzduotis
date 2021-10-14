// v0.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>
#include "egzamino_generatorius.h"
#include "egzamino_ivedimas.h"
#include "pild.h"
#include "mediana.h"
#include "pazymiu_generatorius.h"
#include "pazymiu_ivedimas.h"
#include "printas1.h"
#include "printas2.h"
#include "studentas.h"

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
using std::istringstream;
//using std::exception;


int main()
{
    int stud, duom;
    char raide, x, y, z, w;
    studentas studentai[100];

    cout << "Ar norite duomenis ivesti patys, ar nuskaityti juos is failo? Jeigu patys, spauskite p, jeigu is failo, spauskite f." << endl;
    cin >> z;
    try {
        if (z != 'p' && z != 'P' && z != 'f' && z != 'F') {
            throw 1;
        }
    }catch (int error)
    {
        cout << "Simbolis netinkamas, turite ivesti p arba f simboli." << endl;
    }
        if (z == 'p' || z == 'P') {
            cout << "Iveskite studentu skaiciu: " << endl;
            cin >> stud;
            try {
                if (stud < 1 || stud > 100) {
                    throw 2;
                }
            }catch (int error)
            {
                cout <<"Ivestas blogas studentu skaicius, iveskite skaiciu is naujo (nuo 1-100)" <<" "<< endl;
                exit(1);
            }
            for (int i = 0; i < stud; i++) {
                cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
                pild(studentai[i]);
            }
            cout << "Ar zinote, kiek namu darbu pazymiu bus? Jei taip, irasykite t, jei ne - irasykite n." << endl;
            cin >> x;
            try {
                if (x != 't' && x != 'T' && x != 'n' && x != 'N') {
                    throw 3;
                }
            }catch (int error)
            {
                cout << "Simbolis netinkamas, turite ivesti t arba n simboli." << endl;
                exit(1);
            }
            if (x == 'n' || x == 'N') {
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
                try {
                    if (y != 'p' && y != 'P' && y != 'k' && y != 'K') {
                        throw 4;
                    }
                }catch (int error)
                {
                    cout << "Simbolis netinkamas, turite ivesti p arba k simboli." << endl;
                    exit(1);
                }
                if (y == 'k' || y == 'K') {
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
            cout << "Ar egzamino pazymi ivesite patys, ar ji sugeneruoti kompiuteriui? Jei patys, spauskite 'p', jei kompiuteris, spauskite 'k' (noredami nutraukti pazymiu ivedima spauskite 0)." << endl;
            cin >> w;
            try {
                if (w != 'p' && w != 'P' && w != 'k' && w != 'K') {
                    throw 5;
                }
            }catch (int error)
            {
                cout << "Simbolis netinkamas, turite ivesti p arba k simboli." << endl;
                exit(1);
            }
            if (w == 'k' || w == 'K') {
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
            try {
                if (raide != 'v' && raide != 'V' && raide != 'm' && raide != 'M') {
                    throw 6;
                }
            }catch (int error)
            {
                cout << "Simbolis netinkamas, turite ivesti v arba m simboli." << endl;
                exit(1);
            }

            if (raide == 'v' || raide == 'V') {
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
    else if (z == 'f' || z == 'F') {
        ifstream file_;
        string eilute, vardas, pavarde;
        vector<int>v;
        float sk2 = 0;
        double galutinis1, galutinis2, vid, vidurinis, mediana;
        int z = 0, sum = 0, grade;


        file_.open("studentai10000.txt.txt");
        try{
            if (!file_) {
                throw 7;
            }
        }
        catch (int error) {
            cout << "Failo atidaryti nepavyko. Bandykite dar karta." << endl;
            exit(1);
        }
        cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(47) << "Galutinis pazymys pagal vidurki" << "\t" << setw(36) << "Galutinis pazymys pagal mediana" << endl;
        getline(file_, eilute);
        while (!file_.eof())
        {
            getline(file_, eilute);
            istringstream ss(eilute);
            ss >> vardas >> pavarde;
            cout << setw(15) << left << vardas << " " << setw(15) << left << pavarde << " " << "\t" << setw(3) << left;
            while (ss >> grade) {
                sk2 += 1;
                sum += grade;
                v.push_back(grade);
            }
            v.pop_back();
            sort(v.begin(), v.end());
            vidurinis = size(v) / 2;
            mediana = size(v) % 2 == 0 ? (v[vidurinis - 1] + v[vidurinis]) / 2.0 : v[vidurinis];
            sum -= grade;
            vid = sum / (sk2 - 1);
            galutinis1 = 0.4 * vid + 0.6 * grade;
            galutinis2 = 0.4 * mediana + 0.6 * grade;
            v.clear();
            sum -= sum;
            sk2 = 0;
            z++;
            cout << galutinis1 << setprecision(3) << " " << setw(30) << "\t";
            cout << galutinis2 << setprecision(3) << endl;
        }

        file_.close();

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
