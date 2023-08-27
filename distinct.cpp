#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long power_mod(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;

        long long configurations_A = power_mod(n, k);
        long long configurations_B = (power_mod(3, k) - configurations_A + MOD) % MOD; // Subtract configurations_A to avoid overcounting
        long long total_configurations = (configurations_A * configurations_B * 2) % MOD; // Multiply by 2 for both halves
        cout << total_configurations << endl;
    }

    return 0;
}
