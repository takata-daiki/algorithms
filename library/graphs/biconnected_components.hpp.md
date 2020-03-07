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


# :heavy_check_mark: graphs/biconnected_components.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/biconnected_components.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/graphs/biconnected_components.articulation_points.test.cpp.html">test/graphs/biconnected_components.articulation_points.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graphs/biconnected_components.bridges.test.cpp.html">test/graphs/biconnected_components.bridges.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct BiconnectedComponents {
    int n;
    int time;
    vector<bool> is_art_point;
    vector<int> idx, low;
    set<pair<int, int>> bridges;
    vector<vector<int>> g;

    BiconnectedComponents(int _n)
        : n(_n),
          time(0),
          is_art_point(_n, false),
          idx(_n, -1),
          low(_n, -1),
          g(_n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (idx[i] == -1) dfs(i, -1);
        }
    }
    void dfs(int u, int p) {
        idx[u] = low[u] = time++;
        for (auto&& v : g[u]) {
            if (idx[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (idx[u] <= low[v])
                    is_art_point[u] = (idx[u] > 0) || (idx[v] > 1);
                if (idx[u] < low[v]) bridges.insert({min(u, v), max(u, v)});
            } else if (v != p) {
                low[u] = min(low[u], idx[v]);
            }
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/biconnected_components.hpp"
#include <bits/stdc++.h>
using namespace std;

struct BiconnectedComponents {
    int n;
    int time;
    vector<bool> is_art_point;
    vector<int> idx, low;
    set<pair<int, int>> bridges;
    vector<vector<int>> g;

    BiconnectedComponents(int _n)
        : n(_n),
          time(0),
          is_art_point(_n, false),
          idx(_n, -1),
          low(_n, -1),
          g(_n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (idx[i] == -1) dfs(i, -1);
        }
    }
    void dfs(int u, int p) {
        idx[u] = low[u] = time++;
        for (auto&& v : g[u]) {
            if (idx[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (idx[u] <= low[v])
                    is_art_point[u] = (idx[u] > 0) || (idx[v] > 1);
                if (idx[u] < low[v]) bridges.insert({min(u, v), max(u, v)});
            } else if (v != p) {
                low[u] = min(low[u], idx[v]);
            }
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
