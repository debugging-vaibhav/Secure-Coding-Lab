#include <iostream>
#include <string>

constexpr int MIN_AGE = 0;
constexpr int MAX_AGE = 150;
constexpr int ADULT_AGE = 18;
constexpr int TEEN_MIN = 10;
constexpr int TEEN_MAX = 20;

int main() {
    std::string name;
    int age = 0;

    std::cout << "Enter a name: ";
    if (!std::getline(std::cin, name) || name.empty()) {
        std::cerr << "Invalid name\n";
        return 1;
    }

    std::cout << "Enter an age: ";
    if (!(std::cin >> age) || age < MIN_AGE || age > MAX_AGE) {
        std::cerr << "Invalid age\n";
        return 1;
    }

    std::cout << name << ": ";
    if (age >= ADULT_AGE) {
        std::cout << "Adult\n";
    }
    else if (age > TEEN_MIN && age < TEEN_MAX) {
        std::cout << "Teenager\n";
    }
    else {
        std::cout << "Minor\n";
    }

    return 0;
}
