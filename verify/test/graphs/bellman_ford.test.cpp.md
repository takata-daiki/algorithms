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


# :heavy_check_mark: test/graphs/bellman_ford.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/bellman_ford.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 17:58:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graphs/bellman_ford.hpp.html">graphs/bellman_ford.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"
#include "../../graphs/bellman_ford.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    BellmanFord<int> g(v);
    while (e--) {
        int s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    bool neg_cycle;
    auto dist = g.build(r, neg_cycle);
    if (neg_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < v; i++) {
        const int NO_PATH = BellmanFord<int>::INF + BellmanFord<int>::INF;
        if (dist[i] == NO_PATH) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/bellman_ford.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"
#line 2 "test/graphs/../../graphs/bellman_ford.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };

    int n;
    static T INF;
    vector<int> prev;
    vector<Edge> es;

    BellmanFord(int _n) : n(_n), prev(_n, -1) {}

    void add_edge(int u, int v, const T w) { es.push_back({u, v, w}); }
    vector<T> build(int s, bool& neg_cycle) {
        neg_cycle = false;
        vector<T> dist(n, INF + INF);
        dist[s] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto&& e : es) {
                if (dist[e.from] == INF + INF) continue;
                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    prev[e.to] = e.from;
                    if (i == n - 1) neg_cycle = true;
                }
            }
        }
        return dist;
    }
    vector<int> get_path(int t) {
        vector<int> path;
        for (int i = t; i != -1; i = prev[i]) path.push_back(i);
        reverse(begin(path), end(path));
        return path;
    }
};
template <typename T>
T BellmanFord<T>::INF = numeric_limits<T>::max() / 2;
#line 3 "test/graphs/bellman_ford.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    BellmanFord<int> g(v);
    while (e--) {
        int s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    bool neg_cycle;
    auto dist = g.build(r, neg_cycle);
    if (neg_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < v; i++) {
        const int NO_PATH = BellmanFord<int>::INF + BellmanFord<int>::INF;
        if (dist[i] == NO_PATH) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
