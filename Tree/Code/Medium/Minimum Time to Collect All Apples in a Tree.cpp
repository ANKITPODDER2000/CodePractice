class Solution
{
    int recFunc(int node, vector<vector<int>> &adj, vector<bool> &hasApple,
                vector<int> &visited)
    {
        int time = 0;
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (visited[i] == 0)
            {
                time += recFunc(i, adj, hasApple, visited);
            }
        }
        if (hasApple[node] || time > 0)
            return time + 2;
        return 0;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int time = recFunc(0, adj, hasApple, visited);
        return time > 0 ? time - 2 : 0;
    }
};