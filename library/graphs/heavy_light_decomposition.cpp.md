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


# :warning: graphs/heavy_light_decomposition.cpp
<a href="../../index.html">Back to top page</a>

* category: graphs
* <a href="{{ site.github.repository_url }}/blob/master/graphs/heavy_light_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46 +0900




## Code
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
    using P = pair<int, int>;
    using F = function<void(int, int)>;

    int n, time;
    vector<vector<int>> g;
    vector<int> num, next, sub_size, head, par, depth, inv, chain;

    HeavyLightDecomposition() {}
    HeavyLightDecomposition(int n)
        : n(n),
          time(0),
          g(n),
          num(n, -1),
          next(n, -1),
          sub_size(n, 1),
          head(n),
          par(n),
          depth(n),
          inv(n),
          chain(n) {}

    void build(vector<int> roots = vector<int>(1, 0)) {
        int c = 0;
        for (auto&& r : roots) {
            dfs(r);
            bfs(r, c++);
        }
    }
    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void dfs(int r) {
        stack<P, deque<P>> s;
        par[r] = -1;
        depth[r] = 0;
        s.push({r, 0});
        while (!s.empty()) {
            int u = s.top().first;
            int& i = s.top().second;
            int sz = g[u].size();
            if (i < sz) {
                int v = g[u][i++];
                if (v == par[u]) continue;
                par[v] = u;
                depth[v] = depth[u] + 1;
                s.push({v, 0});
            } else {
                s.pop();
                int mx = 0;
                for (auto&& v : g[u]) {
                    if (v == par[u]) continue;
                    sub_size[u] += sub_size[v];
                    if (mx < sub_size[v]) mx = sub_size[v], next[u] = v;
                }
            }
        }
    }
    void bfs(int r, int c) {
        int& k = time;
        queue<int> q({r});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int u = h; u != -1; u = next[u]) {
                chain[u] = c;
                num[u] = k++;
                inv[num[u]] = u;
                head[u] = h;
                for (auto&& v : g[u]) {
                    if (v != par[u] && v != next[u]) q.push(v);
                }
            }
        }
    }
    int for_each_vertex(int u, int v, const F& f) {
        while (true) {
            if (num[u] > num[v]) swap(u, v);
            f(max(num[head[v]], num[u]), num[v]);
            if (head[u] != head[v]) {
                v = par[head[v]];
            } else {
                break;
            }
        }
    }
    int for_each_edge(int u, int v, const F& f) {
        while (true) {
            if (num[u] > num[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(num[head[v]], num[v]);
                v = par[head[v]];
            } else {
                if (u != v) f(num[u] + 1, num[v]);
                break;
            }
        }
    }
    int lca(int u, int v) {
        while (true) {
            if (num[u] > num[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

