#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

// int ballonGame(int input1, int input2[])
// {
//     int count = input1;
//     int ans = 0;
//     int x = 1;
//     int pd = 0;
//     vector<bool> visited(input1, false);
//     sort(input2, input2 + input1);
//     while (count != 0)
//     {
//         int y;
//         int flag=0;
//         pd = pd + x;
//         for (int i = 0; i < input1; i++)
//         {
//             if (input2[i] == pd && !visited[i])
//             {
//                 visited[i] = 1;
//                 pd = 0;
//                 x++;
//                 count--;
//                 flag=0;
//                 break;
//             }
//             else if(input2[i] <= pd && !visited[i])
//             {
//                 flag=1;
//                 y=i;
//             }
//         }
//         if(flag==1)
//         {
//             visited[y] = 1;
//                 pd = 0;
//                 x++;
//                 count--;
//                 flag=0;
//         }
//         ans++;
//     }
//     return ans;
// }
int ballonGame(int input1, int input2[]) {
    unordered_map<int, int> balloons;
    for (int i = 0; i < input1; i++) {
        balloons[input2[i]]++;
    }

    int count = input1;
    int ans = 0;
    int x = 1;
    int pd = 0;

    while (count != 0) {
        pd += x;
        if (balloons.count(pd) && balloons[pd] > 0) {
            balloons[pd]--;
            pd = 0;
            x++;
            count--;
        }
        ans++;
    }

    return ans;
}
int main()
{
    int input1 = 2;
    int input2[2] = {9,9};
    cout << ballonGame(input1, input2) << endl;
    return 0;
}