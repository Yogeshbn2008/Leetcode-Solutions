class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        void rangeXor(int l, int r, int val) {
            add(l + 1, val);
            if (r + 1 < n)
                add(r + 2, val);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), pref(n);

        struct Event {
            int u, p;
            bool exit;
        };

        stack<Event> st;
        st.push({0, 0, false});
        int timer = 0;

        while (!st.empty()) {
            auto [u, p, exit] = st.top();
            st.pop();

            if (exit) {
                tout[u] = timer - 1;
                continue;
            }

            up[0][u] = p;
            depth[u] = (u == p ? 0 : depth[p] + 1);

            for (int j = 1; j < LOG; j++)
                up[j][u] = up[j - 1][up[j - 1][u]];

            pref[u] = (u == p ? 0 : pref[p])
                    ^ (1 << (s[u] - 'a'));

            tin[u] = timer++;

            st.push({u, p, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v != p)
                    st.push({v, u, false});
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        Fenwick fw(n);
        vector<bool> ans;

        for (string q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a'))
                          ^ (1 << (c - 'a'));

                fw.rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ fw.query(tin[u] + 1);
                int pv = pref[v] ^ fw.query(tin[v] + 1);

                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};