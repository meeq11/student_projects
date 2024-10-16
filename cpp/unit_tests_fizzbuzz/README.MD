# FizzBuzz Program

## Opis

Program implementuje klasyczną funkcję **FizzBuzz**, która działa zgodnie z poniższymi zasadami:
- Jeśli liczba jest podzielna przez 3, zwraca "Fizz".
- Jeśli liczba jest podzielna przez 5, zwraca "Buzz".
- Jeśli liczba jest podzielna przez 3 i 5, zwraca "FizzBuzz".
- W przeciwnym wypadku zwraca samą liczbę jako ciąg znaków.

Dodatkowo, program zawiera testy jednostkowe napisane w Google Test, które sprawdzają poprawność działania funkcji `fizzBuzz`.

## Testy
| Nazwa testu | Opis | Przykładowe dane wejściowe | Oczekiwany wynik |
|--------------------|--------------------|---------------------|---------------------|
| MultipleOf3 | Testuje przypadki, gdy liczba jest wielokrotnością 3 | 3, 9, 21 | "Fizz" |
| MultipleOf5 | Testuje przypadki, gdy liczba jest wielokrotnością 5 | 5, 10, 20 | "Buzz" |
| MultipleOf3And5 | Testuje przypadki, gdy liczba jest wielokrotnością 3 i 5 | 15, 30, 45 | "FizzBuzz" |
| NonMultipleOf3And5 | Testuje przypadki, gdy liczba nie jest wielokrotnością 3 i 5 | 4, 7, 16 | "4", "7", "16" |
