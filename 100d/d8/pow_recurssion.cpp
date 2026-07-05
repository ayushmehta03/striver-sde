#include <iostream>
using namespace std;

int power(int base, int exponent) {
    int ans = 1;

    while (exponent != 0) {
        ans *= base;
        exponent--;
    }

    return ans;
}

int main() {
    int base, exponent;

    cin >> base;
    cin >> exponent;

    cout << "The number after applying " << exponent << " power is:\n";
    cout << power(base, exponent);
}