#include <iostream>
#include <vector>

using namespace std;

int longestDivisibleSubsequenceLength(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                }
            }
        }
    }

    return maxLength;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr ;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        arr.push_back(d);
    }
    
    int result = longestDivisibleSubsequenceLength(arr);

    cout << "Length of Longest Divisible Subsequence: " << result << endl;

    return 0;
}
