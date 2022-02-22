#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], stack<int> &s, vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, s, vis);
        }
    }
    s.push(node);
}

vector<int> topoSort(int v, vector<int> adj[])
{
    stack<int> s;
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, s, vis);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topoSort(N, adj);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}