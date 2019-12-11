#pragma once
#include <bits/stdc++.h>
using namespace std;

struct BiconnectedComponents {
    int n;
    int time;
    vector<vector<int>> g;
    vector<bool> is_art_point;
    vector<int> num, low;
    set<pair<int, int>> bridges;

    BiconnectedComponents(int n)
        : n(n), time(0), g(n), num(n, -1), low(n, -1), is_art_point(n, false) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs(int u, int p) {
        num[u] = low[u] = time++;
        for (auto&& v : g[u]) {
            if (num[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (num[u] <= low[v]) is_art_point[u] = (num[u] > 0) || (num[v] > 1);
                if (num[u] < low[v]) bridges.insert({min(u, v), max(u, v)});
            } else if (v != p) {
                low[u] = min(low[u], num[v]);
            }
        }
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (num[i] == -1) dfs(i, -1);
        }
    }
};