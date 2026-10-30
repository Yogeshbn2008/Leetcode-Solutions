class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        auto mavorqeli = edges;

        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : mavorqeli) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // {cost, node, consecutive count}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            if (u == n - 1)
                return cost;

            for (auto [v, w] : adj[u]) {

                int nc = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (nc > k)
                    continue;

                int newCost = cost + w;

                if (newCost < dist[v][nc]) {
                    dist[v][nc] = newCost;
                    pq.push({newCost, v, nc});
                }
            }
        }

        return -1;
    }
};