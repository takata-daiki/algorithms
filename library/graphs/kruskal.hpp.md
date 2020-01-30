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

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/kruskal.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:50:18+09:00




## Depends on

* :x: <a href="../data_structures/union_find.hpp.html">data_structures/union_find.hpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/kruskal.hpp"
#include <bits/stdc++.h>
#line 2 "graphs/../data_structures/union_find.hpp"
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(const int n) : data(n, -1) {}

    inline int root(const int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    inline int size(const int x) { return -data[root(x)]; }
    inline bool same(const int x, const int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};
#line 4 "graphs/kruskal.hpp"
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

