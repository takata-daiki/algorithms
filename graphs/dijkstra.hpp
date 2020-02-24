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

    Dijkstra(int n) : prev(n, -1), g(n) {}

    void add_edge(int u, int v, T w) { g[u].push_back({v, w}); }
    vector<T> build(int s) {
        using Node = pair<T, int>;
        vector<T> dist(g.size(), -1);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({dist[s] = 0, s});
        while (!pq.empty()) {
            T d = pq.top().first;
            int u = pq.top().second;
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
        for (int i = t; i != -1; i = prev[i]) path.push_back(i);
        reverse(begin(path), end(path));
        return path;
    }
};