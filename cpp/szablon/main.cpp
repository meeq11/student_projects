#include <iostream>
#include <cmath> // Do użycia funkcji std::floor i std::round

// Funkcja do obliczenia liczby stopni
int obliczLiczbeStopni(double wysokoscKondygnacji, double minWysokoscStopnia = 17.0, double maxWysokoscStopnia = 19.0) {
    // Liczymy wstępnie liczbę stopni dla maksymalnej i minimalnej wysokości stopnia
    int liczbaStopni = std::round(wysokoscKondygnacji / ((minWysokoscStopnia + maxWysokoscStopnia) / 2.0));
    return liczbaStopni;
}

// Funkcja do obliczenia wysokości stopni
double obliczWysokoscStopnia(double wysokoscKondygnacji, int liczbaStopni) {
    return wysokoscKondygnacji / liczbaStopni;
}

// Funkcja do obliczenia głębokości stopni
double obliczGlebokoscStopnia(double dlugoscBieguSchodow, int liczbaStopni) {
    return dlugoscBieguSchodow / liczbaStopni;
}

int main() {
    double wysokoscKondygnacji, dlugoscBieguSchodow;

    std::cout << "Podaj wysokosc kondygnacji (w cm): ";
    std::cin >> wysokoscKondygnacji;

    std::cout << "Podaj dlugosc biegu schodow (w cm): ";
    std::cin >> dlugoscBieguSchodow;

    int liczbaStopni = obliczLiczbeStopni(wysokoscKondygnacji);

    double wysokoscStopnia = obliczWysokoscStopnia(wysokoscKondygnacji, liczbaStopni);

    double glebokoscStopnia = obliczGlebokoscStopnia(dlugoscBieguSchodow, liczbaStopni);

    std::cout << "\nWyniki obliczen:\n";
    std::cout << "Liczba stopni: " << liczbaStopni << "\n";
    std::cout << "Wysokosc stopnia: " << wysokoscStopnia << " cm\n";
    std::cout << "Glebokosc stopnia: " << glebokoscStopnia << " cm\n";

    return 0;
}
