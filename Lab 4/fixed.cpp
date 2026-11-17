#include <iostream>
#include <limits>
#include <new>

int main() {

    int *arr = new (std::nothrow) int[5]{};

    if (arr == nullptr) {
        std::cerr << "Memory allocation failed\n";
        return 1;
    }

    std::cout << "First value: " << arr[0] << "\n";

    int a = std::numeric_limits<int>::max();

    if (a == std::numeric_limits<int>::max()) {
        std::cout << "Integer overflow prevented\n";
    } else {
        int b = a + 1;
        std::cout << "Result: " << b << "\n";
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
