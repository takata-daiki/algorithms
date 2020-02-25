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


# :heavy_check_mark: test/graphs/strongly_connected_components.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/strongly_connected_components.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graphs/strongly_connected_components.hpp.html">graphs/strongly_connected_components.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
#include "../../graphs/strongly_connected_components.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    StronglyConnectedComponents g(n);
    while (m--) {
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t);
    }
    g.build();

    vector<int> idx(n);
    for (int i = 0; i < (int)g.scc.size(); i++) {
        for (auto&& x : g.scc[i]) idx[x] = i;
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (idx[u] == idx[v]) << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/strongly_connected_components.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
#line 2 "test/graphs/../../graphs/strongly_connected_components.hpp"
#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents {
    int n;
    int time;
    vector<bool> in_stk;
    vector<int> idx, low;
    vector<vector<int>> g, scc;
    stack<int, deque<int>> stk;

    StronglyConnectedComponents(int _n)
        : n(_n), in_stk(_n, false), idx(_n, -1), low(_n, -1), g(_n) {}

    void add_edge(int u, int v) { g[u].push_back(v); }
    void build() {
        for (int i = 0; i < n; ++i) {
            if (idx[i] == -1) dfs(i);
        }
    }
    void dfs(int u) {
        idx[u] = low[u] = time++;
        stk.push(u);
        in_stk[u] = true;
        for (auto&& v : g[u]) {
            if (idx[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = min(low[u], idx[v]);
            }
        }
        if (low[u] == idx[u]) {
            scc.push_back({});
            while (true) {
                int v = stk.top();
                stk.pop();
                in_stk[v] = false;
                scc.back().push_back(v);
                if (u == v) break;
            }
        }
    }
};
#line 3 "test/graphs/strongly_connected_components.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    StronglyConnectedComponents g(n);
    while (m--) {
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t);
    }
    g.build();

    vector<int> idx(n);
    for (int i = 0; i < (int)g.scc.size(); i++) {
        for (auto&& x : g.scc[i]) idx[x] = i;
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (idx[u] == idx[v]) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

