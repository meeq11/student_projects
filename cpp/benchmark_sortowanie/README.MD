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

## Funkcja główna

```cpp
int main(int argc, char **argv)
