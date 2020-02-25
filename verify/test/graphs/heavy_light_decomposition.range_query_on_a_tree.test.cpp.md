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


# :heavy_check_mark: test/graphs/heavy_light_decomposition.range_query_on_a_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/heavy_light_decomposition.range_query_on_a_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-25 12:34:16+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/lazy_segment_tree.hpp.html">data_structures/lazy_segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/graphs/heavy_light_decomposition.hpp.html">graphs/heavy_light_decomposition.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/affine.hpp.html">monoids/affine.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/sum.hpp.html">monoids/sum.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoids/sum_affine_action.hpp.html">monoids/sum_affine_action.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E"
#include <bits/stdc++.h>

#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../graphs/heavy_light_decomposition.hpp"
#include "../../monoids/affine.hpp"
#include "../../monoids/sum.hpp"
#include "../../monoids/sum_affine_action.hpp"
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();

    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = P(0, 1);
    }
    LazySegmentTree<sum_monoid<ll>, affine_monoid<ll>, sum_affine_action<ll>> seg(begin(a), end(a));
    auto add = [&](int v, int w) {
        hld.for_each_edge(0, v, [&](int l, int r) {
            seg.update(l, r + 1, P(1, w));
            });
    };
    auto get_sum = [&](int u) {
        ll res = 0;
        hld.for_each_edge(0, u, [&](int l, int r) {
            res += seg.query(l, r + 1).first;
            });
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int com;
        cin >> com;
        if (com) {
            int u;
            cin >> u;
            cout << get_sum(u) << endl;
        } else {
            int v, w;
            cin >> v >> w;
            add(v, w);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graphs/heavy_light_decomposition.range_query_on_a_tree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E"
#include <bits/stdc++.h>

#line 2 "test/graphs/../../data_structures/lazy_segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidU, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::value_type;
    using U = typename MonoidU::value_type;

    int n, height;
    vector<T> data;
    vector<U> lazy;
    MonoidT monoid_t;
    MonoidU monoid_u;
    Action act;

    LazySegmentTree() {}
    LazySegmentTree(int _n, const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        n = 1, height = 0;
        while (n < _n) n <<= 1, height++;
        data.assign(n << 1, monoid_t.identity());
        lazy.assign(n << 1, monoid_u.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    LazySegmentTree(InputIterator first, InputIterator last,
                    const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        int size = distance(first, last);
        n = 1, height = 0;
        while (n < size) n <<= 1, height++;
        data.assign(n << 1, monoid_t.identity());
        lazy.assign(n << 1, monoid_u.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid_t.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(data[k], lazy[k]); }
    inline void eval(int k) {
        if (lazy[k] == monoid_u.identity()) return;
        lazy[k << 1] = monoid_u.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = monoid_u.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = monoid_u.identity();
    }
    // [a, b)
    void update(int a, int b, U x) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        for (int i = height; i > 0; i--) {
            eval(a >> i);
            eval(b >> i);
        }
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = monoid_u.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = monoid_u.merge(lazy[r], x);
        }
        for (int l = a >> 1; l > 0; l >>= 1) {
            data[l] = monoid_t.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = b >> 1; r > 0; r >>= 1) {
            data[r] = monoid_t.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        for (int i = height; i > 0; i--) {
            eval(a >> i);
            eval(b >> i);
        }
        T vl = monoid_t.identity(), vr = monoid_t.identity();
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid_t.merge(vl, action(l++));
            if (r & 1) vr = monoid_t.merge(action(--r), vr);
        }
        return monoid_t.merge(vl, vr);
    }
};
#line 2 "test/graphs/../../graphs/heavy_light_decomposition.hpp"
#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
    using P = pair<int, int>;
    using F = function<void(int, int)>;

    int n, time;
    vector<int> idx, next, sub_size, head, par, depth, inv, chain;
    vector<vector<int>> g;

    HeavyLightDecomposition() {}
    HeavyLightDecomposition(int _n)
        : n(_n),
          time(0),
          idx(_n, -1),
          next(_n, -1),
          sub_size(_n, 1),
          head(_n),
          par(_n),
          depth(_n),
          inv(_n),
          chain(_n),
          g(_n) {}

    void add_edge(int s, int t) {
        g[s].push_back(t);
        g[t].push_back(s);
    }
    void build(vector<int> roots = vector<int>(1, 0)) {
        int c = 0;
        for (auto&& r : roots) {
            dfs(r);
            bfs(r, c++);
        }
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
        queue<int> q({r});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int u = h; u != -1; u = next[u]) {
                chain[u] = c;
                idx[u] = time++;
                inv[idx[u]] = u;
                head[u] = h;
                for (auto&& v : g[u]) {
                    if (v != par[u] && v != next[u]) q.push(v);
                }
            }
        }
    }
    void for_each_vertex(int u, int v, const F& f) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            f(max(idx[head[v]], idx[u]), idx[v]);
            if (head[u] != head[v]) {
                v = par[head[v]];
            } else {
                break;
            }
        }
    }
    void for_each_edge(int u, int v, const F& f) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(idx[head[v]], idx[v]);
                v = par[head[v]];
            } else {
                if (u != v) f(idx[u] + 1, idx[v]);
                break;
            }
        }
    }
    int lca(int u, int v) {
        while (true) {
            if (idx[u] > idx[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
#line 2 "test/graphs/../../monoids/affine.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct affine_monoid {
    using P = pair<T, T>;
    using value_type = P;
    P identity() { return make_pair(T(1), T(0)); }
    P merge(P a, P b) {
        T fst = a.first * b.first;
        T snd = a.second * b.first + b.second;
        return make_pair(fst, snd);
    }
};
#line 2 "test/graphs/../../monoids/sum.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct sum_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(T(), 0); }
    P merge(P a, P b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }
};
#line 2 "test/graphs/../../monoids/sum_affine_action.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct sum_affine_action {
    typename sum_monoid<T>::value_type operator()(
        typename sum_monoid<T>::value_type a,
        typename affine_monoid<T>::value_type b) {
        return make_pair(a.first * b.first + a.second * b.second, a.second);
    }
};
#line 9 "test/graphs/heavy_light_decomposition.range_query_on_a_tree.test.cpp"
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();

    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = P(0, 1);
    }
    LazySegmentTree<sum_monoid<ll>, affine_monoid<ll>, sum_affine_action<ll>> seg(begin(a), end(a));
    auto add = [&](int v, int w) {
        hld.for_each_edge(0, v, [&](int l, int r) {
            seg.update(l, r + 1, P(1, w));
            });
    };
    auto get_sum = [&](int u) {
        ll res = 0;
        hld.for_each_edge(0, u, [&](int l, int r) {
            res += seg.query(l, r + 1).first;
            });
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int com;
        cin >> com;
        if (com) {
            int u;
            cin >> u;
            cout << get_sum(u) << endl;
        } else {
            int v, w;
            cin >> v >> w;
            add(v, w);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

