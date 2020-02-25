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


# :heavy_check_mark: test/graphs/ford_fulkerson.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/ford_fulkerson.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graphs/ford_fulkerson.hpp.html">graphs/ford_fulkerson.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#include "../../graphs/ford_fulkerson.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    FordFulkerson ssp(n);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        ssp.add_edge(u, v, c);
    }
    cout << ssp.build(0, n - 1) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/ford_fulkerson.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#line 2 "test/graphs/../../graphs/ford_fulkerson.hpp"
#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };

    int n, init;
    vector<bool> used;
    vector<vector<Edge>> g;

    FordFulkerson(int _n, int _init = 1e9) : n(_n), init(_init), g(_n) {}

    void add_edge(int u, int v, int c) {
        int sz_u = g[u].size();
        int sz_v = g[v].size();
        g[u].push_back({v, c, sz_v});
        g[v].push_back({u, 0, sz_u});
    }
    int build(int s, int t) {
        int flow = 0;
        while (true) {
            used.assign(n, false);
            int f = dfs(s, t, init);
            if (f == 0) break;
            flow += f;
        }
        return flow;
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
};
#line 3 "test/graphs/ford_fulkerson.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    FordFulkerson ssp(n);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        ssp.add_edge(u, v, c);
    }
    cout << ssp.build(0, n - 1) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

