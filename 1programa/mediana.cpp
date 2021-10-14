#include "mediana.h"

void mediana(studentas& l) {
    l.vidurinis = size(l.nd) / 2;
    l.mediana = size(l.nd) % 2 == 0 ? (l.nd[l.vidurinis - 1] + l.nd[l.vidurinis]) / 2.0 : l.nd[l.vidurinis];
}