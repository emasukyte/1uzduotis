#include "pazymiu_ivedimas.h"

void pazymiu_ivedimas(studentas& kk) {
    while (std::cin >> kk.paz) {

        if (kk.paz == 0) {
            break;
        }

        else if ((kk.paz < 1) || (kk.paz > 10))
        {
            std::cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
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