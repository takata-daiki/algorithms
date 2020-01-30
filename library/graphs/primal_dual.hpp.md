---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: graphs/primal_dual.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/primal_dual.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct PrimalDual {
    struct Edge {
        int to, cap, cost, rev;
    };
    int n, init;
    vector<vector<Edge>> g;
    vector<int> dist, pv, pe, h;

    PrimalDual() {}
    PrimalDual(int n, int INF = 1e9)
        : n(n), init(INF), g(n), dist(n), pv(n), pe(n) {}

    void add_edge(int u, int v, int cap, int cost) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, cap, cost, szV});
        g[v].push_back({u, 0, -cost, szU});
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
    int build(int s, int t, int f) {
        int res = 0;
        h = vector<int>(n, 0);
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
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/primal_dual.hpp"
#include <bits/stdc++.h>
using namespace std;

struct PrimalDual {
    struct Edge {
        int to, cap, cost, rev;
    };
    int n, init;
    vector<vector<Edge>> g;
    vector<int> dist, pv, pe, h;

    PrimalDual() {}
    PrimalDual(int n, int INF = 1e9)
        : n(n), init(INF), g(n), dist(n), pv(n), pe(n) {}

    void add_edge(int u, int v, int cap, int cost) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, cap, cost, szV});
        g[v].push_back({u, 0, -cost, szU});
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
    int build(int s, int t, int f) {
        int res = 0;
        h = vector<int>(n, 0);
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
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

