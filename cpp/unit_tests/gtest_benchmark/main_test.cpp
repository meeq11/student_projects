#include "benchmark/benchmark.h"
#include <vector>



int add(int a, int b) {
    return a + b;
}

static void BM_Add(benchmark::State& state) {
    int a = 5;
    int b = 10;
    for (auto _ : state) {
        int result = add(a, b);
        benchmark::DoNotOptimize(result);
    }
}


unsigned long long calculateSumOfSquares(int n) {
    unsigned long long *squares = new unsigned long long[n];
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        squares[i - 1] = i * i;
        sum += squares[i - 1];
    }
    delete[] squares;
    return sum;
}

static void BM_calculateSumOfSquares(benchmark::State& state) {
    for (auto _ : state) {
        unsigned long long result = calculateSumOfSquares(5);
        benchmark::DoNotOptimize(result);
    }
}



std::vector<int> findPrimes(int n) {
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}

static void BM_findPrimes(benchmark::State& state) {
    int n = 1000;  // Można zwiększyć dla trudniejszych testów
    for (auto _ : state) {
        auto primes = findPrimes(n);
        benchmark::DoNotOptimize(primes);
    }
}



BENCHMARK(BM_Add);
BENCHMARK(BM_calculateSumOfSquares);
BENCHMARK(BM_findPrimes);

BENCHMARK_MAIN();
