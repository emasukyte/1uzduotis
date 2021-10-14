#include "printas2.h"

void printas2(studentas& ki) {
    ki.galutinis_pazymys = ki.mediana * 0.4 + 0.6 * ki.egzaminas;
    std::cout << std::setw(15) << std::left << ki.vardas << " " << std::setw(15) << std::left << ki.pavarde << " " << "\t" << std::setw(3) << std::left << std::setprecision(3) << ki.galutinis_pazymys <<std::endl;
}