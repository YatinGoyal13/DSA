#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int MOD=1000000007;

int countPossibleArrays(const string& s, int K) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if ((s[i-1]-'0')>K){
            return 0;
        }
        else
        {
            dp[i]=dp[i-1];
        }
        if (i >= 2)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int num = stoi(s.substr(j, i));

                if((num<=K)){
                    if((i+j)<n)
                    {string ss=s.substr(i+j);
                    dp[i]=(dp[i]+countPossibleArrays(ss,K))% MOD;
                    }
                    else{
                        dp[i]=(dp[i]+1)% MOD;
                    }
                }
            }
        }

    }

    return dp[n];
}

int main() {

    string s;
    int n, K;
    cin >> n >> K;
    cin>>s;

    int count = countPossibleArrays(s, K);
    cout << count << endl;

    return 0;
}
