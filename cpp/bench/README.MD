# IfVsSwitch PerformanceTest

Ten kod implementuje dwa benchmarki porównujące czas wykonywania instrukcji warunkowej if oraz instrukcji switch w C++. 
Testy zostały napisane przy użyciu frameworka Google Test i wykorzystują bibliotekę chrono do mierzenia czasu. 
Celem testów jest zmierzenie wydajności obu podejść dla zestawu operacji iterowanych w pętli.

## Kod

```cpp
#include <gtest/gtest.h>
#include <chrono>
#include <iostream>

int cIf(int value) {
    if (value == 1) {
        return 1;
    } else if (value == 2) {
        return 2;
    } else if (value == 3) {
        return 3;
    }
    return 0;
}

int cSwitch(int value) {
    switch (value) {
        case 1:
        return 1;
        case 2:
        return 2;
        case 3:
        return 3;
        default:
        return 0;
    }
}

TEST(BenchmarkTest, IfBenchmark) {
    const int iterations = 10000;
    int sIf = 0;

    auto startIf = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sIf += cIf(i % 4);
    }
    auto endIf = std::chrono::high_resolution_clock::now();
    auto durationIf = std::chrono::duration_cast<std::chrono::microseconds>(endIf - startIf);

    std::cout << "Trwanie if: " << durationIf.count() << " mikrosekund" << std::endl;
}

TEST(BenchmarkTest, SwitchBenchmark) {
    const int iterations = 10000;
    int sSwitch = 0;

    auto startSwitch = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sSwitch += cSwitch(i % 4);
    }
    auto endSwitch = std::chrono::high_resolution_clock::now();
    auto durationSwitch = std::chrono::duration_cast<std::chrono::microseconds>(endSwitch - startSwitch);

    std::cout << "Trwanie switch: " << durationSwitch.count() << " mikrosekund" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```



## Testy

TEST(BenchmarkTest, IfBenchmark)

Opis: Testuje czas wykonywania funkcji cIf w pętli. Funkcja jest wywoływana 10 000 razy, gdzie wartość przekazywana do funkcji to wynik operacji i % 4 (dla każdej iteracji i, zwracana jest reszta z dzielenia przez 4, czyli wartości w przedziale 0-3).
Mierzenie czasu:
Zmierzony czas zaczyna się przed pętlą i kończy się zaraz po niej. Czas jest obliczany w mikrosekundach.
Wynik:
Wydrukowany czas wykonania funkcji cIf w mikrosekundach.

TEST(BenchmarkTest, SwitchBenchmark)

Opis: Testuje czas wykonywania funkcji cSwitch w analogiczny sposób jak IfBenchmark. Funkcja jest wywoływana 10 000 razy z wartościami od 0 do 3 (wynik i % 4).
Mierzenie czasu:
Zmierzony czas zaczyna się przed pętlą i kończy się po niej, a czas jest obliczany w mikrosekundach.
Wynik:
Wydrukowany czas wykonania funkcji cSwitch w mikrosekundach.
## Kontrybucja

Wszelkie propozycje ulepszeń mile widziane. Prosimy o przestrzeganie naszych wytycznych przy kontrybucji.

## Zrzuty ekranu i wyniki

![przykladowa grafika](Screenshot_1.png)

## Autorzy

- [Maksym Petrushkevych](https://github.com/meeq11)
