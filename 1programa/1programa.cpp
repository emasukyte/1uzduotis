// 1programa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;

struct studentas {
    string vardas, pavarde;
    float namu_darbai[10]{};
    float egzaminas;
    float galutinis_pazymys;
};

void pild(studentas &kint);
void printas(studentas &kin);


int main()
{
    studentas studentai[10];
    for (int i = 0; i < 3; i++)
        pild(studentai[i]);
    cout << "Vardas" << "\t" << setw(15) << "Pavarde" << "\t" << setw(36) << "Galutinis rezultatas" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < 3; i++)
        printas(studentai[i]);
    
}

    void pild(studentas &kint) {
        int n;
        cout << "Iveskite studento varda ir pavarde "; cin >> kint.vardas >> kint.pavarde;
        cout << "Kiek namu darbu bus? (1-10) "; cin >> n;
        if (n < 1 || n > 10) {
            cout<<"Ivestas neteisingas skaicius, bandykite dar karta ir iveskite skaicius 1-10.";
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
            else
                sum += kint.namu_darbai[i];
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

    void printas(studentas &kin) {
        cout << setw(15) << left << kin.vardas << " " << setw(15) << left << kin.pavarde << " " << "\t" << setw(3) << left << setprecision(3) << kin.galutinis_pazymys << endl;;
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
