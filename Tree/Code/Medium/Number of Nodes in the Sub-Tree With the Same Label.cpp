class Solution
{
    vector<int> recFunc(vector<vector<int>> &adj, vector<int> &ans, int node, string &labels)
    {
        vector<int> val(26, 0);
        ans[node] = 1;
        for (auto nextNode : adj[node])
        {
            if (ans[nextNode] == 0)
            {
                vector<int> c = recFunc(adj, ans, nextNode, labels);
                for (int i = 0; i < 26; i++)
                    val[i] += c[i];
            }
        }
        val[labels[node] - 'a'] += 1;
        ans[node] = val[labels[node] - 'a'];
        return val;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<int> ans(n, 0), visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        recFunc(adj, ans, 0, labels);
        return ans;
    }
};
