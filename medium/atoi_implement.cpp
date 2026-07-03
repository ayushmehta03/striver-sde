#include <iostream>
#include <limits>
#include <string>
#include <cctype> 

using namespace std;

// Helper func to convert string into integer
int ad(string s) {
    int sign = 1;
    long long res = 0;
    int i = 0;
    int n = s.size();

    // Skip the white space and move the i pointer
    while (i < n && s[i] == ' ') i++;

    // Check the sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        // If the sign is - convert sign into -1 else 1
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Add on the digits
    while (i < n && isdigit(s[i])) {
        // Get the digit
        int digit = s[i] - '0';

        // Add to the result
        res = res * 10 + digit;

        if (sign == 1 && res > INT_MAX) return INT_MAX;
        if (sign == -1 && -res < INT_MIN) return INT_MIN;

        i++; // 
    }

    return (int)(sign * res);
}

int main() {
    string s;
    getline(cin, s); 

    int ans = ad(s);
    cout << "integer is: " << ans << endl;
    cout << "type is: " << typeid(ans).name() << endl; 

    return 0;
}