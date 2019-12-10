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


# :warning: graphs/kruskal.hpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/kruskal.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46 +0900




## Dependencies
* :heavy_check_mark: <a href="../data_structures/union_find.hpp.html">data_structures/union_find.hpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
#include "../data_structures/union_find.hpp"
using namespace std;

template <typename T>
struct Kruskal {
    struct Edge {
        int s, t;
        T cost;
    };
    int n;
    vector<Edge> es;
    Kruskal(int n = 0) : n(n) {}

    void add_edge(int u, int v, T w) {
        n = max(n, max(u, v) + 1);
        es.push_back({u, v, w});
    }
    T build() {
        UnionFind uf(n);
        sort(begin(es), end(es), [](Edge e1, Edge e2) { return e1.cost < e2.cost; });
        T res = 0;
        for (auto&& e : es) {
            if (!uf.same(e.s, e.t)) {
                uf.unite(e.s, e.t);
                res += e.cost;
            }
        }
        return res;
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

