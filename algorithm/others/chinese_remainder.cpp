#include <iostream>
using namespace std;

// Function to find modulo inverse of 'a' under modulo 'm'
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 0)
            return x;
    return 1;
}

// Function to find the smallest x such that:
// x ≡ num[i] (mod rem[i]) for all i
int chineseRemainder(int num[], int rem[], int k) {
    // Product of all numbers (n1 * n2 * ... * nk)
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply the formula: x = sum (rem[i] * pp[i] * inv[i]) % prod
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];  // pp[i] is prod / num[i]
        result += rem[i] * pp * modInverse(pp, num[i]);
    }

    return result % prod;
}

int main() {
    int k;
    cout << "Enter the number of equations: ";
    cin >> k;

    int num[k], rem[k];
    cout << "Enter the divisors (moduli):\n";
    for (int i = 0; i < k; i++)
        cin >> num[i];

    cout << "Enter the remainders:\n";
    for (int i = 0; i < k; i++)
        cin >> rem[i];

    cout << "The solution is: " << chineseRemainder(num, rem, k) << endl;

    return 0;
}
