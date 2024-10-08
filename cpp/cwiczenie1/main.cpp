#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

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
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size() - 1 - i; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0));
    std::generate(vec.begin(), vec.end(), std::rand);

    std::vector<int> vecCopy = vec;

    auto startQuick = std::chrono::high_resolution_clock::now();
    quickSort(vec);
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedQuick = endQuick - startQuick;

    auto startBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(vecCopy);
    auto endBubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedBubble = endBubble - startBubble;

    std::cout << "Czas sortowania QuickSort: " << elapsedQuick.count() << "s\n";
    std::cout << "Czas sortowania bąbelkowego: " << elapsedBubble.count() << "s\n";

    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    EXPECT_TRUE(std::is_sorted(vecCopy.begin(), vecCopy.end()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
