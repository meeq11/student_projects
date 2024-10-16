# Dokumentacja kodu

Kod ten implementuje dwa algorytmy sortowania: **szybkie sortowanie (quick sort)** oraz **sortowanie bąbelkowe (bubble sort)**. Przy użyciu frameworka Google Test dokonano testów porównawczych, które mierzą czas wykonania każdego z algorytmów na dużym zbiorze danych (10 000 losowych elementów).

## Funkcje sortujące

### Funkcja `quickSort`

| Nazwa funkcji     | Opis                                                                                                              |
|--------------------|--------------------------------------------------------------------------------------------------------------------|
| `void quickSort(std::vector<int>& vec)` | Funkcja rekurencyjnie implementująca algorytm szybkiego sortowania. Jeśli wektor `vec` zawiera więcej niż jeden element, wybiera element pivotu (środkowy element wektora), po czym dzieli pozostałe elementy na dwa wektory: `left` (elementy mniejsze niż pivot) i `right` (elementy większe niż pivot). Następnie rekurencyjnie sortuje oba podzbiory i łączy je w jeden posortowany wektor. |

**Parametry**:
- `vec`: Referencja do wektora `std::vector<int>`, który zostanie posortowany.

### Funkcja `bubbleSort`

| Nazwa funkcji     | Opis                                                                                                              |
|--------------------|--------------------------------------------------------------------------------------------------------------------|
| `void bubbleSort(std::vector<int>& vec)` | Implementuje algorytm sortowania bąbelkowego, który wielokrotnie iteruje przez wektor, zamieniając miejscami sąsiadujące elementy, jeśli są one w niewłaściwej kolejności. Proces ten jest powtarzany aż do posortowania całego wektora. |

**Parametry**:
- `vec`: Referencja do wektora `std::vector<int>`, który zostanie posortowany.

## Testy porównawcze

W kodzie znajdują się dwa testy, `QuickSortBenchmark` oraz `BubbleSortBenchmark`, które mierzą czas wykonania odpowiednio funkcji `quickSort` i `bubbleSort`.

### Test `QuickSortBenchmark`

- Tworzy wektor `vec` zawierający 10 000 losowych liczb.
- Mierzy czas rozpoczęcia sortowania (`start`) przy użyciu `std::chrono::high_resolution_clock::now()`.
- Wywołuje funkcję `quickSort` na wektorze `vec`.
- Mierzy czas zakończenia sortowania (`end`).
- Wyświetla czas wykonania algorytmu w sekundach.

### Test `BubbleSortBenchmark`

- Tworzy wektor `vec` zawierający 10 000 losowych liczb.
- Mierzy czas rozpoczęcia sortowania (`start`).
- Wywołuje funkcję `bubbleSort` na wektorze `vec`.
- Mierzy czas zakończenia sortowania (`end`).
- Wyświetla czas wykonania algorytmu w sekundach.

## Czas wykonania algorytmów

| Algorytm          | Przypadek testowy       | Czas wykonania (ms)      |
|--------------------|-------------------------|--------------------------|
| **Quick Sort**     | Losowy wektor 10 000    | 13    |
| **Bubble Sort**    | Losowy wektor 10 000    | 672    |

## Analiza wyników

1. **Quick Sort**:
   - **Efektywność**: Szybkie sortowanie jest znacznie bardziej efektywne niż sortowanie bąbelkowe, szczególnie dla dużych zbiorów danych. Algorytm działa w średnim czasie O(n log n), co czyni go jednym z najszybszych algorytmów sortowania.
   - **Rekurencyjność**: Szybkie sortowanie używa podejścia dziel i rządź, co sprawia, że jest w stanie efektywnie dzielić problem na mniejsze podproblemy.

2. **Bubble Sort**:
   - **Wydajność**: Sortowanie bąbelkowe ma średnią złożoność czasową O(n²), co sprawia, że staje się niepraktyczne dla dużych zbiorów danych. Czas wykonania znacznie wzrasta w miarę zwiększania się rozmiaru wektora.
   - **Prostota**: Mimo że sortowanie bąbelkowe jest łatwe do zrozumienia i zaimplementowania, nie jest zalecane do użytku w aplikacjach wymagających efektywności.

## Wnioski

- **Szybkie sortowanie** jest zdecydowanie lepszym wyborem dla sortowania dużych zbiorów danych, ze względu na swoją efektywność i szybszy czas wykonania.
- **Sortowanie bąbelkowe** może być użyteczne w celach edukacyjnych lub do sortowania małych zbiorów danych, ale w praktycznych zastosowaniach powinno być unikane ze względu na swoją niską wydajność.

