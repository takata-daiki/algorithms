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


# :heavy_check_mark: test/graphs/kruskal.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/kruskal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-02 22:50:19+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/union_find.hpp.html">data_structures/union_find.hpp</a>
* :heavy_check_mark: <a href="../../../library/graphs/kruskal.hpp.html">graphs/kruskal.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#include "../../graphs/kruskal.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    Kruskal<int> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        g.add_edge(s, t, w);
    }
    cout << g.build() << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/kruskal.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#line 2 "test/graphs/../../graphs/kruskal.hpp"
#include <bits/stdc++.h>
#line 2 "test/graphs/../../graphs/../data_structures/union_find.hpp"
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(const int n) : data(n, -1) {}

    inline int root(const int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    inline int size(const int x) { return -data[root(x)]; }
    inline bool same(const int x, const int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};
#line 4 "test/graphs/../../graphs/kruskal.hpp"
using namespace std;

template <typename T>
struct Kruskal {
    struct Edge {
        int s, t;
        T cost;
        bool operator<(const Edge& e) const { return cost < e.cost; }
    };

    int n;
    vector<Edge> es;

    Kruskal(const int _n = 0) : n(_n) {}

    void add_edge(const int u, const int v, const T w) {
        n = max(n, max(u, v) + 1);
        es.push_back({u, v, w});
    }
    T build() {
        UnionFind uf(n);
        sort(begin(es), end(es));
        T res = 0;
        for (auto&& e : es) {
            if (!uf.same(e.s, e.t)) {
                uf.unite(e.s, e.t);
                res += e.cost;
            }
        }
        return res;
    }
};
#line 3 "test/graphs/kruskal.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    Kruskal<int> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        g.add_edge(s, t, w);
    }
    cout << g.build() << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

