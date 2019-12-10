#pragma once
#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents {
    int n;
    int time;
    vector<vector<int>> g;
    vector<int> num, low;
    vector<vector<int>> scc;
    stack<int, deque<int>> S;
    vector<bool> inS;

    StronglyConnectedComponents(int n)
        : n(n), g(n), num(n, -1), low(n, -1), inS(n, false) {}

    void add_edge(int u, int v) { g[u].push_back(v); }
    void dfs(int u) {
        num[u] = low[u] = time++;
        S.push(u);
        inS[u] = true;
        for (auto&& v : g[u]) {
            if (num[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inS[v]) {
                low[u] = min(low[u], num[v]);
            }
        }
        if (low[u] == num[u]) {
            scc.push_back({});
            while (true) {
                int v = S.top();
                S.pop();
                inS[v] = false;
                scc.back().push_back(v);
                if (u == v) break;
            }
        }
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (num[i] == -1) dfs(i);
        }
    }
};