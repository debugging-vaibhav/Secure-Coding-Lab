#include <iostream>
#include <climits>

int main() {

    int *arr = new int[5];

    std::cout << "First value: " << arr[0] << "\n";

    int a = INT_MAX;
    int b = a + 1;

    std::cout << "Result: " << b << "\n";

    delete[] arr;
    std::cout << "After free: " << arr[0] << "\n";

    return 0;
}
