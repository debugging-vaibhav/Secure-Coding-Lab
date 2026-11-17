#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[10];
    char input[100];
    int age;

    cout << "Enter a name: ";
    cin.getline(input, 100);
    strcpy(name, input);

    cout << "Enter a age: ";
    cin >> age;

    if (age = 18) {
        cout << "Adult" << endl;
    }
    else {
        if (age > 10) {
            if (age < 20) {
                cout << "Teenager" << endl;
            }
        }
    }

    int x = 100;
    int y = 20;

    cout << x/y << endl;

    return 0;
}
