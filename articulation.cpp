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

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low,
         vector<bool> &vis, unordered_map<int, list<int> > &adj,
         vector<int> &result)
{
    vis[node] = 1;
    disc[node] = low[node] = timer++;
    int child=0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, vis, adj, result);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] >= disc[node] && parent!=-1)
            {
                result[node]=1;
            }
            child++;
        }
        else
        {
            // back edge case
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent==1 && child>1)
    {
        result[node]=1;
    }
}

int main()
{
    int n = 5;
    int e = 5;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(0, 1));

    unordered_map<int, list<int> > adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1;
    int timer = 0;
    vector<bool> vis(n, 0);
    vector<int> ap(n,0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, vis, adj, ap);
        }
    }
   cout << "Articulation Points: ";
   for (int i = 0; i < n; i++)
   {
    if(ap[i]==1)
    {
        cout<<i<<" ";
    }
   }
   
    return 0;
}
