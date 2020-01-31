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


# :heavy_check_mark: test/data_structures/lazy_segment_tree.min_add.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/data_structures/lazy_segment_tree.min_add.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 02:46:07+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structures/segtrees/lazy_segment_tree.hpp.html">data_structures/segtrees/lazy_segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structures/segtrees/monoids/min.hpp.html">data_structures/segtrees/monoids/min.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structures/segtrees/monoids/min_plus_action.hpp.html">data_structures/segtrees/monoids/min_plus_action.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structures/segtrees/monoids/plus.hpp.html">data_structures/segtrees/monoids/plus.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include "../../data_structures/segtrees/lazy_segment_tree.hpp"
#include "../../data_structures/segtrees/monoids/min.hpp"
#include "../../data_structures/segtrees/monoids/plus.hpp"
#include "../../data_structures/segtrees/monoids/min_plus_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    LazySegmentTree<min_monoid<int>, plus_monoid<int>, min_plus_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/data_structures/lazy_segment_tree.min_add.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#line 2 "test/data_structures/../../data_structures/segtrees/lazy_segment_tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidU, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::value_type;
    using U = typename MonoidU::value_type;

    const MonoidT monoid_t;
    const MonoidU monoid_u;
    const Action act;
    int n, height;
    vector<T> data;
    vector<U> lazy;

    LazySegmentTree() {}
    LazySegmentTree(const int _n, const MonoidT& _monoid_t = MonoidT(),
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
        data.resize(n << 1, monoid_t.identity());
        lazy.resize(n << 1, monoid_u.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid_t.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(data[k], lazy[k]); }
    inline void eval(const int k) {
        if (lazy[k] == monoid_u.identity()) return;
        lazy[k << 1] = monoid_u.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = monoid_u.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = monoid_u.identity();
    }
    // [a, b)
    void update(const int a, const int b, const U x) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = monoid_u.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = monoid_u.merge(lazy[r], x);
        }
        for (int l = (a + n) >> 1; l > 0; l >>= 1) {
            data[l] = monoid_t.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = (b + n - 1) >> 1; r > 0; r >>= 1) {
            data[r] = monoid_t.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        T vl = monoid_t.identity(), vr = monoid_t.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid_t.merge(vl, action(l++));
            if (r & 1) vr = monoid_t.merge(action(--r), vr);
        }
        return monoid_t.merge(vl, vr);
    }
};
#line 2 "test/data_structures/../../data_structures/segtrees/monoids/min.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_monoid {
    using value_type = T;
    T identity() const { return numeric_limits<T>::max(); }
    T merge(const T a, const T b) const { return min(a, b); }
};
#line 2 "test/data_structures/../../data_structures/segtrees/monoids/plus.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct plus_monoid {
    using value_type = T;
    T identity() const { return T(); };
    T merge(const T a, const T b) const { return a + b; };
};
#line 2 "test/data_structures/../../data_structures/segtrees/monoids/min_plus_action.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct min_plus_action {
    typename min_monoid<T>::value_type operator()(
        typename min_monoid<T>::value_type a,
        typename plus_monoid<T>::value_type b) const {
        return (b == plus_monoid<T>().identity()) ? a : a + b;
    }
};
#line 6 "test/data_structures/lazy_segment_tree.min_add.test.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    LazySegmentTree<min_monoid<int>, plus_monoid<int>, min_plus_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

