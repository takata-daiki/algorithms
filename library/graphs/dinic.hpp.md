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


# :heavy_check_mark: graphs/dinic.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8706a28320e46fa20885a2933e42797">graphs</a>
* <a href="{{ site.github.repository_url }}/blob/master/graphs/dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/graphs/dinic.test.cpp.html">test/graphs/dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    int n, init;
    vector<int> itr, level;
    vector<vector<Edge>> g;

    Dinic(int _n, int _init = 1e9) : n(_n), init(_init), g(_n) {}

    void add_edge(int u, int v, int c) {
        int sz_u = g[u].size();
        int sz_v = g[v].size();
        g[u].push_back({v, c, sz_v});
        g[v].push_back({u, 0, sz_u});
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) break;
            itr.assign(n, 0);
            for (int f; (f = dfs(s, t, init)) > 0;) flow += f;
        }
        return flow;
    }
    void bfs(int s) {
        level.assign(n, -1);
        queue<int> que({s});
        level[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto&& e : g[u]) {
                int v = e.to;
                if (level[v] < 0 && e.cap > 0) {
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    int dfs(int u, int t, int c) {
        if (u == t) return c;
        for (int& i = itr[u]; i < (int)g[u].size(); ++i) {
            Edge& e = g[u][i];
            int v = e.to;
            if (level[u] < level[v] && e.cap > 0) {
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
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graphs/dinic.hpp"
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    int n, init;
    vector<int> itr, level;
    vector<vector<Edge>> g;

    Dinic(int _n, int _init = 1e9) : n(_n), init(_init), g(_n) {}

    void add_edge(int u, int v, int c) {
        int sz_u = g[u].size();
        int sz_v = g[v].size();
        g[u].push_back({v, c, sz_v});
        g[v].push_back({u, 0, sz_u});
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) break;
            itr.assign(n, 0);
            for (int f; (f = dfs(s, t, init)) > 0;) flow += f;
        }
        return flow;
    }
    void bfs(int s) {
        level.assign(n, -1);
        queue<int> que({s});
        level[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto&& e : g[u]) {
                int v = e.to;
                if (level[v] < 0 && e.cap > 0) {
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    int dfs(int u, int t, int c) {
        if (u == t) return c;
        for (int& i = itr[u]; i < (int)g[u].size(); ++i) {
            Edge& e = g[u][i];
            int v = e.to;
            if (level[u] < level[v] && e.cap > 0) {
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
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

