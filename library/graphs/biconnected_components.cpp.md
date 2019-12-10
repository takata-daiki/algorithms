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


# :warning: graphs/biconnected_components.cpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/biconnected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46 +0900




## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct BiconnectedComponents {
    int n;
    int time;
    vector<vector<int>> g;
    vector<bool> is_art_point;
    vector<int> num, low;
    set<pair<int, int>> bridges;

    BiconnectedComponents(int n)
        : n(n), time(0), g(n), num(n, -1), low(n, -1), is_art_point(n, false) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs(int u, int p) {
        num[u] = low[u] = time++;
        for (auto&& v : g[u]) {
            if (num[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (num[u] <= low[v]) is_art_point[u] = (num[u] > 0) || (num[v] > 1);
                if (num[u] < low[v]) bridges.insert({min(u, v), max(u, v)});
            } else if (v != p) {
                low[u] = min(low[u], num[v]);
            }
        }
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (num[i] == -1) dfs(i, -1);
        }
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

