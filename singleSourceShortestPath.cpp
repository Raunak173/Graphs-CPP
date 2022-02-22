#include <bits/stdc++.h>
using namespace std;

vector<int> distances(vector<int> adj[], int v, int s)
{
    vector<int> d(v, INT_MAX);
    vector<bool> vis(v, false);
    queue<int> q;
    vis[s] = true;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (auto it : adj[p])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
                d[it] = d[p] + 1; // Calculating distances
            }
        }
    }
    return d;
}

int main()
{
    int v = 4;
    int e = 5;
    vector<int> adj[v];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[0].push_back(3);
    adj[3].push_back(0);
    // adj[2].push_back(0);
    // adj[0].push_back(2);
    vector<int> ans = distances(adj, v, 0);
    for (int x : ans)
    {
        cout << x << ",";
    }
    return 0;
}