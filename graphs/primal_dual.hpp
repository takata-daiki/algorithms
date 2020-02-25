#pragma once
#include <bits/stdc++.h>
using namespace std;

struct PrimalDual {
    struct Edge {
        int to, cap, cost, rev;
    };

    int n, init;
    vector<int> dist, pv, pe, h;
    vector<vector<Edge>> g;

    PrimalDual() {}
    PrimalDual(int _n, int _init = 1e9)
        : n(_n), init(_init), dist(_n), pv(_n), pe(_n), g(_n) {}

    void add_edge(int u, int v, int cap, int cost) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, cap, cost, szV});
        g[v].push_back({u, 0, -cost, szU});
    }
    int build(int s, int t, int f) {
        int res = 0;
        h.assign(n, 0);
        while (f > 0) {
            if (dijkstra(s, t) == init) return -1;
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            int flow = f;
            for (int u = t; u != s; u = pv[u]) {
                flow = min(flow, g[pv[u]][pe[u]].cap);
            }
            f -= flow;
            res += flow * h[t];
            for (int u = t; u != s; u = pv[u]) {
                Edge& e = g[pv[u]][pe[u]];
                e.cap -= flow;
                g[u][e.rev].cap += flow;
            }
        }
        return res;
    }
    int dijkstra(int s, int t) {
        dist = vector<int>(n, init);
        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({dist[s] = 0, s});

        while (!pq.empty()) {
            auto d = pq.top().first;
            auto u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (size_t i = 0; i < g[u].size(); ++i) {
                Edge& e = g[u][i];
                int v = e.to;
                if (e.cap > 0 && dist[v] > dist[u] + e.cost + h[u] - h[v]) {
                    dist[v] = dist[u] + e.cost + h[u] - h[v];
                    pv[v] = u;
                    pe[v] = i;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[t];
    }
};