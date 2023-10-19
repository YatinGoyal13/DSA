#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include <list>
#include<limits.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> x;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        x.push_back(d);
    }
    int a=0,b=0;
    int u=0,v=n-1;
    while(v>=u)
    {
        if(x[u]>x[v])
        {
            a+=x[u];
            
        }
        
    }
    cout<<abs(a-b)<<endl;

    return 0;
}