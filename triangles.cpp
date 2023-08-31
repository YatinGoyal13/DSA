#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int solve(int n) {
    vector<int> dp(n+1, 0);
    dp[3] = 1;

    for (int i = 4; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= i - 2; ++j) {
            for (int k = j + 2; k <= i - 1; ++k) {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - k]) % MOD) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        int result = solve(n);
        cout << result << endl;
    }

    return 0;
}
