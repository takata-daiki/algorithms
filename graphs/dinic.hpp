#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    int n, init;
    vector<int> itr, level;
    vector<vector<Edge>> g;

    Dinic(int _n, int _init = 1e9) : n(_n), init(_init), g(_n) {}

    void add_edge(int u, int v, int c) {
        int sz_u = g[u].size();
        int sz_v = g[v].size();
        g[u].push_back({v, c, sz_v});
        g[v].push_back({u, 0, sz_u});
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) break;
            itr.assign(n, 0);
            for (int f; (f = dfs(s, t, init)) > 0;) flow += f;
        }
        return flow;
    }
    void bfs(int s) {
        level.assign(n, -1);
        queue<int> que({s});
        level[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto&& e : g[u]) {
                int v = e.to;
                if (level[v] < 0 && e.cap > 0) {
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    int dfs(int u, int t, int c) {
        if (u == t) return c;
        for (int& i = itr[u]; i < (int)g[u].size(); ++i) {
            Edge& e = g[u][i];
            int v = e.to;
            if (level[u] < level[v] && e.cap > 0) {
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
};