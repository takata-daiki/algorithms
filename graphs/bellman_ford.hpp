#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };

    const int n;
    static T INF;
    vector<int> prev;
    vector<Edge> es;

    BellmanFord(const int _n) : n(_n), prev(_n, -1) {}

    void add_edge(const int u, const int v, const T w) {
        es.push_back({u, v, w});
    }
    vector<T> build(const int s, bool& neg_cycle) {
        neg_cycle = false;
        vector<T> dist(n, INF + INF);
        dist[s] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto&& e : es) {
                if (dist[e.from] == INF + INF) continue;
                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    prev[e.to] = e.from;
                    if (i == n - 1) neg_cycle = true;
                }
            }
        }
        return dist;
    }
    vector<int> get_path(int t) {
        vector<int> path;
        for (; t != -1; t = prev[t]) path.push_back(t);
        reverse(begin(path), end(path));
        return path;
    }
};
template <typename T>
T BellmanFord<T>::INF = 1e9;