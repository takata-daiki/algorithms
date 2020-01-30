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


# :warning: graphs/ford_fulkerson.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/ford_fulkerson.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };
    int n, init;
    vector<vector<Edge>> g;
    vector<bool> used;

    FordFulkerson() {}
    FordFulkerson(int n, int INF = 1e9) : n(n), g(n), init(INF) {}

    void add_edge(int u, int v, int c) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, c, szV});
        g[v].push_back({u, 0, szU});
    }
    int dfs(int u, int t, int c) {
        if (u == t) return c;
        used[u] = true;
        for (auto&& e : g[u]) {
            int v = e.to;
            if (!used[v] && e.cap > 0) {
                int f = dfs(v, t, min(c, e.cap));
                if (f > 0) {
                    e.cap -= f;
                    g[v][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            used = vector<bool>(n, false);
            int f = dfs(s, t, init);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/ford_fulkerson.hpp"
#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };
    int n, init;
    vector<vector<Edge>> g;
    vector<bool> used;

    FordFulkerson() {}
    FordFulkerson(int n, int INF = 1e9) : n(n), g(n), init(INF) {}

    void add_edge(int u, int v, int c) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, c, szV});
        g[v].push_back({u, 0, szU});
    }
    int dfs(int u, int t, int c) {
        if (u == t) return c;
        used[u] = true;
        for (auto&& e : g[u]) {
            int v = e.to;
            if (!used[v] && e.cap > 0) {
                int f = dfs(v, t, min(c, e.cap));
                if (f > 0) {
                    e.cap -= f;
                    g[v][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            used = vector<bool>(n, false);
            int f = dfs(s, t, init);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

