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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/graphs/primal_dual.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/primal_dual.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graphs/primal_dual.hpp.html">graphs/primal_dual.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"
#include "../../graphs/primal_dual.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual ssp(n);
    while (m--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        ssp.add_edge(u, v, c, d);
    }
    cout << ssp.build(0, n - 1, f) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/primal_dual.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"
#line 2 "test/graphs/../../graphs/primal_dual.hpp"
#include <bits/stdc++.h>
using namespace std;

struct PrimalDual {
    struct Edge {
        int to, cap, cost, rev;
    };

    int n, init;
    vector<int> dist, pv, pe, h;
    vector<vector<Edge>> g;

    PrimalDual() {}
    PrimalDual(int _n, int _init = 1e9)
        : n(_n), init(_init), dist(_n), pv(_n), pe(_n), g(_n) {}

    void add_edge(int u, int v, int cap, int cost) {
        int szU = g[u].size();
        int szV = g[v].size();
        g[u].push_back({v, cap, cost, szV});
        g[v].push_back({u, 0, -cost, szU});
    }
    int build(int s, int t, int f) {
        int res = 0;
        h.assign(n, 0);
        while (f > 0) {
            if (dijkstra(s, t) == init) return -1;
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            int flow = f;
            for (int u = t; u != s; u = pv[u]) {
                flow = min(flow, g[pv[u]][pe[u]].cap);
            }
            f -= flow;
            res += flow * h[t];
            for (int u = t; u != s; u = pv[u]) {
                Edge& e = g[pv[u]][pe[u]];
                e.cap -= flow;
                g[u][e.rev].cap += flow;
            }
        }
        return res;
    }
    int dijkstra(int s, int t) {
        dist = vector<int>(n, init);
        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({dist[s] = 0, s});

        while (!pq.empty()) {
            auto d = pq.top().first;
            auto u = pq.top().second;
            pq.pop();
            if (dist[u] < d) continue;
            for (size_t i = 0; i < g[u].size(); ++i) {
                Edge& e = g[u][i];
                int v = e.to;
                if (e.cap > 0 && dist[v] > dist[u] + e.cost + h[u] - h[v]) {
                    dist[v] = dist[u] + e.cost + h[u] - h[v];
                    pv[v] = u;
                    pe[v] = i;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[t];
    }
};
#line 3 "test/graphs/primal_dual.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual ssp(n);
    while (m--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        ssp.add_edge(u, v, c, d);
    }
    cout << ssp.build(0, n - 1, f) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

