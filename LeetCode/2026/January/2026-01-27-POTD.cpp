class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        vector<unordered_map<int,int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];

            if (!adj[u].count(v)) adj[u][v] = w;
            else adj[u][v] = min(adj[u][v], w);

            int backCost = 2 * w;
            if (!adj[v].count(u)) adj[v][u] = backCost;
            else adj[v][u] = min(adj[v][u], backCost);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;
            if (u == n - 1) return cost;

            for (auto &it : adj[u])
            {
                int v = it.first;
                int w = it.second;

                if (cost + w < dist[v])
                {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};
