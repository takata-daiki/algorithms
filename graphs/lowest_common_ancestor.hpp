#pragma once
#include <bits/stdc++.h>
#include "../data_structures/segment_tree.hpp"
#include "../monoids/min_index.hpp"
using namespace std;

struct LowestCommonAncestor {
    using P = pair<int, int>;

    int n;
    vector<int> idx;
    vector<P> euler_tour;
    vector<vector<int>> g;
    SegmentTree<min_index_monoid<int>> seg;

    LowestCommonAncestor(int _n) : n(_n), idx(_n), g(_n) {}

    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void build(int r) {
        dfs(r, -1, 0);
        seg = SegmentTree<min_index_monoid<int>>(begin(euler_tour),
                                                 end(euler_tour));
    }
    void dfs(int u, int par, int dep) {
        idx[u] = euler_tour.size();
        euler_tour.push_back({dep, u});
        for (auto&& v : g[u]) {
            if (v == par) continue;
            dfs(v, u, dep + 1);
            euler_tour.push_back({dep, u});
        }
    }
    int query(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int i = idx[u];
        int j = idx[v];
        if (i > j) swap(i, j);
        return seg.query(i, j + 1).second;
    }
};