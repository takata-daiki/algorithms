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


# :heavy_check_mark: graphs/bellman_ford.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/bellman_ford.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-02 23:23:57+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/graphs/bellman_ford.test.cpp.html">test/graphs/bellman_ford.test.cpp</a>


## Code

<a id="unbundled"></a>
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
T BellmanFord<T>::INF = numeric_limits<T>::max() / 2;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/bellman_ford.hpp"
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
T BellmanFord<T>::INF = numeric_limits<T>::max() / 2;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

