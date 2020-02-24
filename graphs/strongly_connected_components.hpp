#pragma once
#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents {
    int n;
    int time;
    vector<bool> in_stk;
    vector<int> idx, low;
    vector<vector<int>> g, scc;
    stack<int, deque<int>> stk;

    StronglyConnectedComponents(int _n)
        : n(_n), in_stk(n, false), idx(n, -1), low(n, -1), g(_n) {}

    void add_edge(int u, int v) { g[u].push_back(v); }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (idx[i] == -1) dfs(i);
        }
    }
    void dfs(int u) {
        idx[u] = low[u] = time++;
        stk.push(u);
        in_stk[u] = true;
        for (auto&& v : g[u]) {
            if (idx[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = min(low[u], idx[v]);
            }
        }
        if (low[u] == idx[u]) {
            scc.push_back({});
            while (true) {
                int v = stk.top();
                stk.pop();
                in_stk[v] = false;
                scc.back().push_back(v);
                if (u == v) break;
            }
        }
    }
};