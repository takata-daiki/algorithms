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


# :warning: graphs/bellman_ford.hpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/bellman_ford.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:50:18 +0900




## Code
{% raw %}
```cpp
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
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

