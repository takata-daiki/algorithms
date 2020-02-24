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


# :heavy_check_mark: test/graphs/lowest_common_ancestor.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/lowest_common_ancestor.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 22:28:03+09:00




## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/segment_tree.hpp.html">data_structures/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/graphs/lowest_common_ancestor.hpp.html">graphs/lowest_common_ancestor.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/min_index.hpp.html">monoids/min_index.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include "../../graphs/lowest_common_ancestor.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    LowestCommonAncestor g(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            g.add_edge(i, c);
        }
    }
    g.build(0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.query(u, v) << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/lowest_common_ancestor.test.cpp"
#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#line 2 "test/graphs/../../graphs/lowest_common_ancestor.hpp"
#include <bits/stdc++.h>
#line 2 "test/graphs/../../graphs/../data_structures/segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    int n;
    vector<T> data;
    Monoid monoid;

    SegmentTree() {}
    SegmentTree(int _n, const Monoid& _monoid = Monoid()) : monoid(_monoid) {
        n = 1;
        while (n < _n) n <<= 1;
        data.assign(n << 1, monoid.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        int size = distance(first, last);
        n = 1;
        while (n < size) n <<= 1;
        data.assign(n << 1, monoid.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    void update(int k, T x) {
        assert(0 <= k && k < n);
        k += n;
        data[k] = x;
        for (int i = k >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};
#line 2 "test/graphs/../../graphs/../monoids/min_index.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_index_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(numeric_limits<T>::max(), INT_MAX); }
    P merge(P a, P b) { return min(a, b); }
};
#line 5 "test/graphs/../../graphs/lowest_common_ancestor.hpp"
using namespace std;

struct LowestCommonAncestor {
    using P = pair<int, int>;

    int n;
    vector<int> idx;
    vector<P> euler_tour;
    vector<vector<int>> g;
    SegmentTree<min_index_monoid<int>> seg;

    LowestCommonAncestor(int _n) : n(_n), idx(_n), g(_n) {}

    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void build(int r) {
        dfs(r, -1, 0);
        seg = SegmentTree<min_index_monoid<int>>(begin(euler_tour),
                                                 end(euler_tour));
    }
    void dfs(int u, int par, int dep) {
        idx[u] = euler_tour.size();
        euler_tour.push_back({dep, u});
        for (auto&& v : g[u]) {
            if (v == par) continue;
            dfs(v, u, dep + 1);
            euler_tour.push_back({dep, u});
        }
    }
    int query(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int i = idx[u];
        int j = idx[v];
        if (i > j) swap(i, j);
        return seg.query(i, j + 1).second;
    }
};
#line 4 "test/graphs/lowest_common_ancestor.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    LowestCommonAncestor g(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            g.add_edge(i, c);
        }
    }
    g.build(0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.query(u, v) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

