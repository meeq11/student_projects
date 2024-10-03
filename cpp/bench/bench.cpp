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
    } else if (value == 4) {
	return 4;
    } else {
    return 0;
}
}

int cSwitch(int value) {
    switch (value) {
        case 1:
        return 1;
        case 2:
        return 2;
        case 3:
        return 3;
	case 4:
	return 4;
        default:
        return 0;
    }
}

TEST(BenchmarkTest, IfBenchmark) {
    const int iterations = 100000;
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
    const int iterations = 100000;
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
