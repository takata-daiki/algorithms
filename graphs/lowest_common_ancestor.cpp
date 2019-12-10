#pragma once
#include <bits/stdc++.h>
using namespace std;

struct LowestCommonAncestor {
    using P = pair<int, int>;

    int n, time;
    vector<vector<int>> g;
    vector<int> num, euler_tour;
    vector<P> depth;
    SegmentTree<P> seg;

    LowestCommonAncestor(int n)
        : n(n), time(0), g(n), num(n), euler_tour(n * 2 - 1), depth(n * 2 - 1) {}

    void build(int r) {
        dfs(r, r, 0);
        SegmentTree<P>::F f = [](P a, P b) { return min(a, b); };
        seg = SegmentTree<P>(n * 2 - 1, f, {INT_MAX, -1}, depth);
    }
    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void dfs(int u, int p, int d) {
        num[u] = time;
        euler_tour[time] = u;
        depth[time] = {d, time};
        ++time;
        for (auto&& v : g[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
            euler_tour[time] = u;
            depth[time] = {d, time};
            ++time;
        }
    }
    int build(int u, int v) {
        int i = num[u];
        int j = num[v];
        if (i > j) swap(i, j);
        return euler_tour[seg.query(i, j + 1).second];
    }
};