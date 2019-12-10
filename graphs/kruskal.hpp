#pragma once
#include <bits/stdc++.h>
#include "../data_structures/union_find.hpp"
using namespace std;

template <typename T>
struct Kruskal {
    struct Edge {
        int s, t;
        T cost;
    };
    int n;
    vector<Edge> es;
    Kruskal(int n = 0) : n(n) {}

    void add_edge(int u, int v, T w) {
        n = max(n, max(u, v) + 1);
        es.push_back({u, v, w});
    }
    T build() {
        UnionFind uf(n);
        sort(begin(es), end(es), [](Edge e1, Edge e2) { return e1.cost < e2.cost; });
        T res = 0;
        for (auto&& e : es) {
            if (!uf.same(e.s, e.t)) {
                uf.unite(e.s, e.t);
                res += e.cost;
            }
        }
        return res;
    }
};