#include "pazymiu_generatorius.h"

void pazymiu_generatorius(studentas& k) {
    std::cout << "Iveskite, kiek namu darbu pazymiu reikia sugeneruoti: " << std::endl;
    std::cin >> k.sk;
    std::cout << "Jusu pazymiai: ";
    for (int i = 0; i < k.sk; i++)
    {

        k.paz = rand() % 10 + 1;
        k.skaitiklis += 1;
        k.sum += k.paz;
        k.nd.push_back(k.paz);
        sort(k.nd.begin(), k.nd.end());
        std::cout << k.paz << " ";
    }
    std::cout << std::endl;
    k.vid = k.sum / k.skaitiklis;

}