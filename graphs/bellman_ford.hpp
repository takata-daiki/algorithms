#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };
    vector<T> dist;
    vector<int> has_path;
    vector<Edge> es;
    BellmanFord(const int n, const T INF = 1e9
        : n(n), dist(n, INF + INF), has_path(n, 0) {}

    void add_edge(const int u, const int v, const T w) {
        es.push_back({u, v, w});
    }
    bool build(const int s) {
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