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


# :heavy_check_mark: graphs/dijkstra.hpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 13:59:37 +0900




## Verified
* :heavy_check_mark: <a href="../../verify/test/graphs/dijkstra.test.cpp.html">test/graphs/dijkstra.test.cpp</a>


## Code
{% raw %}
```cpp
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

    void add_edge(int u, int v, T w) {
        g[u].push_back({v, w});
    }
    vector<T> build(int s) {
        vector<T> dist(g.size(), -1);
        using Node = pair<T, int>;
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
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

