// for directed acyclic graph

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
class graph
{
public:
    unordered_map<int, list<pair<int, int> > > adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    void dfs(int node, vector<bool> &visited, stack<int> &topo)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }
    void getShortestPath(stack<int> topo, int src, vector<int> &dist)
    {

        dist[src] = 0;
        while (!topo.empty())
        {
            int topp = topo.top();
            topo.pop();
            if (dist[topp] != INT_MAX)
                for (auto i : adj[topp])
                {
                    if (dist[topp] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[topp] + i.second;
                    }
                }
        }
    }
};
int main()
{
    graph G;
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 6);
    G.addEdge(2, 3, 7);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(3, 4, -1);
    G.addEdge(4, 5, -2);
    int n = 6;
    vector<bool> visited(n, 0);
    stack<int> topo;

    G.printAdj();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            G.dfs(i, visited, topo);
    }
    int src = 1;
    vector<int> dist(n, INT_MAX);
    G.getShortestPath(topo, src, dist);
    for (int i = src; i < n; ++i)
    {
        cout << "Distance of node " << i << " from source is: ";
        cout << dist[i];
        cout << endl;
    }
    return 0;
}
