#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countPossibleArrays(string S, int K) {
    int N = S.size();
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        int num = S[i - 1] - '0';
        int mul = 10;
        for (int j = i - 2; j >= 0; j--) {
            if (mul > K)
                break;

            int digit = S[j] - '0';
            num += digit * mul;
            if (num <= K && S[j] != '0') {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }

            mul *= 10;
        }
    }

    return dp[N];
}

int main() {
    string S ;
    int n,K;
    cin>>n>>K;
    cin>>S;

    if (K < *max_element(S.begin(), S.end()) - '0' || S[0] == '0') {
        cout << 0 << endl;
    } else {
        int result = countPossibleArrays(S, K);
        cout << result << endl;
    }

    return 0;
}
