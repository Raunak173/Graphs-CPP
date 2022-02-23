#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &visited, int node)
    {
        visited.push_back(node);
        if (node == graph.size() - 1)
        { // If we are at the target node then we can push the path taken to our ans vector.
            ans.push_back(visited);
        }
        else
        {
            for (auto x : graph[node])
            {
                dfs(graph, ans, visited, x);
            }
        }
        visited.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        vector<int> visited;
        vector<vector<int>> ans;
        dfs(graph, ans, visited, 0);

        return ans;
    }
};