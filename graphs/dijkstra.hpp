#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Dijkstra {
    struct Edge {
        int to;
        T cost;
    };

    vector<int> prev;
    vector<vector<Edge>> g;

    Dijkstra(const int n) : prev(n, -1), g(n) {}

    void add_edge(const int u, const int v, const T w) {
        g[u].push_back({v, w});
    }
    vector<T> build(const int s) {
        using Node = pair<T, int>;
        vector<T> dist(g.size(), -1);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({dist[s] = 0, s});
        while (!pq.empty()) {
            auto d = pq.top().first;
            auto u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (auto&& v : g[u]) {
                if (dist[v.to] < 0 || dist[v.to] > dist[u] + v.cost) {
                    pq.push({dist[v.to] = dist[u] + v.cost, v.to});
                    prev[v.to] = u;
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