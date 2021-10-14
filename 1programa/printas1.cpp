#include "printas1.h"

void printas1(studentas& kin) {
    kin.galutinis_pazymys = kin.vid * 0.4 + 0.6 * kin.egzaminas;
    std::cout << std::setw(15) << std::left << kin.vardas << " " << std::setw(15) << std::left << kin.pavarde << " " << "\t" << std::setw(3) << std::left << std::setprecision(3) << kin.galutinis_pazymys << std::endl;
}