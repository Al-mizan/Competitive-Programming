#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    string bcd;
    cout << "Enter the BCD code number: ";
    cin >> bcd;

    ll decimal = 0;
    for (int i = 0; i < bcd.size(); i += 4) {
        ll digit = 0;
        for (int j = 0; j < 4; j++) {
            if (bcd[i + j] == '1') {
                digit += (1 << (3 - j));
            }
        }
        decimal = decimal * 10 + digit;
    }

    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}