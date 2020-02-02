#pragma once
#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };

    const int n, init;
    vector<bool> used;
    vector<vector<Edge>> g;

    FordFulkerson(const int _n, const int _init = 1e9)
        : n(_n), init(_init), g(_n) {}

    void add_edge(const int u, const int v, const int c) {
        int sz_u = g[u].size();
        int sz_v = g[v].size();
        g[u].push_back({v, c, sz_v});
        g[v].push_back({u, 0, sz_u});
    }
    int dfs(const int u, const int t, const int c) {
        if (u == t) return c;
        used[u] = true;
        for (auto&& e : g[u]) {
            int v = e.to;
            if (!used[v] && e.cap > 0) {
                int f = dfs(v, t, min(c, e.cap));
                if (f > 0) {
                    e.cap -= f;
                    g[v][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int build(const int s, const int t) {
        int flow = 0;
        while (true) {
            used.assign(n, false);
            int f = dfs(s, t, init);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};