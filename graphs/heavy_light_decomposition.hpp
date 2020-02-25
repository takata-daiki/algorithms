#pragma once
#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
    using P = pair<int, int>;
    using F = function<void(int, int)>;

    int n, time;
    vector<int> idx, next, sub_size, head, par, depth, inv, chain;
    vector<vector<int>> g;

    HeavyLightDecomposition() {}
    HeavyLightDecomposition(int _n)
        : n(_n),
          time(0),
          idx(_n, -1),
          next(_n, -1),
          sub_size(_n, 1),
          head(_n),
          par(_n),
          depth(_n),
          inv(_n),
          chain(_n),
          g(_n) {}

    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void build(vector<int> roots = vector<int>(1, 0)) {
        int c = 0;
        for (auto&& r : roots) {
            dfs(r);
            bfs(r, c++);
        }
    }
    void dfs(int r) {
        stack<P, deque<P>> s;
        par[r] = -1;
        depth[r] = 0;
        s.push({r, 0});
        while (!s.empty()) {
            int u = s.top().first;
            int& i = s.top().second;
            int sz = g[u].size();
            if (i < sz) {
                int v = g[u][i++];
                if (v == par[u]) continue;
                par[v] = u;
                depth[v] = depth[u] + 1;
                s.push({v, 0});
            } else {
                s.pop();
                int mx = 0;
                for (auto&& v : g[u]) {
                    if (v == par[u]) continue;
                    sub_size[u] += sub_size[v];
                    if (mx < sub_size[v]) mx = sub_size[v], next[u] = v;
                }
            }
        }
    }
    void bfs(int r, int c) {
        queue<int> q({r});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int u = h; u != -1; u = next[u]) {
                chain[u] = c;
                idx[u] = time++;
                inv[idx[u]] = u;
                head[u] = h;
                for (auto&& v : g[u]) {
                    if (v != par[u] && v != next[u]) q.push(v);
                }
            }
        }
    }
    void for_each_vertex(int u, int v, const F& f) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            f(max(idx[head[v]], idx[u]), idx[v]);
            if (head[u] != head[v]) {
                v = par[head[v]];
            } else {
                break;
            }
        }
    }
    void for_each_edge(int u, int v, const F& f) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(idx[head[v]], idx[v]);
                v = par[head[v]];
            } else {
                if (u != v) f(idx[u] + 1, idx[v]);
                break;
            }
        }
    }
    int lca(int u, int v) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};