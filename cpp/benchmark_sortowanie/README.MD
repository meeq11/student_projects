# Benchmark sortowanie

Jako zadanie na lekcji mieliśmy zrobić benchmarksortowanie, jest to bardzo prosty algorytm do zaimplemntowania 
a naszym celem na koniec było wykonanie test aplikacji na koniec.

## Część kodu
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// Funkcja sortująca wektor za pomocą QuickSort
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

void bubbleSort(std::vector<int>& vec) {
	for (size_t i =0; i < vec.size(); i++) {
		for (size_t j =0; j < vec.size() - 1 - i; j++) {
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
			}
		}
	}
}

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);


    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(vec); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

TEST(BenchmarkTest, BubbleSortBenchmark) {
	std::vector<int> vec(10000);
	std::srand(time(0));
	std::generate(vec.begin(), vec.end(), rand);

	auto start = std::chrono::high_resolution_clock::now();

	bubbleSort(vec);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "Czas sortowania babelkowego: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## Użycie

Instrukcje jak uruchomić aplikację: 
sh kompiluj_test.sh

## Wynik sortowania

![przykladowa grafika](Screenshot1.png)

## Kontrybucja

Wszelkie propozycje ulepszeń mile widziane. Prosimy o przestrzeganie naszych wytycznych przy kontrybucji.

## Autorzy

- [Maksym Petrushkevych](https://github.com/meeq11)
