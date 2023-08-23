#include<vector>
#include<string>
#include<iostream>
using namespace std;
int solution(vector<string> &S, int K)
{
    int count = 0;
    for (int i = 0; i < S.size(); i++)
    {
        int freq = 0;
        for (int j = 0; j < S[i].length(); j++)
        {
            int curr_pos = S[i][j] - 'a';
            freq = freq | (1 << curr_pos);
        }
        int ans = 0;
        while (freq != 0)
        {
            if ((freq & 1) == 1)
                ans++;
            freq = freq >> 1;
        }
        if (ans <= K)
        {
            count++;
        }
    }
    return count;
}

int main(){
    vector<string> str = {"abc","abb","cb","a","bbb"};
    int ans = solution(str,2);
    cout << ans << endl;
}