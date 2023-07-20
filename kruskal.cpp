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

void makeset(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    // Your graph-related code goes here
int n;
    // number of nodes
cin>>n;
vector<int> parent(n);
vector<int> rank(n);
makeset(parent,rank,n);
    return 0;
}