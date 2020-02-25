#pragma once
#include <bits/stdc++.h>
using namespace std;

struct BiconnectedComponents {
    int n;
    int time;
    vector<bool> is_art_point;
    vector<int> idx, low;
    set<pair<int, int>> bridges;
    vector<vector<int>> g;

    BiconnectedComponents(int _n)
        : n(_n),
          time(0),
          is_art_point(_n, false),
          idx(_n, -1),
          low(_n, -1),
          g(_n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (idx[i] == -1) dfs(i, -1);
        }
    }
    void dfs(int u, int p) {
        idx[u] = low[u] = time++;
        for (auto&& v : g[u]) {
            if (idx[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (idx[u] <= low[v])
                    is_art_point[u] = (idx[u] > 0) || (idx[v] > 1);
                if (idx[u] < low[v]) bridges.insert({min(u, v), max(u, v)});
            } else if (v != p) {
                low[u] = min(low[u], idx[v]);
            }
        }
    }
};