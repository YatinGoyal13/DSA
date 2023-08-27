#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> dp(n+1, 0);
        dp[3] = 1;

        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i - 2; ++j) {
                for (int k = j + 2; k <= i - 1; ++k) {
                    dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                }
            }
        }

        long long total_ways = dp[n];
        for (int i = 3; i <= n; ++i) {
            total_ways = (total_ways - dp[i]) % MOD;
        }

        if (total_ways < 0) {
            total_ways += MOD;
        }

        cout << total_ways << endl;
    }

    return 0;
}
