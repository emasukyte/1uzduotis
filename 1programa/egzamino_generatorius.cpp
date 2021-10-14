#include "egzamino_generatorius.h"

void egzamino_generatorius(studentas& ll) {
    ll.egzaminas = rand() % 10 + 1;
    std::cout << " " << ll.egzaminas << std::endl;
}