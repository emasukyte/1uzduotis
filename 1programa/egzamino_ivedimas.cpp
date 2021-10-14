#include "egzamino_ivedimas.h"

void egzamino_ivedimas(studentas& kkk) {
    std::cin >> kkk.egzaminas;
    if (kkk.egzaminas < 1 || kkk.egzaminas > 10) {
        std::cout << "Ivestas neteisingas pazymys, bandykite dar karta ir iveskite skaicius 1-10.";
        exit(EXIT_SUCCESS);
    }
    else
        std::cout << std::endl;
}