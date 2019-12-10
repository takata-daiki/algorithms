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


# :warning: graphs/lowest_common_ancestor.cpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/lowest_common_ancestor.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46 +0900




## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct LowestCommonAncestor {
    using P = pair<int, int>;

    int n, time;
    vector<vector<int>> g;
    vector<int> num, euler_tour;
    vector<P> depth;
    SegmentTree<P> seg;

    LowestCommonAncestor(int n)
        : n(n), time(0), g(n), num(n), euler_tour(n * 2 - 1), depth(n * 2 - 1) {}

    void build(int r) {
        dfs(r, r, 0);
        SegmentTree<P>::F f = [](P a, P b) { return min(a, b); };
        seg = SegmentTree<P>(n * 2 - 1, f, {INT_MAX, -1}, depth);
    }
    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void dfs(int u, int p, int d) {
        num[u] = time;
        euler_tour[time] = u;
        depth[time] = {d, time};
        ++time;
        for (auto&& v : g[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
            euler_tour[time] = u;
            depth[time] = {d, time};
            ++time;
        }
    }
    int build(int u, int v) {
        int i = num[u];
        int j = num[v];
        if (i > j) swap(i, j);
        return euler_tour[seg.query(i, j + 1).second];
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

