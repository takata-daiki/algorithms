#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };
    int n;
    vector<T> dist;
    vector<int> has_path;
    vector<Edge> es;
    BellmanFord(int n_, T INF = 1e9)
        : n(n_), dist(n_, INF + INF), has_path(n_, 0) {}

    void add_edge(int u, int v, T w) { es.push_back({u, v, w}); }
    bool build(int s) {
        dist[s] = 0;
        has_path[s] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto&& e : es) {
                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    has_path[e.to] |= has_path[e.from];
                    if (i == n - 1 && has_path[e.to]) return false;
                }
            }
        }
        return true;
    }
};