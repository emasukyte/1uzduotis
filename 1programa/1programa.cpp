// 1programa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;
using std::vector;
using std::sort;

struct studentas {
    string vardas, pavarde;
    float namu_darbai[10]{};
    float egzaminas;
    float galutinis_pazymys;
    double mediana;
};

void pild(studentas& kint);
void printas1(studentas& kin);
void printas2(studentas& ki);

int main()
{
    char raide;
    studentas studentai[10];
    for (int i = 0; i < 3; i++)
        pild(studentai[i]);
    cout << "Iveskite, ar galutini pazymi norite matyti isvesta pagal namu darbu pazymiu vidurki, ar pagal ju mediana. Jei vidurkis, rasykite v, jei mediana, rasykite m." << endl;
    cin >> raide;
    if (raide != 'v' && raide != 'V' && raide != 'm' && raide != 'M') {
        cout << "Simbolis netinkamas, turite ivesti v arba m simboli." << endl;
        exit(EXIT_SUCCESS);
    }

    else if (raide == 'v' || raide == 'V')
        void printas1(studentas & kin);
    else if (raide == 'm' || raide == 'M')
        void printas2(studentas & ki);
    if (raide == 'v' || raide == 'V')
        cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(36) << "Galutinis rezultatas pagal vidurki" << endl;
    else if (raide == 'm' || raide == 'M')
        cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(36) << "Galutinis rezultatas pagal mediana" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < 3; i++)
        printas1(studentai[i]);
}

void pild(studentas& kint) {
    int n;
    vector <int> nd;
    int vidurinis;
    cout << "Iveskite studento varda ir pavarde "; cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek namu darbu bus? (1-10) "; cin >> n;

    if (n < 1 || n > 10) {
        cout << "Ivestas neteisingas skaicius, bandykite dar karta ir iveskite skaicius 1-10.";
        exit(EXIT_SUCCESS);
    }
    else
        cout << "Iveskite pazymius: " << endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.namu_darbai[i];
        if ((kint.namu_darbai[i] < 1) || (kint.namu_darbai[i] > 10)) {
            cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
            exit(EXIT_SUCCESS);
        }
        else {
            sum += kint.namu_darbai[i];
            nd.push_back(kint.namu_darbai[i]);
            sort(nd.begin(), nd.end());
            vidurinis = size(nd) / 2;
            kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis - 1] + nd[vidurinis]) / 2.0 : nd[vidurinis];

        }
    }
    vid = sum / n;
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egzaminas;
    if (kint.egzaminas < 1 || kint.egzaminas > 10) {
        cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
        exit(EXIT_SUCCESS);
    }
    else
        kint.galutinis_pazymys = vid * 0.4 + 0.6 * kint.egzaminas;

}

void printas1(studentas& kin) {
    cout << setw(15) << left << kin.vardas << " " << setw(15) << left << kin.pavarde << " " << "\t" << setw(3) << left << setprecision(3) << kin.galutinis_pazymys << endl;

}

void printas2(studentas& ki) {
    ki.galutinis_pazymys = ki.mediana * 0.4 + 0.6 * ki.egzaminas;
    cout << setw(15) << left << ki.vardas << " " << setw(15) << left << ki.pavarde << " " << "\t" << setw(3) << left << setprecision(3) << ki.galutinis_pazymys << endl;
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

