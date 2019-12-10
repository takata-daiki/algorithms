#pragma once
#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };
    int n, init;
    vector<vector<Edge>> g;
    vector<bool> used;

    FordFulkerson() {}
    FordFulkerson(int n, int INF = 1e9) : n(n), g(n), init(INF) {}

    void add_edge(int u, int v, int c) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, c, szV});
        g[v].push_back({u, 0, szU});
    }
    int dfs(int u, int t, int c) {
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
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            used = vector<bool>(n, false);
            int f = dfs(s, t, init);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};