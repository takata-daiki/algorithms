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
    static T INF;
    vector<int> prev;
    vector<Edge> es;

    BellmanFord(int _n) : n(_n), prev(_n, -1) {}

    void add_edge(int u, int v, const T w) { es.push_back({u, v, w}); }
    vector<T> build(int s, bool& neg_cycle) {
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
        for (int i = t; i != -1; i = prev[i]) path.push_back(i);
        reverse(begin(path), end(path));
        return path;
    }
};
template <typename T>
T BellmanFord<T>::INF = numeric_limits<T>::max() / 2;